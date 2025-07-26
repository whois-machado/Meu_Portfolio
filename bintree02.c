#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree bintree;
struct tree{
    int value;
    bintree* lcn;
    bintree* rcn;
};
bintree* create_empty(){
    return NULL;
}
int empty_tree(bintree* t){
    return (t==NULL);
}
bintree* create_tree(int number, bintree* left, bintree* right){
    bintree* t = (bintree*)malloc(sizeof(bintree));
    t->value = number;
    t->lcn = left;
    t->rnc = right;
    return t;  
}
bintree* release_tree(bintree* t){
    while(!empty_tree(t)){
        release_tree(t->lcn);
        release_tree(t->rcn);
        free(t);
    }
    return NULL;
}
int belongs_tree(int number, bintree* t){
    if(empty_tree(t)) return 0;
    else{
        return t->value ||
        belongs_tree(number, t->lcn) ||
        belongs_tree(number, t->rcn);
    }
}
void print_tree(bintree* t){
    printf("<");
    if(!empty_tree(t)){
        printf("%d", t->value);
        print_tree(t->lcn);
        print_tree(t->rcn);
    }
    printf(">");
}
void main(){}











