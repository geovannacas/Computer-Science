public class Cadastro {
    public static void main(String[] args) {
        // Caixa
        Caixa caixa = new Caixa("João", "C001");
        caixa.setTelefone("1234-5678");
        caixa.setHorario("08:00 - 16:00");
        caixa.setSalario(3000);
        caixa.aplicarAumento(10);
        caixa.mostrarDados();
        System.out.println("Recebimento anual: R$ " + caixa.getRecebimentoAnual());
        System.out.println();

        // Gerente
        Gerente gerente = new Gerente("Ana", "G002");
        gerente.setTelefone("9876-5432");
        gerente.setSalario(8000);
        gerente.setBonificacao(2000);
        gerente.setTipo("PF");
        gerente.aplicarAumento(20);
        gerente.mostrarDados();
        System.out.println("Recebimento anual: R$ " + gerente.getRecebimentoAnual());
        System.out.println();

        // Clientes
        Cliente cliente1 = new Cliente("Maria", "2345-6697", 20, "8889989898");
        Cliente cliente2 = new Cliente("Carlos", "2244-7788", 30, "12345678901");
        Cliente cliente3 = new Cliente("Júlia", "9988-7766", 25, "10987654321");

        cliente2.desativar();

        System.out.println(cliente1.mostrarDados());
        System.out.println(cliente2.mostrarDados());
        System.out.println(cliente3.mostrarDados());
    }
}
