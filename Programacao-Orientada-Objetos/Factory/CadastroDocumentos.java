package Factory;

public class CadastroDocumentos {
    public static void main(String[] args) {
        Fabrica fabricaDeDocumentos = new FabricaDocumentos(); // [cite: 4]

        System.out.println("Solicitando criação de documentos à fábrica:\n");

        String tipoCarta = "CARTA";
        Documento carta = fabricaDeDocumentos.criarDocumento(tipoCarta, 101, "João Silva"); // [cite: 4]
        if (carta != null) {
            System.out.println("Documento do tipo '" + tipoCarta + "' criado:");
            carta.exibirDetalhes();
        }

        String tipoNotificacao = "NOTIFICACAO";
        Documento notificacao = fabricaDeDocumentos.criarDocumento(tipoNotificacao, 202, "Maria Oliveira"); // [cite: 4]
        if (notificacao != null) {
            System.out.println("Documento do tipo '" + tipoNotificacao + "' criado:");
            notificacao.exibirDetalhes();
        }

        String tipoTelegrama = "TELEGRAMA";
        Documento telegrama = fabricaDeDocumentos.criarDocumento(tipoTelegrama, 303, "Empresa XYZ"); // [cite: 4]
        if (telegrama != null) {
            System.out.println("Documento do tipo '" + tipoTelegrama + "' criado:");
            telegrama.exibirDetalhes();
        }

        String tipoDesconhecido = "FATURA";
        Documento desconhecido = fabricaDeDocumentos.criarDocumento(tipoDesconhecido, 404, "Pedro Costa"); // [cite: 4]
        if (desconhecido == null) {
            System.out.println("Tentativa de criar documento do tipo '" + tipoDesconhecido + "' resultou em null (tipo não suportado pela fábrica).");
            System.out.println("--------------------");
        }
    }
}

