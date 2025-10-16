from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
from time import sleep                                  
import pyautogui                            

# use o seguinte comando no seu terminal: "C:\Program Files\Google\Chrome\Application\chrome.exe" --remote-debugging-port=9222 --user-data-dir="C:\selenium\chrome-profile"
# agora abra o planer logado na sua conta.
# e seja feliz ;)
options = Options()
options.debugger_address = "localhost:9222"
driver = webdriver.Chrome(options=options)
wait = WebDriverWait(driver, 15)

# 1 abrir o site que já ta em uma aba do google
pyautogui.keyDown('alt')
pyautogui.press('tab')                              
pyautogui.keyUp('alt')

# 2 acessar a aba do site
pyautogui.hotkey('ctrl', '1')

# 3 apertar no botão meus planos
for i in range(9):
    pyautogui.press('tab')

pyautogui.press('down')
pyautogui.press('down')
pyautogui.press('enter')

# 4 acessar o botao compartilhado
for i in range(4):
    pyautogui.press('tab')

pyautogui.press('right')
pyautogui.press('enter')

# 5 apertar na impressao
pyautogui.press('tab')
pyautogui.press('tab')
pyautogui.press('enter')

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
    print(f"❌ Ocorreu um erro ao processar a descrição. Erro: {e}")

# 9 ele ira abrir todos os arquivos e colocar estas opções
aba_original = driver.current_window_handle

try:
    # --- PASSO 9.1: Clicar no anexo para abrir a Aba 2 (Visualização) ---
    print("\n--- Iniciando Processo de Impressão (3 Etapas) ---")
    seletor_anexo = ".attachmentChicklet"
    anexo_element = wait.until(
        EC.element_to_be_clickable((By.CSS_SELECTOR, seletor_anexo))
    )
    anexo_element.click()
    print("ETAPA 1/3: Anexo clicado, abrindo aba de visualização...")

    # --- PASSO 9.2: Mudar o foco para a Aba 2 e clicar em Imprimir ---
    wait.until(EC.number_of_windows_to_be(2))
    aba_visualizacao = driver.window_handles[1]
    driver.switch_to.window(aba_visualizacao)
    print("ETAPA 1/3: Foco na aba de visualização.")
    sleep(7)
    # Clica no botão 'Três Pontos' (Mais Opções)
    botao_mais_opcoes = wait.until(
        EC.element_to_be_clickable((By.ID, "oneupCommandBarOverflow"))
    )
    botao_mais_opcoes.click()

    # Clica no botão 'Imprimir' do menu para abrir a Aba 3
    botao_imprimir_menu = wait.until(
        EC.element_to_be_clickable((By.XPATH, "//*[text()='Imprimir']"))
    )
    botao_imprimir_menu.click()
    print("ETAPA 2/3: Clicou em 'Imprimir' no menu, abrindo aba final...")

    # --- PASSO 9.3: Mudar o foco para a Aba 3 (Preparação) ---
    wait.until(EC.number_of_windows_to_be(3))
    # A aba mais recente é sempre a última da lista
    aba_preparacao = driver.window_handles[2]
    driver.switch_to.window(aba_preparacao)
    print("ETAPA 2/3: Foco na aba de preparação para impressão.")

    # --- PASSO 9.4: Clicar no botão final de Impressão ---
    sleep(5)
    for i in range(14):
        pyautogui.press('tab')

    pyautogui.press('enter')

    print("ETAPA 3/3: Botão final 'Imprimir' clicado!")
    print("\n🎉 SUCESSO! A caixa de diálogo de impressão do sistema deve estar aberta.")

    # --- A partir daqui, o controle é do PyAutoGUI ---
    print("⏳ Dando 5 segundos para a caixa de diálogo de impressão aparecer...")
    sleep(5)
    
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
        impressoraPrincipal = "W"
    elif (copiasInt < 30 and cor == "cor"):
        impressoraPrincipal = "T"
    elif (cor == "preto"):
        impressoraPrincipal = "6001"
    else:
        print("\n🟡 Não foi possivel definir impressora")
        impressoraPrincipal = "w"

    print(f"\n✅impressora defiinida: {impressoraPrincipal}")
    

except ValueError:
    print("\n🟡 Não foi possivel definir impressora")
    impressoraPrincipal = "w"

# 11 configura de acordo
for i in range(6):
    pyautogui.press('tab')

if (paginas != "todas"):
    pyautogui.press('down')
    pyautogui.press('backspace')
    pyautogui.write(paginas)

for i in range(2):
    pyautogui.press('tab')

if (cor == "cor"):

# 12 imprimi

