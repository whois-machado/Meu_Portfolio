#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
    float info;
    Node* next;
};

typedef struct queue Queue;
struct queue{
    Node* first;
    Node* last;
};

Queue* create_queue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->first = q-> last = NULL;
    return q;
}
int check_queue(Queue* q){
    if(q->first == NULL)
        return 1;                                    
    return 0;
}
void insert_queue(Queue* q, float v){
    Node* new = (Node*)malloc(sizeof(Node));
    new->info = v;
    new->next = NULL;
    if(q->last!=NULL){
        q->last->next = new;
    }
    else{
        q->first = new;
    }
    q->last = new;
}
void printf_queue(Queue* q){
    Node* p = q->first;
    while(p->next!=NULL){
        printf("[%.1f]->", p->info);
        p = p->next;
    }
    printf("[%.1f]", p->info);
    printf("\n");
}
void main(){
    Queue* q;
    q = create_queue();
    if(check_queue(q)) printf("empty queue\n");
    else printf("no empty\n");
    insert_queue(q, 2);
    insert_queue(q, 4);
    insert_queue(q, 6);
    if(check_queue(q)) printf("empty queue\n");
    else printf("no empty\n");
    printf_queue(q);
}