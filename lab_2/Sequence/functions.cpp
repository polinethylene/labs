#include "functions.h"
#include "../Complex.h"

int add_two(int a){
    return a+2;
}

int square(int a){
    return a*a;
}

int mult_tree(int a){
    return a*3;
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

float add_four(float a){
    return a+4;
}
float minus_ten_half(float a){
    return a-10.5;
}
float divide_by_two(float a){
    return a/2;
}

Complex add_treetree(Complex a){
    Complex b = Complex(3,3);
    return a+b;
}

Complex minus_tenten(Complex a){
    Complex b = Complex(-10,-10);
    return a+b;
}

Complex mult_two(Complex a){
    Complex b = Complex(2,0);
    return a*b;
}

bool is_even (int a){
    if (a%2==0){
        return true;
    } else {
        return false;
    }
}

bool is_positive (int a){
    if (a>0){
        return true;
    } else {
        return false;
    }
}

bool compare_two (float a){
    if (a>2){
        return true;
    } else {
        return false;
    }
}
bool float_positive (float a){
    if (a>0){
        return true;
    } else {
        return false;
    }
}

bool comp_mod_two (Complex a){
    float absm = sqrt(a.Im*a.Im+a.Re*a.Re);
    if (absm>2){
        return true;
    } else {
        return false;
    }
}

int less_number(int a, int b){
    if (a>b){
        return b;
    } else {
        return a;
    }
}

float higher_number(float a, float b){
    if (a>b){
        return a;
    } else {
        return b;
    }
}

Complex higher_module(Complex a, Complex b){
    float absm = sqrt(a.Im*a.Im+a.Re*a.Re);
    float bbsm = sqrt(b.Im*b.Im+b.Re*b.Re);
    if (absm>bbsm){
        return a;
    } else {
        return b;
    }
}