/*
Universidade Federal de Itajubá
Programa referente a atividade avaliativa 1 - COM110
----------------------------------------------------------
| Mauro Sérgio Ribeiro de Souza - 2020020935              |
| André Marcos Ferreira - 2020026106                      |
----------------------------------------------------------

Jogo do 15

Objetivo: O objetivo do jogo é organizar as peças em ordem, da esquerda para a direita,
de cima a baixo fazendo a menor quantidade movimentos possível utilizando o
espaço vazio para mover as peças.

*/

//INCLUDES

// Os includes servem para importar bibliotecas já existentes no direório do C ou criadas pelo desenvolvedor
#include <stdio.h>   //Biblioteca padrão
#include <stdlib.h>  //Biblioteca de propósito geral padrão
#include <stdbool.h> //Biblioteca de variáveis lógicas
#include <time.h>    //Biblioteca de manipulação de tempo
#include <math.h>    //Biblioteca de manipulação de números, será utilizada para realizar o sorteio dos números no tabuleiro

//FIM DOS INCLUDES


// Função implementada para enfeitar a inicialização do jogo e apresentar uma mensagem de boas vindas 
void CarregarJogo(){
  for(int i = 0; i < 3 ; i++){ // For para apresentar a tela de Carregamento - ENFEITE
    printf("\n"); //Pular linha
    printf("\n Carregando o jogo");
    system("sleep 01"); //Delay de 1 segundo
    system("clear"); //Limpar tela
    printf("\n"); //Pular linha
    printf("\n Carregando o jogo .");
    system("sleep 01"); //Delay de 1 segundo
    system("clear"); //Limpar tela
    printf("\n"); //Pular linha
    printf("\n Carregando o jogo ..");
    system("sleep 01"); //Delay de 1 segundo
    system("clear"); //Limpar tela
    printf("\n"); //Pular linha
    printf("\n Carregando o jogo ...");
    system("sleep 01"); //Delay de 1 segundo
    system("clear"); //Limpar tela    
  } // Final do for
  printf("\n");
  system("clear"); //Limpar tela
  system("sleep 01"); //Delay de 1 segundo
  printf("|--------------------------------|\n");
  printf("|                                |\n");
  printf("|         BEM VINDO AO           |\n");
  printf("|          JOGO DO 15            |\n");
  printf("|             :)                 |\n");
  printf("|--------------------------------|\n");
}
//------------------------------------------ PRONTO

//Função implementada para embelezar a opção SAIR
void SairDoJogo(){
  printf("\n");
  printf("\n Salvando configurações... ");
  system("sleep 01"); //Delay de 1 segundo
  system("clear"); // Limpar tela
  printf("\n Finalizando o jogo... ");
  system("sleep 01"); //Delay de 1 segundo
  system("clear"); //Limpa a tela
  printf("\n Nós vemos por ai! ");
  system("sleep 01"); //Delay de 1 segundo
  system("clear"); //Limpa a tela
  printf("\n Obrigado por ter jogado! ");
  system("sleep 01"); //Delay de 1 segundo
  system("clear"); //Limpa a tela
}
//------------------------------------------ PRONTO

//Funçao implementada para a impressão do Menu Principal
int ImprimeMenu(){
  printf("|----------- MENU ---------------|\n");
  printf("|                                |\n");
  printf("| 1 - JOGAR                      |\n");
  printf("| 2 - RANKING                    |\n");
  printf("| 3 - REGRAS                     |\n");
  printf("| 4 - SAIR                       |\n");
  printf("|                                |\n");
  printf("|---- Opção Escolhida: ");
} 
//------------------------------------------ PRONTO

//Função implementada para exibir as REGRAS
void Regras(){
  printf("\n");
  system("clear");
  FILE *regra;
  char LinhaRegra[100];
  char *resultadoRegra;
  regra = fopen("regras.txt", "rt");
  if(regra == NULL){
    printf("-----------------------------------\n");
    printf("Não foi possível carregar as regras\n");
    printf("-----------------------------------\n");
  }
  printf("\n");
  while(!feof(regra)){
    resultadoRegra = fgets(LinhaRegra, 100, regra);
    printf("  %s", LinhaRegra);
  }
  char sairRegra[2];
  printf("\n \n ");
  printf("Pressione qualquer letra para continuar...");
  scanf("%s",&sairRegra);
  printf("\n");
  system("clear");
}
//------------------------------------------ PRONTO

//Função implementada para exibir o RANKING
void Ranking(){
  system("clear"); //Limpar tela
  FILE *rank; //Declarando o arquivo
  char Linha [100]; //Variável para pegar a linha do ranking
  char *resultado; //Receber resultado (ponteiro)
  rank = fopen("ranking.txt", "rt"); //Abrir documento
  if(rank == NULL){ //Verificando se foi feita a abertura
    printf("\n--------------------------------");
    printf("\n FALHA AO CARREGAR O RANKING ");
    printf("\n--------------------------------");
  } //Fim IF
  printf("\n ---------------- ");
  printf("\n     PLACAR       \n");
  while(!feof(rank)){ //Verificando se está nulo para frente
    resultado = fgets(Linha, 100, rank);
    printf("    %s", Linha);
  }
  printf("\n");
  printf("\n");
  printf(" ---------------- \n");
  char tecla[5];
  printf("Aperte qualquer letra para continuar...");
  scanf("%s",&tecla);
  system("clear");
}
//------------------------------------------ PRONTO

//Função implementada para imprimir tabuleiro
void ImprimeTabuleiro (int tabu[4][4]){
  printf("TABULEIRO: \n");
  printf("\n");
  printf("|-------------|\n");
  for(int i = 0; i < 4; i++){ //Linha
    for(int j = 0; j < 4; j++){ //Coluna
      if(j==0){
        printf("| ");
      }
      if(tabu[i][j] < 10){
        printf("0%d ",tabu[i][j]);
      }else{
        printf("%d ",tabu[i][j]);
      }
      if(j==3){
        printf("|");
        if(i==0){
          printf("    A casa em branco");
        }
        if(i==1){
          printf("    se refere ao número 00");
        }
      }
    }
    printf("\n");
  }
  printf("|-------------|\n");
  printf("\n");
}

//Função implementada para fazer testes enquanto é gerado o Tabuleiro
int testeVariavel(int numero, int tabu[4][4], int i, int j){
  if( j == 3){
    if(i == 3){
      return 1;
    }else{
      for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
          if(numero == tabu[i][j]){
            return 0;
          }
        } 
      }
    }
  }else{  
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(numero == tabu[i][j]){
        return 0;
      }
    } 
  }
}
  return 1;
}

//Função implementada para iniciar o MODO DE JOGO
void Jogar(){
  system("clear");
  int tabuaux [64];
  int tabu[4][4];
  int cont = 0;
  int teste = 0;
  srand((unsigned)time(NULL));
  for(int i = 0; i < 64; i++){ //Gerando 64 números aleatorios de 1 a 15
    tabuaux[i]= 1 + (rand() % 15);
  }
  printf("\n");
  //Gerando o tabuleiro com os números aleatorios gerados
  for(int i = 0; i < 4; i++){ 
    for(int j = 0; j < 4; j++){
      do{
        if(testeVariavel(tabuaux[cont], tabu, i, j)==1){
          teste = 1;
          tabu[i][j] = tabuaux[cont];
        }else{
          cont++;
        }
      }while(teste != 1);
      teste = 0;
      cont ++;
    }
  }
  //Colocando a posição zero no tabuleiro
  tabu[3][3]=0;
  ImprimeTabuleiro(tabu);
}

// -----------------------------------------



//Função Principal do Jogo (main)
int main(void) {
  //CarregarJogo(); //Inicializando o JOGO com as Boas Vindas
  int opcao;
  do{
    ImprimeMenu();
    scanf("%d", &opcao);
    switch(opcao){
      case 1: // Escolha JOGAR
        Jogar();
        break; 
      case 2: // Escolha RANKING
        Ranking();
        break;
      case 3: // Escolha REGRAS
        Regras();
        break;
      case 4: // Escolha SAIR
        SairDoJogo(); // Finalizando Jogo
        break;
      default: //Número fora do menu digitado
        printf("\n INFORME UMA OPÇÃO VÁLIDA \n");
        system("sleep 1"); //Delay de 1 segundo
        system("clear"); //Limpar a tela
    }
  }while(opcao != 4);
  return 0;
}