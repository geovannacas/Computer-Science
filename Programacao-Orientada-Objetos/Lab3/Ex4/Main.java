package Lab3.Ex4;

public class Main {
    public static void main(String[] args) {
        Empregado empregado = new Empregado("Geovanna Cunha", 12345);

        Empresa empresa = new Empresa("12.345.678/0001-99", "BigDataCorp", empregado);

        Endereco endereco = new Endereco(
            "Rua das Palmeiras",
            "Centro",
            "Sala 101",
            456,
            "Goiânia",
            "GO",
            empresa
        );

        System.out.println(endereco);
    }
}
