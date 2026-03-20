package Factory;

public class Telegrama extends Documento {
    public Telegrama(int numero, String remetente) {
        super(numero, remetente);
    }

    @Override
    public String getTipoDocumento() {
        return "Telegrama";
    }

    @Override
    public void exibirDetalhes() {
        System.out.println("Documento: Telegrama");
        System.out.println("Número: " + getNumero());
        System.out.println("Remetente: " + getRemetente());
        System.out.println("--------------------");
    }
}
