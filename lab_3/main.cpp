#include <iostream>
#include "b_tree.h"
#include <string>
#include "functions.h"

using namespace std;

const char *TRAVERSE[] = {"0. Prefix", "1. Infix", "2. Postfix",
                          "3. Prefix right", "4. Infix right", "5. Postfix right"};
const int TRAVERSE_SIZE = sizeof(TRAVERSE) / sizeof(TRAVERSE[0]);

const char *TYPES[] = {"0. Int", "1. Float", "2. Complex", "3. Char", "4. Person", "5. String"};
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

const char *FUNCTIONS_CHAR[] = {"0. Make num"};
const int FUNCTIONS_CHAR_SIZE = sizeof(FUNCTIONS_CHAR) / sizeof(FUNCTIONS_CHAR[0]);
const char *WHERE_CHAR[] = {"0. Comparison with a"};
const int WHERE_CHAR_SIZE = sizeof(WHERE_CHAR) / sizeof(WHERE_CHAR[0]);
const char *REDUCE_CHAR[] = {"0. Less letter"};
const int REDUCE_CHAR_SIZE = sizeof(REDUCE_CHAR) / sizeof(REDUCE_CHAR[0]);

const char *FUNCTIONS_PERSON[] = {"0. ID + 1"};
const int FUNCTIONS_PERSON_SIZE = sizeof(FUNCTIONS_PERSON) / sizeof(FUNCTIONS_PERSON[0]);
const char *WHERE_PERSON[] = {"0. Even ID"};
const int WHERE_PERSON_SIZE = sizeof(WHERE_PERSON) / sizeof(WHERE_PERSON[0]);
const char *REDUCE_PERSON[] = {"0. Less ID"};
const int REDUCE_PERSON_SIZE = sizeof(REDUCE_PERSON) / sizeof(REDUCE_PERSON[0]);

const char *FUNCTIONS_STRING[] = {};
const int FUNCTIONS_STRING_SIZE = sizeof(FUNCTIONS_STRING) / sizeof(FUNCTIONS_STRING[0]);
const char *WHERE_STRING[] = {};
const int WHERE_STRING_SIZE = sizeof(WHERE_STRING) / sizeof(WHERE_STRING[0]);
const char *REDUCE_STRING[] = {};
const int REDUCE_STRING_SIZE = sizeof(REDUCE_STRING) / sizeof(REDUCE_STRING[0]);

int ((*functionsint[6]))(int) = {add_two, square, mult_tree, sum, mult_ten, add_one};
float ((*functionsfloat[3]))(float) = {add_four, minus_ten_half, divide_by_two};
Complex ((*functionscomplex[3]))(Complex) = {add_treetree, minus_tenten, mult_two};
char ((*functionschar[1]))(char) = {make_num};
string ((*functionsstring[0]))(string) = {};
Person ((*functionsperson[1]))(Person) = {id_plus_one};

bool ((*whereint[2]))(int) = {is_even, is_positive};
bool ((*wherefloat[2]))(float) = {compare_two, float_positive};
bool ((*wherecomplex[1]))(Complex) = {comp_mod_two};
bool ((*wherechar[1]))(char) = {comp_a};
bool ((*whereperson[1]))(Person) = {even_id};
bool ((*wherestring[0]))(string) = {};

int ((*reduceint[1]))(int, int) = {less_number};
float ((*reducefloat[1]))(float, float) = {higher_number};
Complex ((*reducecomplex[1]))(Complex, Complex) = {higher_module};
char ((*reducechar[1]))(char, char) = {less_letter};
Person ((*reduceperson[1]))(Person, Person) = {less_id};
string ((*reducestring[0]))(string, string) = {};

int dialog(const char *menu[], int n) {
    int choice;
    for (int i = 0; i < n; ++i) {
        cout << menu[i] << endl;
    }
    cout << "Make your choice: ";
    cin >> choice;
    while(choice < 0 || choice >= n) {
        cout << "Wrong input. Make your choice:" << endl;
        cin >> choice;
    }
    return choice;
}

template<class T>
T *get_items(int len) {
    if (len<=0){
        throw runtime_error("Incorrect length");
    }
    T *items = new T[len]();
    cout << "Input tree:" << endl;
    T value;
    for (int i = 0; i < len; i++) {
        cin >> value;
        items[i] = value;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return items;
}

template<class T>
void menu(BTree<T> tree, const char *FUNCTIONS[], int FUNC_SIZE, T (*functions[])(T),
          const char *WHEREFUNCTIONS[], int WHEREFUNC_SIZE, bool (*wherefunctions[])(T),
          const char *REDUCEFUNCTIONS[], int REDUCEFUNC_SIZE, T (*reducefunctions[])(T, T)){
    BTree<T> *subtree;
    BTree<T> *restree;
    T *sub_items;
    T item, res;
    int choice = 0, c = 0, func = 0, len = 0;
    bool flag;
    string adress, line;

    do {
        cout << "Choose operation:" << endl;
        cout << "0. Add Elem" << endl;
        cout << "1. Remove Elem" << endl;
        cout << "2. Traverse" << endl;
        cout << "3. Map" << endl;
        cout << "4. Where" << endl;
        cout << "5. Reduce" << endl;
        cout << "6. Find Subtree (by element)" << endl;
        cout << "7. Find element (subtree)" << endl;
        cout << "8. Find subtree by abs path" << endl;
        cout << "9. Concat" << endl;
        cout << "10. Print" << endl;
        cout << "11. Quit" << endl;
        cin >> c;
        switch (c) {
            case 0:
                cout << "Enter item: ";
                cin >> item;
                tree.AddElem(item);
                cout << "Result tree:" << endl;
                tree.Print();
                break;
            case 1:
                cout << "Enter item: ";
                cin >> item;
                tree.RemoveElem(item);
                cout << "Result tree:" << endl;
                tree.Print();
                break;
            case 2:
                cout << "Choose traverse:" << endl;
                choice = dialog(TRAVERSE,TRAVERSE_SIZE);
                if (choice==0){
                    tree.PreOrderR()->Print();
                }
                if (choice==1){
                    tree.InOrderR()->Print();
                }
                if (choice==2){
                    tree.PostOrderR()->Print();
                }
                if (choice==3){
                    tree.PreOrderRR()->Print();
                }
                if (choice==4){
                    tree.InOrderRR()->Print();
                }
                if (choice==5){
                    tree.PostOrderRR()->Print();
                }
                break;
            case 3:
                cout << "Choose function:" <<endl;
                func = dialog(FUNCTIONS, FUNC_SIZE);
                restree = tree.Map(functions[func]);
                cout << "Result tree:" << endl;
                restree->Print();
                break;
            case 4:
                cout << "Choose function:" <<endl;
                func = dialog(WHEREFUNCTIONS, WHEREFUNC_SIZE);
                restree = tree.Where(wherefunctions[func]);
                cout << "Result tree:" << endl;
                restree->Print();
                break;
            case 5:
                cout << "Choose function:" <<endl;
                func = dialog(REDUCEFUNCTIONS, REDUCEFUNC_SIZE);
                cout << "Input starting elem:" <<endl;
                cin >> item;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                res = tree.Reduce(reducefunctions[func], item);
                cout << "Result: ";
                cout << res << endl;
                break;
            case 6:
                cout << "Enter item: ";
                cin >> item;
                subtree = tree.GetSubtree(item);
                if (subtree){
                    cout << "Result tree:" << endl;
                    subtree->Print();
                } else {
                    cout << "No such tree" << endl;
                }
                break;
            case 7:
                cout << "Find element/subtree? (0/1)";
                cin >> choice;
                if (choice == 0){
                    cout << "Enter item: ";
                    cin >> item;
                    flag = tree.FindElem(item);
                    if (flag) {
                        cout << "Elem is in tree\n";
                    } else {
                        cout << "Elem is not in tree\n";
                    }
                } else if (choice == 1){
                    cout << "Enter subtree length: ";
                    cin >> len;
                    sub_items = get_items<T>(len);
                    subtree = new BTree<T>(sub_items,len);
                    delete[] sub_items;
                    flag = tree.FindSubtree(subtree);
                    if (flag) {
                        cout << "Subtree is in tree\n";
                    } else {
                        cout << "Subtree is not in tree\n";
                    }
                } else {
                    cout << "Wrong input\n";
                }
                break;
            case 8:
                cout << "Enter path (in format: r for right, l for left)\n";
                cin >> adress;
                subtree = tree.AdressTree(adress);
                if (subtree) {
                    subtree->Print();
                } else {
                    cout << "Incorrect path\n";
                }
                break;
            case 9:
                cout << "Enter subtree length: ";
                cin >> len;
                sub_items = get_items<T>(len);
                subtree = new BTree<T>(sub_items,len);
                delete[] sub_items;
                restree = tree.Concat(subtree);
                restree->Print();
                break;
            case 10:
                tree.Print();
                break;
            case 11:
                break;
            default:
                cout << "There is no such option" << endl;
                break;
        }
    } while (c!=11);
}

int main() {
    int type = 0, len = 0;
    BTree<int> int_tree;
    BTree<float> float_tree;
    BTree<char> char_tree;
    BTree<string> string_tree;
    BTree<Complex> complex_tree = BTree<Complex>();
    BTree<Person> person_tree = BTree<Person>();
    cout << "Choose tree type:" << endl;
    type = dialog(TYPES,TYPES_SIZE);
    cout << "Enter tree length:" << endl;
    cin >> len;

    switch(type){
        case 0:
            if (1){
                int *items = get_items<int>(len);
                int_tree = BTree<int>(items,len);
                delete[] items;
                int_tree.Print();
            }
            break;
        case 1:
            if (1){
                float *items = get_items<float>(len);
                float_tree = BTree<float>(items,len);
                delete[] items;
                float_tree.Print();
            }
            break;
        case 2:
            if (1){
                Complex *items = get_items<Complex>(len);
                complex_tree = BTree<Complex>(items,len);
                delete[] items;
                complex_tree.Print();
            }
            break;
        case 3:
            if (1){
                char *items = get_items<char>(len);
                char_tree = BTree<char>(items,len);
                delete[] items;
                char_tree.Print();
            }
            break;
        case 4:
            if (1){
                Person *items = get_items<Person>(len);
                person_tree = BTree<Person>(items,len);
                delete[] items;
                person_tree.Print();
            }
            break;
        case 5:
            if (1){
                string *items = get_items<string>(len);
                string_tree = BTree<string>(items,len);
                delete[] items;
                string_tree.Print();
            }
            break;
        default:
            cout << "There is no such type" << endl;
            break;
    }

    if (type==0){
        menu(int_tree, FUNCTIONS_INT, FUNCTIONS_INT_SIZE, functionsint,
                    WHERE_INT, WHERE_INT_SIZE, whereint,
                    REDUCE_INT, REDUCE_INT_SIZE, reduceint);
    } else if (type==1){
        menu(float_tree, FUNCTIONS_FLOAT, FUNCTIONS_FLOAT_SIZE, functionsfloat,
             WHERE_FLOAT, WHERE_FLOAT_SIZE, wherefloat,
             REDUCE_FLOAT, REDUCE_FLOAT_SIZE, reducefloat);
    } else if (type==2){
        menu(complex_tree, FUNCTIONS_COMPLEX, FUNCTIONS_COMPLEX_SIZE, functionscomplex,
             WHERE_COMPLEX, WHERE_COMPLEX_SIZE, wherecomplex,
             REDUCE_COMPLEX, REDUCE_COMPLEX_SIZE, reducecomplex);
    } else if (type==3){
        menu(char_tree, FUNCTIONS_CHAR, FUNCTIONS_CHAR_SIZE, functionschar,
             WHERE_CHAR, WHERE_CHAR_SIZE, wherechar,
             REDUCE_CHAR, REDUCE_CHAR_SIZE, reducechar);
    } else if (type==4) {
        menu(person_tree, FUNCTIONS_PERSON, FUNCTIONS_PERSON_SIZE, functionsperson,
             WHERE_PERSON, WHERE_PERSON_SIZE, whereperson,
             REDUCE_PERSON, REDUCE_PERSON_SIZE, reduceperson);
    } else if (type==5) {
        menu(string_tree, FUNCTIONS_STRING, FUNCTIONS_STRING_SIZE, functionsstring,
             WHERE_STRING, WHERE_STRING_SIZE, wherestring,
             REDUCE_STRING, REDUCE_STRING_SIZE, reducestring);
    }

    return 0;
}
