#include <iostream>
#include <iomanip>
#include <math.h>
#include <chrono>
#include <thread>
extern double f1();
extern double f2(double a);
extern double f3(double a);
extern double f4(double a);
extern double f5(double a);
extern double f6(double a, double b);
extern double f7(double a);
void thread_1(double *a,int *flag,double *c,int *b_flag,double *b){
	*a=f1();
	*flag=1;
	*c=f3(*a);
    while(b_flag==0);
    *a=f6(*b,*c);
}
void thread_2(double *b,double a,double *e,int *b_flag){
	*b=f2(a);
    *b_flag=1;
    *e=f5(*b);
}
void thread_3(double *d,double a){
	*d=f4(a);
    *d=f7(*d);	
}

int main(int argc, char **argv)
{
	static int num_of_threads=3;
	std::thread t[num_of_threads];
	double a, b, c, d ,e,res;
	int t0=0,t1=1,t2=2,t3=3;
	auto start = std::chrono::high_resolution_clock::now();
	int flag=0,b_flag=0;
	t[t0]=std::thread(thread_1,&a,&flag,&c,&b_flag,&b);
	while(flag==0);
	t[t1]= std::thread(thread_2,&b,a,&e,&b_flag);
	t[t2]= std::thread(thread_3,&d,a);
	for(int i=0;i<3;i++){
		t[i].join();
	}
    res=e+d+a;
	auto end = std::chrono::high_resolution_clock::now();
	
	std::cout << "Result = " << std::setprecision(18) << res << std::endl;
	std::cout << "Time: " << (end - start)/std::chrono::milliseconds(1) << "ms" << std::endl;
	return 0;
}
