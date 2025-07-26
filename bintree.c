#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree BinTree;
struct tree{
    char info;
    BinTree* lcn; //left child node
    BinTree* rcn; //right child node
};
BinTree* create_empty(){
    return NULL;
}
int empty_tree(BinTree* t){
    return t==NULL; // 0 or 1
}
BinTree* create_tree(char c, BinTree* left, BinTree* right){
    BinTree* t = (BinTree*)malloc(sizeof(BinTree));
    t->info = c;
    t->lcn = left;
    t->rcn = right;
    return t;
}
BinTree* release_tree(BinTree* t){ // release nodes
    if(!empty_tree(t)){
        release_tree(t->lcn);
        release_tree(t->rcn);
        free(t);
    }
    return NULL;
}
int belongs_tree(char c, BinTree* t){ //check if 'c' belongs to the tree
    if(empty_tree(t)) return 0;
    else{
        return t->info = c ||
        belongs_tree(c, t->lcn) ||
        belongs_tree(c, t->rcn);
    }
}                                                                             
void printf_tree(BinTree* t){                                              
    printf("<");                                                            
    if(!empty_tree(t)){
        printf("%c\n", t->info);
        printf_tree(t->lcn);
        printf_tree(t->rcn);
    }
    printf(">");
}
void main(){
    BinTree* t = create_empty();
    t = create_tree('a',
        create_tree('b',
            create_empty(),
            create_tree('d', create_empty(), create_empty())
        ),
        create_tree('c',
            create_tree('e', create_empty(), create_empty()),
            create_tree('f', create_empty(), create_empty())
        )
    );
    printf_tree(t);
}
