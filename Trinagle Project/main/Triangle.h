#include <iostream>
#ifndef __TRIANGLE__
#define __TRIANGLE__
using namespace std;

class Triangle{
private:
	double base; // base
	double height; // height
public:
	Triangle(double b, double h) : base(b), height(h) {}; // Constructor

	~Triangle() {
		cout << "Distructor: base: " << base << ", height: " << height << endl; // Distractor
	};

	double getBase(); // in order to get base height and area
	double getHeight();
	double area();


};

#endif // !__TRIANGLE__

