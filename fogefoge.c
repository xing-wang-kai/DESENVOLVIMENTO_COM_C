#include <stdio.h>
char mapa[5][10+1];
int linhas;
int colunas;


int main(void){
    

    FILE *f;
    f = fopen("mapa.txt", "r");
    if(f == 0){
        printf("[ERROR] - Ocorreu um erro na leitura do arquivo\n");
    }

    fscanf(f, "%d %d", &linhas, &colunas);
    printf("LINHAS: [%d] COLUNAS [%d] \n\n", linhas, colunas);
    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", mapa[i]);

    }
    for (int j = 0; j < 5; j++){
        printf("%s\n", mapa[j] );
    }

    fclose(f);

    return 0;
}

