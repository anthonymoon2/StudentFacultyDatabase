#include <iostream>
using namespace std;

#include "student.h"
#include "faculty.h"
#include "scapegoatST.h"
#include "menu.h"


/*
a. main.cpp
b. none
c. class 
d. none 
*/

int main(){
  
  menu *m = new menu();
  while (true){
    m->runMenu();
  }
  delete m;


  /*
  scapegoatST<student> *masterStudent;
  masterStudent = new scapegoatST<student>;

  student newStudent(200, "eric", 300);
  student newStudent2(30, "max", 400);
  student newStudent3(400, "ant", 50);

  masterStudent->insert(newStudent);
  masterStudent->insert(newStudent2);
  masterStudent->insert(newStudent3);
  masterStudent->printTree();
  cout << "--------------------" << endl;
  masterStudent->remove(newStudent);

  masterStudent->printTree();

  scapegoatST<faculty> *masterFaculty;
  masterFaculty = new scapegoatST<faculty>;

  faculty newFaculty(200, "linstead");
  faculty newFaculty2(30, "jipsen");
  faculty newFaculty3(400, "stevens");

  masterFaculty->insert(newFaculty);
  masterFaculty->insert(newFaculty2);
  masterFaculty->insert(newFaculty3);
  
  masterFaculty->printTree();

  newFaculty.addAdvisee(200);
  newFaculty.addAdvisee(30);
  newFaculty.addAdvisee(300);

  newFaculty.printFacultyAdvisees();
  newFaculty2.printFacultyAdvisees();
  
  */

  return 0;
}
