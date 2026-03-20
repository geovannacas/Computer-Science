package Factory;

public class Notificacao extends Documento {
    public Notificacao(int numero, String remetente) {
        super(numero, remetente);
    }

    @Override
    public String getTipoDocumento() {
        return "Notificação";
    }

    @Override
    public void exibirDetalhes() {
        System.out.println("Documento: Notificação");
        System.out.println("Número: " + getNumero());
        System.out.println("Remetente: " + getRemetente());
        System.out.println("--------------------");
    }
}
