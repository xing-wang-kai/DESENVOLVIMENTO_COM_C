#include <stdio.h> // biblioteca básica do C
#include <math.h> // Incluir algumas operações matemáticas
#include <stdlib.h> // ajusa a usar a função ABS para converter o número para negativos
#include <time.h> // bibliotéca usada para incluir a funcionabilidade TIME()

//Este tipo de váriavel é declarada fora do programa e chamada de váriavel const e está toda em letra maiúscula por convensões
#define VARIAVELTENTATIVAS 3

int main(void) {


    //Cabeçalho usado para exemplos dos exercícios em lenguagem C
    printf("\n***********************************************************\n");
    printf("----------WELCOME TO THE GUESS GAME CHOICE A NUMBER--------\n");
    printf("***********************************************************\n");
    //retorna os segundos EPOCH deste 1970 até o momento
    int segundos = time(0);
    srand(segundos);

    int numerorand = rand();
    int numerosecreto = numerorand % 100;
    int chute, errou, tentativas;
    double pontos;
    errou = 0;
    pontos = 1000;
    int dificuldade = 0;

   
    printf("\n-------------------------------------------------------------\n");
    printf("-------------------CHOICE THE DIFICULT LEVEL: ---------------\n");
    printf("-------------------------------------------------------------\n");
    printf("-----------------(1) EASY (2) MEDIUM (3) HARD----------------\n");
    printf("-------------------------------------------------------------\n");
    scanf("%d", &dificuldade);

    switch (dificuldade)
    {
    case 1:
        tentativas = 20;
        break;
    case 2: 
        tentativas = 10;
        break;
    case 3:
        tentativas = 5;
        break;
    default:
        break;
    }
    
    for ( int c = 0; c < tentativas; c++){
         printf("whats is you choice ?: \n");
         scanf("%d", &chute);
         printf("your choice is %d \n", chute);


        if(chute < 0){
            printf("please!! don't choise negative number, Try Again!!");
            continue;
        } else if(chute == numerosecreto){
            printf("\n congratulation you win\n");
            printf("\n with you want try again\n");

            printf("        _  _  _____  __  __    _    _  ____  _  _ /\\/\\     \n");
            printf("       ( \\/ )(  _  )(  )(  )  ( \\/\\/ )(_  _)( \\( ))()(   \n");
            printf("        \\  /  )(_)(  )(__)(    )    (  _)(_  )  ( \\/\\/    \n");
            printf("        (__) (_____)(______)  (__/\\__)(____)(_)\\_)()(      \n");
            
            break;

        } else if(chute > numerosecreto){
                printf("\n you choice is bigger than secret word\n");
                printf("\n Sorry but you lose\n");
                printf("\n Try Again\n");
                errou ++;
            }
            else{
                printf("\n you choice is less than secret word\n");
                printf("\n Sorry but you lose\n");
                printf("\n Try Again\n");
                errou ++;
            }
            //O compilador vai realizar primeiro a op math para depois declarar a váriavel
            //nesta situação ela não será um double e sim um int e não terá casas decimais
            //então é preciso colocar 2.0 como double para que ao processar a conta seja double
            //então será armazenado o valor correto dentro da váreavel   
            //tbm é possivel fazer um CASTING usando (double) antes do valor assim ele é convertido para double int long short float depende da escolha
            double pontosperdido = (chute - numerosecreto)/2.0;
            //podemos importar <stdlib.h> e então usar o abs( ) para converter o número, será mais eficiente do que o if.
            if(pontosperdido < 0){
                pontosperdido *= -1;
            }
            pontos -= pontosperdido;
    }
    
    printf("\n YOUR HAVE TOTAL %d ERROS \n\n", errou);
    //usando o .2 informo ao programa a qtd de casas decimais que será gerada no final do double
    printf(" Total of Points in this round is %.2f \n", pontos);

    printf("\n***********************************************************\n");
    printf("------------------------END GAME---------------------------\n");
    printf("***********************************************************\n");
    
    return 0;
}