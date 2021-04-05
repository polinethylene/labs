#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "poly.h"
#include "functions.h"

const char *MENU[] = {"0. Quit", "1. Add elements", "2. Print", "3. Map", "4. Where", "5. Reduce", "6. Concatenate",
                      "7. Generate elements"};
const int MENU_SIZE = sizeof(MENU) / sizeof(MENU[0]);

const char *MAPFUNCTION[] = {"0. FirstWord (char -> char, 1 arg)",
                             "1. EvenOutput (int f -> int f, 1 arg)"};
const int MAPFUNC_SIZE = sizeof(MAPFUNCTION) / sizeof(MAPFUNCTION[0]);

const char *WHEREFUNCTION[] = {"0. IsVowel (char -> bool, 1 arg)",
                               "1. EvenOutputBool (int f -> bool, 1 arg)"};
const int WHEREFUNC_SIZE = sizeof(WHEREFUNCTION) / sizeof(WHEREFUNCTION[0]);

const char *REDUCEFUNCTION[] = {"0. Compare_Min (char, char -> char, 2 args)",
                                "1. LessOutput (int f, int f -> int f, 2 args)"};
const int REDUCEFUNC_SIZE = sizeof(REDUCEFUNCTION) / sizeof(REDUCEFUNCTION[0]);

const char *FUNCTION[] = {"0. int add_two(int a)", "1. int square(int a)",
                          "2. int mult_two(int a)", "3. int sum(int a)",
                          "4. int mult_ten(int a)", "5. int add_one(int a)"};
const int FUNC_SIZE = sizeof(FUNCTION) / sizeof(FUNCTION[0]);

void *t = add_two;
void *u = square;
void *q = mult_two;
void *r = sum;
void *s = mult_ten;
void *v = add_one;

int dialog(const char *menu[], int n) {
    char *error = "";
    int choice;
    for (int i = 0; i < n; ++i) {
        puts(menu[i]);
    }
    puts("Make your choice: ");
    do {
        printf("%s", error);
        error = "Wrong input. Make your choice:\n";
        scanf("%d", &choice);
        while (getchar() != '\n') {}
    } while (choice < 0 || choice >= n);
    return choice;
}

char *get_str() {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    printf("Enter line\n");
        do {
            n = scanf("%80[^\n]", buf);
            if (n < 0) {
                if (!res) {
                    return NULL;
                }
            } else if (n > 0) {
                int chunk_len = strlen(buf);
                int str_len = len + chunk_len;
                res = realloc(res, str_len + 1);
                memcpy(res + len, buf, chunk_len);
                len = str_len;
            } else {
                scanf("%*c");
            }
        } while (n > 0);
        if (len > 0) {
            res[len] = '\n';
            len += 1;
        }

    if (len > 0) {
        res[len-1] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }

    return res;
}

char *generate_str(int len) {
    char *data = calloc(len+1, sizeof(char));
    int sh = 0;
    int r = 0;
    for (int i = 0; i < len; ++i) {
        r = rand()%4;
        if (r){
            data[i+sh] = rand()%95 + 32;
        } else{
            data[i+sh] = ' ';
        }
    }
    sh += len+1;
    data[sh-1]='\n';
    data[sh-1] = '\0';
    return data;
}

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

int main(){
    srand(time(NULL));
    void *x = FirstWord;
    void *y = IsVowel;
    void *z = Compare_Min;
    void *j = EvenOutput;
    void *k = EvenOutputBool;
    void *e = LessOutput;
    void *mapfunction = calloc(MAPFUNC_SIZE, sizeof(int *));
    void *wherefunction = calloc(WHEREFUNC_SIZE, sizeof(int *));
    void *reducefunction = calloc(REDUCEFUNC_SIZE, sizeof(int *));
    memcpy(mapfunction, &x, sizeof(int *));
    memcpy((char *)mapfunction + sizeof(int *), &j, sizeof(int *));
    memcpy(wherefunction, &y, sizeof(int *));
    memcpy((char *)wherefunction + sizeof(int *), &k, sizeof(int *));
    memcpy(reducefunction, &z, sizeof(int *));
    memcpy((char *)reducefunction + sizeof(int *), &e, sizeof(int *));

    void *function = calloc(FUNC_SIZE, sizeof(int *));
    memcpy(function, &t, sizeof(int *));
    memcpy((char *)function + sizeof(int *), &u, sizeof(int *));
    memcpy((char *)function + 2*sizeof(int *), &q, sizeof(int *));
    memcpy((char *)function + 3*sizeof(int *), &r, sizeof(int *));
    memcpy((char *)function + 4*sizeof(int *), &s, sizeof(int *));
    memcpy((char *)function + 5*sizeof(int *), &v, sizeof(int *));

    int c = 0, type = 0;
    int choice;
    char ch = ' ';
    printf("Choose data type:\n");
    printf("1 - string, 2 - function");
    char *error = "";
    do {
        puts(error);
        error = "Wrong input. Make your choice:";
        scanf("%d", &type);
        while (getchar() != '\n') {}
    } while(type!=1 && type!=2);

    Func *func = createFunc();
    Poly *arr = createPoly(sizeof(char *), func);
    char *line = 0;
    do {
        c = dialog(MENU, MENU_SIZE);
        switch(c) {
            case 0:
                free(func);
                free(function);
                free(mapfunction);
                free(wherefunction);
                free(reducefunction);
                if (type == 1){
                    for (int i = 0; i < arr->len; i++) {
                        free(*((char **) (arr->data) + i));
                    }
                }
                deletePoly(arr);
                break;
            case 1:
                if (type == 1) {
                    do {
                        line = get_str();
                        arr->func->add(arr, &line);
                        printf("Continue input? (n or any other)");
                        ch = (char) getchar();
                        while (getchar() != '\n') {}
                    } while (ch != 'n');
                }
                if (type == 2) {
                    do {
                        printf("Choose function:\n");
                        choice = dialog(FUNCTION, FUNC_SIZE);
                        arr->func->add(arr,((char *)function + choice*sizeof(int *)));
                        printf("Continue input? (n or any other)");
                        ch = (char) getchar();
                        while (getchar() != '\n') {}
                    } while (ch != 'n');
                }
                break;
            case 2:
                if (type == 1) {
                    printPolyString(arr);
                }
                if (type == 2) {
                    printPolyFunction(arr, FUNCTION, FUNC_SIZE, function);
                }
                break;
            case 3:
                printf("Choose function:\n");
                choice = dialog(MAPFUNCTION, MAPFUNC_SIZE);
                Poly *ansm = arr->func->map((*(void *(**)(void *))((char *)mapfunction + choice*sizeof(int *))), arr);

                if (type == 1) {
                    printPolyString(ansm);
                }
                if (type == 2) {
                    printPolyFunction(ansm, FUNCTION, FUNC_SIZE, function);
                }
                if (type == 1){
                    for (int i = 0; i < ansm->len; i++) {
                        free(*((char **) (ansm->data) + i));
                    }
                }
                deletePoly(ansm);
                break;
            case 4:
                printf("Choose function:\n");
                choice = dialog(WHEREFUNCTION, WHEREFUNC_SIZE);
                Poly *answ = arr->func->where((*(int (**)(void *))((char *)wherefunction + choice*sizeof(int *))), arr);
                if (type == 1) {
                    printPolyString(answ);
                }
                if (type == 2) {
                    printPolyFunction(answ, FUNCTION, FUNC_SIZE, function);
                }
                deletePoly(answ);
                break;
            case 5:
                printf("\n");
                void *l;
                if (type == 1) {
                    l = get_str();
                }
                if (type == 2) {
                    printf("Choose start function:\n");
                    choice = dialog(FUNCTION, FUNC_SIZE);
                    l = *(void *(**)(void *))((char *)function + choice*sizeof(int *));
                }
                printf("Choose reduce function:\n");
                choice = dialog(REDUCEFUNCTION, REDUCEFUNC_SIZE);
                void *ansr = arr->func->reduce((*(void *(**)(void *, void *))((char *)reducefunction + choice*sizeof(int *))),
                                               arr, &l);
                if (type == 1) {
                    printf("str - %s\n", *(char **)ansr);
                }
                if (type == 2) {
                    for (int j = 0; j < FUNC_SIZE; j++) {
                        if ((*(int (**)(int)) ((char *) function + j * sizeof(int *))) ==
                            (*(int (**)(int)) ansr)) {
                            puts(FUNCTION[j]);
                        }
                    }
                    printf("\n");
                }
                break;
            case 6:
                printf("Input array:\n");
                Poly *arr2 = createPoly(sizeof(char *), func);
                if (type == 1) {
                    do {
                        line = get_str();
                        arr2->func->add(arr2, &line);
                        printf("Continue input? (n or any other)");
                        ch = (char)getchar();
                        while (getchar() != '\n') {}
                    } while (ch != 'n');
                }
                if (type == 2) {
                    do {
                        printf("Choose function:\n");
                        choice = dialog(FUNCTION, FUNC_SIZE);
                        arr2->func->add(arr2,((char *)function + choice*sizeof(int *)));
                        printf("Continue input? (n or any other)");
                        ch = (char) getchar();
                        while (getchar() != '\n') {}
                    } while (ch != 'n');
                }
                Poly *ansc = arr->func->concat(arr,arr2);
                if (type == 1) {
                    printPolyString(ansc);
                    if (type == 1){
                        for (int i = 0; i < arr2->len; i++) {
                            free(*((char **) (arr2->data) + i));
                        }
                    }
                    deletePoly(arr2);
                    deletePoly(ansc);
                }
                if (type == 2) {
                    printPolyFunction(ansc, FUNCTION, FUNC_SIZE, function);
                    deletePoly(arr2);
                    deletePoly(ansc);
                }
                break;
            case 7:
                if (type == 1){
                    do {
                        int check = 0;
                        int len = 0;
                        char *error = "";
                        do {
                            printf("%s", error);
                            error = "Wrong input.\n";
                            printf("Enter size of line:\n");
                            check = scanf("%d",&len);
                            if (len<0){
                                check = 0;
                            }
                            while (getchar() != '\n') {}
                        } while (check == 0);
                        line = generate_str(len);
                        arr->func->add(arr, &line);
                        printf("Continue generating? (n or any other)");
                        ch = (char)getchar();
                        while (getchar() != '\n') {}
                    } while(ch != 'n');
                }
                if (type == 2) {
                    int count = 0;
                    do {
                        count++;
                        choice = rand()%FUNC_SIZE;
                        arr->func->add(arr,((char *)function + choice*sizeof(int *)));
                        printf("Generated %d element\n", count);
                        printf("Continue generating? (n or any other)");
                        ch = (char) getchar();
                        while (getchar() != '\n') {}
                    } while (ch != 'n');
                }
                break;
        }
    } while (c != 0);

    return 0;
}