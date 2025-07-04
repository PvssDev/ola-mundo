console.log(`Trabalhando com listas`)

//criando uma lista
const listaDeDestinos = new Array(` salvador`,` sao paulo`,` rio de janeiro`)
console.log(`Minha lista de destinos:${listaDeDestinos}`)

//adicionando elemento na lista
listaDeDestinos.push(` curitiba`)
console.log(`Minha lista de destinos:${listaDeDestinos}`)

//removendo elementos na lista de acordo com (indice,quantidade de elementos)
listaDeDestinos.splice(0,1)
console.log(`Minha lista de destinos:${listaDeDestinos}`)

//listando um elemento de acordo com o indice Array[0]
console.log(listaDeDestinos[0])