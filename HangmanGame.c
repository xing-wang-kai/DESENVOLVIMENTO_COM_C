#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hangmangame.h"


char secretyword[20];
int acertou, enforcou, erros, hits;


void escolhePalavra(){
    FILE * f;
    f = fopen("wordsforhangmangame.txt", "r");
    
   
    int qtdpalavra;
    fscanf(f, "%d", &qtdpalavra);

    srand(time(0));
    int randomico = rand() % qtdpalavra;

    for(int c = 0; c <= randomico; c++){
        fscanf(f, "%s", secretyword);
    }

    fclose(f);
}

void opengame(){
    printf("\n-----------------------------------------------------------\n");
    printf("------------------WELCOME TO HANGMAN GAME------------------\n");
    printf("-----------------------------------------------------------\n");
}
void finalgame(){
    printf("\n-----------------------------------------------------------\n");
    printf("----------------------THE END GAME-------------------------\n");
    printf("-----------------------------------------------------------\n");
}

void youwrong(){
            printf("   ---%s----           \n", secretyword);
            printf("     OH MY GODS YOU BE HANGED   \n");
            printf("                                \n");
            printf("    _______________             \n");  
            printf("   /               \\           \n");
            printf("  /                 \\          \n");
            printf("//                   \\/\\      \n");
            printf("\\|   XXXX     XXXX   | /       \n");
            printf(" |   XXXX     XXXX   |/         \n");
            printf(" |   XXX       XXX   |          \n");
            printf(" |                   |          \n");
            printf(" \\__      XXX      __/         \n");
            printf("   |\\     XXX     /|           \n");
            printf("   | |           | |            \n");
            printf("   | I I I I I I I |            \n");
            printf("   |  I I I I I I  |            \n");
            printf("   \\_             _/           \n");
            printf("     \\_         _/             \n");
            printf("       \\_______/               \n");
}

void youwin(){
    printf(" CONGRATULATIONS YOU WIN \n");
            printf("                         \n");
            printf("       ___________       \n");
            printf("      '._==_==_=_.'      \n");
            printf("      .-\\:      /-.      \n");
            printf("     | (|:.     |) |     \n");
            printf("      '-|:.     |-'      \n");
            printf("        \\::.    /        \n");
            printf("         '::. .'         \n");
            printf("           ) (           \n");
            printf("         _.' '._         \n");
            printf("        '-------'        \n");
}
// nesta função ultilizei alguns ponteiros para que o espaço na memória seja apontada para váriavel dentro da função e executar dentro do jogo
void verificar(int *erros, int *hits, int manipulador, int *enforcou, int *acertou){
    if((*erros) == 1){

        printf("YOU HAVE %d \n", (*erros));
        printf("\n  _______            \n");
        printf(" |/      |          \n");
        printf(" |                  \n");
        printf(" |                  \n");
        printf(" |                  \n");
        printf(" |                  \n");
        printf(" |                  \n");
        printf("_|___               \n");

        } 
        else if((*erros) == 2){
             printf("YOU HAVE %d \n", (*erros));
            printf("\n  _______           \n");
            printf(" |/      |          \n");
            printf(" |      (_)         \n");
            printf(" |                  \n");
            printf(" |                  \n");
            printf(" |                  \n");
            printf(" |                  \n");
            printf("_|___               \n");
        } 
        else if((*erros) == 3){
             printf("YOU HAVE %d\n", (*erros));
            printf("\n  _______            \n"); 
            printf(" |/      |           \n");
            printf(" |      (_)          \n");
            printf(" |      \\|/         \n");
            printf(" |                   \n");
            printf(" |                   \n");
            printf(" |                   \n");  
            printf("_|___                \n");

        } 
        else if ((*erros) == 4){

            printf("YOU HAVE %d\n", (*erros));
            printf("\n  _______            \n"); 
            printf(" |/      |           \n");
            printf(" |      (_)          \n");
            printf(" |      \\|/         \n");
            printf(" |       |           \n");
            printf(" |                   \n");
            printf(" |                   \n");  
            printf("_|___                \n");
        }
        else if((*erros) == 5){
            printf("YOU HAVE %d\n", (*erros));
            printf("\n  _______            \n"); 
            printf(" |/      |           \n");
            printf(" |      (_)          \n");
            printf(" |      \\|/         \n");
            printf(" |       |           \n");
            printf(" |      / \\         \n");
            printf(" |                   \n");  
            printf("_|___                \n");

            (*enforcou) = 1;

            youwrong();
        }
        else if ((*hits) >= manipulador){
            (*acertou) = 1;
            youwin();
        }


}
        


int main(void){

    opengame();

    // palavras são arrays que deve ser colocados o qtd de caracteres dentro de []
    // sprintf printa todo o array não somente palavra por palavra
    
    //sprintf(secretyword, "watermelon");
    

    escolhePalavra();


    acertou = 0;
    enforcou = 0;
    erros = 0;
    hits = 0;
    
    
    char hangmanstring[strlen(secretyword)];

    
    for( int y = 0; y < strlen(secretyword); y ++){
        hangmanstring[y] = '_';
    }

    while(acertou == 0 && enforcou == 0){

        char letter;
        printf("enter your first guess for the letter in the secret word. \n");
        printf("rights: %d end erros: %d \n", hits, erros);
        scanf(" %c", &letter);

        int achou = 0;
        for(int c = 0; c <= strlen(secretyword); c++){
            if(secretyword[c] == letter){
                printf("you hit it!!! \n");
                hangmanstring[c] = letter;
                hits ++;
                achou ++;

            }
        }

        
        if(achou == 0){
            erros += 1;

        }

        printf("LOOK THE HANGMAN: %s \n", hangmanstring);

        verificar(&erros, &hits, strlen(secretyword), &enforcou, &acertou);
    }
     
    finalgame();

    return 0;
}