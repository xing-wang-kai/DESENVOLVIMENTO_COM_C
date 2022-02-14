#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



int main(void){

    printf("\n-----------------------------------------------------------\n");
    printf("------------------WELCOME TO HANGMAN GAME------------------\n");
    printf("-----------------------------------------------------------\n");

    // palavras são arrays que deve ser colocados o qtd de caracteres dentro de []
    // sprintf printa todo o array não somente palavra por palavra
    char secretyword[20];
    sprintf(secretyword, "watermelon");
    printf("%s \n", secretyword);

    int acertou, enforcou, erros, hits;
    acertou = 0;
    enforcou = 0;
    erros = 0;
    hits = 0;
    
    
    char hangmanstring[strlen(secretyword)];
    for( int y = 0; y < strlen(secretyword); y ++){
        hangmanstring[y] = '_';
    }

    while(acertou == 0 || enforcou == 0){

        char letter;
        printf("enter your first guess for the letter in the secret word. \n");
        printf("acetou: %d errou: %d \n", hits, erros);
        scanf(" %c", &letter);

        for(int c = 0; c <= strlen(secretyword); c++){
            if(secretyword[c] == letter){
                printf("you hit it!!! \n");
                printf("------------- a psicao %d----------------------\n\n", c);
                hangmanstring[c] = letter;
                hits ++;

            }
            /*else{

                printf("the secret letter is : $s \n", letter);

                printf("you don't hit it please try again\n");
                erros ++;
            }*/

        }
        printf("LOOK THE HANGMAN: %s \n", hangmanstring);
        
        
        if(erros == 1){

        printf("YOU HAVE %d \n", erros);
        printf("\n  _______            \n");
        printf(" |/      |          \n");
        printf(" |                  \n");
        printf(" |                  \n");
        printf(" |                  \n");
        printf(" |                  \n");
        printf(" |                  \n");
        printf("_|___               \n");

        } 
        else if(erros == 2){
             printf("YOU HAVE %d \n", erros);
            printf("\n  _______           \n");
            printf(" |/      |          \n");
            printf(" |      (_)         \n");
            printf(" |                  \n");
            printf(" |                  \n");
            printf(" |                  \n");
            printf(" |                  \n");
            printf("_|___               \n");
        } 
        else if(erros == 3){
             printf("YOU HAVE %d\n", erros);
            printf("\n  _______            \n"); 
            printf(" |/      |           \n");
            printf(" |      (_)          \n");
            printf(" |      \\|/         \n");
            printf(" |                   \n");
            printf(" |                   \n");
            printf(" |                   \n");  
            printf("_|___                \n");

        } 
        else if (erros == 4){

            printf("YOU HAVE %d\n", erros);
            printf("\n  _______            \n"); 
            printf(" |/      |           \n");
            printf(" |      (_)          \n");
            printf(" |      \\|/         \n");
            printf(" |       |           \n");
            printf(" |                   \n");
            printf(" |                   \n");  
            printf("_|___                \n");
        }
        else if(erros == 5){
            printf("YOU HAVE %d\n", erros);
            printf("\n  _______            \n"); 
            printf(" |/      |           \n");
            printf(" |      (_)          \n");
            printf(" |      \\|/         \n");
            printf(" |       |           \n");
            printf(" |      / \\         \n");
            printf(" |                   \n");  
            printf("_|___                \n");

            enforcou = 1;
        }
        else if (hits <= strlen(secretyword)-1){
            acertou = 1;
        }
        
    }


    
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




              
    printf("\n-----------------------------------------------------------\n");
    printf("----------------------THE END GAME-------------------------\n");
    printf("-----------------------------------------------------------\n");

    return 0;
}