//Extend the Animal class to include a constructor that 
// initializes an animal's name. The Dog class should also 
// have its own constructor that calls the base class 
// constructor to set the name. Implement destructors for both 
// classes that display messages when the object is destroyed.

#include<iostream>
#include<string>
using namespace std;
class animal {
private:
	string name;
public:
	animal(string x):name(x){

	}
	void displayanimal() {
		cout << "Animal name: " << this->name << endl;
	}
	~animal() {
		cout << "destructor for animal: " << this->name << endl;
	}
};
class dog : public animal {
private:
	string name;
public:
	dog(string y,string x) :name(y),animal(x) {

	}
	void displaydog() {
		cout << "Dog name: " << this->name << endl;
	}
	~dog() {
		cout << "Destructo for dog: " << this->name << endl;
	}
};
int main() {
	string base_name, derived_name;
	cout << "Enter animal name: ";
	getline(cin, base_name);
	cout << "Enter dog name: ";
	getline(cin, derived_name);
	animal a(base_name);
	a.displayanimal();
	dog b(derived_name,base_name);
	b.displaydog();

	system("pause");
	return 0;
}
