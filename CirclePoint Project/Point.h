#ifndef __POINT_H__
#define __POINT_H__

class Point {
public:
	double m_x;
	double m_y;
	double *x = &m_x;
	double *y = &m_y;
	Point(double x, double y) { // Constructor with parameters
		m_x = x;
		m_y = y;
	}

	void get(double& a, double& b);
	void info();
	double getx() const;
	double gety() const;
};


#endif // __POINT_H__
