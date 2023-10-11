#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

namespace shape {
	int rec_area(int w, int l) {
		return w * l;
	}

	double tri_area(int b, int h) {
		return 0.5 * b * h;
	}

	double cir_area(int r) {
		double p = 3.14;
		return p * pow(r, 2);
	}
}

int main() {
	cout << "Area of Rectangle(W:20, L:10):";
	cout << shape::rec_area(20, 10) << endl;
	cout << "Area of Triangle(b:20, h:10):";
	cout << shape::tri_area(20, 10) << endl;
	cout << "Area of Circle(r:20):";
	cout << shape::cir_area(20) << endl;
	return 0;
}