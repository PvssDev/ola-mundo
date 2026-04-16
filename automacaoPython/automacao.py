from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
from time import sleep                                  
import pyautogui

def limpar_nome_impressora(nome):
    """Padroniza o nome da impressora para comparação, removendo excessos e espaços."""
    # Garante que a comparação ignore maiúsculas/minúsculas e espaços extras.
    nome = nome.lower().strip()
    
    # Remove textos comuns que podem aparecer no fim do nome do driver (como (Cópia 1))
    if ')' in nome:
        # Pega apenas a parte antes do primeiro parêntese (ajusta para sua necessidade)
        nome = nome.split('(')[0].strip()
        
    # Remove espaços duplos
    nome = ' '.join(nome.split()) 
    return nome

# use o seguinte comando no seu terminal: "C:\Program Files\Google\Chrome\Application\chrome.exe" --remote-debugging-port=9222 --user-data-dir="C:\selenium\chrome-profile"
# agora abra o planer logado na sua conta.
# e seja feliz ;)
options = Options()
options.debugger_address = "localhost:9222"
driver = webdriver.Chrome(options=options)
wait = WebDriverWait(driver, 5)

# 1 abrir o site que já ta em uma aba do google
pyautogui.keyDown('alt')
pyautogui.press('tab')                              
pyautogui.keyUp('alt')

# 2 acessar a aba do site
pyautogui.hotkey('ctrl', '1')

# 3 apertar no botão meus planos
print("Iniciando a navegação via Selenium...")

for i in range(9):
    pyautogui.press('tab')

pyautogui.press('down')
pyautogui.press('down')
pyautogui.press('enter')

# --- PASSO 4: Acessar a aba 'Compartilhados' (Pivot/Filtro) ---
try:
    print("🔎 Clicando na aba 'Compartilhados'...")
    # A aba 'Compartilhados' tem o atributo data-content="Partilhados" ou o ID="myPlansSharedPivot".
    # Vamos usar o atributo de texto que é o mais legível: "Compartilhado"
    xpath_compartilhados = "//button[@data-content='Partilhados' or .//span[text()='Compartilhado']]"

    # 1. Espera o elemento ser clicável
    btn_compartilhados = wait.until(
        EC.element_to_be_clickable((By.XPATH, xpath_compartilhados))
    )
    # 2. Clica
    btn_compartilhados.click()
    print("✅ Aba 'Compartilhados' selecionada.")

except Exception as e:
    print(f"❌ Erro ao clicar em 'Compartilhados': {e}")

# --- PASSO 5: Acessar o plano de Impressão (Primeiro item da lista) ---
# Assumindo que "Impressao" é o nome do plano que você quer.
try:
    print("🔎 Procurando o plano de impressão na lista...")
    
    # XPath focado no BOTÃO que contém o texto "IMPRESSÃO" (e variantes).
    # Este XPath é robusto, mesmo que não seja o mais rápido, mas o
    # problema de lentidão é frequentemente resolvido ajustando as esperas.
    xpath_simples = (
        "//div[@data-automationid='DetailsRow']" +
        "//span[contains(@class, 'cell-value') and (" +
        "text()='IMPRESSÃO' or text()='Impressao' or text()='impressão')" +
        "]/ancestor::button[1]" 
    )
    
    # 1. Usar a espera EXPLICITA para que o elemento seja CLICÁVEL.
    # Esta é a melhor prática para performance.
    plano_impressao = wait.until(
        EC.element_to_be_clickable((By.XPATH, xpath_simples))
    )
    
    # 2. Executar um script JavaScript para clicar no elemento.
    # Isto é MUITO mais rápido e evita problemas de interceptação ou de lentidão
    # da execução do clique nativo do Selenium.
    driver.execute_script("arguments[0].click();", plano_impressao)
    
    print("✅ Plano 'IMPRESSÃO' clicado com sucesso via JavaScript (mais rápido).")
    
    # 3. Use uma espera após o clique para um ELEMENTO-CHAVE da PRÓXIMA TELA.
    # Evite 'sleep(3)' (Thread.sleep).
    # Exemplo: espere por um elemento conhecido que só aparece APÓS o plano carregar.
    # Ex: O título da lista de tarefas.
    # wait.until(EC.visibility_of_element_located((By.XPATH, "//div[@aria-label='Lista de tarefas']"))) 

except Exception as e:
    # Captura a exceção de tempo limite de espera (TimeoutException) se o plano não for encontrado
    print(f"❌ Ocorreu um erro (Plano 'IMPRESSÃO' não encontrado ou não clicável): {e}")

# 6 ir na coluna Para Imprimir
# 7 entrar em uma das impressões
try:
    # Encontrar a coluna "Para Imprimir"
    xpath_coluna = "//li[.//h3[text()='Para Imprimir']]"
    print("🔎 Procurando a coluna 'Para Imprimir'...")
    coluna_para_imprimir = wait.until(EC.presence_of_element_located((By.XPATH, xpath_coluna)))
    print("👍 Coluna encontrada!\n")

    # Encontrar todos os cards dentro dessa coluna
    cards_na_coluna = coluna_para_imprimir.find_elements(By.CLASS_NAME, 'taskBoardCard')

    # Verificar se existe algum card e clicar no primeiro
    if cards_na_coluna:
        print(f"✅ {len(cards_na_coluna)} cards encontrados. Clicando no primeiro...\n")
        
        # Pega o primeiro elemento da lista (índice 0)
        primeiro_card = cards_na_coluna[0]
        
        # Pega e mostra o título do card que será clicado
        try:
            titulo_primeiro_card = primeiro_card.find_element(By.CLASS_NAME, 'title').text
            print(f"🖱️ Clicando no card: '{titulo_primeiro_card}'")
        except:
            print("🖱️ Clicando no primeiro card...\n")

        # Ação de clicar no card
        primeiro_card.click()
        
        print("🎉 Sucesso! O primeiro card foi clicado.\n")
        
    else:
        print("🟡 Nenhum card de tarefa foi encontrado na coluna para ser clicado.\n")

except Exception as e:
    print(f"❌ Ocorreu um erro: {e}\n")

# 8 ler anotações com a seguinte estrutura (copias, colorido ou preto e branco,frente e verso ou frente, A4 ou A3, paginas ou todas, normal ou cartão 2x1) 
#ex: 10 cor frente A4 todas normal, para ele pular aquela impressão basta iniciar a anotação com #
try:
    # Definir os valores padrão para a impressão
    # Esta lista serve como nosso modelo base.
    valores_padrao = ['1', 'cor', 'frente', 'A4', 'todas', 'normal', 'padrão']
    
    # PASSO 2: Criar uma cópia da lista padrão para esta tarefa específica
    # Usamos .copy() para que a lista original 'valores_padrao' não seja modificada.
    configuracao_final = valores_padrao.copy()
    
    print("⚙️ Configuração padrão carregada:", configuracao_final)

    # PASSO 3: Localizar e extrair o texto da descrição
    seletor_css_da_descricao = ".notes-editor"
    elemento_descricao = wait.until(
        EC.visibility_of_element_located((By.CSS_SELECTOR, seletor_css_da_descricao))
    )
    texto_completo = elemento_descricao.text.strip()
    
    print(f"\n📝 Texto extraído da tarefa: '{texto_completo}'\n")

    # Sobrescrever os valores padrão com os da descrição
    # Apenas processa se a descrição não estiver vazia e não começar com '#'
    if texto_completo and not texto_completo.startswith('#'):
        palavras_da_descricao = texto_completo.split()
        
        # Este loop atualiza a lista 'configuracao_final' com as novas palavras
        for i in range(len(palavras_da_descricao)):
            # Verifica se o índice está dentro dos limites da nossa lista de configuração
            if i < len(configuracao_final):
                configuracao_final[i] = palavras_da_descricao[i]
                
        print("🔄 Configuração atualizada:", configuracao_final)

    elif texto_completo.startswith('#'):
        print(f"🟡 Tarefa ignorada (inicia com #): '{texto_completo}'")
        # Você pode adicionar um 'return' ou 'continue' aqui se estiver dentro de um loop maior
    
    # --- PASSO 5: Atribuir os valores da lista final às variáveis ---
    # Esta técnica é chamada de "desempacotamento de lista" (list unpacking)
    copias, cor, tipo_frente, tamanho_papel, paginas, tipo_impressao, formato = configuracao_final

    # --- PASSO 6: Exibir o resultado final ---
    print("\n--- ✅ Variáveis de Impressão Definidas ---")
    print(f"  - Cópias: {copias}")
    print(f"  - Cor: {cor}")
    print(f"  - Frente/Verso: {tipo_frente}")
    print(f"  - Papel: {tamanho_papel}")
    print(f"  - Páginas: {paginas}")
    print(f"  - Tipo: {tipo_impressao}")
    print(f"  - Formato: {formato}")

except Exception as e:
    print(f"Ocorreu um erro. Erro: {e}")

# 9 abrir todos os arquivos e colocar estas opções
aba_original = driver.current_window_handle

try:

    print("\nIniciando Processo de Impressão")
    seletor_anexo = ".attachmentChicklet"
    anexo_element = wait.until(
        EC.element_to_be_clickable((By.CSS_SELECTOR, seletor_anexo))
    )
    anexo_element.click()

    wait.until(EC.number_of_windows_to_be(2))
    aba_visualizacao = driver.window_handles[1]
    driver.switch_to.window(aba_visualizacao)
    print("aba de visualização.")
    sleep(5)

    botao_mais_opcoes = wait.until(
        EC.element_to_be_clickable((By.ID, "oneupCommandBarOverflow"))
    )
    botao_mais_opcoes.click()

    botao_imprimir_menu = wait.until(
        EC.element_to_be_clickable((By.XPATH, "//*[text()='down']"))
    )
    botao_imprimir_menu.click()
    print("abrindo aba final...")
    
    wait.until(EC.number_of_windows_to_be(3))

    # A aba mais recente é sempre a última da lista
    aba_preparacao = driver.window_handles[2]
    driver.switch_to.window(aba_preparacao)


    # --- PASSO 9.4: Clicar no botão final de Impressão ---
    sleep(3)
    pyautogui.keyDown('ctrl')
    pyautogui.press('p')                              
    pyautogui.keyUp('ctrl')

    print("ETAPA 3/3: Botão final 'Imprimir' clicado!")
    print("\n🎉 SUCESSO! A caixa de diálogo de impressão do sistema deve estar aberta.")

    # --- A partir daqui, o controle é do PyAutoGUI ---
    print("⏳ Dando 5 segundos para a caixa de diálogo de impressão aparecer...")

    # Exemplo de como usar PyAutoGUI para confirmar a impressão
    # print("🤖 Usando PyAutoGUI para confirmar a impressão...")
    # pyautogui.press('enter')

except Exception as e:
    print(f"❌ Ocorreu um erro durante o processo de impressão. Erro: {e}")

# 10 escolhe impressora de acordo
copiasInt = 1 
    
try:
    # 2. Tenta converter a variável de texto 'copias' para um número inteiro.
    copiasInt = int(copias)
    print(f"\n✅ A variável 'copias' ('{copias}') foi convertida para o inteiro: {copiasInt}")
    
except ValueError:
    # 3. Se a conversão falhar, avisa o usuário e usa o valor padrão definido acima.
    print(f"\n🟡 Aviso: O valor de cópias ('{copias}') não é um número. Usando o valor padrão: {copiasInt}.")

try:
    if (copiasInt >= 30 and cor == "cor"):
        impressoraPrincipal = "EPSON7030C9 (WF-C5810 Series)"
    elif (copiasInt < 30 and cor == "cor"):
        impressoraPrincipal = "ET-16600 Series(Rede)"
    elif (cor == "preto"):
        impressoraPrincipal = "RICOH Aficio MP 6001"
    else:
        print("\n🟡 Não foi possivel definir impressora")
        impressoraPrincipal = "EPSON7030C9 (WF-C5810 Series)"

    print(f"\n✅impressora defiinida: {impressoraPrincipal}")
    

except ValueError:
    print("\n🟡 Não foi possivel definir impressora")
    impressoraPrincipal = "EPSON7030C9 (WF-C5810 Series)"

# 11 configura de acordo


    # Navega até o campo de seleção de impressora
for i in range(5):
    pyautogui.press('tab')
    sleep(0.1) # Pequena pausa entre tabs

# Abre a lista de impressoras
pyautogui.press('enter')
sleep(1)

# Navega até a opção "Ver mais" ou "Imprimir usando caixa de diálogo do sistema"
for i in range(4): # Ajuste este número se necessário
    pyautogui.press('down')
sleep(0.3)

# Abre a caixa de diálogo para digitar o nome
pyautogui.press('enter')
sleep(1)

# Digita o nome da impressora alvo
pyautogui.write(impressoraPrincipal)
sleep(1)

# Seleciona a impressora encontrada
pyautogui.press('tab')
sleep(0.5)
pyautogui.press('tab')
pyautogui.press('enter') 
sleep(1) # Tempo para a seleção ser aplicada

print("✅ Impressora selecionada via PyAutoGUI.")

pyautogui.press('esc') 
pyautogui.press('esc') 
# Este bloco para Páginas (Ajuste o número de 'tab' acima se o foco mudar)
if (paginas != "todas"):
    print(f"🤖 Configurando Páginas Personalizadas: {paginas}")

    sleep(0.5)    
    pyautogui.press('enter') 
    sleep(0.5)    
    pyautogui.press('down') 
    sleep(0.5)    
    pyautogui.press('enter') 
    sleep(0.5)    
    pyautogui.write(paginas) 
    sleep(0.5)    

pyautogui.press('tab')
sleep(0.5)    
pyautogui.write(copias)
sleep(0.5)    
pyautogui.press('tab')
sleep(0.5)    


if (cor != "cor"):
    # Se o foco estiver no campo 'Cor' e o padrão for "Preto e branco", 
    # você precisa pressionar 'down' e 'enter' para selecionar 'Cor'.
    pyautogui.press('down')
    
    # Se o foco não estiver no campo 'Cor', você precisará adicionar mais 'tab's
    # até chegar ao `<print-preview-color-settings>`.


# 12 imprimi