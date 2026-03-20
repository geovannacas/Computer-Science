package Lab3.Ex3;

public class Main {
    public static void main(String[] args) {
        Cliente cliente = new Cliente("Geovanna Cunha", "123.456.789-00");

        Endereco endereco = new Endereco(
            "Rua das Flores", 
            "Jardim Primavera", 
            "Apto 202", 
            150, 
            "Goiânia", 
            "GO", 
            cliente
        );

        System.out.println(endereco);
    }
}
