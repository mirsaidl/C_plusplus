#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Point.h"
#include <iostream>
using namespace std;

class Circle {
public:
	Point center;
	double m_radius;
	double x = center.getx();
	double y = center.gety();
	
	Circle() : center(x, y), m_radius{} {};

	// Constructor with center and radius
	Circle(Point& c, double r) : center(c), m_radius(r) {}
	Circle(double a,double b, double r): center(a,b), m_radius(r) {}

	~Circle() {
		cout << "Destruction of a class instance\n";
	
		cout << "Center: [" << center.getx() << ", " << center.gety() << "], Radius: " << m_radius << endl;
	};

	void info();
	double area(void);
	Point centre_f(void) const;
	double radius(void);
	bool IsInside(const Point&);
};


#endif


