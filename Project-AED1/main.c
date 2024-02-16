#include "tad.h"

/**
 * @brief Função principal do programa.
 *
 * Esta função gerencia a interação com o usuário e executa as ações do menu.
 * Insere casos base
 * 
 * @return Retorna 0 para indicar sucesso.
 */
int main(){

    Lista_funcionarios *lista_funcionarios;
    // Aloca memória para a lista de funcionários
    lista_funcionarios = (Lista_funcionarios*)malloc(sizeof(Lista_funcionarios)); // Aloca memória para a lista de funcionários

    // Inicializa a lista de funcionários
    inicia_lista(lista_funcionarios);

    Funcionario funcionario; // Variável para armazenar informações do funcionário
    int opcao, id; // Variáveis para armazenar opções e IDs
    char especializacao[50]; // Variável para armazenar a especialização do funcionário
    char turno[50]; // Variável para armazenar o turno de trabalho
    char turno_atual[50]; // Variável para armazenar o turno atual para troca
    char turno_trocado[50]; // Variável para armazenar o turno desejado para troca
    char escolha[50]; // Variável para armazenar escolhas (Sim ou Não)
    int horas; // Variável para armazenar a quantidade de horas
    float salario=0.0; // Variável para armazenar o salário calculado

    // Inserindo alguns exemplos na lista de funcionários
    // Cada bloco de código cria um funcionário, insere na lista, adiciona turno e horas
    // Repetido para vários funcionários

    strcpy(funcionario.nome, "Lucas Silva");
    strcpy(funcionario.especializacao, "Cardiologia");
    funcionario.disponibilidade[0] = 1;
    funcionario.disponibilidade[1] = 0;
    funcionario.disponibilidade[2] = 1;
    horas = 60;
    funcionario.id = 1;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "manha");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Maria Santos");
    strcpy(funcionario.especializacao, "Cardiologia");
    funcionario.disponibilidade[0] = 0;
    funcionario.disponibilidade[1] = 1;
    funcionario.disponibilidade[2] = 1;
    horas = 30;
    funcionario.id = 2;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "tarde");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Pedro Oliveira");
    strcpy(funcionario.especializacao, "Neurologia");
    funcionario.disponibilidade[0] = 1;
    funcionario.disponibilidade[1] = 0;
    funcionario.disponibilidade[2] = 0;
    horas = 70;
    funcionario.id = 3;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "manha");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Ana Costa");
    strcpy(funcionario.especializacao, "Neurologia");
    funcionario.disponibilidade[0] = 1;
    funcionario.disponibilidade[1] = 1;
    funcionario.disponibilidade[2] = 0;
    horas = 45;
    funcionario.id = 4;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "tarde");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "João Rodrigues");
    strcpy(funcionario.especializacao, "Trauma");
    funcionario.disponibilidade[0] = 0;
    funcionario.disponibilidade[1] = 1;
    funcionario.disponibilidade[2] = 1;
    horas = 25;
    funcionario.id = 5;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "tarde");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Isabela Almeida");
    strcpy(funcionario.especializacao, "Trauma");
    funcionario.disponibilidade[0] = 1;
    funcionario.disponibilidade[1] = 0;
    funcionario.disponibilidade[2] = 1;
    horas = 32;
    funcionario.id = 6;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "noite");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Gabriel Souza");
    strcpy(funcionario.especializacao, "Pediatria");
    funcionario.disponibilidade[0] = 0;
    funcionario.disponibilidade[1] = 1;
    funcionario.disponibilidade[2] = 1;
    horas = 61;
    funcionario.id = 7;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "noite");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Laura Pereira");
    strcpy(funcionario.especializacao, "Pediatria");
    funcionario.disponibilidade[0] = 1;
    funcionario.disponibilidade[1] = 0;
    funcionario.disponibilidade[2] = 1;
    horas = 60;
    funcionario.id = 8;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "manha");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Matheus Fernandes");
    strcpy(funcionario.especializacao, "Enfermagem");
    funcionario.disponibilidade[0] = 0;
    funcionario.disponibilidade[1] = 0;
    funcionario.disponibilidade[2] = 1;
    horas = 47;
    funcionario.id = 9;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "noite");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Sofia Goncalves");
    strcpy(funcionario.especializacao, "Enfermagem");
    funcionario.disponibilidade[0] = 1;
    funcionario.disponibilidade[1] = 0;
    funcionario.disponibilidade[2] = 0;
    horas = 30;
    funcionario.id = 10;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "manha");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Rafael Barbosa");
    strcpy(funcionario.especializacao, "Pneumologia");
    funcionario.disponibilidade[0] = 1;
    funcionario.disponibilidade[1] = 1;
    funcionario.disponibilidade[2] = 0;
    horas = 15;
    funcionario.id = 11;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "tarde");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Julia Lima");
    strcpy(funcionario.especializacao, "Pneumologia");
    funcionario.disponibilidade[0] = 0;
    funcionario.disponibilidade[1] = 0;
    funcionario.disponibilidade[2] = 1;
    horas = 65;
    funcionario.id = 12;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "noite");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Enzo Carvalho");
    strcpy(funcionario.especializacao, "Ortopedia");
    funcionario.disponibilidade[0] = 1;
    funcionario.disponibilidade[1] = 1;
    funcionario.disponibilidade[2] = 0;
    horas = 32;
    funcionario.id = 13;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "manha");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Gustavo Cunha");
    strcpy(funcionario.especializacao, "Ortopedia");
    funcionario.disponibilidade[0] = 0;
    funcionario.disponibilidade[1] = 1;
    funcionario.disponibilidade[2] = 1;
    horas = 43;
    funcionario.id = 14;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "tarde");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Vitória Cardoso");
    strcpy(funcionario.especializacao, "Tecnico em Enfermagem");
    funcionario.disponibilidade[0] = 1;
    funcionario.disponibilidade[1] = 0;
    funcionario.disponibilidade[2] = 0;
    horas = 60;
    funcionario.id = 15;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "manha");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Miguel Nunes");
    strcpy(funcionario.especializacao, "Tecnico em Enfermagem");
    funcionario.disponibilidade[0] = 0;
    funcionario.disponibilidade[1] = 1;
    funcionario.disponibilidade[2] = 1;
    horas = 80;
    funcionario.id = 16;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "noite");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Clara Costa");
    strcpy(funcionario.especializacao, "Cardiologia");
    funcionario.disponibilidade[0] = 1;
    funcionario.disponibilidade[1] = 0;
    funcionario.disponibilidade[2] = 1;
    horas = 36;
    funcionario.id = 17;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "manha");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Davi Ribeiro");
    strcpy(funcionario.especializacao, "Cardiologia");
    funcionario.disponibilidade[0] = 0;
    funcionario.disponibilidade[1] = 1;
    funcionario.disponibilidade[2] = 0;
    horas = 65;
    funcionario.id = 18;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "tarde");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Manuela Andrade");
    strcpy(funcionario.especializacao, "Neurologia");
    funcionario.disponibilidade[0] = 1;
    funcionario.disponibilidade[1] = 0;
    funcionario.disponibilidade[2] = 0;
    horas = 57;
    funcionario.id = 19;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "manha");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    strcpy(funcionario.nome, "Thiago Santos");
    strcpy(funcionario.especializacao, "Pediatria");
    funcionario.disponibilidade[0] = 0;
    funcionario.disponibilidade[1] = 0;
    funcionario.disponibilidade[2] = 1;
    horas = 31;
    funcionario.id = 20;

    insercao_funcionario(lista_funcionarios, funcionario);
    insere_turno(lista_funcionarios, funcionario, "noite");
    adicionar_horas(lista_funcionarios, funcionario, horas);

    // Loop principal do menu
    do{

        printf("-----------MENU-----------\n"); // Exibe o menu para o usuário
        // Opções do menu...
        printf("1- Inserir funcionario novo.\n");
        printf("2- Inserir turno.\n");
        printf("3- Remove turno.\n");
        printf("4- Consulta disponibilidade.\n");
        printf("5- Troca turno.\n");
        printf("6- Consulta de horas trabalhadas.\n");
        printf("7- Adicionar horas trabalhadas.\n");
        printf("8- Imprimir funcionarios que estao trabalhando.\n");
        printf("9- Calcular salario.\n");
        printf("10- Ordena alfabeticamente.\n");
        printf("--------------------------\n");

        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário

         // Realiza a ação de acordo com a opção escolhida
        switch(opcao){

            case 0:
                break;

            case 1:
                printf("Insira as informacoes do funcionario que voce deseja adicionar:\n");
                printf("Insira o nome:\n");
                scanf(" %[^\n]", funcionario.nome);
                limpa_buffer();

                printf("Insira a especializacao:\n");
                scanf(" %[^\n]", funcionario.especializacao);
                limpa_buffer();

                printf("Insira a disponibilidade (Sim ou Nao):\n");
                for(int i=0; i<3; i++){
                    printf("Turno %d: ", i+1);
                    scanf("%s", escolha);
                    if(strcmp(escolha, "Sim") == 0){
                        funcionario.disponibilidade[i] = 1;
                    } else{
                        funcionario.disponibilidade[i] = 0;
                    }
                    limpa_buffer();
                }

                printf("Insira o id:\n");
                scanf("%d", &funcionario.id);
                limpa_buffer();
                
                
                if(ja_foi_inserido(lista_funcionarios, funcionario)) {
                    printf("Erro - O ID ja foi inserido.\n");
                } else{
                    insercao_funcionario(lista_funcionarios, funcionario);
                }
    
                break;

            case 2:
                printf("Insira as informacoes do funcionario que voce deseja adicionar um turno de trabalho:\n");
                printf("Insira o id:\n");
                scanf("%d", &funcionario.id);
                limpa_buffer();
                

                printf("Insira a especializacao:\n");
                scanf(" %[^\n]", funcionario.especializacao);
                limpa_buffer();

                printf("Insira o turno escolhido para trabalhar:\n");
                scanf("%s", turno);
                limpa_buffer();
                

                insere_turno(lista_funcionarios, funcionario, turno);
                break;

            case 3:
                printf("Insira as informacoes do funcionario que voce deseja remover um turno trabalhado:\n");
                printf("Insira o id do funcionario:\n");
                scanf("%d", &funcionario.id);
                limpa_buffer();

                printf("Insira a especializacao:\n");
                scanf(" %[^\n]", funcionario.especializacao);
                limpa_buffer();

                printf("Insira o turno a ser removido:\n");
                scanf("%s", turno);
                limpa_buffer();

                remove_turno(lista_funcionarios, funcionario, turno);
                break;

            case 4:
                printf("Insira as informacoes do funcionario que voce deseja consultar a disponibilidade:\n");
                printf("Especializacao:\n");
                scanf(" %[^\n]", funcionario.especializacao);
                limpa_buffer();

                printf("Id:\n");
                scanf("%d", &funcionario.id);
                limpa_buffer();
                

                consulta_disponibilidade(lista_funcionarios, funcionario);
                break;

            case 5:
                printf("Insira as informacoes do funcionario que quer trocar de turno:\n");
                printf("Especializacao:\n");
                scanf(" %[^\n]", funcionario.especializacao);
                limpa_buffer();

                printf("Id:\n");
                scanf("%d", &funcionario.id);
                limpa_buffer();
                

                printf("Turno atual a ser trocado:\n");
                scanf("%s", turno_atual);
                limpa_buffer();

                printf("Turno desejado:\n");
                scanf("%s", turno_trocado);
                limpa_buffer();

                troca_turno(lista_funcionarios, funcionario, turno_atual, turno_trocado);

                break;

            case 6:
                printf("Insira as informacoes do funcionario que voce deseja checar as horas trabalhadas:\n");
                printf("Especializacao:\n");
                scanf(" %[^\n]", funcionario.especializacao);
                limpa_buffer();

                printf("Id:\n");
                scanf("%d", &funcionario.id);
                limpa_buffer();
                

                restricao(lista_funcionarios, funcionario);
                break;

            case 7:
                printf("Insira as informacoes do funcionario que voce deseja adicionar horas trabalhadas:\n");
                printf("Insira o id: ");
                scanf("%d", &funcionario.id);
                limpa_buffer();
                
                
                printf("Insira a especializacao: ");
                scanf(" %[^\n]", funcionario.especializacao);
                limpa_buffer();

                printf("Escolha a quantidade de horas a ser adicionada: ");
                scanf("%d", &horas);
                limpa_buffer();
                
                adicionar_horas(lista_funcionarios, funcionario, horas);
                break;

            case 8:
                printf("Digite a funcao a ser consultada:\n");
                scanf(" %[^\n]", funcionario.especializacao);
                limpa_buffer();
                
                printf("Os funcionarios que estao trabalhando sao:\n");
                imprime(lista_funcionarios, funcionario);
                break;

            case 9:
                printf("Calculo e impressao de salario:\n");
                printf("Digite a funcao do funcionario:\n");
                scanf(" %[^\n]", funcionario.especializacao);
                limpa_buffer();
                
                calcula_salario(lista_funcionarios, funcionario);

                break;

            case 10:
                printf("Insira a especializacao:\n");
                scanf(" %[^\n]", funcionario.especializacao);
                limpa_buffer();

                ordena_nome(lista_funcionarios, funcionario);
                break;

            default:
                printf("Insira uma opcao valida!\n");
                break;
        }

    }while(opcao != 0);  // O loop continua até o usuário escolher a opção 0 (sair)

    libera_memoria(lista_funcionarios); // Libera a memória alocada para a lista de funcionários

    return 0;
}