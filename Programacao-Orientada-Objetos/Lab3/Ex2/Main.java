package Lab3.Ex2;

public class Main {
    public static void main(String[] args) {
        Aluno aluno1 = new Aluno("Geovanna Cunha", "202200512", 2022);

        Curso curso1 = new Curso("Ciência da Computação","CC", aluno1);

        Departamento departamento1 = new Departamento("Informática", "INF", curso1);

        System.out.println(departamento1);
    }
}
