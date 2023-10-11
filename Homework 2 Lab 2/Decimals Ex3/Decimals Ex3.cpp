#include <iostream>
using namespace std;

void cout_int(int num) {
	cout << num << endl;
}

void cout_int(int num, int base) {
	if (base == 8) {
		cout << "Octal " << oct << 100 << endl;
	}
	else if(base == 10) {
		cout << "Decimal " << dec << 100 << endl;
	}
	else if (base == 16) {
		cout << "Hexadecimal " << hex << 100 << endl;
	}
	else {
		cout << "ERROR: unknown base!";
	}
}


int main() {
    
	cout_int(100);
	cout_int(100, 8);
	cout_int(100, 10);
	cout_int(100, 16);
	cout_int(100, 20);

    return 0;
}