#include "faculty.h"

/*
a. faculty.h
b. none
c. class 
d. none 
*/

faculty::faculty(){
    m_id = 0; 
    m_facultyID = 0;
} 
/*
a. faculty
b. none
c. int faculty_ID, string faculty_Name 
d. A description of any exceptions thrown, if applicable 
*/

faculty::faculty(int faculty_ID, string faculty_Name){ 
    m_id = faculty_ID; 
    m_facultyID = faculty_ID;
    m_name = faculty_Name;
} 
faculty::~faculty(){} 

void faculty::setFacultyID(int num){
    m_facultyID = num;
}

int faculty::getFacultyID(){
    return m_facultyID;
}

void faculty::addAdvisee(int a_ID){
    listOfAdvisees.addFront(a_ID);
}

/*
a. removeAdvisee
b. void
c. int a_ID to remove
d. none
*/
void faculty::removeAdvisee(int a_ID){
    for (int i = 0; i < listOfAdvisees.size(); ++i){
        if(listOfAdvisees.get(i) == a_ID){
            listOfAdvisees.remove(i);
        }
    }
}
/*
a. printFacultyAdvisees
b. void
c. none
d. none
*/
void faculty::printFacultyAdvisees(){
    if (listOfAdvisees.size() != 0){
        cout << "Advisees' ID #s: ";
        for (int i = 0; i < listOfAdvisees.size(); ++i){
            cout << listOfAdvisees.get(i) << ". ";
        }
    }
    else{
        cout << "No advisees for this faculty member yet.";
    }
    cout << endl;
}

ostream& operator<< (ostream &s, const faculty &fac){
    s << "Faculty ID: " << fac.m_facultyID << endl << "Faculty Name: " << fac.m_name << endl;
    return s;
}






