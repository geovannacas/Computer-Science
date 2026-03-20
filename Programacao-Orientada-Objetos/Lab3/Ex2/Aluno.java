package Lab3.Ex2;

public class Aluno {
    private String nome;
    private String matricula;
    private int ano;

    public Aluno(String nome, String matricula, int ano) {
        this.nome = nome;
        this.matricula = matricula;
        this.ano = ano;
    }

    public String toString() {
        return "Nome: " + nome + ", Matricula: " + matricula + ", Ano: " + ano;
    }
}

class Curso {
    private String nome;
    private String sigla;
    private Aluno aluno;

    public Curso(String nome, String sigla, Aluno aluno) {
        this.nome = nome;
        this.sigla = sigla;
        this.aluno = aluno;
    }

    public String toString() {
        return "Nome: " + nome + ", Sigla: " + sigla + "\n" + "| Aluno | " + aluno.toString();
    }
}

class Departamento {
    private String nome;
    private String sigla;
    private Curso curso;

    public Departamento(String nome, String sigla, Curso curso) {
        this.nome = nome;
        this.sigla = sigla;
        this.curso = curso;
    }

    public String toString() {
        return "| Departamento | Nome: " + nome + ", Sigla: " + sigla + "\n" + "| Curso | " + curso.toString();
    }
}
