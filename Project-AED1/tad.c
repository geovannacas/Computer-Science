#include "tad.h"

/**
 * @brief Inicializa a lista de funcionários e departamentos, alocando memória para cada departamento e inicializando seus ponteiros.
 * 
 * Esta função é responsável por inicializar a estrutura `Lista_funcionarios`, que contém listas de funcionários de diferentes especializações.
 * Ela aloca memória para cada departamento e define os ponteiros de início e final de cada lista como NULL, indicando que a lista está vazia.
 * 
 * @param lista_funcionarios Um ponteiro para a estrutura `Lista_funcionarios` que irá armazenar as listas de funcionários de diferentes especializações.
 */
void inicia_lista(Lista_funcionarios *lista_funcionarios){

    
    lista_funcionarios->cardiologia = (Cardiologia*)malloc(sizeof(Cardiologia));
    lista_funcionarios->cardiologia->inicio = NULL;
    lista_funcionarios->cardiologia->final = NULL;

    lista_funcionarios->neurologia = (Neurologia*)malloc(sizeof(Neurologia));
    lista_funcionarios->neurologia->inicio = NULL;
    lista_funcionarios->neurologia->final = NULL;

    lista_funcionarios->trauma = (Trauma*)malloc(sizeof(Trauma));
    lista_funcionarios->trauma->inicio = NULL;
    lista_funcionarios->trauma->final = NULL;

    lista_funcionarios->pediatria = (Pediatria*)malloc(sizeof(Pediatria));
    lista_funcionarios->pediatria->inicio = NULL;
    lista_funcionarios->pediatria->final = NULL;

    lista_funcionarios->enfermagem = (Enfermagem*)malloc(sizeof(Enfermagem));
    lista_funcionarios->enfermagem->inicio = NULL;
    lista_funcionarios->enfermagem->final = NULL;

    lista_funcionarios->pneumologia = (Pneumologia*)malloc(sizeof(Pneumologia));
    lista_funcionarios->pneumologia->inicio = NULL;
    lista_funcionarios->pneumologia->final = NULL;

    lista_funcionarios->ortopedia = (Ortopedia*)malloc(sizeof(Ortopedia));
    lista_funcionarios->ortopedia->inicio = NULL;
    lista_funcionarios->ortopedia->final = NULL;

    lista_funcionarios->tecnico_de_enfermagem = (Tecnico_de_enfermeagem*)malloc(sizeof(Tecnico_de_enfermeagem));
    lista_funcionarios->tecnico_de_enfermagem->inicio = NULL;
    lista_funcionarios->tecnico_de_enfermagem->final = NULL;

    return;
}

/**
 * @brief Aloca dinamicamente espaço na memória para um novo nó da estrutura "Funcionario".
 * 
 * Esta função é utilizada para alocar dinamicamente memória para armazenar as informações de um novo funcionário.
 * Um novo nó da estrutura "Funcionario" é criado e os campos são inicializados. O ponteiro "prox" é definido como NULL
 * para indicar que o novo nó ainda não está conectado a outros elementos.
 * 
 * @return Um ponteiro para o nó "Funcionario" recém-alocado.
 */
Funcionario *aloca_funcionario(){
    Funcionario *funcionario = (Funcionario*)malloc(sizeof(Funcionario));

    funcionario->prox = NULL;

    return funcionario;
}

/**
 * @brief Verifica se a lista de funcionários de uma especialização está vazia.
 * 
 * Esta função verifica se a lista de funcionários de uma especialização específica está vazia.
 * Ela utiliza a especialização fornecida na estrutura "funcionario" para determinar qual lista verificar.
 * 
 * @param lista_funcionarios Um ponteiro para a estrutura "Lista_funcionarios" que contém as listas de especializações.
 * @param funcionario Uma estrutura com informações sobre o funcionário, incluindo a especialização.
 * @return Um valor booleano: 1 se a lista estiver vazia, 0 caso contrário.
 */
int lista_vazia(Lista_funcionarios *lista_funcionarios, Funcionario funcionario){
   Funcionario *aux = NULL;

    if(strcmp(funcionario.especializacao, "Cardiologia") == 0){
        aux = lista_funcionarios->cardiologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Enfermagem") == 0){
        aux = lista_funcionarios->enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Neurologia") == 0){
        aux = lista_funcionarios->neurologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Ortopedia") == 0){
        aux = lista_funcionarios->ortopedia->inicio;
    } else if(strcmp(funcionario.especializacao, "Pediatria") == 0){
        aux = lista_funcionarios->pediatria->inicio;
    } else if(strcmp(funcionario.especializacao, "Pneumologia") == 0){
        aux = lista_funcionarios->pneumologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Tecnico em Enfermagem") == 0){
        aux = lista_funcionarios->tecnico_de_enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Trauma") == 0){
        aux = lista_funcionarios->trauma->inicio;
    }

    return (aux == NULL);
}

/**
 * @brief Insere um novo funcionário na lista correspondente à sua especialização.
 * 
 * Esta função recebe um ponteiro para a estrutura de listas de funcionários e uma estrutura
 * contendo as informações do funcionário a ser inserido. Ela aloca memória para um novo
 * funcionário, preenche seus atributos com as informações fornecidas e o insere na lista
 * correspondente à sua especialização.
 * 
 * @param lista_funcionarios Ponteiro para a estrutura Lista_funcionarios que contém as listas das especializações.
 * @param funcionario Estrutura com informações do funcionário a ser inserido.
 */
void insercao_funcionario(Lista_funcionarios *lista_funcionarios, Funcionario funcionario){
    
    // Aloca memória para um novo funcionário
    Funcionario *funcionario_novo = aloca_funcionario();
    
    // Verifica a especializacao do funcionário e insere nos respectivos departamentos
    if(strcmp(funcionario.especializacao, "Cardiologia") == 0){
        // Configura os atributos do novo funcionário
        funcionario_novo->id = funcionario.id;
        funcionario_novo->horas_trabalhadas = 0;
        funcionario_novo->manha = 0;
        funcionario_novo->tarde = 0;
        funcionario_novo->noite = 0;
        funcionario_novo->salario = 0.0;
        funcionario_novo->disponibilidade[0] = funcionario.disponibilidade[0];
        funcionario_novo->disponibilidade[1] = funcionario.disponibilidade[1];
        funcionario_novo->disponibilidade[2] = funcionario.disponibilidade[2];
        strcpy(funcionario_novo->nome, funcionario.nome);
        strcpy(funcionario_novo->especializacao, funcionario.especializacao);

        // Verifica se a lista de cardiologia está vazia e insere o funcionário
        if(lista_vazia(lista_funcionarios, funcionario)){
            lista_funcionarios->cardiologia->inicio = funcionario_novo;
            lista_funcionarios->cardiologia->final = funcionario_novo;
        }else{
            lista_funcionarios->cardiologia->final->prox = funcionario_novo;
            lista_funcionarios->cardiologia->final = funcionario_novo;
        }
    }else if(strcmp(funcionario.especializacao, "Neurologia") == 0){ //Configuração similar para o restante das especializações
        funcionario_novo->id = funcionario.id;
        funcionario_novo->horas_trabalhadas = 0;
        funcionario_novo->manha = 0;
        funcionario_novo->tarde = 0;
        funcionario_novo->noite = 0;
        funcionario_novo->salario = 0.0;
        funcionario_novo->disponibilidade[0] = funcionario.disponibilidade[0];
        funcionario_novo->disponibilidade[1] = funcionario.disponibilidade[1];
        funcionario_novo->disponibilidade[2] = funcionario.disponibilidade[2];
        strcpy(funcionario_novo->nome, funcionario.nome);
        strcpy(funcionario_novo->especializacao, funcionario.especializacao);

        if(lista_vazia(lista_funcionarios, funcionario)){
            lista_funcionarios->neurologia->inicio = funcionario_novo;
            lista_funcionarios->neurologia->final = funcionario_novo;
        }else{
            lista_funcionarios->neurologia->final->prox = funcionario_novo;
            lista_funcionarios->neurologia->final = funcionario_novo;
        }
    }else if(strcmp(funcionario.especializacao, "Tecnico em Enfermagem") == 0){
        funcionario_novo->id = funcionario.id;
        funcionario_novo->horas_trabalhadas = 0;
        funcionario_novo->manha = 0;
        funcionario_novo->tarde = 0;
        funcionario_novo->noite = 0;
        funcionario_novo->salario = 0.0;
        funcionario_novo->disponibilidade[0] = funcionario.disponibilidade[0];
        funcionario_novo->disponibilidade[1] = funcionario.disponibilidade[1];
        funcionario_novo->disponibilidade[2] = funcionario.disponibilidade[2];
        strcpy(funcionario_novo->nome, funcionario.nome);
        strcpy(funcionario_novo->especializacao, funcionario.especializacao);

        if(lista_vazia(lista_funcionarios, funcionario)){
            lista_funcionarios->tecnico_de_enfermagem->inicio = funcionario_novo;
            lista_funcionarios->tecnico_de_enfermagem->final = funcionario_novo;
        }else{
            lista_funcionarios->tecnico_de_enfermagem->final->prox = funcionario_novo;
            lista_funcionarios->tecnico_de_enfermagem->final = funcionario_novo;
        }
    }else if(strcmp(funcionario.especializacao, "Ortopedia") == 0){
        funcionario_novo->id = funcionario.id;
        funcionario_novo->horas_trabalhadas = 0;
        funcionario_novo->manha = 0;
        funcionario_novo->tarde = 0;
        funcionario_novo->noite = 0;
        funcionario_novo->salario = 0.0;
        funcionario_novo->disponibilidade[0] = funcionario.disponibilidade[0];
        funcionario_novo->disponibilidade[1] = funcionario.disponibilidade[1];
        funcionario_novo->disponibilidade[2] = funcionario.disponibilidade[2];
        strcpy(funcionario_novo->nome, funcionario.nome);
        strcpy(funcionario_novo->especializacao, funcionario.especializacao);

        if(lista_vazia(lista_funcionarios, funcionario)){
            lista_funcionarios->ortopedia->inicio = funcionario_novo;
            lista_funcionarios->ortopedia->final = funcionario_novo;
        }else{
            lista_funcionarios->ortopedia->final->prox = funcionario_novo;
            lista_funcionarios->ortopedia->final = funcionario_novo;
        }
    }else if(strcmp(funcionario.especializacao, "Enfermagem") == 0){
        funcionario_novo->id = funcionario.id;
        funcionario_novo->horas_trabalhadas = 0;
        funcionario_novo->manha = 0;
        funcionario_novo->tarde = 0;
        funcionario_novo->noite = 0;
        funcionario_novo->salario = 0.0;
        funcionario_novo->disponibilidade[0] = funcionario.disponibilidade[0];
        funcionario_novo->disponibilidade[1] = funcionario.disponibilidade[1];
        funcionario_novo->disponibilidade[2] = funcionario.disponibilidade[2];
        strcpy(funcionario_novo->nome, funcionario.nome);
        strcpy(funcionario_novo->especializacao, funcionario.especializacao);

        if(lista_vazia(lista_funcionarios, funcionario)){
            lista_funcionarios->enfermagem->inicio = funcionario_novo;
            lista_funcionarios->enfermagem->final = funcionario_novo;
        }else{
            lista_funcionarios->enfermagem->final->prox = funcionario_novo;
            lista_funcionarios->enfermagem->final = funcionario_novo;
        }
    }else if(strcmp(funcionario.especializacao, "Trauma") == 0){
        funcionario_novo->id = funcionario.id;
        funcionario_novo->horas_trabalhadas = 0;
        funcionario_novo->manha = 0;
        funcionario_novo->tarde = 0;
        funcionario_novo->noite = 0;
        funcionario_novo->salario = 0.0;
        funcionario_novo->disponibilidade[0] = funcionario.disponibilidade[0];
        funcionario_novo->disponibilidade[1] = funcionario.disponibilidade[1];
        funcionario_novo->disponibilidade[2] = funcionario.disponibilidade[2];
        strcpy(funcionario_novo->nome, funcionario.nome);
        strcpy(funcionario_novo->especializacao, funcionario.especializacao);

        if(lista_vazia(lista_funcionarios, funcionario)){
            lista_funcionarios->trauma->inicio = funcionario_novo;
            lista_funcionarios->trauma->final = funcionario_novo;
        }else{
            lista_funcionarios->trauma->final->prox = funcionario_novo;
            lista_funcionarios->trauma->final = funcionario_novo;
        }
    }else if(strcmp(funcionario.especializacao, "Pediatria")==0){
        funcionario_novo->id = funcionario.id;
        funcionario_novo->horas_trabalhadas = 0;
        funcionario_novo->manha = 0;
        funcionario_novo->tarde = 0;
        funcionario_novo->noite = 0;
        funcionario_novo->salario = 0.0;
        funcionario_novo->disponibilidade[0] = funcionario.disponibilidade[0];
        funcionario_novo->disponibilidade[1] = funcionario.disponibilidade[1];
        funcionario_novo->disponibilidade[2] = funcionario.disponibilidade[2];
        strcpy(funcionario_novo->nome, funcionario.nome);
        strcpy(funcionario_novo->especializacao, funcionario.especializacao);
            
        if(lista_vazia(lista_funcionarios, funcionario)){
            lista_funcionarios->pediatria->inicio = funcionario_novo;
            lista_funcionarios->pediatria->final = funcionario_novo;
        }else{
            lista_funcionarios->pediatria->final->prox = funcionario_novo;
            lista_funcionarios->pediatria->final= funcionario_novo;
        }
    }else if(strcmp(funcionario.especializacao, "Pneumologia") == 0){
        funcionario_novo->id = funcionario.id;
        funcionario_novo->horas_trabalhadas = 0;
        funcionario_novo->manha = 0;
        funcionario_novo->tarde = 0;
        funcionario_novo->noite = 0;
        funcionario_novo->salario = 0.0;
        funcionario_novo->disponibilidade[0] = funcionario.disponibilidade[0];
        funcionario_novo->disponibilidade[1] = funcionario.disponibilidade[1];
        funcionario_novo->disponibilidade[2] = funcionario.disponibilidade[2];
        strcpy(funcionario_novo->nome, funcionario.nome);
        strcpy(funcionario_novo->especializacao, funcionario.especializacao);

        if(lista_vazia(lista_funcionarios, funcionario)){
            lista_funcionarios->pneumologia->inicio = funcionario_novo;
            lista_funcionarios->pneumologia->final = funcionario_novo;
        }else{
            lista_funcionarios->pneumologia->final->prox = funcionario_novo;
            lista_funcionarios->pneumologia->final = funcionario_novo;
        }
    } else{
        //Caso a especializacao seja inválida
        printf("Erro - Especializacao inserida e invalida\n");
        return;
    }
    return;
}

/**
 * @brief Insere um turno de trabalho para um funcionário específico.
 * 
 * Esta função recebe um ponteiro para a estrutura de listas de funcionários, uma estrutura contendo as
 * informações do funcionário e o turno a ser inserido. Ela verifica a especialização do funcionário e
 * insere o turno correspondente na lista de funcionários dessa especialização.
 * 
 * @param lista_funcionarios Ponteiro para a estrutura Lista_funcionarios que contém as listas das especializações.
 * @param funcionario Estrutura com informações do funcionário.
 * @param turno Turno a ser inserido ("manha", "tarde" ou "noite").
 */
void insere_turno(Lista_funcionarios *lista_funcionarios, Funcionario funcionario, char turno[]){
    Funcionario *aux = NULL;
    int aux1 = 0;
    
    // Verifica a especializacao do funcionário para determinar qual lista usar
    if(strcmp(funcionario.especializacao, "Cardiologia") == 0){
        aux = lista_funcionarios->cardiologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Enfermagem") == 0){
        aux = lista_funcionarios->enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Neurologia") == 0){
        aux = lista_funcionarios->neurologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Ortopedia") == 0){
        aux = lista_funcionarios->ortopedia->inicio;
    } else if(strcmp(funcionario.especializacao, "Pediatria") == 0){
        aux = lista_funcionarios->pediatria->inicio;
    } else if(strcmp(funcionario.especializacao, "Pneumologia") == 0){
        aux = lista_funcionarios->pneumologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Tecnico em Enfermagem") == 0){
        aux = lista_funcionarios->tecnico_de_enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Trauma") == 0){
        aux = lista_funcionarios->trauma->inicio;
    } else{
        // Encerra a função se a especializacao for inválida
        printf("Erro - Especializacao inserida e invalida\n");
        return;
    } 

    // Verifica se a lista está vazia
    if(lista_vazia(lista_funcionarios, funcionario)){
        printf("Erro - Lista Vazia: Nao e possivel inserir turnos a ser trabalhados.\n");
        return; // Encerra a função se a lista estiver vazia
    } else {
        // Percorre a lista de Funcionarios para encontrar o funcionário correspondente
        while(aux != NULL){
            if(aux->id == funcionario.id){  
                aux1 = 1;
                // Verifica a disponibilidade e o turno a ser inserido
                if(aux->disponibilidade[0] == 1 && strcmp(turno, "manha")==0)
                {
                    aux->manha++;
                }
                else if(aux->disponibilidade[1] == 1 && strcmp(turno, "tarde") == 0)
                {
                    aux->tarde++;
                }
                else if(aux->disponibilidade[2] == 1 && strcmp(turno, "noite")==0)
                {
                    aux->noite++;
                }
                else
                {
                    printf("Turno inserido invalido ou nao ha disponibilidade!\n");
                }
            }
            aux = aux->prox;
        }
    }
    if(aux1 == 0){
        printf("ID invalido!\n");
    }
}

/**
 * @brief Remove um turno de trabalho de um funcionário específico.
 * 
 * Esta função recebe um ponteiro para a estrutura de listas de funcionários, uma estrutura contendo as
 * informações do funcionário e o turno a ser removido. Ela verifica a especialização do funcionário e
 * remove o turno correspondente da lista de funcionários dessa especialização.
 * 
 * @param lista_funcionarios Ponteiro para a estrutura Lista_funcionarios que contém as listas das especializações.
 * @param funcionario Estrutura com informações do funcionário.
 * @param turno Turno a ser removido ("manha", "tarde" ou "noite").
 */
void remove_turno(Lista_funcionarios *lista_funcionarios, Funcionario funcionario, char turno[]){
    Funcionario *aux = NULL;
    int aux1 = 0;

     // Verifica a especializacao do funcionário para determinar qual lista usar
    if(strcmp(funcionario.especializacao, "Cardiologia") == 0){
        aux = lista_funcionarios->cardiologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Enfermagem") == 0){
        aux = lista_funcionarios->enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Neurologia") == 0){
        aux = lista_funcionarios->neurologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Ortopedia") == 0){
        aux = lista_funcionarios->ortopedia->inicio;
    } else if(strcmp(funcionario.especializacao, "Pediatria") == 0){
        aux = lista_funcionarios->pediatria->inicio;
    } else if(strcmp(funcionario.especializacao, "Pneumologia") == 0){
        aux = lista_funcionarios->pneumologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Tecnico em Enfermagem") == 0){
        aux = lista_funcionarios->tecnico_de_enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Trauma") == 0){
        aux = lista_funcionarios->trauma->inicio;
    } else{
        // Encerra a função se a especializacao for inválida
        printf("Erro - Especializacao inserida e invalida\n");
        return;
    } 

     // Verifica se a lista está vazia
    if(lista_vazia(lista_funcionarios, funcionario)){
        printf("Erro - Lista vazia: Nao e possivel remover turnos trabalhados.\n");
        return; // Encerra a função se a lista estiver vazia
    } else {
        while(aux!=NULL)
        {
            if(aux->id == funcionario.id)  // Verifica o turno a ser removido
            {
                if(aux->manha == 1 && strcmp(turno, "manha")==0)
                {
                    aux->manha--;
                    aux1 = 1;
                }
                else if(aux->tarde == 1 && strcmp(turno, "tarde")==0)
                {
                    aux->tarde--;
                    aux1 = 1;
                }
                else if(aux->noite == 1 && strcmp(turno, "noite")==0)
                {
                    aux->noite--;
                    aux1 = 1;
                }
                else
                {
                    printf("Turno inserido invalido!\n");
                    aux1 = 1;
                }
            }
            aux = aux->prox;
        }
    }
    if(aux1 == 0){
        printf("ID invalido!\n");
    }
}

/**
 * @brief Troca os valores de dois IDs usando o Quick Sort.
 * 
 * Esta função recebe dois ponteiros para inteiros que representam IDs de médicos.
 * Ela realiza uma troca dos valores dos IDs para auxiliar na etapa de particionamento do algoritmo Quick Sort.
 * 
 * @param x Ponteiro para o primeiro ID a ser trocado.
 * @param y Ponteiro para o segundo ID a ser trocado.
 */
void troca(int *x, int *y){
    int temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * @brief Funcao que define o pivô e particiona o vetor no Quick Sort.
 * 
 * @param vetor lista estatica
 * @param inicio inicio do vetor (0)
 * @param fim fim do vetor (tamanho do vetor - 1)
 * @return int i+1
 */
int particionar(Lista_funcionarios_estatica *vetor, int inicio, int fim){
    int i=inicio-1, t;
    int pivo = vetor->id[fim];

    for(t=inicio;t<fim;t++){
        if(vetor->id[t]<=pivo){
            i++;
            troca(&vetor->id[i],&vetor->id[t]);
        }
    }

    troca(&vetor->id[i+1], &vetor->id[fim]);

    return i+1; 
}

/**
 * @brief QuickSort: função de ordenação Quick Sort que consiste, primeiramente, na escolha de um pivô, que 
 * e um elemento arbitrariamente escolhido do vetor. Após isso, particiona-se o vetor, ou seja, o vetor deve ser 
 * reorganizado de forma que os elementos menores que o pivô fiquem de um lado, e os maiores, de outro. 
 * Por último, recursivamente, ordena-se as sub-listas abaixo e acima do pivô.
 * 
 * @param lista lista estatica
 * @param inicio inicio do vetor (0)
 * @param fim fim do vetor (tamanho do vetor - 1)
 */
void quickSort(Lista_funcionarios_estatica *lista, int inicio, int fim){
    if(inicio<fim){
        int p = particionar(lista, inicio, fim);

        quickSort(lista,inicio,p-1);
        quickSort(lista,p+1,fim);
    }
}

/**
 * @brief Função pesquisa binária que, dado um vetor ordenado, deve-se, inicialmente, partir o 
 * vetor ao meio. Após isso, devemos comparar o elemento do meio da lista com a chave. Se a chave 
 * for maior que o elemento do meio, devemos procurar pelo elemento na parte direita do vetor.
 * Caso contrário, devemos comparar na parte esquerda. Apos a definição do lado da busca
 * pela chave, devemos repetir o processo de repartição do vetor, mas agora considerando
 * apenas os elementos do lado que definimos a procura. Esse processo se repete ate que a
 * chave seja encontrada. A implementação da função foi feita de forma recursiva.
 * 
 * @param busca vetor estático
 * @param left inicio do vetor (0)
 * @param right fim do vetor
 * @param id fim do vetor (tamanho do vetor - 1)
 * @param n tamanho do vetor
 * @return int índice do ID procurado
 */
int busca_binaria(Lista_funcionarios_estatica *busca, int left, int right, int id, int n){
    int m;

    if(left<=right){
        m = (right+left)/2;
        if( (m==0 || id > busca->id[m-1]) && busca->id[m] == id) return m;
        else if(id > busca->id[m]) return busca_binaria(busca, (m+1), right, id, n);
        else return busca_binaria(busca, left, (m-1), id, n);
    }

    return -1;
}

/**
 * @brief Função para consultar se um médico de uma determinada especialidade esta disponível em algum turno (manhã, tarde ou noite), 
 * com o uso de pesquisa binária e do algoritmo de ordenação Quick Sort (algortimo eficiente) para ordenar a lista antes do uso da 
 * pesquisa binária.
 * 
 * @param lista_funcionarios lista dinâmica contendo todas as listas de especialização.
 * @param especializacao nome da especialização do médico que o usuário deseja buscar.
 * @param id ID referente ao médico que o usuário deseja buscar.
 */
void consulta_disponibilidade(Lista_funcionarios *lista_funcionarios, Funcionario funcionario){
    Funcionario *aux = NULL; // ponteiro auxiliar para percorrer a lista
    Lista_funcionarios_estatica busca; // vetor estático
    int i=0, tam=0, p; // contador i usado no for; tamanho tam do vetor estático; parâmetro p que receberá o índice achado na busca binária

    busca.inicio = 0;  // inicialização do índice vetor estático

    /* Comparação da especialidade digitada pelo usuário com o nome da especialização em si. Ao achar a especialização, o ponteiro auxiliar 
    apontará para o primeiro elemento da lista da determinada especialização. */
    if(strcmp(funcionario.especializacao, "Cardiologia") == 0){
        aux = lista_funcionarios->cardiologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Enfermagem") == 0){
        aux = lista_funcionarios->enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Neurologia") == 0){
        aux = lista_funcionarios->neurologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Ortopedia") == 0){
        aux = lista_funcionarios->ortopedia->inicio;
    } else if(strcmp(funcionario.especializacao, "Pediatria") == 0){
        aux = lista_funcionarios->pediatria->inicio;
    } else if(strcmp(funcionario.especializacao, "Pneumologia") == 0){
        aux = lista_funcionarios->pneumologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Tecnico em Enfermagem") == 0){
        aux = lista_funcionarios->tecnico_de_enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Trauma") == 0){
        aux = lista_funcionarios->trauma->inicio;
    } else{
        printf("Erro - Especializacao inserida e invalida\n");
        return;
    }

    if(lista_vazia(lista_funcionarios, funcionario)){
        printf("Erro - Lista vazia: Nao ha funcionario na lista a ser consultado.\n");
        return;
    }

    // Colocaremos todos os IDs e disponibilidades dos médicos que estão na lista da especialização no vetor estático
    while(aux != NULL){
        busca.id[busca.inicio] = aux->id;
        busca.disponibilidade_m[busca.inicio] = aux->disponibilidade[0]; 
        busca.disponibilidade_t[busca.inicio] = aux->disponibilidade[1]; 
        busca.disponibilidade_n[busca.inicio] = aux->disponibilidade[2];
        busca.inicio++;
        aux = aux->prox;
    }

    tam = busca.inicio; // tam recebe o tamanho do vetor estático

    // Antes de usar a busca binária, devemos ordenar o vetor estático. Para isso, usaremos o Quick Sort
    quickSort(&busca, 0, tam-1);


    // Agora, usaremos a busca binária para achar o ID de determinado médico
    p = busca_binaria(&busca, 0, tam-1, funcionario.id, tam); // A busca retorna o índice do ID do médico procurado
    // Se retornar -1, o ID não foi encontrado
    
    if(p==-1) printf("O profissional nao foi encontrado.\n");
    else{ // Verificaremos disponibilidade do médico associado ao ID achado:
        if(busca.disponibilidade_m[p]==0) printf("O profissional nao esta disponivel no periodo da manha.\n");
        
        else printf("O profissional esta disponivel no periodo da manha.\n");

        if(busca.disponibilidade_t[p]==0) printf("O profissional nao esta disponivel no periodo da tarde.\n");
        
        else printf("O profissional esta disponivel no periodo da tarde.\n");

        if(busca.disponibilidade_n[p]==0) printf("O profissional nao esta disponivel no periodo da noite.\n");
        
        else printf("O profissional esta disponivel no periodo da noite.\n");
    }
    
}

/**
 * @brief Troca o turno atual do funcionário pelo turno desejado, verificando a disponibilidade.
 * 
 * Esta função permite que um funcionário altere seu turno de trabalho atual para um novo turno desejado, desde que haja disponibilidade e a troca seja válida. Ela verifica a especialização do funcionário, a lista de funcionários correspondente e realiza a troca de turnos conforme as condições estabelecidas.
 * 
 * @param lista_funcionarios Ponteiro para a estrutura Lista_funcionarios que contém as listas de especializações.
 * @param funcionario Struct com informações do funcionário que deseja trocar de turno.
 * @param turno Turno atual que o funcionário está trabalhando.
 * @param turno_trocado Novo turno desejado para a troca.
 */
void troca_turno(Lista_funcionarios *lista_funcionarios, Funcionario funcionario, char turno[], char turno_trocado[]){
    Funcionario *aux = NULL;
    int aux1 = 0;
    
     // Verifica a especializacao do funcionário para determinar qual lista usar
    if(strcmp(funcionario.especializacao, "Cardiologia") == 0){
        aux = lista_funcionarios->cardiologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Enfermagem") == 0){
        aux = lista_funcionarios->enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Neurologia") == 0){
        aux = lista_funcionarios->neurologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Ortopedia") == 0){
        aux = lista_funcionarios->ortopedia->inicio;
    } else if(strcmp(funcionario.especializacao, "Pediatria") == 0){
        aux = lista_funcionarios->pediatria->inicio;
    } else if(strcmp(funcionario.especializacao, "Pneumologia") == 0){
        aux = lista_funcionarios->pneumologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Tecnico em Enfermagem") == 0){
        aux = lista_funcionarios->tecnico_de_enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Trauma") == 0){
        aux = lista_funcionarios->trauma->inicio;
    } else{
        printf("Erro - Especializacao inserida e invalida\n");
        return; // Encerra a função se a especializacao for inválida
    } 

    // Verifica se a lista está vazia
    if(lista_vazia(lista_funcionarios, funcionario)){
        printf("Erro - Lista Vazia: Nao e possivel a troca de turno\n");
        return; // Encerra a função se a lista estiver vazia
    } else {
        while(aux != NULL){
            if(aux->id == funcionario.id){
                aux1 = 1;
                // Verifica o turno atual e o turno a ser trocado
                if(aux->manha == 1 && strcmp(turno, "manha") == 0){
                    if(strcmp(turno_trocado, "tarde") == 0 && aux->tarde != 1){
                        aux->manha--;
                        aux->tarde++;
                    } else if(strcmp(turno_trocado, "noite") == 0 && aux->noite != 1){
                        aux->manha--;
                        aux->noite++;
                    } else{
                        printf("Turno escolhido para troca ja trabalhado.\n");
                    }

                } else if(aux->tarde == 1 && strcmp(turno, "tarde") == 0){
                    //Realiza a troca de turnos
                    if(strcmp(turno_trocado, "manha") == 0 && aux->manha != 1){
                        aux->tarde--;
                        aux->manha++;
                    } else if(strcmp(turno_trocado, "noite") == 0 && aux->noite != 1){
                        aux->tarde--;
                        aux->noite++;
                    } else{
                        printf("Turno escolhido para troca ja trabalhado.\n");
                    }

                } else if(aux->noite == 1 && strcmp(turno, "noite") == 0){
                    if(strcmp(turno_trocado, "tarde") == 0 && aux->tarde != 1){
                        aux->noite--;
                        aux->tarde++;
                    } else if(strcmp(turno_trocado, "manha") == 0 && aux->manha != 1){
                        aux->noite--;
                        aux->manha++;
                    } else{
                        printf("Turno escolhido para troca ja trabalhado.\n");
                    }
                    
                } else{
                    printf("Turno inserido invalido\n");
                }
            }
            aux = aux->prox;
        }
    }
    if(aux1 == 0){
        printf("ID invalido!\n");
    }
}

/**
 * @brief Função que checará se um médico de um certa especialidade já trabalhou o numero de horas semanais máximo (60 horas semanais),
 * com o uso de busca sequencial.
 * 
 * @param lista_funcionarios lista dinâmica contendo todas as listas de especialização.
 * @param especializacao nome da especialização do médico que o usuário deseja buscar.
 * @param ID ID referente ao médico que o usuário deseja buscar.
 */
void restricao(Lista_funcionarios *lista_funcionarios, Funcionario funcionario){
    Funcionario *aux; // ponteiro auxiliar para percorrer a lista
    Lista_funcionarios_estatica busca; // vetor estático
    int i, tam=0, aux1 = 0; // contador i usado no for e tamanho tam do vetor estático

    busca.inicio = 0; // inicialização do índice vetor estático

    /* Comparação da especialidade digitada pelo usuário com o nome da especialização em si. Ao achar a especialização, o ponteiro auxiliar 
    apontará para o primeiro elemento da lista da determinada especialização. */
    if(strcmp(funcionario.especializacao, "Cardiologia") == 0){
        aux = lista_funcionarios->cardiologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Enfermagem") == 0){
        aux = lista_funcionarios->enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Neurologia") == 0){
        aux = lista_funcionarios->neurologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Ortopedia") == 0){
        aux = lista_funcionarios->ortopedia->inicio;
    } else if(strcmp(funcionario.especializacao, "Pediatria") == 0){
        aux = lista_funcionarios->pediatria->inicio;
    } else if(strcmp(funcionario.especializacao, "Pneumologia") == 0){
        aux = lista_funcionarios->pneumologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Tecnico em Enfermagem") == 0){
        aux = lista_funcionarios->tecnico_de_enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Trauma") == 0){
        aux = lista_funcionarios->trauma->inicio;
    } else{
        printf("Erro - Especializacao inserida e invalida\n");
        return;
    } 

    if(lista_vazia(lista_funcionarios, funcionario)){
        printf("Erro - Lista Vazia: Nao ha funcionario na lista a ser consultado.\n");
        return;
    }
    // Colocaremos todos os IDs e horas trabalhadas que estao na lista da especialização no vetor estático
    while(aux!=NULL){
        busca.id[busca.inicio] = aux->id;
        busca.horas_trabalhadas[busca.inicio] = aux->horas_trabalhadas;
        busca.inicio++;
        aux = aux->prox;
    }

    /* Busca sequencial: procuraremos o ID fornecido pelo usuário no vetor estático. Ao achar o ID, haverá a 
    verificação das horas trabalhadas do médico associado a tal ID. Se essas horas trabalhadas forem maior que 60 horas, 
    entao médico ja trabalhou o número máximo de horas. Caso contrário, ele ainda pode trabalhar mais horas. */
    for(i=0;i<=busca.inicio;i++){
        if(busca.id[i] == funcionario.id){
            aux1 = 1;
            if(busca.horas_trabalhadas[i] >=60){
                printf("O medico ja trabalhou o numero maximo de horas.\n");
            }else if(busca.horas_trabalhadas[i] < 60){
                printf("O medico nao trabalhou o numero maximo de horas.\nHoras trabalhada: %d\n", busca.horas_trabalhadas[i]);
            }
        }
    }
    if(aux1 == 0){
        printf("ID invalido!\n");
    }
    return;
}

/**
 * @brief Adiciona horas trabalhadas ao registro do funcionário.
 * 
 * Esta função atualiza o número de horas trabalhadas de um funcionário específico na estrutura de dados. Ela verifica a especialização do funcionário e procura o funcionário correspondente na lista adequada, adicionando as horas informadas ao registro.
 * 
 * @param lista_funcionarios Ponteiro para a estrutura Lista_funcionarios que contém as listas de especializações.
 * @param funcionario Struct com informações do funcionário.
 * @param horas Horas trabalhadas a serem adicionadas.
 */
void adicionar_horas(Lista_funcionarios *lista_funcionarios, Funcionario funcionario, int horas){
    Funcionario *aux = NULL;
    int aux1 = 0;
    
    // Verifica a especializacao do funcionário para determinar qual lista usar
    if(strcmp(funcionario.especializacao, "Cardiologia") == 0){
        aux = lista_funcionarios->cardiologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Enfermagem") == 0){
        aux = lista_funcionarios->enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Neurologia") == 0){
        aux = lista_funcionarios->neurologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Ortopedia") == 0){
        aux = lista_funcionarios->ortopedia->inicio;
    } else if(strcmp(funcionario.especializacao, "Pediatria") == 0){
        aux = lista_funcionarios->pediatria->inicio;
    } else if(strcmp(funcionario.especializacao, "Pneumologia") == 0){
        aux = lista_funcionarios->pneumologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Tecnico em Enfermagem") == 0){
        aux = lista_funcionarios->tecnico_de_enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Trauma") == 0){
        aux = lista_funcionarios->trauma->inicio;
    } else{
        printf("Erro - Especializacao inserida e invalida\n");
        return; // Encerra a função se a especializacao for inválida
    } 

    // Verifica se a lista está vazia
    if(lista_vazia(lista_funcionarios, funcionario)){
        printf("Erro - Lista Vazia: Nao ha funcionario na lista a ser consultado.\n");
        return; // Encerra a função se a lista estiver vazia
    } else {
        while(aux != NULL){
            if(aux->id == funcionario.id){
                aux1 = 1;
                // Adiciona as horas trabalhadas ao funcionário
                aux->horas_trabalhadas += horas;
            }
            aux = aux->prox;
        }
    }
    if(aux1 == 0){
        printf("ID invalido!\n");
    }
}

/**
 * @brief Limpa o buffer do teclado após entrada de dados.
 * 
 * Esta função descarta qualquer entrada de dados pendente no buffer do teclado, permitindo uma entrada limpa e consistente em futuras interações.
 */
void limpa_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

/**
 * @brief Verifica se um novo funcionário com o mesmo ID já foi inserido.
 * 
 * Esta função verifica se um funcionário com o mesmo ID já foi inserido na lista de funcionários da especialização correspondente. Ela percorre a lista procurando por correspondências de IDs e retorna 1 se um funcionário com o mesmo ID for encontrado, ou 0 caso contrário.
 * 
 * @param lista_funcionarios Ponteiro para a estrutura Lista_funcionarios que contém as listas de especializações.
 * @param funcionario Struct com informações do funcionário.
 * @return int Retorna 1 se o funcionário já foi inserido, ou 0 se não foi.
 */
int ja_foi_inserido(Lista_funcionarios *lista_funcionarios, Funcionario funcionario){

    Funcionario *aux = NULL;
    
     // Verifica a especializacao do funcionário para determinar qual lista usar
    if(strcmp(funcionario.especializacao, "Cardiologia") == 0){
        aux = lista_funcionarios->cardiologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Enfermagem") == 0){
        aux = lista_funcionarios->enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Neurologia") == 0){
        aux = lista_funcionarios->neurologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Ortopedia") == 0){
        aux = lista_funcionarios->ortopedia->inicio;
    } else if(strcmp(funcionario.especializacao, "Pediatria") == 0){
        aux = lista_funcionarios->pediatria->inicio;
    } else if(strcmp(funcionario.especializacao, "Pneumologia") == 0){
        aux = lista_funcionarios->pneumologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Tecnico de Enfermagem") == 0){
        aux = lista_funcionarios->tecnico_de_enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Trauma") == 0){
        aux = lista_funcionarios->trauma->inicio;
    } 
 
    // Verifica se o funcionário já foi inserido na lista
    while(aux != NULL){
        if(aux->id == funcionario.id){           
            return 1; // Retorna 1 se o funcionário já foi inserido      
        } 
        aux = aux->prox;
    }

    return 0; // Retorna 0 se o funcionário não foi inserido
}

/**
 * @brief Imprime informações dos funcionários de uma especialização.
 * 
 * Esta função imprime na tela informações detalhadas de todos os funcionários pertencentes à especialização fornecida. Ela percorre a lista de funcionários da especialização e exibe seus detalhes, incluindo ID, nome, especialização, horas trabalhadas e disponibilidade de turnos.
 * 
 * @param lista_funcionarios Ponteiro para a estrutura Lista_funcionarios que contém as listas de especializações.
 * @param funcionario Struct com informações do funcionário que servirá como referência para a especialização.
 */
void imprime(Lista_funcionarios *lista_funcionarios, Funcionario funcionario){
    Funcionario *aux = NULL;
    
    // Verifica a especializacao do funcionário para determinar qual lista usar
    if(strcmp(funcionario.especializacao, "Cardiologia") == 0){
        aux = lista_funcionarios->cardiologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Enfermagem") == 0){
        aux = lista_funcionarios->enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Neurologia") == 0){
        aux = lista_funcionarios->neurologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Ortopedia") == 0){
        aux = lista_funcionarios->ortopedia->inicio;
    } else if(strcmp(funcionario.especializacao, "Pediatria") == 0){
        aux = lista_funcionarios->pediatria->inicio;
    } else if(strcmp(funcionario.especializacao, "Pneumologia") == 0){
        aux = lista_funcionarios->pneumologia->inicio;
    } else if(strcmp(funcionario.especializacao, "Tecnico em Enfermagem") == 0){
        aux = lista_funcionarios->tecnico_de_enfermagem->inicio;
    } else if(strcmp(funcionario.especializacao, "Trauma") == 0){
        aux = lista_funcionarios->trauma->inicio;
    } else{
        printf("Erro - Especializacao inserida e invalida\n");
        return;
    }

    // Verifica se a lista está vazia
    if(lista_vazia(lista_funcionarios, funcionario)){
        printf("Erro - Lista Vazia: Nao ha funcionario na lista a ser consultado.\n");
        return;
    }

    // Avança pela lista de Funcionarios e imprime suas informações
    while(aux!=NULL){
        printf("\n----ID: %d----\n", aux->id);
        printf("Nome: %s\n", aux->nome);
        printf("Especializacao: %s\n", aux->especializacao);
        printf("Horas trabalhadas: %d\n", aux->horas_trabalhadas);
        printf("Disponibilidade: ");
        if(aux->disponibilidade[0] == 1){
            printf("Manha - Sim/");
        } else{
            printf("Manha - Nao/");
        }
        if(aux->disponibilidade[1] == 1){
            printf(" Tarde - Sim/");
        } else{
            printf(" Tarde - Nao/");
        }
        if(aux->disponibilidade[2] == 1){
            printf(" Noite - Sim\n");
        } else{
            printf(" Noite - Nao\n");
        }
        printf("Trabalha na manha? ");
        if(aux->manha == 1){
            printf("Sim\n");
        } else{
            printf("Nao\n");
        }
        printf("Trabalha na tarde? ");
        if(aux->tarde == 1){
            printf("Sim\n");
        } else{
            printf("Nao\n");
        }
        printf("Trabalha na noite? ");
        if(aux->noite == 1){
            printf("Sim\n");
        } else{
            printf("Nao\n");
        }
        aux=aux->prox;
    }
}

/**
 * @brief Libera a memória alocada para as listas de funcionários.
 * 
 * Esta função libera a memória alocada para cada lista de funcionários pertencente a diferentes especializações. Ela percorre todas as listas e seus nós de funcionários, liberando a memória antes de encerrar o programa.
 * 
 * @param lista_funcionarios Ponteiro para a estrutura Lista_funcionarios que contém as listas de especializações.
 */
void libera_memoria(Lista_funcionarios *lista_funcionarios){
    Funcionario *aux = lista_funcionarios->neurologia->inicio;
    Funcionario *aux2;

    // Percorre a lista de neurologia e libera a memória para cada funcionário
    while(aux != NULL){
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }

    // Repete o processo para cada departamento
    aux = lista_funcionarios->cardiologia->inicio;

    while(aux != NULL){
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }

    aux = lista_funcionarios->trauma->inicio;

    while(aux != NULL){
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }

    aux = lista_funcionarios->pediatria->inicio;

    while(aux != NULL){
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }

    aux = lista_funcionarios->enfermagem->inicio;

    while(aux != NULL){
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }

    aux = lista_funcionarios->pneumologia->inicio;

    while(aux != NULL){
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }

    aux = lista_funcionarios->ortopedia->inicio;

    while(aux != NULL){
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }

    aux = lista_funcionarios->tecnico_de_enfermagem->inicio;

    while(aux != NULL){
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }

    return;
}

/**
 * @brief Função que vai efetivamente fazer a ordenação do Merge Sort.
 * 
 * @param vetor vetor estático
 * @param inicio início do vetor
 * @param meio meio do vetor (inicio+(fim-inicio)/2)
 * @param fim fim do vetor (tamanho do vetor - 1)
 */
void merge(Lista_funcionarios_estatica *vetor, int inicio, int meio, int fim){
    int tamanhoEsquerdo = meio-inicio+1;
    int tamanhoDireito = fim-meio;
    int i, t, j, k;

    
    char** esquerdo = (char**) malloc(tamanhoEsquerdo*sizeof(char*));
    char** direito = (char**) malloc(tamanhoDireito*sizeof(char*));

    for(t=0;t<tamanhoEsquerdo;t++){
        esquerdo[t] = (char*) malloc(sizeof(vetor->nome[inicio+t]));
    }
    for(t=0;t<tamanhoDireito;t++){
        direito[t] = (char*) malloc(sizeof(vetor->nome[meio+t+1]));
    }


    for(i=0;i<tamanhoEsquerdo;i++){
        strcpy(esquerdo[i],vetor->nome[inicio+i]);
    }
    for(j=0;j<tamanhoDireito;j++){
        strcpy(direito[j],vetor->nome[meio+1+j]);
    }
    
    i = 0; 
    j = 0;
    k = inicio; 

    while(i<tamanhoEsquerdo&&j<tamanhoDireito){
        if(strcmp(esquerdo[i],direito[j])<=0){
            strcpy(vetor->nome[k],esquerdo[i]);
            i++;
        }else{
            strcpy(vetor->nome[k],direito[j]);
            j++;
        }
        k++;
    }

    
    while(i<tamanhoEsquerdo){
        strcpy(vetor->nome[k],esquerdo[i]);
        i++;
        k++;
    }

    
    while(j<tamanhoDireito){
        strcpy(vetor->nome[k],direito[j]);
        j++;
        k++;
    }

    for(t=0;t<tamanhoEsquerdo;t++) free(esquerdo[t]);
    free(esquerdo);
    for(t=0;t<tamanhoDireito;t++) free(direito[t]);
    free(direito);
}

/**
 * @brief Função de ordenação Merge Sort. O vetor e dividido em duas partes iguais, que serão 
 * sucessivamente divididas até que reste apenas um ou dois elementos em cada parte. Quando isso 
 * ocorrer, ordena-se essas partes. Após isso, deve-se juntar tais partes. Na junção, os dois 
 * elementos de cada parte são separados e o menor deles é retirado de sua parte. Após isso, os 
 * menores entre os restantes são comparados e assim se prossegue até juntar as partes.
 * 
 * @param vetor vetor estático
 * @param inicio inicio do vetor (0)
 * @param fim fim do vetor (tamanho do vetor - 1)
 */
void mergeSort(Lista_funcionarios_estatica *vetor, int inicio, int fim){
    if(inicio<fim){
        int meio = inicio+(fim-inicio)/2;

        mergeSort(vetor,inicio,meio);
        mergeSort(vetor,meio+1,fim);

        merge(vetor,inicio,meio,fim);
    }
}

/**
 * @brief Função para ordenar nomes de médicos de determinada especialidade com o uso Merge Sort (algoritmo de ordenação eficiente).
 * 
 * @param lista_funcionarios lista dinâmica contendo todas as listas de especialização.
 * @param especializacao nome da especialização do médico que o usuário deseja buscar.
 */
void ordena_nome(Lista_funcionarios *lista_funcionarios, Funcionario funcionario){
    Funcionario *aux; // ponteiro auxiliar para percorrer a lista
    Lista_funcionarios_estatica busca; // vetor estático
    int i, tam; // contador i usado no for e tamanho tam do vetor estático

    busca.inicio = 0; // inicialização do índice vetor estático

    /* Comparação da especialidade digitada pelo usuário com o nome da especialização em si. Ao achar a especialização, o ponteiro auxiliar 
    apontará para o primeiro elemento da lista da determinada especialização. */
    if(strcmp(funcionario.especializacao, "Cardiologia") == 0){
        aux = lista_funcionarios->cardiologia->inicio;
    }
    else if(strcmp(funcionario.especializacao, "Enfermagem") == 0){
        aux = lista_funcionarios->enfermagem->inicio;
    }
    else if(strcmp(funcionario.especializacao, "Ortopedia") == 0){
        aux = lista_funcionarios->ortopedia->inicio;
    }
    else if(strcmp(funcionario.especializacao, "Pneumologia") == 0){
        aux = lista_funcionarios->pneumologia->inicio;
    }
    else if(strcmp(funcionario.especializacao, "Tecnico em Enfermagem") == 0){
        aux = lista_funcionarios->tecnico_de_enfermagem->inicio;
    }
    else if(strcmp(funcionario.especializacao, "Trauma") == 0){
        aux = lista_funcionarios->trauma->inicio;
    }
    else if(strcmp(funcionario.especializacao, "Neurologia") == 0){
        aux = lista_funcionarios->neurologia->inicio;
    }
    else if(strcmp(funcionario.especializacao, "Pediatria") == 0){
        aux = lista_funcionarios->pediatria->inicio;
    } else{
        printf("Erro - Especializacao inserida e invalida\n");
        return;
    }

    if(lista_vazia(lista_funcionarios, funcionario)){
        printf("Erro - Lista Vazia: Nao ha funcionario na lista a ser consultado.\n");
        return;
    }

    // Colocaremos todos os nomes dos médicos que estão na lista da especialização no vetor estático
    while(aux!=NULL){
        strcpy(busca.nome[busca.inicio],aux->nome);
        busca.inicio++;
        aux = aux->prox;
    }

    tam = busca.inicio; // tam vai receber o tamnho do vetor estático

    mergeSort(&busca,0,tam-1); // uso do algoritmo de ordenação Merge Sort para ordenar os nomes

    // Impressão dos nomes ordenados do vetor estático
    printf("\nOs nomes ordenados dos medicos da especializacao %s sao:\n", funcionario.especializacao);
    for(i=0;i<tam;i++) printf("%s\n", busca.nome[i]);
}

/**
 * @brief Ordena um array de ponteiros para Funcionário pelo salário de forma decrescente usando o algoritmo Bubble Sort.
 * 
 * Essa função realiza a ordenação de um array de ponteiros para a estrutura "Funcionario" em ordem decrescente com base no salário.
 * Utiliza o algoritmo Bubble Sort para realizar as trocas necessárias entre os elementos do array.
 * 
 * @param arr Um array de ponteiros para a estrutura "Funcionario" que será ordenado.
 * @param n O número de elementos no array.
 */
void bubbleSort(Funcionario **arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j]->salario < arr[j + 1]->salario) {
                // Troca os ponteiros de Funcionario
                Funcionario *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * @brief Ordena os funcionários por especialização e calcula os salários com base nas horas trabalhadas e adicional noturno.
 * 
 * Esta função recebe uma lista de funcionários e a especialização de um funcionário específico.
 * Ela calcula os salários dos funcionários com base nas horas trabalhadas e adicionais noturnos,
 * e depois ordena os funcionários por especialização e exibe os resultados ordenados.
 * 
 * @param lista_funcionarios Um ponteiro para uma estrutura que contém listas de funcionários de diferentes especializações.
 * @param funcionario Uma estrutura que contém informações do funcionário a ser consultado.
 */
void calcula_salario (Lista_funcionarios *lista_funcionarios, Funcionario funcionario){
    Funcionario *aux = NULL;

    
    float horaE = 60;//hora enfermagem.
    float adicionalE = 30;// adicional noturno;
    float horaM = 120;//hora medico;
    float adicionalM = 60;// adicional noturno;
    float horaT = 40;//hora tecnico;
    float adicionalT = 20; //adicional hora tec;

    float calculo = 0;
    
    if(strcmp(funcionario.especializacao, "Cardiologia") == 0){
        aux = lista_funcionarios->cardiologia->inicio;

        if(lista_vazia(lista_funcionarios, funcionario)){
            printf("Erro - Lista Vazia: Nao ha funcionario na lista a ser consultado.\n");
            return;
        }
        
        int numFuncionarios = 0;
        while(aux != NULL){
            if(aux->manha == 1|| aux->tarde == 1){
                aux->salario += horaM*aux->horas_trabalhadas;
            }else if(aux->noite == 1){
                aux->salario += horaM*aux->horas_trabalhadas + adicionalM;
            }
            numFuncionarios++;
            aux = aux->prox;   
        }  

        Funcionario *funcArr[numFuncionarios];
        aux = lista_funcionarios->cardiologia->inicio;
        int index = 0;
        while (aux != NULL) {
            funcArr[index] = aux;
            aux = aux->prox;
            index++;
        }

        bubbleSort(funcArr, numFuncionarios);

        printf("Funcionarios ordenados por especializacao:\n");
        for (int i = 0; i < numFuncionarios; i++) {
            printf("ID: %d, Especializacao: %s, Salario: %.2f\n",
            funcArr[i]->id, funcArr[i]->especializacao, funcArr[i]->salario);
        }


    }else if(strcmp(funcionario.especializacao, "Enfermagem") == 0){
        aux = lista_funcionarios->enfermagem->inicio;

                if(lista_vazia(lista_funcionarios, funcionario)){
            printf("Erro - Lista Vazia: Nao ha funcionario na lista a ser consultado.\n");
            return;
        }
        
        int numFuncionarios = 0;
        while(aux != NULL){
            if(aux->manha == 1|| aux->tarde == 1){
                aux->salario += horaM*aux->horas_trabalhadas;
            }else if(aux->noite == 1){
                aux->salario += horaM*aux->horas_trabalhadas + adicionalM;
            }
            numFuncionarios++;
            aux = aux->prox;   
        }  

        Funcionario *funcArr[numFuncionarios];
        aux = lista_funcionarios->enfermagem->inicio;
        int index = 0;
        while (aux != NULL) {
            funcArr[index] = aux;
            aux = aux->prox;
            index++;
        }

        bubbleSort(funcArr, numFuncionarios);

        printf("Funcionarios ordenados por especializacao:\n");
        for (int i = 0; i < numFuncionarios; i++) {
            printf("ID: %d, Especializacao: %s, Salario: %.2f\n",
            funcArr[i]->id, funcArr[i]->especializacao, funcArr[i]->salario);
        }
    }else if(strcmp(funcionario.especializacao, "Neurologia") == 0){
        aux = lista_funcionarios->neurologia->inicio;

        if(lista_vazia(lista_funcionarios, funcionario)){
            printf("Erro - Lista Vazia: Nao ha funcionario na lista a ser consultado.\n");
            return;
        }
        
        int numFuncionarios = 0;
        while(aux != NULL){
            if(aux->manha == 1|| aux->tarde == 1){
                aux->salario += horaM*aux->horas_trabalhadas;
            }else if(aux->noite == 1){
                aux->salario += horaM*aux->horas_trabalhadas + adicionalM;
            }
            numFuncionarios++;
            aux = aux->prox;   
        }  

        Funcionario *funcArr[numFuncionarios];
        aux = lista_funcionarios->neurologia->inicio;
        int index = 0;
        while (aux != NULL) {
            funcArr[index] = aux;
            aux = aux->prox;
            index++;
        }

        bubbleSort(funcArr, numFuncionarios);

        printf("Funcionarios ordenados por especializacao:\n");
        for (int i = 0; i < numFuncionarios; i++) {
            printf("ID: %d, Especializacao: %s, Salario: %.2f\n",
            funcArr[i]->id, funcArr[i]->especializacao, funcArr[i]->salario);
        }   
    }else if(strcmp(funcionario.especializacao, "Ortopedia") == 0){
        aux = lista_funcionarios->ortopedia->inicio;

        if(lista_vazia(lista_funcionarios, funcionario)){
            printf("Erro - Lista Vazia: Nao ha funcionario na lista a ser consultado.\n");
            return;
        }
        
        int numFuncionarios = 0;
        while(aux != NULL){
            if(aux->manha == 1|| aux->tarde == 1){
                aux->salario += horaM*aux->horas_trabalhadas;
            }else if(aux->noite == 1){
                aux->salario += horaM*aux->horas_trabalhadas + adicionalM;
            }
            numFuncionarios++;
            aux = aux->prox;   
        }  

        Funcionario *funcArr[numFuncionarios];
        aux = lista_funcionarios->ortopedia->inicio;
        int index = 0;
        while (aux != NULL) {
            funcArr[index] = aux;
            aux = aux->prox;
            index++;
        }

        bubbleSort(funcArr, numFuncionarios);

        printf("Funcionarios ordenados por especializacao:\n");
        for (int i = 0; i < numFuncionarios; i++) {
            printf("ID: %d, Especializacao: %s, Salario: %.2f\n",
            funcArr[i]->id, funcArr[i]->especializacao, funcArr[i]->salario);
        }  
    }else if(strcmp(funcionario.especializacao, "Pneumologia") == 0){
        aux = lista_funcionarios->pneumologia->inicio;

        if(lista_vazia(lista_funcionarios, funcionario)){
            printf("Erro - Lista Vazia: Nao ha funcionario na lista a ser consultado.\n");
            return;
        }
        
        int numFuncionarios = 0;
        while(aux != NULL){
            if(aux->manha == 1|| aux->tarde == 1){
                aux->salario += horaM*aux->horas_trabalhadas;
            }else if(aux->noite == 1){
                aux->salario += horaM*aux->horas_trabalhadas + adicionalM;
            }
            numFuncionarios++;
            aux = aux->prox;   
        }  

        Funcionario *funcArr[numFuncionarios];
        aux = lista_funcionarios->pneumologia->inicio;
        int index = 0;
        while (aux != NULL) {
            funcArr[index] = aux;
            aux = aux->prox;
            index++;
        }

        bubbleSort(funcArr, numFuncionarios);

        printf("Funcionarios ordenados por especializacao:\n");
        for (int i = 0; i < numFuncionarios; i++) {
            printf("ID: %d, Especializacao: %s, Salario: %.2f\n",
            funcArr[i]->id, funcArr[i]->especializacao, funcArr[i]->salario);
        }  
    }else if(strcmp(funcionario.especializacao, "Tecnico em Enfermagem") == 0){
        aux = lista_funcionarios->tecnico_de_enfermagem->inicio;

        if(lista_vazia(lista_funcionarios, funcionario)){
            printf("Erro - Lista Vazia: Nao ha funcionario na lista a ser consultado.\n");
            return;
        }
        
        int numFuncionarios = 0;
        while(aux != NULL){
            if(aux->manha == 1|| aux->tarde == 1){
                aux->salario += horaM*aux->horas_trabalhadas;
            }else if(aux->noite == 1){
                aux->salario += horaM*aux->horas_trabalhadas + adicionalM;
            }
            numFuncionarios++;
            aux = aux->prox;   
        }  

        Funcionario *funcArr[numFuncionarios];
        aux = lista_funcionarios->tecnico_de_enfermagem->inicio;
        int index = 0;
        while (aux != NULL) {
            funcArr[index] = aux;
            aux = aux->prox;
            index++;
        }

        bubbleSort(funcArr, numFuncionarios);

        printf("Funcionarios ordenados por especializacao:\n");
        for (int i = 0; i < numFuncionarios; i++) {
            printf("ID: %d, Especializacao: %s, Salario: %.2f\n",
            funcArr[i]->id, funcArr[i]->especializacao, funcArr[i]->salario);
        }   
    }else if(strcmp(funcionario.especializacao, "Trauma") == 0){
        aux = lista_funcionarios->trauma->inicio;

        if(lista_vazia(lista_funcionarios, funcionario)){
            printf("Erro - Lista Vazia: Nao ha funcionario na lista a ser consultado.\n");
            return;
        }
        
        int numFuncionarios = 0;
        while(aux != NULL){
            if(aux->manha == 1|| aux->tarde == 1){
                aux->salario += horaM*aux->horas_trabalhadas;
            }else if(aux->noite == 1){
                aux->salario += horaM*aux->horas_trabalhadas + adicionalM;
            }
            numFuncionarios++;
            aux = aux->prox;   
        }  

        Funcionario *funcArr[numFuncionarios];
        aux = lista_funcionarios->trauma->inicio;
        int index = 0;
        while (aux != NULL) {
            funcArr[index] = aux;
            aux = aux->prox;
            index++;
        }

        bubbleSort(funcArr, numFuncionarios);

        printf("Funcionarios ordenados por especializacao:\n");
        for (int i = 0; i < numFuncionarios; i++) {
            printf("ID: %d, Especializacao: %s, Salario: %.2f\n",
            funcArr[i]->id, funcArr[i]->especializacao, funcArr[i]->salario);
        }
    } else{
        printf("Erro - Especializacao inserida e invalida\n");
        return;
    }
}