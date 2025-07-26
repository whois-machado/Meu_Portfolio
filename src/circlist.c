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
    if(lst == NULL) new->next = new;
    else{
        List* ptr = lst;
        while(ptr->next!=lst){
            ptr = ptr->next;
        }
        ptr->next = new;
        new->next = lst;
    }
    return new;
}

void lst_print(List* lst){
    if(lst == NULL){
        printf("NULL\n");
        return;
    }
    List* ptr = lst;
    do{
        printf("[%d]->", ptr->info);
        ptr = ptr->next;
    }while(ptr!=lst);
    printf("(circular list)\n");
}

int main(){
    List* lst;
    lst = lst_create();
    lst = lst_insert(lst, 5);
    lst = lst_insert(lst, 25);
    lst_print(lst);
    return 0;
}