import javax.swing.*;
import java.util.ArrayList;

public class CadastroContas {
    public static void main(String[] args) {
        ArrayList<Conta> contas = new ArrayList<>();

        while (true) {
            int numero = Integer.parseInt(JOptionPane.showInputDialog("Número da conta (0 para sair):"));
            if (numero == 0) break;

            String nome = JOptionPane.showInputDialog("Nome do cliente:");
            String telefone = JOptionPane.showInputDialog("Telefone:");
            Cliente cliente = new Cliente(nome, telefone);

            int tipo = Integer.parseInt(JOptionPane.showInputDialog("Tipo de conta:\n1 - Corrente\n2 - Salário\n3 - Poupança"));
            Conta conta = null;

            if (tipo == 1) conta = new ContaCorrente(numero, cliente);
            else if (tipo == 2) conta = new ContaSalario(numero, cliente);
            else if (tipo == 3) conta = new ContaPoupanca(numero, cliente);

            contas.add(conta);
        }

        StringBuilder sb = new StringBuilder("Contas cadastradas:\n");
        for (Conta conta : contas) {
            sb.append(conta.toString()).append("\n");
        }

        JOptionPane.showMessageDialog(null, sb.toString());
    }
}