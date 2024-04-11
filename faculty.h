#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
using namespace std;

#include "Person.h"
#include "DblList.h"

/*
a. class faculty
b. none
c. none
d. none
*/

class faculty : public Person{
    public:
        faculty();
        faculty(int faculty_ID, string faculty_Name); 
        ~faculty();

        void setFacultyID(int num);
        int getFacultyID();

        void addAdvisee(int a_ID);
        void removeAdvisee(int a_ID);
        void printFacultyAdvisees();

        friend ostream& operator << (ostream &s, const faculty &fac);

        int facultyID;
        int m_facultyID;
        string m_name; 

        DblList<int> listOfAdvisees;

    private: 
        
};
#endif
