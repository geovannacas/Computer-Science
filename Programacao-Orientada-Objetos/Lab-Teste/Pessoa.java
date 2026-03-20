public class Pessoa {

    private String nome;
    private double salario;
    private int numeroDeDependentes;
    private int idade;

    public Pessoa(String nome, double salario, int numeroDeDependentes, int idade) {
        this.nome = nome;
        this.salario = salario;
        this.numeroDeDependentes = numeroDeDependentes;
        this.idade = idade;
    }

    public double calculaImposto() {
        // Regra 1: Pessoas com 65 anos ou mais são isentas.
        if (this.idade >= 65) {
            return 0.0; // 
        }

        double impostoBruto = 0.0;

        // Etapa 1: Cálculo do imposto bruto com base na faixa salarial.
        // 
        if (this.salario <= 1787.77) {
            impostoBruto = 0.0;
        } else if (this.salario <= 2679.29) {
            impostoBruto = this.salario * 0.075 - 134.08;
        } else if (this.salario <= 3572.43) {
            impostoBruto = this.salario * 0.15 - 335.03;
        } else if (this.salario <= 4463.81) {
            impostoBruto = this.salario * 0.225 - 602.96;
        } else {
            impostoBruto = this.salario * 0.275 - 826.15;
        }

        // Etapa 2: Aplicação da dedução por dependente. 
        double deducaoDependentes = this.numeroDeDependentes * 179.71;
        double impostoFinal = impostoBruto - deducaoDependentes;

        // O imposto não pode ser negativo. Se o cálculo resultar em um valor menor que zero, o imposto a pagar é zero.
        if (impostoFinal < 0) {
            return 0.0;
        }

        return impostoFinal;
    }
}