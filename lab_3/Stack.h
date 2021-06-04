#ifndef LAB_3_STACK_H
#define LAB_3_STACK_H

#include "LinkedListSeq.h"

template <typename T>
class Stack{
private:
    LinkedListSequence<T> q;
public:
    Stack() : q() {}

    void Push(T a) {
        q.Prepend(a);
    }

    T Pop() {
        return q.Pop();
    }

    bool Empty() {
        return q.GetLength() == 0;
    }

    T& Top() {
        return q.GetFirst();
    }
};

#endif //LAB_3_STACK_H
