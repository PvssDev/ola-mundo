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
        print('Não foi possivel adicionar sua empresa')
    else:
        print('Empresa adicionada com sucesso!')

def editar_empresas(nome):
    dados = carregar_empresas()
    concluido = False
    for empresa in dados:
        if empresa['nome'] == nome:
            
            print(f'\nEssa é a empresa {empresa['nome']}:')
            print(f'\n1. Nome: {empresa['nome']}')
            print(f'2. Cnpj: {empresa['cnpj']}')
            print(f'3. Endereço: {empresa['endereço']}')
            print(f'4. Gmail: {empresa['gmail']}')
            print(f'5. Contato: {empresa['contato']}')
            print(f'6. Senha: {empresa['senha']}')

            escolha_edicao = input('Escolha qual opção alterar, exemplo: "nome" ou "contato":' ).strip().lower()

            for chave in empresa:
                if escolha_edicao == chave:
                    empresa[escolha_edicao] = input('Digite a sua alteração')

                    concluido = True
                    escrever_empresas(dados)
                    break
                
    if concluido == False:
        print('Não foi possivel concluir')
    else:
        print('Edição concluida com sucesso!')

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

def excluir_empresas(nome):
    dados = carregar_empresas()

    for empresa in dados:
        if empresa['nome'] == nome:
            print(f'\nEmpresa {empresa['nome']}:')
            print(f'Nome: {empresa['nome']}, Cnpj: {empresa['cnpj']}, Endereço: {empresa['endereço']}, Gmail: {empresa['gmail']} Contato: {empresa['contato']}, Senha: {empresa['senha']}')
            escolha = input('\nDeseja realmente excluir essa empresa? [s/n]').lower().strip()

            match escolha:
                case 's':
                    dados.remove(empresa)
                    print('Empresa removida com sucesso')
                    escrever_empresas(dados)
                case 'n':
                    print('Empresa não foi removida')
            
            concluido = True
            break
        concluido = False
    if concluido == False:
        print('Não foi possivel encontrar sua empresa!')

def menu():
    sleep(1.5)
    print('\n-----📈 Empresas 📉-----')
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
                    nome = input('Digite o nome da empresa que deseja editar: ')
                    editar_empresas(nome)
                case 4:
                    nome = input('Digite o nome da empresa que deseja excluir: ')
                    excluir_empresas(nome)
                case 5:
                    break
                case __:
                    print('Opção invalida!')

        except(ValueError):
            print("opção invalida")
main()