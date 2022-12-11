#include <iostream>
using namespace std;

class dog{
	public:
		void express(){
			if(mood > 10){
				cout << "I am cool" << endl;
			}else{
				cout << "I AM FURIUS" << endl;
			}
		}
		void set_mood(int h){
			mood = h;
		}
		void set_hunger(int h){
			hunger = h;
		}
		
		void get_hunger(){
			cout << "I am " << hunger << " % hungry." << endl;
		}
		void get_mood(){
			cout << "I am " << mood << " % moody." << endl;
		}
		void bark(){
			cout << "WOOF WOOF" << endl;
		}
		void isHungry(){
			if(hunger < 5){
				cout << "I am starving." << endl;
				
			}else if(hunger < 10){
				cout << "I am hungry." << endl;
			}else{
				cout << "I am not hungry." << endl;
			}
		}
	private:
		int mood;
		int hunger;
};

int main(){
	dog Azor;
	Azor.set_mood(30);
	Azor.get_mood();
	Azor.express();
	Azor.set_mood(5);
	Azor.set_hunger(10);
	Azor.isHungry();
	Azor.bark();
	Azor.bark();
	Azor.express();
	
}
