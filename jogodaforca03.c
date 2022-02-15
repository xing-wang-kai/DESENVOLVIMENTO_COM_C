#include <stdio.h>
#include <string.h>

int main(void){

    char palavraSecreta[20];
    sprintf(palavraSecreta, "MELANCIA");

    int acertou =0;
    int enforcou = 0;

    char chutes[30];
    int tentativas = 0;
    
    do{
        for(int i = 0; i < strlen(palavraSecreta); i++){
            int achou = 0;
            for(int j = 0; j < tentativas; j++){
                if(chutes[j] == palavraSecreta[i]){
                    achou = 1;
                    break;
                }
            }
            if(achou){
                printf("{%c}", palavraSecreta[i]);
            } else{
                printf("|_|");
            }
        }
        char chute;
        printf("\n\nDIGITE A LETRA: \n");
        scanf(" %c", &chute);

        chutes[tentativas] = chute;
        tentativas++;


    }while(!acertou && !enforcou);

    return 0;
}