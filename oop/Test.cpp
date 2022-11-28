#include <iostream>
#include <thread>
using namespace std;

void printHello(){
    cout << "Hi I am Muhammad Isa\n";
}
int main(){
    thread t(printHello);
    t.join();
    return 0;
}