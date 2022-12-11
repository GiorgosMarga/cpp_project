#include <iostream>
using  namespace std;

class dummy{
	int x;
	public:
		dummy();
		dummy(int h);
	    int get_x() const;
	    ~dummy();
};
dummy::dummy(int h){
	x = h;
}
dummy::dummy(){
	x = 0;
}

dummy::get_x() const{
	return x;
}

dummy::~dummy(){
	int x;
	x = get_x();
	cout<<"Item destroyed. "<<"Value of x: "<< x<<endl;
}

int main(){
	dummy dummy1(10);
	dummy dummy2;
	return 0;
}
