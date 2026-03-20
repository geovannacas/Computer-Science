package Factory;

public abstract class Fabrica {
    public abstract Documento criarDocumento(String tipo, int numero, String remetente);
}
