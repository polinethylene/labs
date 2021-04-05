#ifndef LAB_1_POLY_H
#define LAB_1_POLY_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Poly Poly;
typedef struct Func Func;

struct Poly {
    void *data;
    size_t size;
    int len;

    Func *func;
};

struct Func {
    void (*add)(Poly *, void *);
    Poly * (*map)(void *(*)(void *), Poly *);
    void * (*reduce)(void *(*)(void *, void *), Poly *, void *);
    Poly * (*where)(int (*)(void *), Poly *);
    Poly * (*concat)(Poly *, Poly *);
};

Poly *createPoly(int, Func *);
Func *createFunc();
Poly *map (void *(*f)(void *), Poly *l);
void *reduce (void *(*f)(void *, void *), Poly *l, void *c);
Poly *where (int (*f)(void *), Poly *l);
Poly *concat (Poly *l, Poly *s);
void add(Poly *a, void *el);
void printPolyString(Poly *a);
void printPolyFunction(Poly *a,const char *FUNCTION[], int FUNC_SIZE, void *function);
void deletePoly(Poly *a);

#endif //LAB_1_POLY_H
