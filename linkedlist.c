#include <stdio.h>
#include <stdlib.h>

typedef struct lista List;
struct lista{
    int info;
    List* next;
};

List* lst_create(){
    return NULL;
}

List* lst_insert(List* lst, int value){
    List* new = (List*)malloc(sizeof(List));
    new->info = value;
    new->next = lst;
    return new;
}

List* lst_ord_insert(List* lst, int value){
    List* prev = NULL;
    List* ptr = lst;
    while(ptr!=NULL && ptr->info<value){
        prev = ptr;
        ptr = ptr->next;
    }
    List* new = (List*)malloc(sizeof(List));
    new->info = value;
    new->next = NULL;
    if(prev == NULL){
        new->info = value;
        lst = new;
    }
    else{
        new->next = prev->next;
        prev->next = new;
    }
    return lst;
}

List* lst_remove(List* lst, int value){
    List* ptr = lst;
    List* prev = NULL;
    while(ptr!=NULL && ptr->info!=value){
        prev = ptr;
        ptr = ptr->next;
    }
    if(ptr == NULL) return lst; //nao achou e retorna a lista
    if(prev == NULL) lst = ptr->next;
    else{
        prev-> next = ptr-> next;
    } 
    free(ptr);
    return lst;
}

void lst_printf(List* lst){
    List* ptr;
    for(ptr=lst; ptr!=NULL; ptr=ptr->next){
        printf("[%d]->", ptr->info);
    }
    if(ptr==NULL)printf("NULL\n");
}

int main(){
    List* lst;
    lst = lst_create();
    lst = lst_insert(lst, 11);
    lst = lst_insert(lst, 7);
    lst = lst_insert(lst, 5);
    lst = lst_insert(lst, 3);
    lst = lst_insert(lst, 0);

    printf("lista inicial:\n");
    lst_printf(lst); // [0]->[3]->[5]->[7]->[11]->NULL
    lst = lst_remove(lst, 7);
    printf("lista apos remover o no com valor 7:\n");
    lst_printf(lst); // [0]->[3]->[5]->[11]->NULL
    lst = lst_ord_insert(lst, 1);
    printf("lista apos inserir o no com valor 1 de forma ordenada:\n");
    lst_printf(lst); // [0]->[1]->[3]->[5]->[11]->NULL

    return 0;
}