#include <iostream>
#include "Matrix.h"
#include "Complex.h"

using namespace std;

const char *ELEMTRANSFORM[] = {"0. Mult i line on scalar", "1. Mult j column on scalar",
                               "2. Permute i and k line", "3. Permute j and k column",
                               "4. Add i line mult on scalar to k line", "5. Add j column mult on scalar to k column"};
const int ELEMTRANSFORM_SIZE = sizeof(ELEMTRANSFORM) / sizeof(ELEMTRANSFORM[0]);

const char *TYPES[] = {"0. Int", "1. Float", "2. Complex"};
const int TYPES_SIZE = sizeof(TYPES) / sizeof(TYPES[0]);

Complex sqrt(const Complex num){
    float absm = sqrt(num.Im*num.Im+num.Re*num.Re);
    float angle = atan(num.Im/num.Re);

    return Complex(sqrt(absm)*cos(angle),sqrt(absm)*sin(angle));
}

template<class T>
T *get_items(int height, int width){
    if (height<=0){
        throw runtime_error("Incorrect height");
    }
    if (width<=0){
        throw runtime_error("Incorrect width");
    }
    T *items = new T[height*width]();
    cout << "Input matrix:" << endl;
    T value;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> value;
            items[i*width+j] = value;
        }
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
    while(choice < 0 || choice >= n) {
        cout << "Wrong input. Make your choice:" << endl;
        cin >> choice;
    }
    return choice;
}

template<class T>
void matrix_menu(Matrix<T> matrix, int height, int width){
    Matrix<T> sub_matrix;
    Matrix<T> res_matrix;
    T *sub_items;
    T scalar;
    int choice = 0, c = 0;
    int j = 0, k = 0;
    T norm;

    do {
        cout << "Choose function:" << endl;
        cout << "0. Matrix Sum" << endl;
        cout << "1. Matrix Mult on scalar" << endl;
        cout << "2. Matrix Norm" << endl;
        cout << "3. Elementary Transformations" << endl;
        cout << "4. Quit" << endl;
        cin >> c;
        switch (c) {
            case 0:
                sub_items = get_items<T>(height, width);
                sub_matrix = Matrix<T>(sub_items, height, width);
                delete[] sub_items;
                res_matrix = matrix.MatrixSum(sub_matrix);
                cout << "Result matrix:" << endl;
                res_matrix.Print();
                break;
            case 1:
                cout << "Input scalar:" << endl;
                cin >> scalar;
                res_matrix = matrix.MatrixMult(scalar);
                cout << "Result matrix:" << endl;
                res_matrix.Print();
                break;
            case 2:
                norm = matrix.MatrixNorm();
                cout << "Matrix norm: " << norm << endl;
                break;
            case 3:
                cout << "Choose elementary transformation:" << endl;
                choice = dialog(ELEMTRANSFORM,ELEMTRANSFORM_SIZE);
                if (choice==0 || choice==1){
                    cout << "Input line/column number and a scalar" << endl;
                    cin >> j >> scalar;
                    matrix.ElemTranform_1(choice, j, scalar);
                }
                if (choice==2 || choice==3){
                    cout << "Input i and k line/column number" << endl;
                    cin >> j >> k;
                    matrix.ElemTranform_2(choice,j,k);
                }
                if (choice==4 || choice==5){
                    cout << "Input i and k line number and a scalar" << endl;
                    cin >> j >> k >> scalar;
                    matrix.ElemTranform_3(choice,j,k,scalar);
                }
                cout << "Current matrix:" << endl;
                matrix.Print();
                break;
            case 4:
                break;
            default:
                cout << "There is no such option" << endl;
                break;
        }
    } while (c!=4);
}

int main() {
    int height=0, width=0;
    int c = 0, type = 0;
    Matrix<int> int_matrix;
    Matrix<float> float_matrix;
    Matrix<Complex> complex_matrix = Matrix<Complex>();
    cout << "Choose matrix type:" << endl;
    type = dialog(TYPES,TYPES_SIZE);
    cout << "Input height and width:" << endl;
    cin >> height >> width;
    cout << "Make zero or input matrix? (0/1)" << endl;
    cin >> c;
    while(c != 0 && c != 1) {
        cout << "Wrong input. Make your choice:" << endl;
        cin >> c;
    }

    switch(type){
        case 0:
            if (c == 1){
                int *items = get_items<int>(height, width);
                int_matrix = Matrix<int>(items,height,width);
                delete[] items;
            }
            if (c == 0){
                int_matrix = Matrix<int>(height,width);
            }
            int_matrix.Print();
            break;
        case 1:
            if (c == 1){
                float *items = get_items<float>(height, width);
                float_matrix = Matrix<float>(items,height,width);
                delete[] items;
            }
            if (c == 0){
                float_matrix = Matrix<float>(height,width);
            }
            float_matrix.Print();
            break;
        case 2:
            if (c == 1){
                Complex *items = get_items<Complex>(height, width);
                complex_matrix = Matrix<Complex>(items,height,width);
                delete[] items;
            }
            if (c == 0){
                complex_matrix = Matrix<Complex>(height,width);
            }
            complex_matrix.Print();
            break;
        default:
            cout << "There is no such type" << endl;
            break;
    }

    if (type==0){
        matrix_menu(int_matrix, height, width);
    } else if (type==1){
        matrix_menu(float_matrix, height, width);
    } else if (type==2){
        matrix_menu(complex_matrix, height, width);
    }

    return 0;
}
