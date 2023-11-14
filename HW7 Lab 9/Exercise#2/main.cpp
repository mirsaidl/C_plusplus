#include <iostream>
using namespace std;


class Test {
private:
	static int counter;
	int m_id;
	int m_data;
public:
	Test(int data)
		: m_id{ ++counter }, m_data{ data }
	{
	}

	// Static member function to get the number of objects created
	static int NumOfObjects() {
		return counter;
	}

	// Member function to get the ID of the object
	int getID() const {
		return m_id;
	}

	// Member function to get the data of the object
	int getData() const {
		return m_data;
	}
};

// Initialize the static ID counter
int Test::counter = 0;

int main() {
	cout << "# of objects: ";
	cout << Test::NumOfObjects() << endl;
	Test t1{ 10 }, t2{ 20 }, t3{ 30 }, t4{ 40 };
	cout << "[t1] data: " << t1.getData() << ", id: " << t1.getID() << endl;
	cout << "[t2] data: " << t2.getData() << ", id: " << t2.getID() << endl;
	cout << "[t3] data: " << t3.getData() << ", id: " << t3.getID() << endl;
	cout << "[t4] data: " << t4.getData() << ", id: " << t4.getID() << endl;
	cout << "# of objects: ";
	cout << Test::NumOfObjects() << endl;
	return 0;
}