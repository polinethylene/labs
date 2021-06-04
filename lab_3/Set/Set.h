#ifndef LAB_3_SET_H
#define LAB_3_SET_H

#include <iostream>
#include "../b_tree.h"

template <typename T>
class Set {
private:
    BTree<T> tree;
    int len;
public:
    Set() : tree(), len() {}

    Set(T *items, int n) : tree(), len() {
        for (int i=0; i<n; i++){
            AddElem(items[i]);
        }
    }

    Set(BTree<T> &t) : tree() {
        LinkedListSequence<T> *a = t.PreOrderR();
        for (int i=0; i<a->GetLength(); i++){
            AddElem(a->Get(i));
        }
    }

    Set(Set<T> &s) : tree(s.tree) {}

    Set<T> *Union (Set<T> *s2) {
        LinkedListSequence<T> *a = s2->GetSet();
        LinkedListSequence<T> *b = this->GetSet();
        Set<T> *res = new Set<T>();
        for (int i=0; i<a->GetLength(); i++){
            res->AddElem(a->Get(i));
        }
        for (int i=0; i<b->GetLength(); i++){
            res->AddElem(b->Get(i));
        }
        return res;
    }

    Set<T> *Intersection (Set<T> *s2) {
        LinkedListSequence<T> *a = s2->GetSet();
        Set<T> *res = new Set<T>();
        for (int i=0; i<a->GetLength(); i++){
            if (FindElem(a->Get(i))){
                res->AddElem(a->Get(i));
            }
        }
        return res;
    }

    Set<T> *RelComplement (Set<T> *s2) {
        LinkedListSequence<T> *a = this->GetSet();
        Set<T> *res = new Set<T>();
        for (int i=0; i<a->GetLength(); i++){
            if (!(s2->FindElem(a->Get(i)))){
                res->AddElem(a->Get(i));
            }
        }
        return res;
    }

    bool FindSubSet(Set<T> *s) {
        LinkedListSequence<T> *b = s->GetSet();
        for(int i=0; i<b->GetLength(); i++){
            if (!(this->FindElem(b->Get(i)))) {
                return false;
            }
        }
        return true;
    }

    bool IsEqual(Set<T> *s) {
        LinkedListSequence<T> *a = this->GetSet();
        LinkedListSequence<T> *b = s->GetSet();

        if (a->GetLength() != b->GetLength()) {
            return false;
        }
        for(int i=0; i<a->GetLength(); i++){
            if (a->Get(i) != b->Get(i)) {
                return false;
            }
        }
        return true;
    }

    LinkedListSequence<T> *GetSet(){
        return tree.InOrderR();
    }

    void AddElem(T a){
        if (!(tree.FindElem(a))) {
            tree.AddElem(a);
            len+=1;
        }
    }

    void RemoveElem(T a){
        tree.RemoveElem(a);
        len-=1;
    }

    Set<T>* Map(T (f)(T )) {
        return new Set<T> (*(tree.Map(f)));
    }

    Set<T>* Where(bool (f)(T )) {
        return new Set<T> (*(tree.Where(f)));
    }

    T Reduce(T (f)(T, T), T a) {
        return tree.Reduce(f, a);
    }

    bool FindElem(T a){
        return tree.FindElem(a);
    }

    void Print() {
        tree.Print();
    }
};

#endif //LAB_3_SET_H
