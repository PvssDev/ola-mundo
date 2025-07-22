console.log("Bem vindo ao banco")

class cliente{
    nome;
     cpf;
    endereco;
    contato;
    gmail;

}

class contaCorrente{
    agencia = 1505;
    saldo = 100;

    sacar(valor){
        saldo = saldo - valor
    };
    depositar(valor){
        saldo = saldo + valor
    };

}


const cliente1 = new cliente()

cliente1.nome = "pedro"
console.log(`Digite o seu nome: ${cliente1.nome}`)

cliente1.contato = 0
console.log(`Digite o número de contato: ${cliente1.contato}`)

cliente1.cpf = 0
console.log(`Digite o seu CPF: ${cliente1.cpf}`)

cliente1.gmail = 0
console.log(`Digite o seu Gmail: ${cliente1.gmail}`)

console.log(`Parabéns você criou sua conta ${cliente1.nome}`)

console.log(`\nEssa é o número de sua agencia: ${contaCorrente.saldo}`)
console.log(`Você começa com um saldo de ${contaCorrente.saldo}`)

console.log(`Este é o menu de operações`)

while (true){
    console.log(```
          ------Menu------
              1. sacar
             2. depositar
              3. saldo```)

              switch (escolha){
                case 1:
                    console.log(`Digite o valor do saque`)
                    valor = 10
                
              }
}

