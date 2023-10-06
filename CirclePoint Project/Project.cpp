#include "Point.h"
#include <iostream>
#include "Circle.h"
using namespace std;


int main() {
	//Exercise 2
	Circle c1;
	Circle c2{};
	Point p {10.5, 20.5};
	Circle c3{ p, 20.0 };
	Circle c4{ 20.5, 10.5, 10.0 };
	cout << "c1.info: "; c1.info();
	cout << "c2.info: "; c2.info();
	cout << "c3.info: "; c3.info();
	cout << "c4.info: "; c4.info();

	//Exercise 3
	cout << "\nArea of c3: " << c3.area() << endl;
	const Point& cent = c3.centre_f();
	cout << "Center of c3: ";
	cout << "[" << cent.getx() << ", " << cent.gety() << "]\n";
	cout << "Radius of c3: " << c3.radius() << endl;
	cout << "IsInside: " << c4.IsInside(Point{ 25.0, 8.0 })
		<< endl << endl;
	return 0;
}
