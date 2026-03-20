package AT5;

public class ContaPoupanca extends Conta {
    public ContaPoupanca(int numero, Cliente dono) {
        super(numero, dono);
    }

    @Override
    public void transferir(double valor, Conta destino) {
        this.sacar(valor);
        destino.depositar(valor);
    }

    public void atualizaSaldo(double percentual) {
        saldo += saldo * percentual / 100.0;
    }
}
