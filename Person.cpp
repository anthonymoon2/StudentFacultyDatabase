#include "Person.h"

/*
a. Person.cpp
b. none
c. class 
d. none 
*/

Person::Person(){}
Person::~Person(){}

bool Person::operator == (const Person &person){
    if(this->m_id == person.m_id){
        return true;
    }
    return false;

}

bool Person::operator != (const Person &person){
    if(this->m_id != person.m_id){
        return true;
    }
    return false;
}

bool Person::operator < (const Person &person){
    if(this->m_id < person.m_id){
        return true;
    }
    return false;

}

bool Person::operator > (const Person &person){
    if(this->m_id > person.m_id){
        return true;
    }
    return false;
}