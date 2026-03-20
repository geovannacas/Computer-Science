public class TestaConta {
    public static void main(String[] args) {
        Cliente c1 = new Cliente("Maria", "99999-0001");
        Cliente c2 = new Cliente("João", "99999-0002");

        Conta cc = new ContaCorrente(1, c1);
        Conta cp = new ContaPoupanca(2, c2);

        cc.depositar(100);
        cc.sacar(20);
        System.out.println(cc);

        cp.depositar(100);
        cp.sacar(20);
        ((ContaPoupanca) cp).atualizaSaldo(10); // cast necessário
        System.out.println(cp);

        cc.transferir(30, cp);
        System.out.println("Após transferência:");
        System.out.println(cc);
        System.out.println(cp);
    }
}