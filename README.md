# JogoDaVelha
Jogo da Velha desenvolvido em linguagem C
 
   Só leia isto se realmente estiver interessado no funcionamento do jogo/código fonte.
Explicarei o "funcionamento" do código, ou pelo menos o funcionamento das partes mais importantes, caso tenha alguma dúvida enquanto estiver lendo o código-fonte, você pode ler os comentários(que são uma forma menos detalhada de explicar o funcionamento), aqui terá uma explicação mais detalhada de tudo(ou quase tudo hehe). Vamos lá!

# VÁRIAVEIS IMPORTANTES
Primeiramente, explicarei quais são as "váriaveis" importantes, para que você entenda como funcionam e qual o seu papel no programa.

  A primeira delas é a váriavel do tipo char, por nome"usertab[3][3]"(tabuleiro do usuário), que na verdade é uma matriz(isso, igual aquela matriz que você aprendeu no ensino médio, uma forma de organizar dados em linhas e colunas). Esse é o "tabuleiro" que imprimiremos para o jogador, é do tipo char pois terá as jogadas marcadas com X e O pelos jogadores, a única finalidade desse tabuleiro é ter um lugar onde poderemos imprimir as jogadas para os jogadores, não faremos nenhum tipo de cálculo(checar se temos algum vencedor ou não) com esse tabuleiro.

E a segunda váriavel é outra matriz, do tipo int, que tem por nome "tab[3][3]", que eu irei chamar de tabuleiro de calculos, aqui é onde a mágica acontece, onde iremos "calcular" o final do jogo. 
Todas as vezes que um jogador entrar com um X em tal posição do tabuleiro, essa mesma posição terá o número -1 nessa váriavel "tab", e quando o jogador entrar com O, a posição escolhida receberá um 1 nesse tabuleiro, essa parte de 1 e -1 será melhor explicada na função checkVencedor, e na imagem para ajuda, que está na "base" do repositório.

# FUNÇÕES COMPLEMENTARES
  Primeiramente, explicarei a função "tabuleiro".
A função tabuleiro é do tipo void, pois não retorna nada, e recebe como parâmetro a váriavel Matriz(ou um array de array's/ vetor de vetores para os mais íntimos) char "usertab"(tabuleiro do usuário), onde todas as jogadas são marcadas com X e O, sua única finalidade é imprimir o tabuleiro de jogadas(onde os caracteres recebem X e O).

Agora, explicarei a função checkVencedor, que é do tipo int e tem como parâmetros a matriz "tab [3][3]"(tabuleiro de cálculos) e a váriavel de controle do laço das jogadas, resumindo ela, ela soma todos as linhas verticais, horizontais, e diagonais, e após cada jogada dos jogadores na função main essa função será executada, somará todas as linhas para checar se temos um vencedor, se alguma soma resultar -3, é porque temos 3 -1s seguidos em uma das linhas de possivel vitória do jogo, a função retornará 1, o que significa que o jogador 1 venceu, se alguma das somas resultar 3 é porque temos três 1s e então a função retornará 2, o que significa que o jogador 2 venceu, se a váriavel de controle do laço for igual a 9(o que significa que o laço está no fim) e vencedor ainda for igual a 0, então a função retornará 3, o que na função main identificaremos como empate.

# FUNÇÃO MAIN

O funcionamento da função main pode parecer complicado ao somente olhar por cima, mas aposto que se você fizer um esforçinho você entenderá.
Primeiro, o programa pede o nome dos jogadores, após isso definimos todos os espaços do tabuleiro de calculo com 0, e definermos todos os espaços do tabuleiro de jogadas como vazios, espaços em branco, esse vazio nas atribuições está no código como "/0".
Após isso iniciamos um laço que rodará 9 vezes(para preencher 9 espaços de um tabuleiro de jogo da velha hehe, quando a váriavel de controle do laço for ímpar será a vez do player1/jogador1, e quando for par, será vez do jogador2), o programa imprime o tabuleiro atráves da função tabuleiro, para o jogador saber onde tem espaços vazios e onde não tem, e depois disso o jogador entra com a linha e a coluna do espaço que ele quer colocar sua jogada, depois válidamos a jogada, para ver se já tinha ou não alguma jogada anterior naquela posição.
Após isso começamos a verificar se temos vencedor, fazendo os calculos atráves da função checkVencedor, se sim, a váriavel string vencedor, recebe o nome do vencedor, e imprime que aquele jogador venceu, é basicamente isso, de resto os comentários no código fonte te ajudarão.
