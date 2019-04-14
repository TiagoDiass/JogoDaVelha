#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*|-----------------------------------------------------------------------------------|
  | fun��o tabuleiro: fun��o que usaremos para imprimir o tabuleiro para o usu�rio    |
  | somente imprimiremos o "usertab"(tabuleiro do usu�rio)                            |
  | onde teremos as jogadas X e O, e por isso a fun��o � Void, pois n�o retorna nada  |
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
|  fun��o checkVencedor: fun��o que usaremos ap�s cada jogada para checar se temos    |
|  um vencedor, somaremos as linhas, as colunas e tamb�m as diagonais, para cada soma |
|  teremos um valor diferente para a variavel "vencedor", se alguma soma resultar -3  |
|  retornaremos vencedor com valor 1, significando que o Jogador_1 venceu, se a soma  |
|  resultar 3, retornaremos vencedor com valor de 2, o que significa que o Jogador_2  |
|  venceu, e no ultimo caso, se i(que na fun��o main tem o nome de ~vez~)valer 9(fim  |
|  do la�o FOR) e vencedor ainda for 0 retornaremos 3, cuidaremos de cada caso na main|
|-------------------------------------------------------------------------------------|*/
int checkVencedor(int tab[3][3], int i)
{                                               //----------------------------------------------------------//
    int somaLinha1, somaLinha2, somaLinha3;     // Soma Linha1, Soma Linha2 e Soma Linha3                   //
    int somaColuna1, somaColuna2, somaColuna3;  // Soma_Coluna1, Soma_Coluna2 e Soma_Coluna3                //
    int somaDiagonal1, somaDiagonal2;           // Soma da Diagonal 1 e Soma da Diagonal 2                  //
    int vencedor = 0;                           // INT VENCEDOR: Caso o P1 Ganhe, retornar� 1               //
                                                // Caso P2 ganhe, retornar� 2, caso d� Empate, retornar� 3  //
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
                            if ( i == 9 && vencedor == 0){  //Caso i seja 9(que � o que vale i no fim do la�o) e vencedor ainda seja 0
                                vencedor = 3;}              //Vencedor receber� 3 o que na fun��o main definiremos como EMPATE

    return (vencedor);
}

int main()
{                                   //-------------------------------------------------------------------------------------------//
                                    // Por defini��o, o jogador que come�ara primeiro usar� X e o Segundo O                      //
    int vez, linha, coluna;         // vez: v�riavel de controle do la�o, linha e coluna: v�riaveis p/ preencher o tab e usertab //
    char usertab[3][3];             // usertab: tabuleiro do us�ario(onde imprimiremos as jogadas)                               //
    int tab[3][3];                  // tab: tabuleiro(onde faremos os calculos para checarmos o vencedor)                        //
    char nome1[15], nome2[15];      // Nome1 e Nome2 s�o Strings que receber�o os nomes dos usu�rios                             //
    char vencedor[15];              // vencedor: String que receber� o nome do vencedor do jogo                                  //
    int winner;                     // winner: V�riavel que recebe o resultado da fun��o checkVencedor                           //
    int escolha;                    // escolha: V�riavel que recebe a op��o do us�ario de jogar novamente ou n�o                 //
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
    tab[0][1] = 0 ;     usertab[0][1] = '\0';       // Definindo os espa�os dos tabuleiros como vazios    //
    tab[0][2] = 0 ;     usertab[0][2] = '\0';       // O ~INT tab~ receber� em todos espa�os 0            //
    tab[1][0] = 0 ;     usertab[1][0] = '\0';       //               enquanto                             //
    tab[1][1] = 0 ;     usertab[1][1] = '\0';       // O ~CHAR usertab~ receber� espa�os em branco('\0')  //
    tab[1][2] = 0 ;     usertab[1][2] = '\0';       //----------------------------------------------------//
    tab[2][0] = 0 ;     usertab[2][0] = '\0';
    tab[2][1] = 0 ;     usertab[2][1] = '\0';
    tab[2][2] = 0 ;     usertab[2][2] = '\0';

    for (vez=1;vez<=9;vez++)
    {
        //Quando ~vez~ for par, ser� a vez do jogador_2
        if (vez % 2 == 0){
        vezplayer2:
        tabuleiro(usertab);
        printf("\nVez do %s\n", nome2);
        printf("\nQual linha?\n"); scanf("%i", &linha); linha--;
        printf("Qual coluna?\n"); scanf("%i", &coluna); coluna--;
        //Etapa onde checaremos se a entrada/input do jogador � v�lida(se n�o � maior que o espa�o do tabuleiro)
        if ((linha<0 || linha > 2) || (coluna<0 || coluna>2)){
                printf("Jogada invalida, temos somente 3 linhas, e 3 colunas\n");
                goto vezplayer2;}
            else
            {
            //Etapa onde checaremos se a posi��o digitada pelo jogador j� n�o est� ocupada
            if (usertab[linha][coluna] != '\0'){
                printf("\n\tPOSICAO JA OCUPADA, %s\n", nome2);
                goto vezplayer2;
            }
            else{
            //Se a jogada n�o entrar nos outros testes, cai neste, ent�o a posi��o digitada � preenchida com O no usertab, e 1 no tab
            usertab[linha][coluna] = 'O';
            tab[linha][coluna] = 1;
            winner = checkVencedor(tab, vez);}
            //Logo ap�s a jogada j� entregamos a ~winner~ o resultado da fun��o checkVencedor para checar se ap�s essa jogada o jogador conseguiu ganhar o jogo
            //Ap�s esta etapa de entrada, valida��o e preenchimento da jogada, testaremos se winner corresponde j� corresponde a vit�ria do Jogador
        }}
        else{
            //Quando ~vez~ for �mpar, ser� a vez do jogador_1
            vezplayer1:
            tabuleiro(usertab);
            printf("\nVez do %s\n", nome1);
            printf("\nQual linha?\n"); scanf("%i", &linha); linha--;
            printf("Qual coluna?\n"); scanf("%i", &coluna); coluna--;
            //Etapa onde checaremos se a entrada/input do jogador � v�lida(se n�o � maior que o espa�o do tabuleiro)
            if ((linha<0 || linha > 2) || (coluna<0 || coluna>2)){
                printf("Jogada invalida, temos somente 3 linhas, e 3 colunas\n");
                goto vezplayer1;
            }
            else{
            //Etapa onde checaremos se a posi��o digitada pelo jogador j� n�o est� ocupada
            if (usertab[linha][coluna] != '\0'){
                printf("\n\tPOSICAO JA OCUPADA, %s\n", nome1);
                goto vezplayer1;
                }
                else {
                    //Se a jogada n�o entrar nos outros testes, cai neste, ent�o a posi��o digitada � preenchida com X no usertab, e -1 no tab
                    usertab[linha][coluna] = 'X';
                    tab[linha][coluna] = -1;
                    winner = checkVencedor(tab, vez);}
        }}      //ETAPA DE JOGADAS ENCERRADAS

        //Ent�o inicia-se a etapa de verifica��o se temos um ganhador
        // Se winner = 1(o que significa o jogador_1 ganhou), a string ~vencedor~ receber� o nome do jogador_1, e ent�o dar� um break(fechar� o la�o na hora)
        if (winner == 1){
            strcpy(vencedor, nome1);    //fun��o StringCopy, copiar� a string de ~nome1~ para a string ~vencedor~
            break;}
            else
            // Se winner = 2(o que significa o jogador_2 ganhou), a string ~vencedor~ receber� o nome do jogador_2, e ent�o dar� um break(fechar� o la�o na hora)
            if (winner == 2){
                strcpy(vencedor, nome2);
                break;}
                else{
                    // Se winner n�o for nem 1, nem 2, ent�o ainda n�o temos um vencedor e podemos continuar o jogo
                    continue;}
    }

    //Fora do la�o j�, se winner for 3, ent�o o jogo empatou
    if(winner == 3){
        printf("\nO jogo empatou\n\n");
        tabuleiro(usertab);}
    else{
        //Se n�o for 3, ent�o imprimiremos ~vencedor~, que recebeu o nome do ganhador do jogo
        printf("\nParabens %s, voce venceu o jogo\n\n", vencedor);
        tabuleiro(usertab);}

    putchar('\n');
    system("pause");
    system("cls");
    escolha:

    //Etapa para os jogadores decidirem se v�o jogar novamente
    printf("\n\tDeseja jogar novamente? 1 para SIM | 2 para NAO\n\t");
    scanf("%i", &escolha);

    if(escolha != 1 && escolha != 2){
        //Valida��o da escolha
        printf("\n\tOPCAO INVALIDA\n");
        goto escolha;}
        else
        //Se escolha for 1, o programa voltar� ao inicio
        if(escolha == 1){
            goto inicio;}
            // Se escolha for 2, o programa ir� para o fim
            else if (escolha == 2){
                goto fim;}

    fim:
    printf("\n\tFIM DO JOGO\n\n\n\n");
}



