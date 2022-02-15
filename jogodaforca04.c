#include <stdio.h>
#include <string.h>

int main(void){

    char palavraSecreta[20];
    sprintf(palavraSecreta, "MELANCIA");

    int venceu = 0;
    int perdeu = 0;
    
    char chutes[30];
    int tentativas = 0;

    do{
        for(int x = 0; x < strlen(palavraSecreta); x++){
            int acertou = 0;
            for(int y = 0; y < tentativas; y++){
                if(chutes[y] == palavraSecreta[x]){
                    acertou = 1;
                    break;
                }
            }
            if(acertou){
                printf("{%c}", palavraSecreta[x]);
            } else{
                printf("|_| ");
            }
        }
        char chute;
        printf("\nDIGITE SEU PALPITE: \n");
        scanf(" %c", &chute);

        chutes[tentativas] = chute;
        tentativas++;


    }while(!perdeu && !venceu);

    return 0;
}