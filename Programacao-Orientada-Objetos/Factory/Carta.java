package Factory;

public class Carta extends Documento {
    public Carta(int numero, String remetente) {
        super(numero, remetente);
    }

    @Override
    public String getTipoDocumento() {
        return "Carta";
    }

    @Override
    public void exibirDetalhes() {
        System.out.println("Documento: Carta");
        System.out.println("Número: " + getNumero());
        System.out.println("Remetente: " + getRemetente());
        System.out.println("--------------------");
    }
}
