#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
    int count=0, arr2[50];
    char arr1[50];
    scanf("%s", arr1);
    for(int i=0; arr1[i]!='\0'; i++){
        arr2[i] = arr1[i] - '0';
        count++;
    }
    for(int i=0; i<count; i++){
        printf("arr[%d]\n", arr2[i]);
    }
}