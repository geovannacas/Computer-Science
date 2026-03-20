package Factory;

public class FabricaDocumentos extends Fabrica {
    @Override
    public Documento criarDocumento(String tipo, int numero, String remetente) { // [cite: 3]
        if (tipo == null) {
            return null;
        }
        if (tipo.equalsIgnoreCase("CARTA")) {
            return new Carta(numero, remetente); // [cite: 2, 3]
        } else if (tipo.equalsIgnoreCase("NOTIFICACAO")) {
            return new Notificacao(numero, remetente); // [cite: 2, 3]
        } else if (tipo.equalsIgnoreCase("TELEGRAMA")) {
            return new Telegrama(numero, remetente); // [cite: 2, 3]
        }
        return null;
    }
}
