package ex_1;

public class Main {
    public static void main(String[] args) {

        // Criando produtos usando diferentes construtores
        Produto produto1 = new Produto("001"); // Apenas código
        Produto produto2 = new Produto("002", "Jogo de Tabuleiro");
        Produto produto3 = new Produto("003", "Bola de Futebol", 15);
        Produto produto4 = new Produto("004", "Camisa Esportiva", 20, "Vestuário", 99.90f);

        // Atualizando produto1 (criado apenas com código) usando inserir()
        produto1.inserir("Smartphone", 30, "Eletrônico", 1999.99f);

        System.out.println("=== PRODUTOS CADASTRADOS ===");
        System.out.println("Produto 1: " + produto1.toString());
        System.out.println("Produto 2: " + produto2.toString());
        System.out.println("Produto 3: " + produto3.toString());
        System.out.println("Produto 4: " + produto4.toString());

        System.out.println("\n=== OPERAÇÃO DE VENDA ===");
        produto1.vender(5);
        produto3.vender(10);

        System.out.println("\n=== OPERAÇÃO DE COMPRA ===");
        produto2.comprar(10);
        produto4.comprarAlterar(5, 89.90f); 

        System.out.println("\n=== PRODUTOS APÓS OPERAÇÕES ===");
        System.out.println("Produto 1: " + produto1.toString());
        System.out.println("Produto 2: " + produto2.toString());
        System.out.println("Produto 3: " + produto3.toString());
        System.out.println("Produto 4: " + produto4.toString());

        System.out.println("\n=== COMPARAÇÃO DE PRODUTOS ===");
        System.out.println("Produto 1 é igual ao Produto 2? " + produto1.igual(produto2));
        System.out.println("Produto 2 é igual ao Produto 3? " + produto2.igual(produto3));

        Produto produtoTeste = new Produto("999", "Smartphone", 0, "Eletrônico", 1999.99f);
        System.out.println("Produto 1 é igual ao Produto Teste? " + produto1.igual(produtoTeste));
    }
}