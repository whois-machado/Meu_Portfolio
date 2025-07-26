#include <stdio.h>
#include<omp.h>
#include<stdlib.h>
// #define N 1000
int N;

void sum(double** A, double** B, double** C){
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            C[i][j] = A[i][j]+B[i][j];
        }
    }
}

void mult(double** A, double** B, double** D){       
    #pragma omp parallel for colapse(2)             
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            D[i][j] = 0;
            for(int k=0; k<N; k++){
                D[i][j] += A[i][k]*B[k][j];
            }
        }
    }
} 

int main(int argc, char* argv[]){


    N = atoi(argv[1]); //valor de N na linha de comando ao executar
    double** A = (double**)malloc(N*sizeof(double*));
    double** B = (double**)malloc(N*sizeof(double*));
    double** C = (double**)malloc(N*sizeof(double*));
    double** D = (double**)malloc(N*sizeof(double*));
    for(int i=0; i<N; i++){
        A[i] = (double*)malloc(N*sizeof(double));
        B[i] = (double*)malloc(N*sizeof(double));
        C[i] = (double*)malloc(N*sizeof(double));
        D[i] = (double*)malloc(N*sizeof(double));
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == j){
                A[i][j] = 1;
            }
            else{
                A[i][j] = 0;
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == j+1){
                B[i][j] = 7;
            }
            else{
                B[i][j] = 4;
            }
        }
    }
  //  sum(A, B, C);
    mult(A, B, D);
/*
    printf("matriz A: \n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%.0f  ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("matriz B: \n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%.0f  ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    sum(A, B, C);
    printf("matriz C(sum): \n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%.0f  ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    mult(A, B, D);
    printf("matriz D(mult): \n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%.0f  ", D[i][j]);
        }
        printf("\n");
    } */ 
    for(int i=0; i<N; i++){
        free(A[i]);
        free(B[i]);
        free(C[i]);
        free(D[i]);
    } 
    free(A);
    free(B);
    free(C);
    free(D);

    return 0;
}
