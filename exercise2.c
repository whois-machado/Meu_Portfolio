/*
Considere a implementcao de uma lista encadeada para
armazenar as notas dos alunos de uma turma. O tipo que
representa a lista eh dado a seguir:

typedef struct lista Lista;
struct lista {
    char nome[81];
    float nota;
    Lista *prox;
};

Escreva uma funcao para retornar a quantidade de alunos
aprovados na turma, assumindo que a media para passar eh 5. Se a
lista for vazia, deve -se retornar o valor zero. O prototipo da funcao
deve ser:
    int aprovados (Lista* l);

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list List;
struct list {
    char name[81];
    float score;
    List* next;
};

List* create(){
    return NULL;                              
}

List* insert(List* lst, char* name, float score){
    List* new = (List*)malloc(sizeof(List));
    strncpy(new->name, name, sizeof(new->name) - 1); 
    new->name[sizeof(new->name) - 1] = '\0';
    new->score = score;
    new->next = lst;
    return new;
}

int aprove(List* lst){
    List* ptr;
    int count = 0;
    if(ptr == NULL) return count;
    for(ptr=lst; ptr!=NULL; ptr=ptr->next){
        if(ptr->score >= 5){
            count++;
        }
    }
    return count;
}

void main(){
    List* lst;
    const char* turma[] = {"jack", "bruce", "amanda", "simone"};
    lst = create();
    lst = insert(lst, "jack", 8.5);
    lst = insert(lst, "bruce", 3.6);
    lst = insert(lst, "amanda", 9.2);
    lst = insert(lst, "simone", 5.0);
    int count = aprove(lst);
    printf("quantidade de alunos aprovados: %d\n", count);
}