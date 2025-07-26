#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node Node;
struct node{
    float info;
    Node* next;
};
struct stack{
    Node* first;
};
typedef struct stack Stack;

Stack* create_stack(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->first = NULL;
    return s;
}

int check_stack(Stack* s){
    if(s->first == NULL) 
        return 1;
    return 0;
}

void push_stack(Stack* s, float v){
    Node* new = (Node*)malloc(sizeof(Node));
    new->info = v;
    new->next = s->first;
    s->first = new;
}

float pop_stack(Stack* s){
    Node* t;
    float v;
    if(check_stack(s)) exit(1); 
    t = s->first;
    v = t->info;
    s->first = t->next;
    free(t);
    return v;
}

void printf_stack(Stack* s){
    Node* q = s->first;
    while(q!=NULL){
        printf("[%.1f]\n", q->info);
        printf("_____\n");
        q = q->next;
    }
}

void release_stack(Stack* s){
    Node* p;
    Node* q = s->first;
    while(q!=NULL){
        p = q->next;
        free(q);
        q = p;
    }
    free(p);
}

void main(){
    Stack* s = create_stack();
    if(check_stack(s)) printf("empty stack\n");
    push_stack(s, 0.5);
    push_stack(s, 4.0);
    push_stack(s, 7.5);
    if(check_stack(s)) printf("empty stack\n");
    else printf("no empty\n");
    printf_stack(s);
}