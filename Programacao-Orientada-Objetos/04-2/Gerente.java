// Gerente herda de Funcionario
public class Gerente extends Funcionario {
    protected double bonificacao;
    protected String tipo; // "PF" ou "PJ"

    public Gerente(String nome, String matricula) {
        super(nome, matricula);
    }

    public double getBonificacao() { return bonificacao; }
    public void setBonificacao(double bonificacao) { this.bonificacao = bonificacao; }

    public String getTipo() { return tipo; }
    public void setTipo(String tipo) { this.tipo = tipo; }

    @Override
    public double getRecebimentoAnual() {
        return (salario + bonificacao) * 12;
    }
}
