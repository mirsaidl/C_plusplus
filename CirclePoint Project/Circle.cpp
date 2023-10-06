#include "Circle.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
#define M_PI 3.14159265358979323846

void Circle::info() {
	cout << "Center: [" << center.getx() << ", " << center.gety() << "], Radius: " << m_radius << endl;
}

double Circle::area(void) {
	return M_PI * m_radius * m_radius;
};
Point Circle::centre_f(void) const {
    const Point c = center;
    return c;
};
double Circle::radius(void) {
	return m_radius;
};
bool Circle::IsInside(const Point& line) {
	double distance = sqrt(pow(line.m_x - center.m_x, 2) + pow(line.m_y - center.m_y, 2));

	if (distance < m_radius)
		return true;
	else if (distance >= m_radius)
		return false;
};
