#include <stdio.h>
#include <stdlib.h> //Rande
#include <string.h> // importa 
#include <time.h> //time
#include "funcao.h"

char palavrasecreta[20];
char chutes[26];
int chutesdados =0;


void abertura(){
    printf("-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-==-=-=\n");
    printf("=            JOGO DA FORCA!!!              =\n");
    printf("-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-==-=-=\n");
}

void Encerrar(){
    printf("-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-==-=-=\n");
    printf("=            FIM DE JOGO -!!!              =\n");
    printf("-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-==-=-=\n");
}

void chutar(char chutes[26]){
    char chute;
        printf("\nDIGITE A LETRAR PARA PALAVRA SECRETA: ");
        scanf(" %c", &chute);

        chutes[(chutesdados)] = chute;
        chutesdados++;
        
}
int verificarletra(char letra){
    int achou = 0;
    for(int j = 0; j < chutesdados; j++){
                if(chutes[j] == letra){
                    achou = 1;
                    break;
                }
            }
            return achou;
}
void desenhaforca(){
      //imprimi a palavra secreta
        for(int i = 0; i < strlen(palavrasecreta); i++){

            int achou = verificarletra(palavrasecreta[i]);
            if(achou){
                printf("{ %c } ", palavrasecreta[i]);
            } else {
                printf("|_|");
            }
        }
        printf("\n");
}
void escreverpalavra(){
    int quer;
    printf("DESEJA INSERIR UMA NOVA PALAVRA? [S/N}");
    scanf("\n%c", &quer);

    if(quer == "S"){
        char novapalavra[20];
        printf("DIGITE A PALAVRA DESEJADA: ");
        scanf(" \n%s", novapalavra);

        FILE * f;
        f = fopen("palavras.txt", "r+");
        fprintf(f, "%s", novapalavra);
        
        fclose(f);
    }
}

void escolhepalavra(){
    FILE *f;

    f = fopen("palavras.txt", "r");

    int qtdpalavras;
    fscanf(f, " %d", &qtdpalavras);

    srand(time(0));

    int randomico = rand() % qtdpalavras;

    for(int n = 0; n <= randomico; n++){
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);

    
}
int jaenforcou(){

    int erros = 0;
    for (int j= 0; j< chutesdados; j++){
        int existe = 0;

        for(int i = 0; i < strlen(palavrasecreta); i++){
            if(chutes[i] == palavrasecreta[j]){
                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }
    return erros>=5;
}

int ganhou(){
    for(int i=0; i < strlen(palavrasecreta); i++){
        if(!verificarletra(palavrasecreta[i])){
            return 0;
        }
    }
}

int main(void) {
    
    int acertou = 0;
    int enforcou = 0;

    escolhepalavra();
    abertura();

    do{

        desenhaforca();
        chutar(chutes);
        
    }while(!ganhou() && !jaenforcou()); 
    Encerrar();
    
    return 0;
}