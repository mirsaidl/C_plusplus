#include "Rectangle.h"
#include <iostream>
using namespace std;

bool Rectangle::InitMembers(const Point& ul, const Point& lr) {
	
	m_upLeft.SetX(min(ul.GetX(), lr.GetX()));
	m_upLeft.SetY(max(ul.GetY(), lr.GetY()));
	m_lowRight.SetX(max(ul.GetX(), lr.GetX()));
	m_lowRight.SetY(min(ul.GetY(), lr.GetY()));

	if ((ul.GetX() > lr.GetX()) || (ul.GetY() > lr.GetY()))
		return false;
	m_upLeft = ul;
	m_lowRight = lr;


	return true;
}
void Rectangle::ShowRecInfo() const {
	cout << "LeftTop: " << '[' << m_upLeft.GetX() << ", ";
	cout << m_upLeft.GetY() << ']' << endl;
	cout << "RightBottom: " << '[' << m_lowRight.GetX() << ", ";
	cout << m_lowRight.GetY() << ']' << endl << endl;
}

bool Rectangle::IsInside(Point p)
{
	if (p.GetX() >= m_upLeft.GetX() && p.GetX() <= m_lowRight.GetX() && p.GetY() >= m_upLeft.GetY() && p.GetY() <= m_lowRight.GetY()) {
		return true;
	}
	else {
		return false;
	}
}

