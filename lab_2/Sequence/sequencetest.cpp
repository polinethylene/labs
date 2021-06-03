#include <iostream>
#include "../Sequence.h"
#include "../ArraySeq.h"
#include "functions.h"
#include "../LinkedListSeq.h"

using namespace std;

const char *TYPES[] = {"0. Int", "1. Float", "2. Complex"};
const int TYPES_SIZE = sizeof(TYPES) / sizeof(TYPES[0]);

const char *FUNCTIONS_INT[] = {"0. add_two", "1. square", "2. mult_tree", "3. sum", "4. mult_ten", "5. add_one"};
const int FUNCTIONS_INT_SIZE = sizeof(FUNCTIONS_INT) / sizeof(FUNCTIONS_INT[0]);

const char *FUNCTIONS_FLOAT[] = {"0. add_four", "1. minus_ten_half", "2. divide_by_two"};
const int FUNCTIONS_FLOAT_SIZE = sizeof(FUNCTIONS_FLOAT) / sizeof(FUNCTIONS_FLOAT[0]);

const char *FUNCTIONS_COMPLEX[] = {"0. add_treetree", "1. minus_tenten", "2. mult_two"};
const int FUNCTIONS_COMPLEX_SIZE = sizeof(FUNCTIONS_COMPLEX) / sizeof(FUNCTIONS_COMPLEX[0]);

const char *WHERE_INT[] = {"0. is_even", "1. is_positive"};
const int WHERE_INT_SIZE = sizeof(WHERE_INT) / sizeof(WHERE_INT[0]);

const char *WHERE_FLOAT[] = {"0. compare_two", "1. float_positive"};
const int WHERE_FLOAT_SIZE = sizeof(WHERE_FLOAT) / sizeof(WHERE_FLOAT[0]);

const char *WHERE_COMPLEX[] = {"0. comp_mod_two"};
const int WHERE_COMPLEX_SIZE = sizeof(WHERE_COMPLEX) / sizeof(WHERE_COMPLEX[0]);

const char *REDUCE_INT[] = {"0. less_number"};
const int REDUCE_INT_SIZE = sizeof(REDUCE_INT) / sizeof(REDUCE_INT[0]);

const char *REDUCE_FLOAT[] = {"0. higher_number"};
const int REDUCE_FLOAT_SIZE = sizeof(REDUCE_FLOAT) / sizeof(REDUCE_FLOAT[0]);

const char *REDUCE_COMPLEX[] = {"0. higher_module"};
const int REDUCE_COMPLEX_SIZE = sizeof(REDUCE_COMPLEX) / sizeof(REDUCE_COMPLEX[0]);

int ((*functionsint[6]))(int) = {add_two, square, mult_tree, sum, mult_ten, add_one};
float ((*functionsfloat[3]))(float) = {add_four, minus_ten_half, divide_by_two};
Complex ((*functionscomplex[3]))(Complex) = {add_treetree, minus_tenten, mult_two};

bool ((*whereint[2]))(int) = {is_even, is_positive};
bool ((*wherefloat[2]))(float) = {compare_two, float_positive};
bool ((*wherecomplex[1]))(Complex) = {comp_mod_two};

int ((*reduceint[1]))(int, int) = {less_number};
float ((*reducefloat[1]))(float, float) = {higher_number};
Complex ((*reducecomplex[1]))(Complex, Complex) = {higher_module};

Complex sqrt(const Complex num){
    float absm = sqrt(num.Im*num.Im+num.Re*num.Re);
    float angle = atan(num.Im/num.Re);

    return Complex(sqrt(absm)*cos(angle),sqrt(absm)*sin(angle));
}

template<class T>
T *get_items(int len){
    if (len<=0){
        throw runtime_error("Incorrect length");
    }
    T *items = new T[len]();
    cout << "Input sequence:" << endl;
    T value;
    for (int i = 0; i < len; i++) {
        cin >> value;
        items[i] = value;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return items;
}

int dialog(const char *menu[], int n) {
    int choice;
    for (int i = 0; i < n; ++i) {
        cout << menu[i] << endl;
    }
    cout << "Make your choice: ";
    cin >> choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (choice < 0 || choice >= n) {
        cout << "Wrong input. Make your choice:" << endl;
        cin >> choice;
    }
    return choice;
}

template<class N, class T>
void menu(N a, const char *FUNCTIONS[], int FUNC_SIZE, T (*functions[])(T),
          const char *WHEREFUNCTIONS[], int WHEREFUNC_SIZE, bool (*wherefunctions[])(T),
          const char *REDUCEFUNCTIONS[], int REDUCEFUNC_SIZE, T (*reducefunctions[])(T, T)){
    int  c = 0, newlen = 0;
    int func = 0;
    int i = 0, j = 0;
    N *aSubSeq;
    N b;
    T *items;
    T elem, ans;
    a.Print();

    do {
        cout << "Choose function:" << endl;
        cout << "0. Get Subsequence" << endl;
        cout << "1. Concatenate" << endl;
        cout << "2. Map" << endl;
        cout << "3. Where" << endl;
        cout << "4. Reduce" << endl;
        cout << "5. Quit" << endl;
        cin >> c;
        switch (c) {
            case 0:
                cout << "Input 2 indexes:" << endl;
                cin >> i >> j;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Result sequence:" << endl;
                aSubSeq = a.GetSubsequence(i,j);
                aSubSeq->Print();
                break;
            case 1:
                cout << "Input len:" <<endl;
                cin >> newlen;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                items = get_items<T>(newlen);
                b = N(items, newlen);
                aSubSeq = a.Concat(&b);
                delete[] items;
                cout << "Result sequence:" << endl;
                aSubSeq->Print();
                break;
            case 2:
                cout << "Choose fuction:" <<endl;
                func = dialog(FUNCTIONS, FUNC_SIZE);
                aSubSeq = a.Map(functions[func]);
                cout << "Result sequence:" << endl;
                aSubSeq->Print();
                break;
            case 3:
                cout << "Choose fuction:" <<endl;
                func = dialog(WHEREFUNCTIONS, WHEREFUNC_SIZE);
                aSubSeq = a.Where(wherefunctions[func]);
                cout << "Result sequence:" << endl;
                aSubSeq->Print();
                break;
            case 4:
                cout << "Choose fuction:" <<endl;
                func = dialog(REDUCEFUNCTIONS, REDUCEFUNC_SIZE);
                cout << "Input starting elem:" <<endl;
                cin >> elem;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                ans = a.Reduce(reducefunctions[func], elem);
                cout << "Result elem: " << ans << endl;
                break;
            case 5:
                break;
            default:
                cout << "There is no such option" << endl;
                break;
        }
    } while (c!=5);
}

int main() {
    int choice = 0, len = 0;
    cout << "ArraySequence or LinkedListSequence? (0/1)" << endl;
    cin >> choice;
    while(choice != 0 && choice != 1) {
        cout << "Wrong input. Make your choice:" << endl;
        cin >> choice;
    }
    cout << "Choose sequence type:" << endl;
    int type = dialog(TYPES,TYPES_SIZE);
    cout << "Input length:" << endl;
    cin >> len;

    if (type==0){
        if (choice == 0){
            int *items = get_items<int>(len);
            ArraySequence<int> a = ArraySequence<int>(items, len);
            delete[] items;
            menu<ArraySequence<int>,int>(a, FUNCTIONS_INT, FUNCTIONS_INT_SIZE , functionsint,
                                         WHERE_INT, WHERE_INT_SIZE, whereint,
                                         REDUCE_INT, REDUCE_INT_SIZE, reduceint);
        } else if (choice == 1) {
            int *items = get_items<int>(len);
            LinkedListSequence<int> a = LinkedListSequence<int>(items, len);
            delete[] items;
            menu<LinkedListSequence<int>,int>(a, FUNCTIONS_INT, FUNCTIONS_INT_SIZE, functionsint,
                                              WHERE_INT, WHERE_INT_SIZE, whereint,
                                              REDUCE_INT, REDUCE_INT_SIZE, reduceint);
        }
    } else if (type==1){
        if (choice == 0){
            float *items = get_items<float>(len);
            ArraySequence<float> a = ArraySequence<float>(items, len);
            delete[] items;
            menu<ArraySequence<float>,float>(a, FUNCTIONS_FLOAT, FUNCTIONS_FLOAT_SIZE, functionsfloat,
                                             WHERE_FLOAT, WHERE_FLOAT_SIZE, wherefloat,
                                             REDUCE_FLOAT, REDUCE_FLOAT_SIZE, reducefloat);
        } else if (choice == 1) {
            float *items = get_items<float>(len);
            LinkedListSequence<float> a = LinkedListSequence<float>(items, len);
            delete[] items;
            menu<LinkedListSequence<float>,float>(a, FUNCTIONS_FLOAT, FUNCTIONS_FLOAT_SIZE, functionsfloat,
                                                  WHERE_FLOAT, WHERE_FLOAT_SIZE, wherefloat,
                                                  REDUCE_FLOAT, REDUCE_FLOAT_SIZE, reducefloat);
        }
    } else if (type==2){
        if (choice == 0){
            Complex *items = get_items<Complex>(len);
            ArraySequence<Complex> a = ArraySequence<Complex>(items, len);
            delete[] items;
            menu<ArraySequence<Complex>,Complex>(a, FUNCTIONS_COMPLEX, FUNCTIONS_COMPLEX_SIZE, functionscomplex,
                                                 WHERE_COMPLEX, WHERE_COMPLEX_SIZE, wherecomplex,
                                                 REDUCE_COMPLEX, REDUCE_COMPLEX_SIZE, reducecomplex);
        } else if (choice == 1) {
            Complex *items = get_items<Complex>(len);
            LinkedListSequence<Complex> a = LinkedListSequence<Complex>(items, len);
            delete[] items;
            menu<LinkedListSequence<Complex>,Complex>(a, FUNCTIONS_COMPLEX, FUNCTIONS_COMPLEX_SIZE, functionscomplex,
                                                      WHERE_COMPLEX, WHERE_COMPLEX_SIZE, wherecomplex,
                                                      REDUCE_COMPLEX, REDUCE_COMPLEX_SIZE, reducecomplex);
        }
    }
    return 0;
}
