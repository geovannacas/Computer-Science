package Singleton;

public class Projeto {
    private String nomeProjeto;
    private String descricao;
    private Empresa empresaContratante;

    public Projeto(String nomeProjeto, String descricao) {
        this.nomeProjeto = nomeProjeto;
        this.descricao = descricao;
        this.empresaContratante = Empresa.getInstance();
    }

    public String getNomeProjeto() {
        return nomeProjeto;
    }

    public String getDescricao() {
        return descricao;
    }

    public Empresa getEmpresaContratante() {
        return empresaContratante;
    }

    public void exibirDetalhes() {
        System.out.println("Detalhes do Projeto:");
        System.out.println("  Nome do Projeto: " + nomeProjeto);
        System.out.println("  Descrição: " + descricao);
        System.out.println("  Empresa Contratante: " + empresaContratante.getNome());
        System.out.println("  CNPJ da Empresa: " + empresaContratante.getCnpj());
        System.out.println("---");
    }

    @Override
    public String toString() {
        return "Projeto {" +
               "\n  Nome do Projeto: '" + nomeProjeto + '\'' +
               "\n  Descrição: '" + descricao + '\'' +
               "\n  Empresa: " + (empresaContratante != null ? empresaContratante.getNome() : "N/A") +
               "\n}";
    }
}