#include <stdio.h>
#include <stdlib.h>

typedef struct list2 List2;
struct list2{
    int info;
    List2* prev;
    List2* next;
};

List2* lst_create(){
    return NULL;
}

List2* lst_search(List2* lst, int value){
    List2* ptr = lst;
    int count = 0;
    for(ptr; ptr!=NULL; ptr=ptr->next){
        count++;
        if(ptr->info == value){
        printf("no[%d] = %d\n", count, value);
        return ptr;
        }
    }
    return NULL;
}

List2* lst_insert(List2* lst, int value){
    List2* new_node = (List2*)malloc(sizeof(List2));
    new_node->info = value;
    new_node->prev = NULL;
    new_node->next = lst;
    if(lst!=NULL) lst->prev = new_node;
    return new_node;
}

List2* lst_remove(List2* lst, int value){
    List2* ptr = lst_search(lst, value);
    if(ptr == NULL){ // lst_search retornou NULL pq nao achou o node
        return lst;
    }
    if(lst == ptr){ // se o node removido for o primeiro da lista, so lst apontar para o prox node 
        lst = ptr->next;
    } else{ 
        ptr->prev->next = ptr->next;
    }
    if(ptr->next != NULL){
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
    return lst;
}

void lst_printf(List2* lst){
    List2* ptr;
    for(ptr=lst; ptr!=NULL; ptr=ptr->next){
        printf("[%d]<->", ptr->info);
    }
    if(ptr==NULL)printf("NULL\n");
}

int main(){
    List2* lst;
    lst = lst_create();
    lst = lst_insert(lst, 11);
    lst = lst_insert(lst, 7);
    lst = lst_insert(lst, 5);
    lst = lst_insert(lst, 3);
    lst = lst_insert(lst, 0);
    printf("linked2list previous: ");
    lst_printf(lst);
    lst_search(lst, 3);
    printf("linked2list after remove a node: ");
    lst = lst_remove(lst, 11);
    lst_printf(lst);
    return 0;
}