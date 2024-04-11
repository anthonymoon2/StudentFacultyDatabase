#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

/*
a. Person.h
b. none
c. class 
d. none 
*/

class Person{
    public:
        Person();
        ~Person();
        Person(Person& p){
            m_id = p.m_id;
        }

        bool operator == (const Person &person);
        bool operator != (const Person &person);
        bool operator < (const Person &person);
        bool operator > (const Person &person);
        int m_id;
        string m_name;
        string m_level;

    private:
};

#endif