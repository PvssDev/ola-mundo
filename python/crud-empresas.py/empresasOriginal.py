import json
from time import sleep
import os

def caminho_json():
    return os.path.join(os.path.dirname(os.path.abspath(__file__)), 'empresas.json')

def carregar_empresas():
    try:
        with open(caminho_json(), 'r', encoding='utf-8') as arq:
            dados = json.load(arq)
    except (FileNotFoundError, json.JSONDecodeError):
        dados = []
    return dados

def escrever_empresas(dados):
    try:
        with open(caminho_json(), 'w', encoding='utf-8') as arq:
            json.dump(dados, arq, indent=8, ensure_ascii=False)
    except:
        return False
    
def criar_empresas():
    dados = carregar_empresas()

    nome = input('Digite o nome: ')
    cnpj = input('Digite o cnpj: ')
    endereço = input('Digite o endereço: ')
    gmail = input('Digite o gmail: ')
    contato = input('Digite o contato: ')
    senha = input('Digite o senha: ')

    dados.append({'nome': nome, 'cnpj': cnpj, 'endereço': endereço, 'gmail': gmail, 'contato': contato, 'senha': senha})

    escrever_empresas(dados)

    if escrever_empresas(dados) == False:
        print('\n❌  Não foi possivel adicionar sua empresa')
    else:
        print('\n✅  Empresa adicionada com sucesso!')

def editar_empresas():
    dados = carregar_empresas()
    concluido = False

    sleep(1)
    print('\n-----📈 Editar Empresas 📉------')

    while not concluido:
        sleep(1)
        nome = input('\n➡️  Digite o nome da empresa que deseja editar: ')

        for empresa in dados:
            if empresa['nome'] == nome:
                
                sleep(1)
                print(f'\nEssa é a empresa {empresa['nome']}:')
                sleep(0.5)
                print(f'\n1. Nome: {empresa['nome']}')
                sleep(0.5)
                print(f'2. Cnpj: {empresa['cnpj']}')
                sleep(0.5)
                print(f'3. Endereço: {empresa['endereço']}')
                sleep(0.5)
                print(f'4. Gmail: {empresa['gmail']}')
                sleep(0.5)
                print(f'5. Contato: {empresa['contato']}')
                sleep(0.5)
                print(f'6. Senha: {empresa['senha']}')

                while not concluido:
                    sleep(1)
                    escolha_edicao = input('\n➡️  Escolha qual opção alterar, exemplo: "nome" ou "contato": ' ).strip().lower()

                    for chave in empresa:

                        if escolha_edicao == chave:
                            sleep(1)
                            print(f'\n➡️  O {escolha_edicao} de {empresa['nome']} é: {empresa[escolha_edicao]}')
                            sleep(1)
                            empresa[escolha_edicao] = input('\n➡️  Digite a sua alteração: ')

                            escrever_empresas(dados)
                            concluido = True

                    if concluido == False:
                        sleep(1)
                        print(f'\n❌  Opção não identificada, Tente verificar se a opção foi Digitada corretamente')
        
        if concluido == True:
            print('\n✅  Alteração concluida com sucesso!')
            
        else:
                
            print('\n❌  Empresa não encontrada! Tente verificar se o nome foi Digitado corretamente')
            sleep (1.5)
            print('\n➡️  Nomes de empresas registradas:\n')
            sleep(1.5)
         
            for empresa in dados:
                print(f'{empresa['nome']}')
                sleep(0.5)
                
def ver_empresas():
    dados = carregar_empresas()
    concluido = False
    if dados.count != 0:
        for empresa in dados:
            print('-----📈 Ver Empresas 📉------')
            sleep(1.5)

            print(f'\n➡️  Temos {len(dados)} empresa(s) registrada(s) no programa')
            sleep(1.5)

            print(f'\n➡️  Essa é a empresa {empresa['nome']}:')
            sleep(1)

            print(f'\nNome: {empresa['nome']}')
            print(f'Cnpj: {empresa['cnpj']}')
            print(f'Endereço: {empresa['endereço']}')
            print(f'Gmail: {empresa['gmail']}')
            print(f'Contato: {empresa['contato']}')
            print(f'Senha: {empresa['senha']}')
        
            concluido = True

    if concluido == True:
        print('\n➡️  Essas são as empresas registradas')
        sleep(2)
    
    if concluido == False:
        print('❌  Não temos empresas registradas registradas ainda!')
        print('❌  Por que você não tenta?')
        sleep(2)

def excluir_empresas():
    dados = carregar_empresas()
    concluido = 0
    sleep(1)
    print('-----📈 Excluir Empresas 📉------')
    sleep(1)

    while not concluido:
        concluido = False
        encontrado = False
        nome = input('\n➡️  Digite o nome da empresa que deseja excluir: ')

        for empresa in dados:
            if empresa['nome'] == nome:

                encontrado = True
                print(f'\n➡️  Empresa {empresa['nome']}:')
                sleep(0.5)
                print(f'Nome: {empresa['nome']}, Cnpj: {empresa['cnpj']}, Endereço: {empresa['endereço']}, Gmail: {empresa['gmail']} Contato: {empresa['contato']}, Senha: {empresa['senha']}')
                sleep(1)
                escolha = input('\n➡️  Deseja realmente excluir essa empresa? [s/n]: ').lower().strip()

                match escolha:
                    case 's':
                        dados.remove(empresa)
                        sleep(1)
                        print('\n✅  Empresa removida com sucesso')
                        escrever_empresas(dados)
                        concluido = True

                    case 'n':
                        sleep(1)
                        print('\n❌  Empresa não foi removida')
                        sleep(1)
                        escolha = input('\n➡️  Deseja voltar ao Menu? [s/n]: ').lower().strip()

                        match escolha:
                            case 's':
                                concluido = True
                            
                            case 'n':
                                concluido = False
                
        if not concluido and not encontrado:
            print('\n❌  Empresa não encontrada! Tente verificar se o nome foi Digitado corretamente')
            sleep (1.5)
            print('\n➡️  Nomes de empresas registradas:\n')
            sleep(1.5)
         
            for empresa in dados:
                print(f'{empresa['nome']}')
                sleep(0.5)
            

def menu():
    sleep(1.5)
    print('\n-----📈 Empresas 📉-----')
    sleep(1)
    print('\n 1.🟦 Ver Empresas')
    print(' 2.🟩 Criar Empresas')
    print(' 3.🟧 Editar Empresas')
    print(' 4.🟥 Excluir Empresas')
    print(' 5.💾 Sair do Programa')

def main():
    print('🗣️  Bem-vindo ao CRUD Empresas')
    sleep(1.5)
    print('🗣️  Um codigo feito para aprender um pouco de python')
    sleep(1.5)
    print('🗣️  Aproveite')
    while True:
        menu()
        try:
            escolha = int(input('Escolha uma das opções acima: '))
            match escolha:
                case 1:
                    ver_empresas()
                case 2:
                    criar_empresas()
                case 3:
                    editar_empresas()
                case 4:
                    excluir_empresas()
                case 5:
                    break
                case __:
                    print('❌  Opção invalida!')
                    sleep(0.5)

        except(ValueError):
            print("opção invalida")
main()