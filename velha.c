#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int a, b, c, d;
    int count = 0;
    char velha[3][3];
    //preenchendo a matriz[3][3] com valores '?'
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            velha[i][j] = '?'; 
        }
    }
    //mostrando a interface inicial do jogo ao user
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf(" %c  ", velha[i][j]); 
        }
        printf("\n\n");
    }
    while(count == 0){
        printf("escolha a casa q deseja preencher: ");
        scanf("%d %d", &a, &b);
        velha[a][b] = 'X';
        c = rand() % 3;
        d = rand() % 3;
        while(c == a && d == b){
            c = rand() % 3;
            d = rand() % 3; 
        }
        velha[c][d] = 'O';

        for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf(" %c  ", velha[i][j]); 
        }
        printf("\n\n");
        }

        //you win nas linhas
        if(velha[0][0] == velha[0][1] && velha[0][1] == velha[0][2] && velha[0][0] == 'X') count = 1;
        if(velha[1][0] == velha[1][1] && velha[1][1] == velha[1][2] && velha[1][0] == 'X') count = 1;
        if(velha[2][0] == velha[2][1] && velha[2][1] == velha[2][2] && velha[2][0] == 'X') count = 1;
        //you win nas diagonais
        if(velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2] && velha[0][0] == 'X') count = 1;
        if(velha[2][0] == velha[1][1] && velha[1][1] == velha[0][2] && velha[2][0] == 'X') count = 1;
        //you win nas colunas
        if(velha[0][0] == velha[1][0] && velha[1][0] == velha[2][0] && velha[0][0] == 'X') count = 1;
        if(velha[0][1] == velha[1][1] && velha[1][1] == velha[2][1] && velha[0][1] == 'X') count = 1;
        if(velha[0][2] == velha[1][2] && velha[1][2] == velha[2][2] && velha[0][0] == 'X') count = 1;

        //machine wins nas linhas
        if(velha[0][0] == velha[0][1] && velha[0][1] == velha[0][2] && velha[0][0] == 'O') count = 2;
        if(velha[1][0] == velha[1][1] && velha[1][1] == velha[1][2] && velha[1][0] == 'O') count = 2;
        if(velha[2][0] == velha[2][1] && velha[2][1] == velha[2][2] && velha[2][0] == 'O') count = 2;
        //machine wins nas diagonais
        if(velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2] && velha[0][0] == 'O') count = 2;
        if(velha[2][0] == velha[1][1] && velha[1][1] == velha[0][2] && velha[2][0] == 'O') count = 2;
        //machine wins nas colunas
        if(velha[0][0] == velha[1][0] && velha[1][0] == velha[2][0] && velha[0][0] == 'O') count = 2;
        if(velha[0][1] == velha[1][1] && velha[1][1] == velha[2][1] && velha[0][1] == 'O') count = 2;
        if(velha[0][2] == velha[1][2] && velha[1][2] == velha[2][2] && velha[0][0] == 'O') count = 2;
    }
    if(count == 1) printf("you win!\n");
    if(count == 2) printf("machine wins!\n");

    return 0;
}