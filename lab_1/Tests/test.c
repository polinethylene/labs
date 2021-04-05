#define CTEST_MAIN
#include "main.c"
#include "../poly.h"
#include "../functions.h"

void *q = mult_two;

void *EvenOutput(void *f){
    if ( (*(int (**)(int))f)(2)%2 == 0){
        return f;
    } else {
        return &q;
    }
}

int EvenOutputBool(void *f){
    if ( (*(int (**)(int))f)(2)%2 == 0){
        return 1;
    } else {
        return 0;
    }
}

void *LessOutput(void *f, void *l){
    if ( ((*(int (**)(int))f)(2)) < ((*(int (**)(int))l)(2))){
        return f;
    } else {
        return l;
    }
}

CTEST(Poly, Create) {
    Func *func = createFunc();
    Poly *a = createPoly(sizeof(char *), func);
    ASSERT_EQUAL (0, a->len);
    ASSERT_EQUAL (sizeof(char *), a->size);
}

CTEST(PolyChar, Functions) {
    Func *func = createFunc();
    Poly *a = createPoly(sizeof(char *), func);
    char *line1 = "aa bb cc";
    char *line2 = "bb aa cc";
    char *line3 = "00 fgrw";
    char *line4 = " $#sd i";
    a->func->add(a, &line1);
    a->func->add(a, &line2);
    a->func->add(a, &line3);
    a->func->add(a, &line4);
    Poly *ansm = a->func->map(FirstWord, a);
    Poly *answ = a->func->where(IsVowel, a);
    char *ansr = a->func->reduce(Compare_Min, a, &line1);
    ASSERT_STR ("aa", *((char **) (ansm->data) ));
    ASSERT_STR ("bb", *((char **) (ansm->data) + 1));
    ASSERT_STR ("00", *((char **) (ansm->data) + 2));
    ASSERT_STR ("", *((char **) (ansm->data) + 3));

    ASSERT_STR ("aa bb cc", *((char **) (answ->data)));
    ASSERT_STR (" $#sd i", *(char **)ansr );

    Poly *b = createPoly(sizeof(char *), func);
    b->func->add(b, &line1);
    b->func->add(b, &line2);
    Poly *ans = a->func->concat(a,b);
    ASSERT_STR ("aa bb cc", *((char **) (ans->data) + 4));
}

CTEST(PolyFunc, Functions) {
    Func *func = createFunc();
    Poly *a = createPoly(sizeof(char *), func);
    void *x = EvenOutput;
    void *y = EvenOutputBool;
    void *z = LessOutput;
    void *r = sum;
    void *s = mult_ten;
    void *v = add_one;
    a->func->add(a, &r);
    a->func->add(a, &s);
    a->func->add(a, &v);
    Poly *ansm = a->func->map(x, a);
    Poly *answ = a->func->where(y, a);
    void *ansr = a->func->reduce(z, a, &s);

    ASSERT_EQUAL ((int (*)(int))r, (*(int (**)(int))((char *) ansm->data)));
    ASSERT_EQUAL ((int (*)(int))s, (*(int (**)(int))((char *) ansm->data + a->size)));
    ASSERT_EQUAL ((int (*)(int))q, (*(int (**)(int))((char *) ansm->data + 2 * a->size)));

    ASSERT_EQUAL ((int (*)(int))r, (*(int (**)(int))((char *) answ->data)));
    ASSERT_EQUAL ((int (*)(int))s, (*(int (**)(int))((char *) answ->data + a->size)));
    ASSERT_EQUAL ((int (*)(int))v, *(int (**)(int))ansr);

    Poly *b = createPoly(sizeof(char *), func);
    void *t = add_two;
    void *u = square;
    b->func->add(b, &t);
    b->func->add(b, &u);
    Poly *ans = a->func->concat(a,b);
    ASSERT_EQUAL ((int (*)(int))t, (*(int (**)(int))((char *) ans->data + 3 * a->size)));
    ASSERT_EQUAL ((int (*)(int))t, (*(int (**)(int))((char *) ans->data + 4 * a->size)));
}