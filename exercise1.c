#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Escreva uma funcao que receba como parametros uma lista
encadeada e uma string, e retire da lista todos os nos que
armazenam uma string igual aquela passada como parametro. A
funcao deve ter como valor de retorno o ponteiro para o primeiro no
da lista resultante. O prototipo dessa funcao eh dado por:
                                                            Lista* retira (Lista* l, char* n);
*/

typedef struct list List;
struct list {
    char* str; /* string armazenada */
    List* next; /* ponteiro para proximo elemento */
};
List* create(){
    return NULL;
}
List* insert_node(List* lst, const char* str){
    List* new = (List*)malloc(sizeof(List));        
    new->str = strdup(str);
    new->next = lst;
    return new;
}
List* remove_node(List* lst, char* str){
    List* ptr = lst;
    List* prev = NULL;
    
    while(ptr!=NULL){
        if(strcmp(ptr->str, str) == 0){
            List* swap = ptr; 
            if(prev == NULL){
            lst = ptr->next;
            } else{
            prev->next = ptr->next;
            }
        ptr = ptr->next;
        free(swap);
        return lst;
        } else{
            prev = ptr;
            ptr = ptr->next;
        }
    
    }
    return lst;   
}
void printf_list(List* lst){
    List* ptr = lst;
    while(ptr!=NULL){
        printf("%s ", ptr->str);
        ptr = ptr->next;
    }
    printf("\n");
}
void main(){
    char str[] = "Hello";
    char arr[] = "World";
    List* lst = create();
    lst = insert_node(lst, str);
    lst = insert_node(lst, arr);
    lst = insert_node(lst, "Planet");
    printf_list(lst);
    lst = remove_node(lst, "Planet");
    printf_list(lst);
}