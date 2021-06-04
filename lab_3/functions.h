#ifndef LAB_2_FUNCTIONS_H
#define LAB_2_FUNCTIONS_H
#include "Complex.h"
#include "Person.h"

int add_two(int a);
int square(int a);
int mult_tree(int a);
int sum(int a);
int mult_ten(int a);
int add_one(int a);
int mod_two(int a);

float add_four(float a);
float minus_ten_half(float a);
float divide_by_two(float a);

Complex add_treetree(Complex a);
Complex minus_tenten(Complex a);
Complex mult_two(Complex a);

bool is_even (int a);
bool is_positive (int a);

bool compare_two (float a);
bool float_positive (float a);

bool comp_mod_two (Complex a);

int less_number(int a, int b);

float higher_number(float a, float b);

Complex higher_module(Complex a, Complex b);

char make_num(char a);
bool comp_a(char a);
char less_letter(char a, char b);

Person id_plus_one(Person a);
bool even_id(Person a);
Person less_id(Person a, Person b);

#endif //LAB_2_FUNCTIONS_H
