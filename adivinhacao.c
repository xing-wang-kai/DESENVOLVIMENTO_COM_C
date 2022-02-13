#include <stdio.h>
#include <math.h>

//Este tipo de váriavel é declarada fora do programa e chamada de váriavel const e está toda em letra maiúscula por convensões
#define VARIAVELTENTATIVAS 3

int main(void) {


    //Cabeçalho usado para exemplos dos exercícios em lenguagem C
    printf("***********************************************************\n");
    printf("----------BEM VINDO AO JOGO DA ADVINHACAO------------------\n");
    printf("***********************************************************\n");

    int numerosecreto = 42;
    int chute;

    for(int cont = 0; cont < VARIAVELTENTATIVAS; cont++){
        printf("whats is you choice ?: \n");
        scanf("%d", &chute);
        printf("your choice is %d \n", chute);

        if(chute == numerosecreto){
            printf("\n congratulation you win\n");
            printf("\n with you want try again\n");
            break;
        } else if(chute > numerosecreto){
                printf("\n you choice is bigger than secret word\n");
                printf("\n Sorry but you lose\n");
                printf("\n Try Again\n");
            }
            else{
                printf("\n you choice is less than secret word\n");
                printf("\n Sorry but you lose\n");
                printf("\n Try Again\n");
            }
            
        
    }
    
    
    return 0;
}