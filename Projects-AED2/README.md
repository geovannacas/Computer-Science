# 1. Projeto Árvore Genealógica

- Este programa em Python implementa uma árvore genealógica interativa e permite criar, visualizar e consultar informações sobre uma árvore genealógica, como pais, filhos, avós, netos, tios e primos

## Funcionalidades:

**Classe Arvore:**
Representa um nó na árvore genealógica e armazena informações sobre uma pessoa, seu cônjuge e filhos.

**Função lerDadosArvore:**
Solicita ao usuário informações sobre uma pessoa, incluindo seu nome, cônjuge e filhos. Usa recursão para lidar com os filhos.

**Função imprimirArvore:**
Exibe a árvore genealógica de maneira hierárquica, mostrando gerações e relacionamentos.

**Função exibirPais:**
Dado o nome de uma pessoa, encontra e exibe os pais dessa pessoa na árvore.

**Função exibirFilhos:**
Dado o nome de uma pessoa, encontra e exibe os filhos dessa pessoa na árvore.

**Função exibirAvos:**
Dado o nome de uma pessoa, encontra e exibe os avós dessa pessoa na árvore.

**Função exibirNetos:**
Dado o nome de uma pessoa, encontra e exibe os netos dessa pessoa na árvore.

**Função exibirTios:**
Dado o nome de uma pessoa, encontra e exibe os tios dessa pessoa na árvore.

**Função exibirPrimos:**
Dado o nome de uma pessoa, encontra e exibe os primos de primeiro grau dessa pessoa na árvore.

**Função solicitarNome:**
Solicita ao usuário o nome de uma pessoa.

**Função main:**
Implementa um menu interativo para realizar operações na árvore genealógica.

**Criar Nova Árvore:**
Selecione a opção 1 no menu e siga as instruções para preencher a árvore genealógica.

**Visualizar Árvore:**
Escolha a opção 2 para visualizar a árvore genealógica hierarquicamente.

**Consultar Informações:**
Utilize as opções de 3 a 8 para consultar informações específicas sobre os membros da família.

**Finalizar:**
Para encerrar o programa, escolha a opção 0.

# 2. Tabela Hash

- Este é um exemplo de implementação de uma tabela hash em Python, com funcionalidades básicas como inserção, pesquisa, remoção e outras operações.

- Uma tabela hash é uma estrutura de dados que permite armazenar e recuperar dados de forma eficiente, mapeando chaves para valores. 

## Funcionalidades:

A **classe Node** representa os elementos individuais que serão armazenados na tabela hash. Cada nó contém uma chave e um valor associado, além de uma referência para o próximo nó na lista encadeada.

A **classe HashTable** é a estrutura principal que contém a lógica para inserir, pesquisar, remover e gerenciar os elementos na tabela hash. Ela mantém uma matriz (ou lista) de nós, onde cada índice corresponde a um possível valor de hash.

A **função _hash(self, key)** é responsável por calcular o valor hash para uma chave específica. Nesta implementação, a função soma os valores ASCII dos caracteres na chave e faz o módulo do resultado pelo tamanho da tabela hash.

A **função _resize(self)** é chamada quando a carga da tabela hash ultrapassa um determinado limite, aumentando o tamanho da tabela e redistribuindo os elementos para evitar colisões.

Outros métodos, como **insert, search, remove, show, entre outros**, permitem interagir com a tabela hash de diferentes maneiras, como inserir novos elementos, pesquisar por chaves, remover elementos e exibir o conteúdo da tabela.

Siga as instruções abaixo para instalar e executar as aplicações corretamente:

## Requisitos do Sistema:

- Python 3.11.4 instalado no sistema.
- Você pode baixar a versão mais recente do Python em python.org.

## Sistema Operacional:

- Microsoft Windows 10/11

## Executar no terminal:

- Projeto-Arvore: **python arvore.py**

- Projeto-Hash: **python hash_table.py**