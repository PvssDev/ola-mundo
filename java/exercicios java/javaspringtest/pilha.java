
public class Objeto{ //criei uma classe simples para representar objeto
    private String nome;

    public Objeto(String nome){
        this.nome = nome;
    }

    @Override //override para sobrescrever o toString(), serve para conseguir printar no final
    public String toString() {
        return String.valueOf(nome);
    }
}
//inicio a classe pilha sabendo que existirá um atributo para armanezar objetos
public class Pilha{
    //o tipo Object[], estou dizendo ao java que pilha irá receber qualquer entidade Object, o mesmo é um Array.
    private Object[] pilha;
    private int topo; //a grande sacada para a pilha funcionar é esse atributo topo
    private int tamPilha;

    public Pilha(int tamPilha){
        this.pilha = new Object[tamPilha];
        this.topo = -1;//o topo é inicalizado como -1, pois num Array o primeiro objeto sera na posição 0
        this.tamPilha = tamPilha;
    }

    public boolean Adicionar(Object o){
        if (topo < tamPilha - 1){//subtraindo tampilha por -1, para que o topo não ultrapasse o tamanho da pilha
            topo++;
            pilha[topo] = o;//aqui eu consigo colocar em ordem cada objeto um após o outro
            return true;
        }
        return false;

    }
    public Object Retirar(){
        if(EstaVazia() == false){
            Object temp = pilha[topo];//Object temporario para não perder qual objeto foi retirado
            pilha[topo] = null;//como o metodo adicionar sempre incrementava, agora eu consigo sempre retirar o ultimo objeto adicionado.
            topo--;
            return temp;
        }
        return null;

    }
    public boolean EstaVazia(){
        if(topo != -1){
            return false;
        return true
    }

    @Override //override para sobrescrever o toString(), serve para conseguir printar no final
    public String toString() {
        //essa logica do toString eu não cheguei sozinho, tive que apelar pra IA
        String s = "[ ";
        for(int i = 0; i <= topo; i++){
            s += pilha[i] + " ";
        } 
        return s + "]";
    }
}
}

public Main{
    public static void main(String[] args){

        Pilha pilha = new Pilha(5);

         //por mais que eu consiga declarar que pilha é um Object, o java não permite eu fazer isso na main, por isso criei uma classe Objeto
        Objeto p = new Objeto("p");
        pilha.Adicionar(p);

        Objeto b = new Objeto("b");
        pilha.Adicionar(b);

        Objeto c = new Objeto("c");
        pilha.Adicionar(c);

        System.out.println("essa é sua pilha atual: " + pilha);// com o toString rescrito nas classes eu posso simplesmente chamar o objeto pilha que ele ira printar bonitinho :)

        pilha.Retirar();
        
        System.out.println("essa é sua pilha atual: " + pilha);
    }
}
//usei IA para descobrir a existencia do tipo Object, antes eu tava usando uma pilha de um tipo String
//usei IA para conseguir fazer o  toString da classe pilha
//#ireimetacardeumpredio!!!!!!!!!