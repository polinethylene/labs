#include "poly.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Poly *createPoly(int size, Func *func) {
    Poly * a = calloc(1, sizeof(Poly));
    a->data = calloc(1,sizeof(size));
    a->size = size;
    a->len = 0;
    a->func = func;
    return a;
}

Func *createFunc(){
    Func *func = calloc(1, sizeof(Func));
    func->add = add;
    func->concat = concat;
    func->map = map;
    func->reduce = reduce;
    func->where = where;
    return func;
}

Poly *map (void *(*f)(void *), Poly *l) {
    Poly *ans = createPoly(l->size, l->func);
    for(int i=0; i<l->len; i++) {
        void *tmp = f(((char *)l->data + i*l->size));
        ans->func->add(ans, tmp);
    }
    return ans;
}

void *reduce (void *(*f)(void *, void *), Poly *l, void *c) {
    void *ans = calloc(1,l->size);
    void *arg = c;
    for(int i=0; i<l->len; i++){
        ans = f(((char *)l->data + i*l->size), arg);
        arg = ans;
    }
    return ans;
}

Poly *where (int (*f)(void *), Poly *l) {
    Poly *ans = createPoly(l->size, l->func);
    for(int i=0; i<l->len; i++) {
        void *tmp = ((char *)l->data + i*l->size);
        if (f(tmp)){
            ans->func->add(ans, tmp);
        }
    }
    return ans;
}

Poly *concat (Poly *l, Poly *s) {
    if (s->size!=l->size){
        return NULL;
    }
    Poly *ans = createPoly(l->size, l->func);
    for(int i=0; i<l->len; i++){
        ans->func->add(ans, (char *)l->data + i*l->size);
    }
    for(int i=0; i<s->len; i++){
        ans->func->add(ans, (char *)s->data + i*s->size);
    }
    return ans;
}

void add(Poly *a, void *el) {
    a->data = realloc(a->data, (a->len+1)*a->size);
    memcpy((char *)a->data + a->len*a->size, el, a->size);
    a->len++;
}

void printPolyString(Poly *a) {
    for (int i = 0; i < a->len; i++) {
        char *tmp = *((char **) (a->data) + i);
        printf("%s\n", tmp);
    }
}

void printPolyFunction(Poly *a,const char *FUNCTION[], int FUNC_SIZE, void *function) {
    for (int i = 0; i < a->len; i++) {
        for (int j = 0; j < FUNC_SIZE; j++) {
            if ((*(int (**)(int))((char *)function + j * sizeof(int *))) ==
                    (*(int (**)(int)) ((char *) a->data + i * a->size))) {
                puts(FUNCTION[j]);
            }
        }
    }
    printf("\n");
}

void deletePoly(Poly *a){
    free(a->data);
    free(a);
}