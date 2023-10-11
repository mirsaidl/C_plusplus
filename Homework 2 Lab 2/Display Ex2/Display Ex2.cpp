// Exercise 2
#include <iostream>
using namespace std;

// function prototypes
void display(char item);
void display(int num);
void display(double fl);



int main() {
	display('A');
	display(1234);
	display(123.4);

	return 0;
}

// function definitions
void display(char item) {
	cout << "Char type: " << item << endl;
}

void display(int num) {
	cout << "Int type: " << num << endl;
}

void display(double fl) {
	cout << "Double type: " << fl << endl;
}