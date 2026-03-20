package Singleton;

public class Principal {
    public static void main(String[] args) {
        Empresa minhaEmpresa = Empresa.getInstance();

        System.out.println("Dados da Empresa (Instância 1):");
        System.out.println(minhaEmpresa.toString());
        System.out.println();

        Empresa outraReferenciaEmpresa = Empresa.getInstance();

        System.out.println("Dados da Empresa (Instância 2 - mesma referência):");
        System.out.println(outraReferenciaEmpresa.toString());
        System.out.println();

        if (minhaEmpresa == outraReferenciaEmpresa) {
            System.out.println("minhaEmpresa e outraReferenciaEmpresa são a MESMA instância (Singleton funciona!).");
        } else {
            System.out.println("minhaEmpresa e outraReferenciaEmpresa são instâncias DIFERENTES (Singleton falhou!).");
        }
        System.out.println("\n------------------------------------\n");

        System.out.println("Criando Projetos vinculados à Empresa '" + minhaEmpresa.getNome() + "':");

        Projeto projetoResidencial = new Projeto("Residencial Bueno Aires", "Construção de edifício residencial de alto padrão.");
        Projeto projetoComercial = new Projeto("Office Park T-55", "Desenvolvimento de complexo comercial com salas e lojas.");

        projetoResidencial.exibirDetalhes();
        projetoComercial.exibirDetalhes();

        System.out.println("Acessando dados da empresa através do projeto '" + projetoResidencial.getNomeProjeto() + "':");
        System.out.println("Nome da Empresa: " + projetoResidencial.getEmpresaContratante().getNome());
        System.out.println("CNPJ: " + projetoResidencial.getEmpresaContratante().getCnpj());
    }
}
