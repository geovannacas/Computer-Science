package Lab3.Ex1;

public class Compositor {
    private String nome;
    private String nacionalidade;

    public Compositor(String nome, String nacionalidade) {
        this.nome = nome;
        this.nacionalidade = nacionalidade;
    }

    public String toString() {
        return "Compositor: " + nome + ", Nacionalidade: " + nacionalidade;
    }
}

class Musica {
    private String nome;
    private int ano;
    private String tipo;
    private Compositor compositor;

    public Musica(String nome, int ano, String tipo, Compositor compositor) {
        this.nome = nome;
        this.ano = ano;
        this.tipo = tipo;
        this.compositor = compositor;
    }

    public String toString() {
        return "Música: " + nome + ", Ano: " + ano + ", Tipo: " + tipo + "\n" + compositor.toString();
    }
}