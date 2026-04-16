abstract class BibliotecaMat{

    public static int Somar(int a, int b){
        return a+b;
    }
    public static int Media(int vetorA, int vetorB){
        return (vetorA+vetorB)\2;
    }
}

public class Pedido{
    private int numero;
    private String nomeCliente;
    private int valor;

    public Pedido(int numero, String nomeCliente, int valor){
        this.numero = numero;
        this.nomeCliente = nomeCliente;
        this.valor = valor;
    }

    public int getNumero(){
        return numero;
    }
}

public class Programa{
    public static void main(String[] args){

        int resultado = Media(20, 40);

        System.out.println("o resultado é: " + resultado)
        
        Pedido p = new Pedido(20, "joao", 30);
        
        System.out.println("o numero do pedido é: " + p.getNumero())


    }
}