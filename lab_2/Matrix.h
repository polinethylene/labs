#ifndef LAB_2_MATRIX_H
#define LAB_2_MATRIX_H

#include <iostream>
#include <cmath>
#include "Sequence.h"
#include "ArraySeq.h"
#include "LinkedListSeq.h"

using namespace std;

template<class T>
class Matrix {
private:
    ArraySequence<T> data;
    int width;
    int height;
public:
    void Set(int index, int index_2, T value) {
        if (index<0 || index>=height){
            throw runtime_error("Index out of range");
        }
        if (index_2<0 || index_2>=width){
            throw runtime_error("Index out of range");
        }
        data.Set(index * width + index_2, value);
    }

    Matrix<T>() : data() {
        width = 0;
        height = 0;
    }

    Matrix<T>(T *items, int height, int width) : data(items, height * width), height(height), width(width) {
    }

    Matrix<T>(int height, int width) : data(height*width), height(height), width(width) {
    }

    T &Get(int index, int index_2) {
        if (index >= height || index < 0) {
            throw runtime_error("Height Index out of range");
        }
        if (index_2 >= width || index < 0) {
            throw runtime_error("Width Index out of range");
        }
        return data.Get(index * width + index_2);
    }

    int &GetWidth() {
        return width;
    }

    int &GetHeight() {
        return height;
    }


    Matrix<T> MatrixSum(Matrix<T> &matrix_2) {
        if (width != matrix_2.GetWidth() || height != matrix_2.GetHeight()) {
            throw runtime_error("Matrix sizes aren't equal");
        }
        Matrix<T> new_matrix = Matrix<T>(height, width);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                new_matrix.Set(i, j, Get(i, j) + matrix_2.Get(i, j));
            }
        }
        return new_matrix;
    }

    Matrix<T> MatrixMult(T scalar) {
        Matrix<T> new_matrix = Matrix<T>(height, width);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                new_matrix.Set(i, j, Get(i, j)*scalar);
            }
        }
        return new_matrix;
    }

    T MatrixNorm() {
        T square_sum;
        T elem;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                elem = Get(i, j);
                square_sum =  square_sum + elem*elem;
            }
        }
        return sqrt(square_sum);
    }

    void ElemTranform_1(int choice, int j, T scalar){
        T elem;
        if (choice == 0){
            for(int i = 0; i < width; i++){
                elem = Get(j,i);
                Get(j,i) = elem * scalar;
            }
        }
        if (choice == 1){
            for(int i = 0; i < height; i++){
                elem = Get(i,j);
                Get(i,j) = elem * scalar;
            }
        }

    }

    void ElemTranform_2(int choice, int j, int k){
        T elem;
        if (choice == 2){
            for(int i = 0; i < width; i++){
                elem = Get(j,i);
                Get(j,i) = Get(k,i);
                Get(k,i) = elem;
            }
        }
        if (choice == 3){
            for(int i = 0; i < height; i++){
                elem = Get(i,j);
                Get(i,j) = Get(i,k);
                Get(i,k) = elem;
            }
        }
    }

    void ElemTranform_3(int choice, int j, int k, T scalar){
        T elem;
        if (choice == 4){
            for(int i = 0; i < width; i++){
                elem = Get(j,i);
                Get(k,i) += elem * scalar;
            }
        }
        if (choice == 5){
            for(int i = 0; i < height; i++){
                elem = Get(i,j);
                Get(i,k) += elem * scalar;
            }
        }
    }

    void Print(){
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++){
                cout << Get(i,j) << ' ';
            }
            cout << endl;
        }
    }
};

#endif //LAB_2_MATRIX_H