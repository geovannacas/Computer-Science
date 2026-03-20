package ex_1;
public class Produto {
    private String codigo; 
	private String nome;
	private int quantidade;
	private String tipo;
    private float valor;

    public Produto(String codigo) {
        this.codigo = codigo;
    }

    public Produto(String codigo, String nome) {
        this.codigo = codigo;
        this.nome = nome;
    }

    public Produto(String codigo, String nome, int quantidade) {
        this.codigo = codigo;
        this.nome = nome;
        this.quantidade = quantidade;
    }

    public Produto(String codigo, String nome, int quantidade, String tipo, float valor) {
        this.codigo = codigo;
        this.nome = nome;
        this.quantidade = quantidade;
        this.tipo = tipo;
        this.valor = valor;
    }

    public float vender(int qtdVendida){
        if(this.quantidade < qtdVendida)
        {
            System.out.println("Estoque insuficiente...");
            return 0;
        }
        
        this.quantidade -= qtdVendida;
        return qtdVendida * valor;
    }

    public void comprarAlterar(int qtdComprada, float novoValor)
    {
        this.quantidade += qtdComprada;
        this.valor = novoValor;
    }

    public void comprar(int qtdComprada)
    {
        quantidade += qtdComprada;
    }

    public String toString() {
        return "Código: " + this.codigo + 
               ", Nome: " + this.nome + 
               ", Quantidade: " + this.quantidade + 
               ", Tipo: " + this.tipo + 
               ", Valor: R$" + String.format("%.2f", this.valor);
    }

    public void inserir(String nome, int quantidade, String tipo, float valor)
    {
        this.nome = nome;
        this.quantidade = quantidade;
        this.tipo = tipo;
        this.valor= valor;
    }

    public boolean igual(Produto produto)
    {
        if (produto == null)
            return false;
            
        return this.nome.equals(produto.nome) && this.tipo.equals(produto.tipo);
    }
}
