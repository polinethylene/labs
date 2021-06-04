#ifndef LAB_3_PERSON_H
#define LAB_3_PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person{
public:
    string Name;
    string Surname;
    int id;

    Person() : Name(), Surname(), id(0) {}

    Person(string N, string S, int num){
        Name = N;
        Surname = S;
        id = num;
    }

    Person &operator=(const Person &p) = default;

    friend ostream &operator<<(ostream &out, const Person &x) {
        out << x.Name << ":" << x.Surname << ":" << x.id;
        return out;
    }

    friend istream &operator>>(istream &in, Person &p) {
        in >> p.Name;
        in >> p.Surname;
        in >> p.id;
        return in;
    }

    bool operator==(const Person &p) const { return !(*this != p); }
    bool operator!=(const Person &p) const {
        if (this->Name != p.Name || this->Surname != p.Surname || this->id != p.id)
            return true;
        else
            return false;
    }

    bool operator>(Person &p) const {
        if (this->id > p.id)
            return true;
        else
            return false;
    }

    bool operator<=(Person &p) const {
        return !(*this > p);
    }

    bool operator<(Person &p) const {
        return *this <= p && *this != p;
    }

    bool operator>=(Person &p) const {
        return *this > p || *this == p;
    }

};

#endif //LAB_3_PERSON_H
