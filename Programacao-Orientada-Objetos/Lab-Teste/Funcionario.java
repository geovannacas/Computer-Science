import java.io.Serializable;
import java.text.DecimalFormat;

// A classe precisa implementar Serializable para ser gravada em arquivo de objeto.
public class Funcionario implements Serializable {

    String nome;
    char sexo;
    double salario;
    int dependentes;

    Funcionario(String nome, char sexo, double salario, int dependentes) {
        this.nome = nome;
        this.sexo = sexo;
        this.salario = salario;
        this.dependentes = dependentes;
    }

    public double impostoRenda() {
        // Regra de negócio para cálculo do imposto de renda 
        double reducaoDep = 189.59 * dependentes;
        double impostoCalculado = 0;

        if (salario <= 1903.98) {
            impostoCalculado = 0;
        } else if (salario <= 2826.65) {
            impostoCalculado = (salario * 7.5 / 100) - 142.80;
        } else if (salario <= 3751.05) {
            impostoCalculado = (salario * 15 / 100) - 354.80;
        } else if (salario <= 4664.68) {
            impostoCalculado = (salario * 22.5 / 100) - 636.13;
        } else {
            impostoCalculado = (salario * 27.5 / 100) - 869.36;
        }

        double impostoFinal = impostoCalculado - reducaoDep;

        // O imposto não pode ser negativo.
        return Math.max(impostoFinal, 0);
    }

    public String mostraFuncionario() {
        // Formata os valores para melhor visualização
        DecimalFormat df = new DecimalFormat("#,##0.00");
        String impostoFormatado = df.format(impostoRenda());
        String salarioFormatado = df.format(salario);

        return "Nome: " + nome + " | Sexo: " + sexo + " | Salário: R$ " + salarioFormatado +
               " | Dependentes: " + dependentes + " | Imposto a Pagar: R$ " + impostoFormatado;
    }
}