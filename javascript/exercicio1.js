//sistema de identificação de viagens
const cidades = new Array (
    `salvador`,
    `rio de janeiro`,
    `são paulo`
)

//variaveis utilizadas
let contador = 0
let permissao = false
const idadeDocomprador = 17
const estaAcompanhado = true
let Passagem = true
const destino = "são paulo"

//verificador de permissão para viajar
console.log(`\nqual a sua idade? ${idadeDocomprador}`)

if (idadeDocomprador >= 18){
    console.log(`você tem passagem? ${Passagem}`)
    
    if (Passagem == true){
        console.log(`você poderá escolher para onde será seu destino\n`)
        permissao = true
        
    }else{
        console.log(`Você infelizmente não pode viajar\n`)
    }
}else{
    console.log(`Você está acompanhado? ${estaAcompanhado}`)
    
    if(estaAcompanhado == true){
        console.log(`Você tem passagem? ${Passagem}`)
        
        if(Passagem == true){
            console.log(`Você poderá escolher para onde será seu destino\n`)
            permissao = true

        }else{
            console.log(`Você infelizmente não pode viajar\n`)
        }
    }else{
        console.log(`Você infelizmente não pode viajar\n`)
    }
}

//Escolha do destino
if (permissao == true){
    console.log(`\nQual o seu destino? ${destino}`)

    while (contador < cidades.length){
        
        if(destino == cidades[contador]){
            console.log(`Parabéns cidade disponivel!\n`)
            console.log(`Boa viagem\n`)

            break
        }
    contador ++
    }
}

if (contador+1 > cidades.length){
    console.log(`Infelizmente não foi possível encontrar o destino\n`)
}
