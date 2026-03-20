package Lab3.Ex3;

public class Cliente {
    private String nome;
    private String cpf;

    public Cliente(String nome, String cpf) {
        this.nome = nome;
        this.cpf = cpf;
    }

    public String toString() {
        return "Nome: " + nome + ", CPF: " + cpf;
    }
}

class Endereco {
    private String rua;
    private String bairro;
    private String complemento;
    private int numero;
    private String cidade;
    private String estado;
    private Cliente cliente;

    public Endereco(String rua, String bairro, String complemento, int numero, String cidade, String estado, Cliente cliente) {
        this.rua = rua;
        this.bairro = bairro;
        this.complemento = complemento;
        this.numero = numero;
        this.cidade = cidade;
        this.estado = estado;
        this.cliente = cliente;
    }

    public String toString() {
        return "Rua: " + rua + ", Bairro: " + bairro + ", Complemento: " + complemento + ", Numero: " + numero + ", Cidade: " + cidade + ", Estado: " + estado  + "\n" + "| Cliente | " + cliente.toString();
    }
}
