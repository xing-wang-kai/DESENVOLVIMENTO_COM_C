#include <stdio.h>

int main(void){

    char palavrasecreta[20];
    sprintf(palavrasecreta, "MELANCIA");
    
    int acertou = 0;
    int enforcou =0;

    char chutes[26];
    int tentativa = 0;

    do{
       
        
        for(int i = 0; i < strlen(palavrasecreta); i++){
            
            int achou = 0;
            for(int j = 0; j< tentativa; j++){
                if(chutes[j] == palavrasecreta[i]){
                    achou =1;
                    break;
                }
            }
            if(achou){
                printf("[%c]", palavrasecreta[i]);
            } else {
                printf("_ ");
            }

        }
        char chute;
        printf("\nDIGITE SEU CHUTE: ");
        scanf(" %c", &chute);

        chutes[tentativa] = chute;
        tentativa ++;

    }while(!acertou && !enforcou);

    return 0;
}