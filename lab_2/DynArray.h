#ifndef LAB_2_DYNARRAY_H
#define LAB_2_DYNARRAY_H

#include <iostream>

using namespace std;

template <class T>
class DynamicArray {
private:
    int length;
    T *data;
public:
    T &operator[](int index) {
        if (index >= length || index < 0) {
            throw runtime_error("Index out of range");
        }
        return *(data + index);
    }

    DynamicArray(){
        length = 0;
        data = new T[1]();
    }

    DynamicArray(T* items, int count){            //Копировать элементы из переданного массива
        if (count < 0){
            throw runtime_error("count < 0");
        }
        data = new T[count]();
        if (items == NULL){
            throw runtime_error("NULL list");
        }
        for (int i = 0; i < count; i++){
            data[i] = items[i];
        }
        length = count;
    }

    explicit DynamicArray(int size) {            //Создать массив заданной длины
        if (size < 0){
            throw runtime_error("count < 0");
        }
        data = new T[size]();
        length = size;
    }

    DynamicArray(const DynamicArray<T> & dynamicArray){
        if (dynamicArray.data == NULL){
            throw runtime_error("NULL list");
        }
        data = new T[dynamicArray.length];
        for (int i = 0; i < dynamicArray.length; i++) {
            data[i] = dynamicArray.data[i];
        }
        length = dynamicArray.length;
    }

    ~DynamicArray() {
        delete[] data;
    }

    T &Get(int index) {                                //Получить элемент по индексу
        if (index >= length || index < 0) {
            throw runtime_error("Index out of range");
        }
        return *(data + index);
    }

    int GetSize() {        //Получить размер массива
        return length;
    }
    void Resize(int newSize){
        if (newSize < 0) {
            throw runtime_error("Size < 0");
        }
        data = static_cast<T *>(realloc(data, sizeof(T) * newSize));
        length = newSize;
    }

    void Set(int index, T value){    //Задать элемент по индексу
        if (index>=length){
            Resize(index+1);
        }
        if (index<0){
            throw runtime_error("Index out of range");
        }
        data[index] = value;
    }

    void Print(){
        for (int i = 0; i < length; i++) {
            cout << data[i] << ' ';
        }
        cout << endl;
    }
};

#endif //LAB_2_DYNARRAY_H
