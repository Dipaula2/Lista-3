# Lista-3

1 . Uma lista encadeada é uma sequência de estruturas, chamadas nós, que estão interligados por meio de ponteiros. Essa sequência pode ser acessada por meio de um ponteiro para o primeiro nó, que é conhecido como cabeça da lista. Cada nó contém um ponteiro que aponta para a estrutura que representa seu sucessor na lista. O ponteiro do último nó da lista aponta para NULL, indicando o final da lista. Essa estrutura de dados é criada dinamicamente na memória usando funções como malloc() e free(), o que permite a fácil inserção, remoção e ordenação dos nós. Detalhes sobre os algoritmos utilizados em uma lista encadeada normalmente são abordados em cursos de algoritmos e estruturas de dados, e estão além do escopo deste curso.

2 . As filas (queue, em inglês) são um tipo de estrutura dinâmica de dados onde os elementos (ou nós) estão arranjados em lista que obedece as seguintes regras:
- Ao inserir um nó, ele vai para a última posição da estrutura
- Ao retirar um nó, é tirado o primeiro elemento da estrutura

Este tipo de estrutura de dados é dita ser FIFO (First in, first out), ou seja, o primeiro elemento a entrar na estrutura é o primeiro a sair.

3 .Uma pilha é uma estrutura de dados que admite remoção de elementos e inserção de novos objetos.  Mais especificamente, uma  pilha (= stack)  é uma estrutura sujeita à seguinte regra de operação:  sempre que houver uma remoção,

o elemento removido é o que está na estrutura há menos tempo.

Em outras palavras, o primeiro objeto a ser inserido na pilha é o último a ser removido. Essa política é conhecida pela sigla LIFO (= Last-In-First-Out).

4 . Como tantas outras, uma Tabela Hash é mais uma estrutura de dados com um objetivo bem específico. O uso de uma tabela hash é indicado quando o tamanho do conjunto de dados é conhecido e é necessária uma grande quantidade de busca que deve ser realizada de forma rápida.

Em sua forma mais simples, uma tabela hash é um vetor de tamanho maior do que o conjunto de dados que será armazenado. A eficiência da busca na tabela hash está diretamente relacionada à função de espalhamento. Essa função recebe uma chave (como um nome, CPF ou matrícula, por exemplo) e gera o índice no vetor onde os dados serão armazenados. Arrume esse texto

5 . Quando itens de dados são armazenados em uma coleção, como uma lista, dizemos que eles têm uma relação linear ou sequencial. Cada item de dados é armazenado em uma posição relativa aos outros. Nas listas (vetores) JavaScript, essas posições relativas são os valores de índice dos itens individuais. Como esses valores de índice são ordenados, é possível para nós visitá-los em sequência. Este processo dá origem a nossa primeira técnica de busca, a busca sequencial.

6 . Caso você possua uma lista com os valores ordenados de forma numérica ou alfabética, é possível fazer uma busca muito mais rápida. Ao invés de pesquisar a lista em sequência, uma busca binária começará examinando o item do meio. Se esse item for aquele que estamos procurando, a busca termina. Se não for o item correto, podemos usar a natureza ordenada da lista para eliminar a metade dos itens restantes. Se o item que procuramos for maior do que o item do meio, sabemos que toda a metade inferior da lista, bem como o item do meio, podem ser eliminados de uma consideração mais aprofundada. O item, se estiver na lista, deve estar na metade superior. 
