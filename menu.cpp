#include "menu.h"

/*
a. menu.h
b. none
c. class 
d. none 
*/

menu::menu(){
    masterStudent = new scapegoatST<student>;
    masterFaculty = new scapegoatST<faculty>;
}

menu::~menu(){
    delete masterStudent;
    delete masterFaculty;
}
/*
a. function runMenu
b. void 
c. none
d. none
*/
void menu::runMenu(){
    int option;
    cout << "Choose an option: " << endl;
    cout << "1) Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2) Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3) Find and display student information given the students id" << endl;
    cout << "4) Find and display faculty information given the faculty id" << endl;
    cout << "5) Add a new student" << endl;
    cout << "6) Delete a student given the id" << endl;
    cout << "7) Add a new faculty member" << endl;
    cout << "8) Delete a faculty member given the id" << endl;
    cout << "9) Change a student’s advisor given the student id and the new faculty id" << endl;
    cout << "10) Remove an advisee from a faculty member given the ids" << endl;
    cout << "11) Exit" << endl;

    cout << "input: ";
    cin >> option;

    if (option == 1){
        printStudentInfo();
    }
    else if (option == 2){
        printFacultyInfo();
    }
    else if (option == 3){
        studentInfoFromID();
    }
    else if (option == 4){
        facultyInfoFromID();
    }  
    else if (option == 5){
        addStudent();
    }
    else if (option == 6){
        removeStudent();
    }
    else if (option == 7){
        addFaculty();
    }
    else if (option == 8){
        removeFaculty();
    }
    else if (option == 9){
        changeStudentAdvisor();
    }
    else if (option == 10){
        removeAdviseeFromID();
    }
    else if (option == 11){
        exit();
    }
}

/*
a. function addStudent
b. void
c. none
d. none
*/
void menu::addStudent(){
    int stu_ID;
    cout << "Enter Student ID: ";
    cin >> stu_ID;

    if (masterStudent->personExistCheck(stu_ID) == false){
        string stu_Name;
        cout << "Enter Student name: ";
        cin >> stu_Name;

        string stu_level;
        cout << "Enter Student's level: ";
        cin >> stu_level;

        string stu_major;
        cout << "Enter Student's major: ";
        cin >> stu_major;

        double stu_GPA;
        cout << "Enter Student's gpa: ";
        cin >> stu_GPA;

        int stu_advisorID;
        cout << "Enter Student's Faculty ID: ";
        cin >> stu_advisorID;
        if (masterFaculty->personExistCheck(stu_advisorID) == false){
            cout << "There is no faculty with this ID in the database, please add a faculty with this ID first!" << endl;
            return;
        }
        else{
            faculty *FF = masterFaculty->copyPerson(stu_advisorID);
            FF->addAdvisee(stu_ID);
        }
        
        student *newStudent = new student(stu_ID, stu_Name, stu_advisorID, stu_level, stu_major, stu_GPA);
        masterStudent->insert(*newStudent);
    }
    else{
        cout << "A student with this student ID already exists! " << endl;
        return;
    }
}
/*
a. function addFaculty
b. void
c. none
d. none
*/
void menu::addFaculty(){
    int fac_ID;
    cout << "Enter Faculty ID: ";
    cin >> fac_ID;

    string fac_Name;
    cout << "Enter Faculty name: ";
    cin >> fac_Name;

    faculty *newFaculty = new faculty(fac_ID, fac_Name); 

    
    int numOfAdvisees;
    cout << "How many advisees would you like to add to " << fac_Name << "?";
    cin >> numOfAdvisees;

    if (masterStudent->isEmpty()){
        if (numOfAdvisees>0){
            cout << "You cannot add advisees when there are no students in the database yet, please input 0 next time to add a faculty with 0 advisees!" << endl;
        }
    }
    else{
        for (int i = 1; i < numOfAdvisees+1; i++){
            int SID;
            cout << "Please input advisee #" << i << "'s student ID #: ";
            cin >> SID;
            if (masterStudent->personExistCheck(SID) == false){
                cout << "There is no student with this ID that exists! If you added no students in the database yet, you must input 0" << endl;
            }
            else{
                newFaculty->addAdvisee(SID);
            }
        }
    }
    
    masterFaculty->insert(*newFaculty);
}
/*
a. function printStudentInfo
b. void
c. none
d. none
*/
void menu::printStudentInfo(){
    
    if (masterStudent->isEmpty()){
        cout << "No students in the database yet." << endl;
    }
    masterStudent->printTree();
}
/*
a. function printFacultyInfo
b. void
c. none
d. none
*/
void menu::printFacultyInfo(){
    
    if (masterFaculty->isEmpty()){
        cout << "No faculty in the database yet." << endl;
    }
    masterFaculty->printTree();
}
/*
a. function studentInfoFromID
b. void
c. none
d. none
*/
void menu::studentInfoFromID(){
    int idHold;
    cout << "Please input the ID of the student: ";
    cin >> idHold;

    if (masterStudent->personExistCheck(idHold)){
        masterStudent->printOnePerson(idHold);
    }
    else { 
        cout << "there is no student with this ID!" << endl;
    }
}
/*
a. function facultyInfoFromID
b. void
c. none
d. none
*/
void menu::facultyInfoFromID(){
    int nidHold;
    cout << "Please input the ID of the faculty: ";
    cin >> nidHold;
    if (masterFaculty->personExistCheck(nidHold)){
        masterFaculty->printOnePerson(nidHold);
        faculty *newF = masterFaculty->copyPerson(nidHold);
        newF->printFacultyAdvisees();
    }
    else { 
        cout << "there is no faculty with this ID!" << endl;
    }
    
}
/*
a. function removeStudent
b. void
c. none
d. none
removes student by checking if they exist first and copying data to new student made then removing
*/
void menu::removeStudent(){
    int idHold;
    cout << "Please input the ID of the student you would like to remove: ";
    cin >> idHold;

    if (masterStudent->personExistCheck(idHold)){
        student *hold = masterStudent->copyPerson(idHold);
        masterStudent->remove(*hold);

        int FACID = hold->getStudentFacultyID();

        faculty *FFF = masterFaculty->copyPerson(FACID);
        FFF->removeAdvisee(idHold);
        cout << "Removed student from the student database and from their advisor's advisee list" << endl;
    }
    else {
        cout << "There is no student with this student ID." << endl;
        return;
    }
}
/*
a. function removeFaculty
b. void
c. none
d. none
*/
void menu::removeFaculty(){
    int idHold;
    cout << "Please input the ID of the faculty you would like to remove: ";
    cin >> idHold;

    if (masterFaculty->personExistCheck(idHold)){
        faculty *hold = masterFaculty->copyPerson(idHold);
        masterFaculty->remove(*hold);
        cout << "Faculty has been removed. Please remember to update the student's faculty with a new faculty member" << endl;
    }
    else {
        cout << "There is no faculty with this student ID." << endl;
        return;
    }


}
/*
a. function changeStudentAdvisor
b. void
c. none
d. none
*/
void menu::changeStudentAdvisor(){
    int studentIDHold;
    cout << "Please input the ID of the student of whom you want to change the advisor: ";
    cin >> studentIDHold; 

    if (masterStudent->personExistCheck(studentIDHold)){
        int facultyIDHold;
        cout << "Please input the ID of the replacement Faculty member: ";
        cin >> facultyIDHold;
        if (masterFaculty->personExistCheck(facultyIDHold)){
            student *newS = masterStudent->copyPerson(studentIDHold);
            int oldFACULID = newS->getStudentFacultyID();
            cout << "oldfacultyID is" << oldFACULID << endl;
            newS->setStudentFacultyID(facultyIDHold);

            faculty *oldFaculty = masterFaculty->copyPerson(oldFACULID);
            oldFaculty->removeAdvisee(studentIDHold);

            faculty *newFacultyPerson = masterFaculty->copyPerson(facultyIDHold);
            newFacultyPerson->addAdvisee(studentIDHold);
        }
        else{
            cout << "A faculty with this ID does not exist!" << endl;
            return;
        }
    }
    else {
        cout << "A student with this ID does not exist!" << endl;
        return;
    }

}
/*
a. function removeAdviseeFromID
b. void
c. none
d. none
*/

void menu::removeAdviseeFromID(){
    int adviseeID;
    cout << "please input the ID of the advisee you would like to remove: ";
    cin >> adviseeID;

    int FFidHold;
    cout << "Please input the ID of the faculty: ";
    cin >> FFidHold;

    faculty *facu = masterFaculty->copyPerson(FFidHold);
    facu->removeAdvisee(adviseeID);
}
/*
a. function exit
b. void
c. none
d. none
*/
void menu::exit(){ 
    exit();
}




