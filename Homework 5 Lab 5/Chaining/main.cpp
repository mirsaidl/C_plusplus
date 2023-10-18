#include <iostream>
using namespace std;

class Rectangle {
private:
	int width;
	int height;
public:
	Rectangle(int w = 0, int h = 0) { // default constructor
		width = w;
		height = h;
	}

	~Rectangle() { // destructor
		width = 0; // 0 if destructor used
		height = 0;
	}

	Rectangle& setWidth(int w) { // chain function
		width = w;
		return *this;
	};
	Rectangle& setHeight(int h) { // chain function
		height = h;
		return *this;

	};
	void Display() {
		// info
		cout << "Width = " << width << " " << "Height = " << height << endl;
	}



};

int main() {
	Rectangle rect;
	rect.Display();
	rect.setWidth(10).setHeight(20).Display();
	return 0;
}

