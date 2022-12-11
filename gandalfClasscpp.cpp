#include <iostream>
#include <cstring>
using namespace std;

class Gandalf{
	int age;
	char colorOfBeard[80];
	int magic;
	public:
		Gandalf(int age, char *color, int magic);
		void fireballSpell();
		void lightningSpell();
		void wait();
		int get_magic() const;
		void set_magic(int x);
		~Gandalf();
		
};
Gandalf::Gandalf(int in_age, char *color, int in_magic){
	age = in_age;
	strcpy(colorOfBeard, color);
	magic = in_magic;
}
void Gandalf::fireballSpell(){
	set_magic(get_magic() - 30);
}

void Gandalf::lightningSpell(){
	set_magic(get_magic() - 90);
}

void Gandalf::wait(){
	set_magic(get_magic() + 10);
}

int Gandalf::get_magic() const{
	return magic;
}

void Gandalf::set_magic(int x){
	magic = x;
}

Gandalf::~Gandalf(){
	cout << "I can't die!!!!!!!!" << endl;
}
int main(){
	char color[] = "Grey";
	Gandalf gand(2019,color, 100);
	cout<< gand.get_magic();
	gand.fireballSpell();
	cout<<"Gandalf casted a fireball spell. His mana is " << gand.get_magic() << " now." << endl;
	gand.wait();
	cout<<"Gandalf is waiting. His mana is " << gand.get_magic() << " now." << endl;
	gand.lightningSpell();
	cout<<"Gandalf casted a lightning spell. His mana is " << gand.get_magic() << " now." << endl;
	gand.wait();
	cout<<"Gandalf is waiting. His mana is " << gand.get_magic() << " now." << endl;
	gand.wait();
	cout<<"Gandalf is waiting. His mana is " << gand.get_magic() << " now." << endl;
	gand.fireballSpell();
	cout<<"Gandalf casted a fireball spell. His mana is " << gand.get_magic() << " now." << endl;
	return 0;
}
