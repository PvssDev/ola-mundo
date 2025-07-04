let idadeComprador = prompt("Digite a sua iadade:")

if (idadeComprador >= 18){
    alert(`você é maior de idade seja bem-vindo`)
    
}else{
    let acompanhado = prompt("Você está acompanhado? [s/n]")

    if(acompanhado == 's'){
        alert(`você é menor de idade, porém está acompanhado. Seja bem-vindo`)

    }else{
        alert(`você é menor de idade, sem acompanhante. me desculpe`)
    }
}