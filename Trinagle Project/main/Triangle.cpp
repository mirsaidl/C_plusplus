#include "Triangle.h"
#include <iostream>
using namespace std;

// Declarations of functions

double Triangle::getBase() {
	return base; 
};

double Triangle::getHeight() {
	return height;
};

double Triangle::area() {
	return base * height * 0.5; // Area of triangle = height * base * 1/2
};

// Finish
