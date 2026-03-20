public class ContaSalario extends ContaCorrente {
    private static final double TAXA = 0.01;

    public ContaSalario(int numero, Cliente dono) {
        super(numero, dono);
    }

    @Override
    public void sacar(double valor) {
        saldo -= (valor + TAXA);
    }

    @Override
    public void depositar(double valor) {
        saldo += (valor - TAXA);
    }

    @Override
    public void transferir(double valor, Conta destino) {
        this.sacar(valor);
        destino.depositar(valor);
    }
}