#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

#include "Person.h"

/*
a. student.h
b. none
c. class 
d. none 
*/

class student : public Person{
    public:
        student();
        student(int stu_ID, string stu_Name, int stu_advisorID, string stu_level, string stu_major, double stu_GPA);
        ~student();

        void setID(int num);
        int getID();
        void setStudentFacultyID(int newSTUfacID);
        int getStudentFacultyID();

        int studentID;
        int m_studentID;
        string m_name; 
        int m_studentAdvisorID;

        string m_level;
        string m_major;
        double m_GPA;

        friend ostream& operator << (ostream &s, const student &stu);
    private: 
        
};
#endif
