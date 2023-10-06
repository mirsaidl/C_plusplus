#include "Point.h"
#include <iostream>
using namespace std;

void Point::get(double& a, double& b) {
	*x = a;
	*y = b;
}

void Point::info() {
	cout << "(x,y) = " << m_x << ", " << m_y << endl;
}

double Point::getx() const {
	return *x;
}

double Point::gety() const{
	return *y;
}
