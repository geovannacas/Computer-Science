import java.io.*;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

public class Principal {

    public static void main(String[] args) {
        // Caminhos dos arquivos
        String arquivoTexto = "funcionarios.txt";
        String arquivoBinario = "funcionarios.dat";

        // Lista para armazenar os funcionários lidos do arquivo de texto
        List<Funcionario> funcionarios = new ArrayList<>();

        System.out.println("### ETAPA 1: Lendo arquivo de texto e calculando totais... ###");

        // Variáveis para os totais de imposto
        double totalImpostoM = 0;
        double totalImpostoF = 0;
        double totalImpostoGeral = 0;

        // Usando try-with-resources para garantir que o leitor será fechado
        try (BufferedReader br = new BufferedReader(new FileReader(arquivoTexto))) {
            String linha;
            while ((linha = br.readLine()) != null) {
                // Separando os campos da linha pelo caractere '#' 
                String[] campos = linha.split("#");
                if (campos.length == 4) {
                    String nome = campos[0];
                    char sexo = campos[1].charAt(0);
                    double salario = Double.parseDouble(campos[2]);
                    int dependentes = Integer.parseInt(campos[3]);

                    // Instanciando o objeto Funcionario 
                    Funcionario func = new Funcionario(nome, sexo, salario, dependentes);
                    funcionarios.add(func);

                    System.out.println(func.mostraFuncionario()); // Mostrando dados do funcionário 

                    // Calculando e somando os impostos
                    double imposto = func.impostoRenda();
                    if (imposto > 0) {
                        if (sexo == 'M') {
                            totalImpostoM += imposto;
                        } else if (sexo == 'F') {
                            totalImpostoF += imposto;
                        }
                        totalImpostoGeral += imposto;
                    }
                }
            }
        } catch (IOException e) {
            System.err.println("Erro ao ler o arquivo de texto: " + e.getMessage());
            return; // Encerra a execução se não conseguir ler o arquivo inicial
        }

        // Mostrando os totais calculados a partir do arquivo de texto 
        DecimalFormat df = new DecimalFormat("#,##0.00");
        System.out.println("\n--- TOTAIS DE IMPOSTO (A PARTIR DO ARQUIVO .TXT) ---");
        System.out.println("Total de imposto pago por funcionários do sexo feminino: R$ " + df.format(totalImpostoF));
        System.out.println("Total de imposto pago por funcionários do sexo masculino: R$ " + df.format(totalImpostoM));
        System.out.println("Total de imposto pago por todos os funcionários: R$ " + df.format(totalImpostoGeral));

        System.out.println("\n### ETAPA 2: Gravando objetos em arquivo binário... ###");

        // Gravando a lista de objetos no arquivo binário 
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(arquivoBinario))) {
            for (Funcionario func : funcionarios) {
                oos.writeObject(func);
            }
            System.out.println("-> Objetos gravados com sucesso em '" + arquivoBinario + "'.");
        } catch (IOException e) {
            System.err.println("Erro ao gravar o arquivo binário: " + e.getMessage());
        }

        System.out.println("\n### ETAPA 3: Lendo objetos do arquivo binário e verificando totais... ###");

        // Resetando os totais para o novo cálculo
        totalImpostoM = 0;
        totalImpostoF = 0;
        totalImpostoGeral = 0;

        // Lendo os objetos do arquivo binário e repetindo o resultado do item 1 
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(arquivoBinario))) {
            while (true) {
                try {
                    Funcionario funcLido = (Funcionario) ois.readObject();
                    
                    // Apenas para verificação, podemos imprimir novamente.
                    // System.out.println(funcLido.mostraFuncionario());

                    double imposto = funcLido.impostoRenda();
                    if (imposto > 0) {
                        if (funcLido.sexo == 'M') {
                            totalImpostoM += imposto;
                        } else if (funcLido.sexo == 'F') {
                            totalImpostoF += imposto;
                        }
                        totalImpostoGeral += imposto;
                    }
                } catch (EOFException e) {
                    // Fim do arquivo alcançado, o que é esperado.
                    break;
                }
            }
        } catch (IOException | ClassNotFoundException e) {
            System.err.println("Erro ao ler o arquivo binário: " + e.getMessage());
        }

        // Mostrando os totais calculados a partir do arquivo de objetos
        System.out.println("\n--- TOTAIS DE IMPOSTO (A PARTIR DO ARQUIVO .DAT) ---");
        System.out.println("Total de imposto pago por funcionários do sexo feminino: R$ " + df.format(totalImpostoF));
        System.out.println("Total de imposto pago por funcionários do sexo masculino: R$ " + df.format(totalImpostoM));
        System.out.println("Total de imposto pago por todos os funcionários: R$ " + df.format(totalImpostoGeral));
    }
}