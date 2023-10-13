#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
#include "Point.h"


class Rectangle {
public:
	Point m_upLeft;
	Point m_lowRight;
public:
	bool InitMembers(const Point& ul,
		const Point& lr);
	void ShowRecInfo() const;
	bool IsInside(Point p);
};
#endif // __RECTANGLE_H__


