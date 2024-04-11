#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

#include "scapegoatST.h"
#include "student.h"
#include "faculty.h"

/*
a. main.h
b. none
c. class 
d. none 
*/

class menu{
    public:
        menu();
        ~menu();
        void runMenu();

        void printStudentInfo();
        void addStudent();
        void removeStudent();
        void studentInfoFromID(); 
        void changeStudentAdvisor(); 

        void printFacultyInfo();
        void addFaculty();
        void removeFaculty();
        void facultyInfoFromID();
        void removeAdviseeFromID();

        void exit();
    private:
        scapegoatST<student> *masterStudent;
        scapegoatST<faculty> *masterFaculty;
};

#endif
