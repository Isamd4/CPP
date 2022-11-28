#include <iostream>
using namespace std;
#include "Student.h"

Student::Student(string name,double cgpa){
    this->name=name;
    this->cgpa=cgpa;
}
Student::Student(Student &from){
    this->name=from.name;
    this->cgpa=from.cgpa;

}
double Student::get_cgpa(){
    return this->cgpa;
}
void Student::set_cgpa(double cgpa){
    this->cgpa=cgpa;
}
void Student::to_print(){
    cout << this->name << " " << this->cgpa;
}