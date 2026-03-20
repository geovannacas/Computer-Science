package AT5;

public class TestaConta {
    public static void main(String[] args) {
        Cliente cliente1 = new Cliente("João", "1234-5678");
        Cliente cliente2 = new Cliente("Maria", "8765-4321");

        Conta conta1 = new ContaCorrente(1001, cliente1);
        Conta conta2 = new ContaPoupanca(2002, cliente2);

        conta1.depositar(500);
        conta1.sacar(100);
        conta1.transferir(50, conta2);

        ((ContaPoupanca) conta2).atualizaSaldo(5); // atualiza com 5% de rendimento

        System.out.println(conta1);
        System.out.println(conta2);
    }
}

