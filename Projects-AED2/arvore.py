TAMANHO_STRING = 100
COMANDO_LIMPAR_CONSOLE = "cls"  # Para Windows: "cls"; Para Linux: "clear"


class Arvore:
    def __init__(self):
        self.nome = ""
        self.nomeConjuge = ""
        self.filhos = None
        self.quantidadeFilhos = 0


def lerDadosArvore(raiz, nivel):
    identacao = ""
    for i in range(nivel):
        identacao += "|" # Cria uma string de identação para exibir a geração correta
    print(f"{identacao}-Geracao {nivel}") # Imprime a geração atual da árvore   

     # Enquanto o nome da pessoa estiver vazio, solicita o preenchimento do nome
    while len(raiz.nome) == 0:
        raiz.nome = input(f"{identacao} Nome da pessoa: ")
        # Solicita o nome do cônjuge, caso não tenha, é deixado em branco
    raiz.nomeConjuge = input(f"{identacao} Nome do conjuge (deixe em branco caso nao tenha): ")

    raiz.filhos = None  # Inicializa a lista de filhos como nula
    raiz.quantidadeFilhos = 0  # Inicializa a quantidade de filhos como zero
    
    adicionarFilhos = True # Variável de controle para adicionar filhos

    while adicionarFilhos:
        lerFilho = input(f"{identacao} Deseja registrar filho? ('s' ou 'n'): ")
        if lerFilho == 's' or lerFilho == 'S':
            # Chamar recursivo para a geração dos filhos:
            filho = Arvore()
            lerDadosArvore(filho, nivel + 1)  # Chama a função para o próximo nível

            # Adiciona o filho no vetor:
            if raiz.filhos is None:
                raiz.filhos = [Arvore()]
            else:
                raiz.filhos.append(Arvore())
            raiz.filhos[raiz.quantidadeFilhos] = filho
            raiz.quantidadeFilhos += 1 # Incrementa a quantidade de filhos
        elif lerFilho == 'n' or lerFilho == 'N':
            adicionarFilhos = False  # Finaliza o processo de adição de filhos
        else:
            print("Opcao invalida! Digite 's' para sim ou 'n' para nao.")

def imprimirArvore(raiz, nivel):
    if raiz is None:
        return # Se a raiz for nula, não há nada para imprimir
    identacao = "|" # Inicializa a string de identação com o caractere "|"
    for i in range(1, nivel):
        identacao += "|"  # Adiciona barras verticais para criar a identação de acordo com o nível
    if len(raiz.nomeConjuge) == 0:
        print("%s+%s \n" % (identacao, raiz.nome)) # Imprime o nome da pessoa se não houver cônjuge
    else:
        print("%s-%s & %s \n" % (identacao, raiz.nome, raiz.nomeConjuge)) # Imprime o nome e o cônjuge
        
    # Se houver filhos, chama recursivamente a função para imprimir os filhos
    if raiz.filhos is not None:
        for i in range(raiz.quantidadeFilhos):
            imprimirArvore(raiz.filhos[i], nivel + 1)  # Chama a função para imprimir os filhos com um nível a mais


def exibirPais(raiz, nome):
     # Verifica se o nome da pessoa procurada está no nó raiz atual.
    for i in range(raiz.quantidadeFilhos):
        if raiz.filhos[i].nome == nome:  # Verifica se o nome corresponde ao de algum filho
            # Se encontrar, imprime os pais dessa pessoa
            print(" => Os pais de %s sao %s e %s \n" % (nome, raiz.nome, raiz.nomeConjuge))
            return 1  # Retorna 1 para indicar que a pessoa foi encontrada

     # Se não encontrou nos filhos do nó raiz atual, chama recursivamente para os filhos
    for i in range(raiz.quantidadeFilhos):
        resultadoRecursivo = exibirPais(raiz.filhos[i], nome)
        if resultadoRecursivo == 1: # Se encontrou nas chamadas recursivas
            return 1 # Retorna 1 indicando que a pessoa foi encontrada em níveis abaixo

    return 0 # Retorna 0 para indicar que a pessoa não foi encontrada na árvore


def exibirFilhos(raiz, nome):
    i = 0
    # Verifica se o nome da pessoa procurada esta no noh raiz atual.
    if (raiz.nome == nome or raiz.nomeConjuge == nome):
        # Verifica se a pessoa eh casada:
        if (len(raiz.nomeConjuge) == 0):
            print(" => %s nao eh casado(a)." % raiz.nome)
        elif (raiz.quantidadeFilhos == 0):  # Verifica se a pessoa possui filhos:
            print(" => %s e %s nao possuem filhos." % (raiz.nome, raiz.nomeConjuge))
        else:
            # Itera pelos filhos exibindo-os:
            print(" => Os filhos de %s e %s sao: \n" % (raiz.nome, raiz.nomeConjuge))
            for i in range(raiz.quantidadeFilhos):
                print("     - %s \n" % raiz.filhos[i].nome)
        return 1  # Retorna 1 indicando que ja encontrou a pessoa.
    elif (raiz.quantidadeFilhos > 0):
        for i in range(raiz.quantidadeFilhos):
            # Verifica se encontrou na chamada recursiva para nao continuar a busca:
            resultadoRecursivo = exibirFilhos(raiz.filhos[i], nome)
            if (resultadoRecursivo == 1):
                return 1
            # Caso nao tenha encontrado continua a busca.
    # Nao encontrou:
    return 0


"""Exibe os avos de uma pessoa, se estivere na Arvore.
 * @Parametro: raiz - Raiz da Arvore.
 * @Parametro: nome - Nome da pessoa que tem os avos procurados na Arvore.
 * @Retorno: 1 - caso tenha encontrado a pessoa. 0 - caso nao tenha encontrado.
 """


def exibirAvos(raiz, nome):
    i = 0
    j = 0
    filho = None
    # Procura nos netos do noh 'raiz' pela pessoa. Se achar, entao os avos sao noh 'raiz'
    for i in range(raiz.quantidadeFilhos):
        filho = raiz.filhos[i]
        for j in range(filho.quantidadeFilhos):
            if (filho.filhos[j].nome == nome):
                print(" => Os avos de %s sao %s e %s \n" % (nome, raiz.nome, raiz.nomeConjuge))
                return 1
    # Chama recursivamente para procurar a pessoa nos niveis abaixo da Arvore:
    for i in range(raiz.quantidadeFilhos):
        # Verifica se encontrou na chamada recursiva para nao continuar a busca:
        resultadoRecursivo = exibirAvos(raiz.filhos[i], nome)
        if (resultadoRecursivo == 1):
            return 1  # Retorna 1 indicando que ja encontrou a pessoa.
    # Nao encontrou:
    return 0


def exibirNetos(raiz, nome):
    i = 0
    j = 0
    filho = None
    possuiNetos = 0
    # Verifica se o nome da pessoa procurada esta no noh raiz atual.
    if (raiz.nome == nome or raiz.nomeConjuge == nome):
        # Verifica se a pessoa eh casada:
        if (len(raiz.nomeConjuge) == 0):
            print(" => %s nao eh casado(a)." % raiz.nome)
        else:
            # Verifica se a pessoa possui netos:
            for i in range(raiz.quantidadeFilhos):
                if (raiz.filhos[i].quantidadeFilhos > 0):
                    possuiNetos = 1
                    break
            if (possuiNetos == 0):
                print(" => %s e %s nao possuem netos." % (raiz.nome, raiz.nomeConjuge))
            else:
                # Itera pelos netos exibindo-os:
                print(" => Os netos de %s e %s sao: \n" % (raiz.nome, raiz.nomeConjuge))
                for i in range(raiz.quantidadeFilhos):
                    filho = raiz.filhos[i]
                    for j in range(filho.quantidadeFilhos):
                        print("     - %s \n" % filho.filhos[j].nome)
                return 1  # Retorna 1 indicando que ja encontrou a pessoa.
    elif (raiz.quantidadeFilhos > 0):
        for i in range(raiz.quantidadeFilhos):
            # Verifica se encontrou na chamada recursiva para nao continuar a busca:
            resultadoRecursivo = exibirNetos(raiz.filhos[i], nome)
            if (resultadoRecursivo == 1):
                return 1
            # Caso nao tenha encontrado continua a busca.
    # Nao encontrou:
    return 0


"""Exibe os tios de uma pessoa, se estivere na Arvore.
 * @Parametro: raiz - Raiz da Arvore.
 * @Parametro: nome - Nome da pessoa que tem os tios procurados na Arvore.
 * @Retorno: 1 - caso tenha encontrado a pessoa. 0 - caso nao tenha encontrado.
 """


def exibirTios(raiz, nome):
    i = 0
    j = 0
    encontrouPessoa = 0
    paiPessoa = None
    tio = None

    """ Procura nos netos do noh 'raiz' pela pessoa. Se achar, entao os tios
     * sao os filhos de 'raiz' exceto os pais da pessoa procurada.
     """
    for i in range(raiz.quantidadeFilhos):
        paiPessoa = raiz.filhos[i]
        for j in range(paiPessoa.quantidadeFilhos):
            # Verifica se encontrou a pessoa:
            if (paiPessoa.filhos[j].nome == nome):
                encontrouPessoa = 1
                break
        if (encontrouPessoa):  # Para a iteracao se tiver encontrado a pessoa.
            break

    # Se encontrou a pessoa, exibe os tios dela, se houverem:
    if (encontrouPessoa):
        if (raiz.quantidadeFilhos == 1):
            print(" => %s nao possui tios." % nome)
        else:
            print(" => Os tios de %s sao: \n" % nome)
            # Itera pelos tios da pessoa (filhos do avo, exceto os pais da pessoa):
            for i in range(raiz.quantidadeFilhos):
                tio = raiz.filhos[i]
                if (tio == paiPessoa):  # Se eh o pai da pessoa, pula.
                    continue
                print("     - %s \n" % tio.nome)
                if (len(tio.nomeConjuge) > 0):
                    print("     - %s \n" % tio.nomeConjuge)
            return 1

    # Chama recursivamente para procurar a pessoa nos niveis abaixo da Arvore:
    for i in range(raiz.quantidadeFilhos):
        # Verifica se encontrou na chamada recursiva para nao continuar a busca:
        resultadoRecursivo = exibirTios(raiz.filhos[i], nome)
        if (resultadoRecursivo == 1):
            return 1  # Retorna 1 indicando que ja encontrou a pessoa.
    # Nao encontrou:
    return 0


def exibirPrimos(raiz, nome):
    encontrouPessoa = 0
    possuiNetos = 0
    paiPessoa = None
    tio = None

    # Procura nos netos do noh 'raiz' pela pessoa. Se achar, entao os primos
    # sao os filhos dos filhos de 'raiz' exceto os irmaos da pessoa.
    for i in range(raiz.quantidadeFilhos):
        paiPessoa = raiz.filhos[i]
        for j in range(paiPessoa.quantidadeFilhos):
            # Verifica se encontrou a pessoa:
            if paiPessoa.filhos[j].nome == nome:
                encontrouPessoa = 1
                break
        if encontrouPessoa:  # Para a iteracao se tiver encontrado a pessoa.
            break

    # Se encontrou a pessoa, exibe os primos dela, se houverem:
    if encontrouPessoa:
        for i in range(raiz.quantidadeFilhos):
            if raiz.filhos[i].quantidadeFilhos > 0:
                possuiNetos = 1
        if possuiNetos == 0:
            print(" => %s nao possui primos." % nome)
        else:
            print(" => Os primos de %s sao: \n" % nome)
            # Itera pelos tios da pessoa (filhos do avo, exceto os pais da pessoa):
            for i in range(raiz.quantidadeFilhos):
                tio = raiz.filhos[i]
                if tio == paiPessoa:  # Se eh o pai da pessoa, pula.
                    continue
                for j in range(tio.quantidadeFilhos):
                    print("     - %s \n" % tio.filhos[j].nome)

        return 1

    # Chama recursivamente para procurar a pessoa nos niveis abaixo da Arvore:
    for i in range(raiz.quantidadeFilhos):
        # Verifica se encontrou na chamada recursiva para nao continuar a busca:
        resultadoRecursivo = exibirPrimos(raiz.filhos[i], nome)
        if resultadoRecursivo == 1:
            return 1  # Retorna 1 indicando que ja encontrou a pessoa.

    # Nao encontrou:
    return 0
# Solicita a digitacao do nome de uma pessoa.
# @Retorno: Nome da pessoa digitada.
def solicitarNome():
    nome = input("Digite o nome da pessoa: ")
    print("\n")
    return nome

def main():
    opcao = -1  # Inicialização para garantir que o loop inicie
    retornoAux = 0
    raiz = None
    nomeAux = None

    while opcao != 0:
        print("=== ARVORE GENEALOGICA === \n")
        print(" 1 - Criar nova Arvore Genealogica \n")
        print(" 2 - Imprimir Arvore Genealogica \n")
        print(" 3 - Exibir pais de uma pessoa \n")
        print(" 4 - Exibir filhos de uma pessoa \n")
        print(" 5 - Exibir avos de uma pessoa \n")
        print(" 6 - Exibir netos de uma pessoa \n")
        print(" 7 - Exibir tios de uma pessoa \n")
        print(" 8 - Exibir primos de primeiro grau de uma pessoa \n")
        print(" 0 - Finalizar \n")
        print(" => Digite a opcao: ")
        opcao = int(input())

        # Verifica se digitou uma opcao inválida:
        if not (0 <= opcao <= 8):
            print("Opcao invalida!\n")
            continue

        # Inicializa a raiz, se necessário:
        if raiz is None and 3 <= opcao <= 8:
            print(" => Voce deve criar ou ler de um arquivo uma Arvore Genealogica "
                  "antes de utilizar as operacoes de 3 a 9!\n")
            continue

        if opcao == 1:
            print(" => Preencha a Arvore Genealogica: \n")
            raiz = Arvore()
            lerDadosArvore(raiz, 1)
            print(" => Fim da leitura.\n")

        elif opcao == 2:
            print(" => Exibicao da Arvore Genealogica: \n")
            imprimirArvore(raiz, 1)

        elif 3 <= opcao <= 8:
            nomeAux = solicitarNome()
            if opcao == 3:
                retornoAux = exibirPais(raiz, nomeAux)
            elif opcao == 4:
                retornoAux = exibirFilhos(raiz, nomeAux)
            elif opcao == 5:
                retornoAux = exibirAvos(raiz, nomeAux)
            elif opcao == 6:
                retornoAux = exibirNetos(raiz, nomeAux)
            elif opcao == 7:
                retornoAux = exibirTios(raiz, nomeAux)
            elif opcao == 8:
                retornoAux = exibirPrimos(raiz, nomeAux)

            if retornoAux == 0:
                print(" => %s nao foi encontrado na Arvore ou nao possui os parentes procurados.\n" % nomeAux)

                
if __name__ == "__main__":
    main()