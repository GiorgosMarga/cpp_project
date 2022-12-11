#include <iostream>
#include <cstring>
using namespace std;

class STRING{
	char *array;
	int length;
	public:
		STRING();
		STRING(char *string);
		~STRING();
		STRING(const STRING &ob);
		char *getString() const;
		int getSize() const;
		void stringPrint();
		void setString(char *newString);
};

STRING::STRING(){
	length = 0;
	array = NULL;
}


STRING::STRING(const STRING &ob){
	cout << "Constructing...." << endl;
	length = ob.getSize();
	array = new char [length];
	if(!array){
		cout << "Error allocating memory..." << endl;
	}
	strcpy(array, ob.getString());
}

STRING::STRING(char *string){
	length = strlen(string);
	array = new char [length];
	if (!array){
		cout << "Error allocating memory!!!" << endl;
	}
	strcpy(array, string);
	
}
STRING::~STRING(){
	cout << "Deleting string..." << endl;
	delete array;
}

int STRING::getSize() const{
	return length;
}

char *STRING::getString() const{
	return array;
}

void STRING::stringPrint(){
	cout << array << endl;
}

void STRING::setString(char *newString){
	if(array != NULL){
		delete array;
	}
	length = strlen(newString);
	array = new char [length];
	if(!array){
		cout << "Error allocating memory..." << endl;
	}
	strcpy(array, newString);
}
int main(){
	char s[80] = "Hello world";
	char t[50] = "This is a new string";
	STRING s1(s);
	STRING s2 = s1;
	
	s1.stringPrint();
	s2.stringPrint();
	s1.setString(t);
	s1.stringPrint();
	return 0;
}

