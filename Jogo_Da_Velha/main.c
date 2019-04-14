#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*|-----------------------------------------------------------------------------------|
  | função tabuleiro: função que usaremos para imprimir o tabuleiro para o usuário    |
  | somente imprimiremos o "usertab"(tabuleiro do usuário)                            |
  | onde teremos as jogadas X e O, e por isso a função é Void, pois não retorna nada  |
  |-----------------------------------------------------------------------------------|*/
void tabuleiro(char usertab[3][3])
{
    printf("\n\t %c | %c | %c\n", usertab[0][0], usertab[0][1], usertab[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c\n", usertab[1][0], usertab[1][1], usertab[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c\n", usertab[2][0], usertab[2][1], usertab[2][2]);
}

/*------------------------------------------------------------------------------------|
|  função checkVencedor: função que usaremos após cada jogada para checar se temos    |
|  um vencedor, somaremos as linhas, as colunas e também as diagonais, para cada soma |
|  teremos um valor diferente para a variavel "vencedor", se alguma soma resultar -3  |
|  retornaremos vencedor com valor 1, significando que o Jogador_1 venceu, se a soma  |
|  resultar 3, retornaremos vencedor com valor de 2, o que significa que o Jogador_2  |
|  venceu, e no ultimo caso, se i(que na função main tem o nome de ~vez~)valer 9(fim  |
|  do laço FOR) e vencedor ainda for 0 retornaremos 3, cuidaremos de cada caso na main|
|-------------------------------------------------------------------------------------|*/
int checkVencedor(int tab[3][3], int i)
{                                               //----------------------------------------------------------//
    int somaLinha1, somaLinha2, somaLinha3;     // Soma Linha1, Soma Linha2 e Soma Linha3                   //
    int somaColuna1, somaColuna2, somaColuna3;  // Soma_Coluna1, Soma_Coluna2 e Soma_Coluna3                //
    int somaDiagonal1, somaDiagonal2;           // Soma da Diagonal 1 e Soma da Diagonal 2                  //
    int vencedor = 0;                           // INT VENCEDOR: Caso o P1 Ganhe, retornará 1               //
                                                // Caso P2 ganhe, retornará 2, caso dê Empate, retornará 3  //
                                                //----------------------------------------------------------//

    somaLinha1 = tab[0][0] + tab[0][1] + tab[0][2];
    somaLinha2 = tab[1][0] + tab[1][1] + tab[1][2];
    somaLinha3 = tab[2][0] + tab[2][1] + tab[2][2];

    somaColuna1 = tab[0][0] + tab[1][0] + tab[2][0];
    somaColuna2 = tab[0][1] + tab[1][1] + tab[2][1];
    somaColuna3 = tab[0][2] + tab[1][2] + tab[2][2];

    somaDiagonal1 = tab[0][0] + tab[1][1] + tab[2][2];
    somaDiagonal2 = tab[0][2] + tab[1][1] + tab[2][0];

    if(somaLinha1 == -3 || somaLinha2 == -3 || somaLinha3 == -3){   //Verificando se alguma soma das linhas resultou -3
        vencedor = 1;}
        else
        if (somaLinha1 == 3 || somaLinha2 == 3 || somaLinha3 == 3){ //Verificando se alguma soma das linhas resultou 3
            vencedor = 2;}
            else
            if (somaColuna1 == -3 || somaColuna2 == -3 || somaColuna3 == -3){ //Verificando se alguma soma das colunas resultou -3
                vencedor = 1;}
                else
                if (somaColuna1 == 3 || somaColuna2 == 3 || somaColuna3 == 3){ //Verificando se alguma soma das colunas resultou 3
                    vencedor = 2;}
                    else
                    if (somaDiagonal1 == -3 || somaDiagonal2 == -3){ //Verificando se alguma soma das diagonais resultou -3
                        vencedor = 1;}
                        else
                        if (somaDiagonal1 == 3 || somaDiagonal2 == 3){ //Verificando se alguma soma das diagonais resultou 3
                            vencedor = 2;}
                            else
                            if ( i == 9 && vencedor == 0){  //Caso i seja 9(que é o que vale i no fim do laço) e vencedor ainda seja 0
                                vencedor = 3;}              //Vencedor receberá 3 o que na função main definiremos como EMPATE

    return (vencedor);
}

int main()
{                                   //-------------------------------------------------------------------------------------------//
                                    // Por definição, o jogador que começara primeiro usará X e o Segundo O                      //
    int vez, linha, coluna;         // vez: váriavel de controle do laço, linha e coluna: váriaveis p/ preencher o tab e usertab //
    char usertab[3][3];             // usertab: tabuleiro do usúario(onde imprimiremos as jogadas)                               //
    int tab[3][3];                  // tab: tabuleiro(onde faremos os calculos para checarmos o vencedor)                        //
    char nome1[15], nome2[15];      // Nome1 e Nome2 são Strings que receberão os nomes dos usuários                             //
    char vencedor[15];              // vencedor: String que receberá o nome do vencedor do jogo                                  //
    int winner;                     // winner: Váriavel que recebe o resultado da função checkVencedor                           //
    int escolha;                    // escolha: Váriavel que recebe a opção do usúario de jogar novamente ou não                 //
                                    //-------------------------------------------------------------------------------------------//

    inicio:
    system("cls");
    printf("\tJOGO DA VELHA\n");
    printf("\n\tJogador 1, insira seu nome: "); scanf("%s", &nome1);
    printf("\tJogador 2, insira seu nome: "); scanf("%s", &nome2);
    printf("\tSejam bem vindos Jogadores\n\t%s\n\t&\n\t%s\n", nome1,nome2);

    printf("\n\tPor definicao, o jogador_1(%s), que comecara, usara X e o Segundo O\n\n\n", nome1);
    system("pause");

    tab[0][0] = 0 ;     usertab[0][0] = '\0';       //----------------------------------------------------//
    tab[0][1] = 0 ;     usertab[0][1] = '\0';       // Definindo os espaços dos tabuleiros como vazios    //
    tab[0][2] = 0 ;     usertab[0][2] = '\0';       // O ~INT tab~ receberá em todos espaços 0            //
    tab[1][0] = 0 ;     usertab[1][0] = '\0';       //               enquanto                             //
    tab[1][1] = 0 ;     usertab[1][1] = '\0';       // O ~CHAR usertab~ receberá espaços em branco('\0')  //
    tab[1][2] = 0 ;     usertab[1][2] = '\0';       //----------------------------------------------------//
    tab[2][0] = 0 ;     usertab[2][0] = '\0';
    tab[2][1] = 0 ;     usertab[2][1] = '\0';
    tab[2][2] = 0 ;     usertab[2][2] = '\0';

    for (vez=1;vez<=9;vez++)
    {
        //Quando ~vez~ for par, será a vez do jogador_2
        if (vez % 2 == 0){
        vezplayer2:
        tabuleiro(usertab);
        printf("\nVez do %s\n", nome2);
        printf("\nQual linha?\n"); scanf("%i", &linha); linha--;
        printf("Qual coluna?\n"); scanf("%i", &coluna); coluna--;
        //Etapa onde checaremos se a entrada/input do jogador é válida(se não é maior que o espaço do tabuleiro)
        if ((linha<0 || linha > 2) || (coluna<0 || coluna>2)){
                printf("Jogada invalida, temos somente 3 linhas, e 3 colunas\n");
                goto vezplayer2;}
            else
            {
            //Etapa onde checaremos se a posição digitada pelo jogador já não está ocupada
            if (usertab[linha][coluna] != '\0'){
                printf("\n\tPOSICAO JA OCUPADA, %s\n", nome2);
                goto vezplayer2;
            }
            else{
            //Se a jogada não entrar nos outros testes, cai neste, então a posição digitada é preenchida com O no usertab, e 1 no tab
            usertab[linha][coluna] = 'O';
            tab[linha][coluna] = 1;
            winner = checkVencedor(tab, vez);}
            //Logo após a jogada já entregamos a ~winner~ o resultado da função checkVencedor para checar se após essa jogada o jogador conseguiu ganhar o jogo
            //Após esta etapa de entrada, validação e preenchimento da jogada, testaremos se winner corresponde já corresponde a vitória do Jogador
        }}
        else{
            //Quando ~vez~ for ímpar, será a vez do jogador_1
            vezplayer1:
            tabuleiro(usertab);
            printf("\nVez do %s\n", nome1);
            printf("\nQual linha?\n"); scanf("%i", &linha); linha--;
            printf("Qual coluna?\n"); scanf("%i", &coluna); coluna--;
            //Etapa onde checaremos se a entrada/input do jogador é válida(se não é maior que o espaço do tabuleiro)
            if ((linha<0 || linha > 2) || (coluna<0 || coluna>2)){
                printf("Jogada invalida, temos somente 3 linhas, e 3 colunas\n");
                goto vezplayer1;
            }
            else{
            //Etapa onde checaremos se a posição digitada pelo jogador já não está ocupada
            if (usertab[linha][coluna] != '\0'){
                printf("\n\tPOSICAO JA OCUPADA, %s\n", nome1);
                goto vezplayer1;
                }
                else {
                    //Se a jogada não entrar nos outros testes, cai neste, então a posição digitada é preenchida com X no usertab, e -1 no tab
                    usertab[linha][coluna] = 'X';
                    tab[linha][coluna] = -1;
                    winner = checkVencedor(tab, vez);}
        }}      //ETAPA DE JOGADAS ENCERRADAS

        //Então inicia-se a etapa de verificação se temos um ganhador
        // Se winner = 1(o que significa o jogador_1 ganhou), a string ~vencedor~ receberá o nome do jogador_1, e então dará um break(fechará o laço na hora)
        if (winner == 1){
            strcpy(vencedor, nome1);    //função StringCopy, copiará a string de ~nome1~ para a string ~vencedor~
            break;}
            else
            // Se winner = 2(o que significa o jogador_2 ganhou), a string ~vencedor~ receberá o nome do jogador_2, e então dará um break(fechará o laço na hora)
            if (winner == 2){
                strcpy(vencedor, nome2);
                break;}
                else{
                    // Se winner não for nem 1, nem 2, então ainda não temos um vencedor e podemos continuar o jogo
                    continue;}
    }

    //Fora do laço já, se winner for 3, então o jogo empatou
    if(winner == 3){
        printf("\nO jogo empatou\n\n");
        tabuleiro(usertab);}
    else{
        //Se não for 3, então imprimiremos ~vencedor~, que recebeu o nome do ganhador do jogo
        printf("\nParabens %s, voce venceu o jogo\n\n", vencedor);
        tabuleiro(usertab);}

    putchar('\n');
    system("pause");
    system("cls");
    escolha:

    //Etapa para os jogadores decidirem se vão jogar novamente
    printf("\n\tDeseja jogar novamente? 1 para SIM | 2 para NAO\n\t");
    scanf("%i", &escolha);

    if(escolha != 1 && escolha != 2){
        //Validação da escolha
        printf("\n\tOPCAO INVALIDA\n");
        goto escolha;}
        else
        //Se escolha for 1, o programa voltará ao inicio
        if(escolha == 1){
            goto inicio;}
            // Se escolha for 2, o programa irá para o fim
            else if (escolha == 2){
                goto fim;}

    fim:
    printf("\n\tFIM DO JOGO\n\n\n\n");
}



