#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

int search_bin(int size, int *array, int element){

    int start = 0;
    int end = size-1;
    int middle;
    while(start <= end){
        middle = (start+end)/2;
        if(element > array[middle]){
            start = middle+1;
        }
        else if(element < array[middle]){
            end = middle-1;
        }
        else{
            return middle;
        }
    }
    return -1;
}

int main(){
    int array[] = {1, 4, 5, 7, 9, 11, 16, 21};
    size_t size = sizeof(array)/sizeof(array[0]);
    int element;
    scanf("%d", &element);
    int result = search_bin(size, array, element);
    #pragma omp parallel
    if(result == -1){
        printf("elemento nao existe nessa lista\n");
    }
    else{
        printf("elemento na posicao [%d]\n", result); 
    } 
    return 0;
}