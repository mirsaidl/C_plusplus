#include <iostream>
using namespace std;

class Person {
public:
	string name;
	string gender;
	int age;
	string email;

	void introduceMyself() {
		cout << "My name is " << name << endl;
		cout << "I am " << gender << " and " << age << " years old" << endl;
		cout << "My email address is " << email << endl;
	}
};

int main() {
	Person ryu = { "Victor Ryu", "male", 30, "IGS2130v1@inha.ac.kr" };
	Person laura = { "Laura Lee", "female", 23, "IGS2130v2@inha.ac.kr" };
	ryu.introduceMyself();
	cout << endl;
	laura.introduceMyself();
	return 0;
}
