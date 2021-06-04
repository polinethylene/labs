#ifndef LAB_3_B_TREE_H
#define LAB_3_B_TREE_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Stack.h"
#include <typeinfo>
#include "Complex.h"
#include "Person.h"

using namespace std;

template <typename T>
class BTree {
private:
    class Node {
    public:
        T data;
        unsigned int height;
        Node* left;
        Node* right;

        Node() : data(), height(), left(nullptr), right(nullptr) {}

        Node(T a) {
            data = a;
            height = 0;
            left = nullptr;
            right = nullptr;
        }

        Node(Node *input) : Node() {
            Stack<Node *> s, s1;
            s.Push(input);
            s1.Push(this);
            while (!s.Empty()) {
                Node *node = s.Pop();
                Node *tmp = s1.Pop();
                tmp->data = node->data;
                tmp->height = node->height;
                if (node->right){
                    tmp->right = new Node();
                    s.Push(node->right);
                    s1.Push(tmp->right);
                }
                if (node->left){
                    tmp->left = new Node();
                    s.Push(node->left);
                    s1.Push(tmp->left);
                }
            }
        }

        Node(Node &node) : Node(&node) {}

        unsigned int Height(Node* p)
        {
            return p?p->height:0;
        }

        int BFactor()
        {
            return Height(right) - Height(left);
        }

        void FixHeight()
        {
            unsigned int hl = Height(left);
            unsigned int hr = Height(right);
            height = (hl>hr?hl:hr)+1;
        }

    };

    Node *root;

public:
    BTree<T> &operator=(const BTree<T> &tree){
        delete this->root;
        this->root = new Node (*tree.root);
        return *this;
    }

    BTree() : root(nullptr) {}

    BTree(T *items, int n) {
        root = AddNode(nullptr, items[0]);
        for (int i=0; i<n-1; i++){
            root = AddNode(root,items[i+1]);
        }
    }

    BTree(BTree<T> &t) : root(new Node(t.root)) {}

    explicit BTree(Node *node) : root(new Node(node)) {}

    //балансировка

    Node* RotateRight(Node* p) {
        Node* q = p->left;
        p->left = q->right;
        q->right = p;
        p->FixHeight();
        q->FixHeight();
        return q;
    }

    Node* RotateLeft(Node* q) {
        Node* p = q->right;
        q->right = p->left;
        p->left = q;
        q->FixHeight();
        p->FixHeight();
        return p;
    }

    Node* Balance(Node* p) // балансировка узла p
    {
        p->FixHeight();
        if( p->BFactor()==2 )
        {
            if( (p->right)->BFactor() < 0 ) {
                p->right = RotateRight(p->right);
            }
            return RotateLeft(p);
        }
        if( p->BFactor()==-2 )
        {
            if( (p->left)->BFactor() > 0  ) {
                p->left = RotateLeft(p->left);
            }
            return RotateRight(p);
        }
        return p;
    }

    //добавление элемента

    Node* AddNode(Node* p, T a) {
        if (p == nullptr) {
            p = new Node(a);
        } else if (a <= p->data){
            p->left = AddNode(p->left, a);
        } else {
            p->right = AddNode(p->right, a);
        }
        return Balance(p);
    }

    void AddElem(T a) {
        if (root == nullptr) {
            root = AddNode(nullptr, a);
        } else {
            root = AddNode(root, a);
            root->FixHeight();
        }
    }

    //удаление элемента

    Node* FindMin(Node* p) {
        return p->left?FindMin(p->left):p;
    }

    Node* RemoveMin(Node* p) {
        if( p->left == nullptr ){
            return p->right;
        }
        p->left = RemoveMin(p->left);
        return Balance(p);
    }

    Node* Remove(Node* p, T k) {
        if( !p ) { return 0; }
        if( k < p->data ){
            p->left = Remove(p->left,k);
        } else if( k > p->data ){
            p->right = Remove(p->right,k);
        } else {                               //  k == p->data
            Node* l = p->left;
            Node* r = p->right;
            delete p;
            if( !r ) { return l; }
            Node* min = FindMin(r);
            min->right = RemoveMin(r);
            min->left = l;
            return Balance(min);
        }
        return Balance(p);
    }

    void RemoveElem(T a) {
        if (root != nullptr) {
            root = Remove(root, a);
        }
    }

    //поиск

    Node *FindNode(Node* p, T a) {
        if(p == nullptr || a==p->data)
            return p;
        if(a > p->data )
            return FindNode(p->right,a);
        else
            return FindNode(p->left,a);
    }

    Node *FindElem(T a) {
        return FindNode(root, a);
    }

    bool FindSubtree(BTree<T> *tree) {
        if (tree->root == NULL){
            return false;
        }
        LinkedListSequence<T> *a = tree->PreOrder(tree->root);
        LinkedListSequence<T> *b = this->PreOrder(FindElem(tree->root->data));
        if (a!=NULL & b!=NULL) {
            return (*a) == (*b);
        } else {
            return false;
        }
    }

    BTree<T> *GetSubtree(T a) {
        if (FindElem(a)){
            return new BTree<T>(FindElem(a));
        } else {
            return NULL;
        }
    }

    //обход

    LinkedListSequence<T> *PreOrder(Node* node) {
        if (node == NULL){
            return NULL;
        }
        LinkedListSequence<T> *a = new LinkedListSequence<T>();
        Stack<Node *> s;
        s.Push(node);
        while (s.Empty() == false){
            Node *tmp = s.Pop();
            a->Append(tmp->data);

            if (tmp->right){
                s.Push(tmp->right);
            }
            if (tmp->left){
                s.Push(tmp->left);
            }
        }
        return a;
    }

    LinkedListSequence<T> *PreOrderRev(Node* node) {
        if (node == NULL){
            return NULL;
        }
        LinkedListSequence<T> *a = new LinkedListSequence<T>();
        Stack<Node *> s;
        s.Push(node);
        while (s.Empty() == false){
            Node *tmp = s.Pop();
            a->Append(tmp->data);

            if (tmp->left){
                s.Push(tmp->left);
            }

            if (tmp->right){
                s.Push(tmp->right);
            }
        }
        return a;
    }

    LinkedListSequence<T> *InOrder(Node* node) {
        Stack<Node *> s;
        LinkedListSequence<T> *a = new LinkedListSequence<T> ();
        while (not s.Empty() or node != NULL){
            if (node != NULL) {
                s.Push(node);
                node = node->left;
            } else {
                node = s.Pop();
                a->Append(node->data);
                node = node->right;
            }
        }
        return a;
    }

    LinkedListSequence<T> *InOrderRev(Node* node) {
        Stack<Node *> s;
        LinkedListSequence<T> *a = new LinkedListSequence<T> ();
        while (not s.Empty() or node != NULL){
            if (node != NULL) {
                s.Push(node);
                node = node->right;
            } else {
                node = s.Pop();
                a->Append(node->data);
                node = node->left;
            }
        }
        return a;
    }

    LinkedListSequence<T> *PostOrder(Node* node) {
        Stack<Node *> s;
        LinkedListSequence<T> *a = new LinkedListSequence<T> ();
        Node *lastnode = NULL;
        while (s.Empty() == false or node != NULL){
            if (node != NULL) {
                s.Push(node);
                node = node->left;
            } else {
                Node *peeknode = s.Top();

                if (peeknode->right != NULL and lastnode != peeknode->right) {
                    node = peeknode->right;
                } else {
                    a->Append(peeknode->data);
                    lastnode = s.Pop();
                }
            }
        }
        return a;
    }

    LinkedListSequence<T> *PostOrderRev(Node* node) {
        Stack<Node *> s;
        LinkedListSequence<T> *a = new LinkedListSequence<T> ();
        Node *lastnode = NULL;
        while (s.Empty() == false or node != NULL){
            if (node != NULL) {
                s.Push(node);
                node = node->right;
            } else {
                Node *peeknode = s.Top();

                if (peeknode->left != NULL and lastnode != peeknode->left) {
                    node = peeknode->left;
                } else {
                    a->Append(peeknode->data);
                    lastnode = s.Pop();
                }
            }
        }
        return a;
    }

    LinkedListSequence<T> *PreOrderR() {
        return PreOrder(root);
    }
    LinkedListSequence<T> *InOrderR() {
        return InOrder(root);
    }
    LinkedListSequence<T> *PostOrderR() {
        return PostOrder(root);
    }
    LinkedListSequence<T> *PreOrderRR() {
        return PreOrderRev(root);
    }
    LinkedListSequence<T> *InOrderRR() {
        return InOrderRev(root);
    }
    LinkedListSequence<T> *PostOrderRR() {
        return PostOrderRev(root);
    }

    BTree<T>* Concat(BTree<T> *tree) {
        LinkedListSequence<T> *a = PreOrder(tree->root);
        LinkedListSequence<T> *b = PreOrder(this->root);
        BTree<T> *res = new BTree<T>();
        for (int i=0; i<a->GetLength(); i++){
            res->AddElem(a->Get(i));
        }
        for (int i=0; i<b->GetLength(); i++){
            res->AddElem(b->Get(i));
        }
        return res;
    }

    BTree<T>* Map(T (f)(T )) {
        BTree<T> *a = new BTree<T> ();
        LinkedListSequence<T> *b = this->InOrder(root);
        for (int i=0; i<b->GetLength(); i++){
            a->AddElem(f(b->Get(i)));
        }
        return a;
    }

    BTree<T>* Where(bool (f)(T )) {
        BTree<T> *a = new BTree<T> ();
        LinkedListSequence<T> *b = this->PreOrder(root);
        for (int i=0; i<b->GetLength(); i++){
            if(f(b->Get(i))){
                a->AddElem(b->Get(i));
            }

        }
        return a;
    }

    T Reduce(T (f)(T, T), T c) {
        T a = c;
        Stack<Node *> s;
        s.Push(root);
        while (s.Empty() == false){
            Node *tmp = s.Pop();
            a = f(tmp->data, a);

            if (tmp->right){
                s.Push(tmp->right);
            }
            if (tmp->left){
                s.Push(tmp->left);
            }
        }
        return a;
    }

    BTree *AdressTree(string &adress) {
        Node *ptr = root;
        for (size_t i=0; i<adress.length(); i++){
            if (adress[i]=='r') {
                if (ptr->right) {
                    ptr = ptr->right;
                } else
                    return NULL;
            } else if (adress[i]=='l') {
                if (ptr->left) {
                    ptr = ptr->left;
                } else
                    return NULL;
            } else {
                return NULL;
            }
        }
        BTree<T> *res = new BTree<T>(ptr);
        return res;
    }

    void PrintElemL(Node *p, int n)
    {
        if (p == NULL) {
            return;
        } else {
            cout << setw(5) << p->data << " " << p->height;
            if (p->left){
                cout << " (l) -> ";
                PrintElemL(p->left, ++n);
                n--;
            }
            if (p->right){
                if (p->left){
                    cout << endl;
                    for (int i=0; i<n; ++i) {
                        cout << "                ";
                    }
                    cout << "      ";
                }
                cout << "  (r) -> ";
                PrintElemL(p->right, ++n);
            }
        }
    }

    void PrintElemR(Node *p, int n)
    {
        int width = 5;
        if (typeid(p->data).name() == typeid(Complex).name() || typeid(p->data).name() == typeid(Person).name()) {
            width = 1;
        }
        if (p == NULL) {
            return;
        } else {
            cout << setw(width) << p->data << " [" << p->height << "]";
            if (p->right){
                cout << " (r) -> ";
                PrintElemR(p->right, ++n);
                n--;
            }
            if (p->left){
                if (p->right){
                    cout << endl;
                    for (int i=0; i<n; ++i) {
                        cout << "               ";
                    }
                    cout << "        ";
                }
                cout << "   (l) -> ";
                PrintElemR(p->left, ++n);
            }
        }
    }

    void Print()
    {
        PrintElemR(root,0);
        cout << endl;
    }

    void Delete(Node *node){
        if (node == nullptr){
            return;
        }
        if (node->left){
            Delete(node->left);
        }
        if (node->right){
            Delete(node->right);
        }
        delete node;
    }

    ~BTree() {
        Delete(root);
    }

};

#endif //LAB_3_B_TREE_H
