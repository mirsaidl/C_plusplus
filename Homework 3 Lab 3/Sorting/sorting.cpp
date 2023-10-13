#include <iostream>
using namespace std;

void swap2(double& x, double& y) {
	double temp;
	temp = x;
	x = y;
	y = temp;
}

void sort3(double& x, double& y, double& z, bool(*compare)(double&, double&)) {
	if (compare(x, y))
		swap2(x, y);
    if (compare(y, z))
		swap2(y, z);
	if (compare(x, y)) {
		swap2(x, y);
	}
	
}

void print3(const double& a, const double& b, const double& c) { // Prints message
	cout << a << ' ' << b << ' ' << c << endl;
}

bool ascending(double& x, double& y) {
	return x > y;
}
bool descending(double& x, double& y) {
	return x < y;
}


int main() {
	double na1 = 10.3, na2 = -2.1, na3 = 8.0;
	double nd1 = 10.3, nd2 = -2.1, nd3 = 8.0;
	cout << "Befere sort: "; print3(na1, na2, na3);
	sort3(na1, na2, na3, ascending);
	sort3(nd1, nd2, nd3, descending);
	cout << "After sort(ascending): "; print3(na1, na2, na3);
	cout << "After sort(descending): "; print3(nd1, nd2, nd3);
	return 0;
}