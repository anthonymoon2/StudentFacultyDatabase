#include "student.h"

/*
a. student.cpp
b. none
c. class 
d. none 
*/

student::student(){
    m_id = 0; 
    m_studentID = 0;
} 
student::student(int stu_ID, string stu_Name, int stu_advisorID, string stu_level, string stu_major, double stu_GPA){
    m_id = stu_ID; 
    m_studentID = stu_ID;
    m_name = stu_Name;
    m_studentAdvisorID = stu_advisorID;
    m_level = stu_level;
    m_major = stu_major;
    m_GPA = stu_GPA;
} 
student::~student(){} 

void student::setID(int num){
    m_studentID = num;
}

int student::getID(){
    return m_studentID;
}

void student::setStudentFacultyID(int newSTUfacID){
    m_studentAdvisorID = newSTUfacID;
}

int student::getStudentFacultyID(){
    return m_studentAdvisorID;
}

ostream& operator<< (ostream &s, const student &stu){
    s << "Student ID: " << stu.m_studentID << endl << "Student Name: " << stu.m_name << endl << "Student Faculty ID: " << stu.m_studentAdvisorID << endl << "Student level: " << stu.m_level << endl << "Student major: " << stu.m_major << endl << "Student GPA: " << stu.m_GPA << endl;
    return s;
}




