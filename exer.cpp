#include <iostream>
using namespace std;

class ARRAY{
	int *pin;
	int size;
	public:
		ARRAY(int sizeOfArray);
		~ARRAY();
		ARRAY(const ARRAY &ob);
		void set_value(int i, int value);
		int get_value(int i);
		int get_size() const;
		void print();
		
};
ARRAY::ARRAY(const ARRAY &ob){
	size = ob.get_size();
	
	pin = new int [size];
	cout <<  "Constructing..." << endl;
	
} 

int ARRAY::get_size() const{
	return size;
}
ARRAY::ARRAY(int sizeOfArray){
	pin = new int [sizeOfArray];
	if(!pin){
		cout << "Error allocationg memory!";
	}
	size = sizeOfArray;
}

ARRAY::~ARRAY(){
	delete [] pin;
}


int ARRAY::get_value(int i){
	if(i >= size || i < 0){
		cout << "Out of boundaries. "<< endl;
	}else{
		return pin[i];
	}
	
}

void ARRAY::set_value(int i, int value){
	if(i >= 0 && i < size){
		pin[i] = value;
	}
	else{
		cout << "Out of boundaries. ";
	}
}

void ARRAY::print(){
	for(int i = 0; i < size; i++){
		cout << pin[i] << " ";
	}
	cout << endl;
}
int main(){
	ARRAY pinakas(10);
	ARRAY pinakas2 = pinakas;
	for(int i = 0; i < 10; i++){
		pinakas.set_value(i, i * i);
	}
	pinakas.print();
	
	for(int i = 0; i < 10; i++){
		pinakas2.set_value(i, i * i * i);
	}
	pinakas2.print();
	
	return 1;
}
