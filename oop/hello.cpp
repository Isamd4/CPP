#include <iostream>
#include <list>
using namespace std;
#include "Student.h"
int main(){
    Student s("Muhammad Isa Hassan",1.23);
    s.set_cgpa(4.65);
    Student s2(s);
    s2.to_print();
    list<int> mylist;
    cout << "Hi I am Muhmmd";
    return 0;
}