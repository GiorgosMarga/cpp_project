#include <iostream>

using namespace std;

double average(int a, int b);
double  average(double a, double b);

int main(){
	cout << average(2.4, 4.5);
}

double average(int a, int b){
	return (a + b) / 2;
}

double average(double a, double b){
	return (a + b) / 2;
}
