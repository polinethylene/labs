#include "functions.h"
#include <stdlib.h>
#include <string.h>

void *FirstWord(void *l){
    int i = 0;
    char **res = calloc(1, sizeof(char *));
    while((*(char **)l)[i]!=' ' && (*(char **)l)[i]!='\0'){
        i++;
    }
    *res = calloc(i,sizeof(char));
    memcpy(*res, *(char **)l, i*sizeof(char));
    return res;
}

int IsVowel(void *l){
    if (!l){
        return 0;
    }
    int i = 0;
    char dict[] = "aeyuioAEYUIO";
    if (strchr (dict,(*(char **)l)[0])){
        i = 1;
    }
    return i;
}

void *Compare_Min(void *l, void *s){
    if((*(char **)l)[0]<(*(char **)s)[0]){
        return l;
    }
    else {
        return s;
    }
}

int add_two(int a){
    return a+2;
}

int square(int a){
    return a*a;
}

int mult_two(int a){
    return a*2;
}

int sum(int a){
    return a+a;
}

int mult_ten(int a){
    return a*10;
}

int add_one(int a){
    return a+1;
}

