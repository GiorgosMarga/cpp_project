#include <iostream>
using namespace std;

class point{
	double x,y;
	public:
		point();
		point(double new_x, double new_y);
		void set_x(double new_x);
		void set_y(double new_y);
		double get_x() const;
		double get_y() const;
		void print();
};

point::point(){
	set_x(0.0);
	set_y(0.0);
}

point::point(double new_x, double new_y){
	set_x(new_x);
	set_y(new_y);
}

double point::get_x() const{
	return x;
}

double point::get_y() const{
	return y;
}

void point::set_x(double new_x){
	x = new_x;
}

void point::set_y(double new_y){
	y = new_y;
}

void point::print(){
	cout<<"("<< get_x() << "," << get_y() << ")" << endl;
}

int main(){
	point p1;
	point p2(10.0, 30.0);
	point p3(5.5, 10.2);
	p1.print();
	p2.print();
	p3.print();
	return 0;
}
