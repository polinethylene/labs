#ifndef LAB_2_LINKEDLISTSEQ_H
#define LAB_2_LINKEDLISTSEQ_H

#include <iostream>
#include "LinkList.h"
#include "Sequence.h"

using namespace std;

template <class T>
class LinkedListSequence : Sequence<T>{
private:
    LinkedList<T>* items;
public:
    LinkedListSequence<T> &operator=(const LinkedListSequence<T> &sequence){
        delete this->items;
        this->items = new LinkedList<T> (*sequence.items);
        return *this;
    }

    LinkedListSequence(){
        this->items = new LinkedList<T> ();
    }

    LinkedListSequence(int count){
        if (count<=0){
            throw runtime_error("Incorrect length");
        }
        this->items = new LinkedList<T> (count);
    }

    LinkedListSequence(T* items, int count){
        this->items = new LinkedList<T> (items, count);
    }

    LinkedListSequence(const LinkedList <T> & list){
        items = new LinkedList<T> (list);
    }

    LinkedListSequence(const LinkedListSequence <T> & list){
        items = new LinkedList<T> (*list.items);
    }

    T &GetFirst(){
        return items->GetFirst();
    }

    T &GetLast(){
        return items->GetLast();
    }

    T &Get(int index){
        return items->Get(index);
    }

    LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex){
        if (startIndex >= endIndex){
            throw runtime_error("Incorrect indexes");
        }
        LinkedList<T> *sublist = items->GetSubList(startIndex,endIndex);
        LinkedListSequence<T> *new_list = new LinkedListSequence<T>(*sublist);
        return new_list;
    }

    int GetLength(){
        return items->GetLength();
    }

    void Set(int index, T value){
        Get(index) = value;
    }

    void Append(T item){
        items->Append(item);
    }

    void Prepend(T item){
        items->Prepend(item);
    }

    void InsertAt(T item, int index){
        items->InsertAt(item, index);
    }

    T Pop() {
        return items->Pop();
    }

    Sequence <T>* Concat(Sequence <T> *list){
        Sequence<T> *res = new LinkedListSequence<T>();
        for(int i=0; i<this->GetLength(); i++){
            res->Append(this->Get(i));
        }
        for(int i=0; i<list->GetLength(); i++){
            res->Append(list->Get(i));
        }
        return res;
    }

    LinkedListSequence <T>* Concat(LinkedListSequence <T> *list){
        LinkedListSequence<T> *res = new LinkedListSequence<T>();
        for(int i=0; i<this->GetLength(); i++){
            res->Append(this->Get(i));
        }
        for(int i=0; i<list->GetLength(); i++){
            res->Append(list->Get(i));
        }
        return res;
    }

    LinkedListSequence <T>* Map(T (f)(T )){
        LinkedListSequence<T> *new_list = new LinkedListSequence<T>();
        for(int i=0; i<items->GetLength(); i++){
            new_list->Append(f(this->Get(i)));
        }
        return new_list;
    }

    LinkedListSequence <T>* Where(bool (f)(T )){
        LinkedListSequence<T> *new_list = new LinkedListSequence<T>();
        for(int i=0; i<items->GetLength(); i++){
            if (f(this->Get(i))==true){
                new_list->Append(this->Get(i));
            }
        }
        return new_list;
    }

    T Reduce(T (f)(T, T), T c){
        T ans;
        T arg = c;
        for(int i=0; i<items->GetLength(); i++){
            ans = f(this->Get(i), arg);
            arg = ans;
        }
        return ans;
    }

    void Print(){
        items->Print();
    }

    bool operator==(LinkedListSequence<T> list) {
        int len = list.GetLength();
        if (len != this->items->GetLength())
            return false;
        for (int i = 0; i < len; ++i)
            if (this->Get(i) != list.Get(i))
                return false;

        return true;
    }
};

#endif //LAB_2_LINKEDLISTSEQ_H
