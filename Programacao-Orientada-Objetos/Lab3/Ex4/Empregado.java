package Lab3.Ex4;

public class Empregado {
    private String nome;
    private int matricula;

    public Empregado(String nome, int matricula) {
        this.nome = nome;
        this.matricula = matricula;
    }

    public String toString() {
        return "Nome: " + nome + ", Matricula: " + matricula;
    }
}

class Empresa{
    private String cnpj;
    private String razao;
    private Empregado empregado;

    public Empresa(String cnpj, String razao, Empregado empregado) {
        this.cnpj = cnpj;
        this.razao = razao;
        this.empregado = empregado;
    }

    public String toString() {
        return "CNPJ: " + cnpj + ", Razão: " + razao + "\n" + "| Empregado | " + empregado.toString();
    }
}

class Endereco {
    private String rua;
    private String bairro;
    private String complemento;
    private int numero;
    private String cidade;
    private String estado;
    private Empresa empresa;

    public Endereco(String rua, String bairro, String complemento, int numero, String cidade, String estado, Empresa empresa) {
        this.rua = rua;
        this.bairro = bairro;
        this.complemento = complemento;
        this.numero = numero;
        this.cidade = cidade;
        this.estado = estado;
        this.empresa = empresa;
    }

    public String toString() {
        return "Rua: " + rua + ", Bairro: " + bairro + ", Complemento: " + complemento + ", Numero: " + numero + ", Cidade: " + cidade + ", Estado: " + estado  + "\n" + "| Empresa | " + empresa.toString();
    }
}
