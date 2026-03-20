package Factory;

public abstract class Documento {
    protected int numero;
    protected String remetente;

    public Documento(int numero, String remetente) {
        this.numero = numero;
        this.remetente = remetente;
    }

    public int getNumero() {
        return numero;
    }

    public String getRemetente() {
        return remetente;
    }

    public abstract String getTipoDocumento();
    public abstract void exibirDetalhes();
}
