#include <iostream>
using namespace std;


class Number {
public:
	double m_val;

	double setValue(double num) {
		m_val = num;
		return m_val;
	}

	double getValue() {
		return m_val;
	}

	double add(double num) {
		m_val = m_val + num;
		return m_val;
	}

	double sub(double num) {
		m_val = m_val - num;
		return m_val;
	}

	double mul(double num) {
		m_val = m_val * num;
		return m_val;
	}

	double div(double num) {
		m_val = m_val / num;
		return m_val;
	}
};

int main(void) {
	Number n1, n2;
	n1.setValue(0.0);
	cout << "n1 : " << n1.getValue() << endl;
	cout << "n1 += 10.5 : " << n1.add(10.5) << endl;
	cout << "n1 -= 1.5 : " << n1.sub(1.5) << endl;
	cout << "n1 *= 3.0 : " << n1.mul(3.0) << endl;
	cout << "n1 /= 9.0 : " << n1.div(9.0) << endl;
	cout << "n2 = n1 : " << n2.setValue(n1.getValue());
	return 0;
}