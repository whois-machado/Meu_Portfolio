#include <stdio.h>
#include <stdlib.h>
#define RET 0
#define TRI 1
#define CIR 2
#define PI 3,14

struct retangulo{
    float b;
    float h;
};
typedef struct retangulo ret;

struct triangulo{
    float b;
    float h;
};
typedef struct triangulo tri;

struct circulo{
    float r;
};
typedef struct circulo cir;

typedef struct list List;
struct list{
    int tipo;
    void* info; 
    List* next;
};
List* lst_create(){
    return NULL;
}

List* create_ret(float b, float h){
    ret* r = (ret*)malloc(sizeof(ret));
    r->b = b;
    r->h = h;
    List* ptr = (List*)malloc(sizeof(List));
    ptr->tipo = RET;
    ptr->info = r;
    ptr->next = NULL;
    return ptr; 
}

List* create_tri(float b, float h){
    tri* t = (tri*)malloc(sizeof(tri));
    t->b = b;
    t->h = h;
    List* ptr = (List*)malloc(sizeof(List));
    ptr->tipo = TRI;
    ptr->info = t;
    ptr->next = NULL;
    return ptr; 
}

List* create_cir(float r){
    cir* c = (cir*)malloc(sizeof(cir));
    c->r = r;
    List* ptr = (List*)malloc(sizeof(List));
    ptr->tipo = CIR;
    ptr->info = c;
    ptr->next = NULL;
    return ptr; 
}

static float area_ret(ret* r){
    return (r->b * r->h);
}
static float area_tri(tri* t){
    return ((t->b * t->h)/2);
}
static float area_cir(cir* c){
    return (PI * c->r * c->r);
}

float area(List* lst){
    float area;
    switch(lst->tipo){
        case RET:
            area = area_ret((ret*)lst->info);
            break;
        case TRI:
            area = area_tri((tri*)lst->info);
            break;
        case CIR:
            area = area_cir((cir*)lst->info);
            break;
    }
    return area;
}

void main(){
    List* lst;
    float b = 3, h = 4;
    lst = lst_create();
    lst = create_tri(b, h);
    float result;
    result = area(lst);
    printf("base tri: %.1f\taltura tri: %.1f\n", b, h);
    printf("area = %.1f\n", result);

}