// Abdurasulov Mirsaid 12225253
#include <iostream>
using namespace std;

class Calculate {
private:
    double value = 0.0; // default variable with the value of 0.0 inside private 
    char operators[5];
    double s_values[5];
    int index = -1;

public:
    // function which returns the value of the value variable
    double getValue() {
        return value;
    }

    double add(double a) { // add function which adds the real number to value
        store_operarion('+', a);
        value += a;
        return value;
    }

    double substract(double a) { // substract function which - the real number from value
        store_operarion('-', a);
        value -= a;
        return value;
    }

    double multiply(double a) { // multiply function which multiplies the real number to the value
        store_operarion('*', a);
        value *= a;
        return value;
    }

    double divide(double a) { // devide function which devides the real number to the value
        store_operarion('/', a);
        value /= a;
        return value;
    }

    void store_operarion(char op, double svalue) {
        if (index < 4) {
            index++;
            operators[index] = op;
            s_values[index] = svalue;
        }
        else {
            for (int i = 0; i < 4; i++) {
                operators[i] = operators[i + 1];
                s_values[i] = s_values[i + 1];
            }
            operators[4] = op;
            s_values[4] = svalue;
        }
    }

    bool lastOperation(char& op, double& svalue) {
        if (index >= 0) {
            op = operators[index];
            svalue = s_values[index];
            return true;
        }
        return false;
    }

    void undo() {
        if (index >= 0) {
            char op = operators[index];
            double svalue = s_values[index];
            index--;

            if (op == '+') value -= svalue;
            else if (op == '-') value += svalue;
            else if (op == '*') value /= svalue;
            else if (op == '/') value *= svalue;
        }
    }
};

int main(void) {
    Calculate cc;
    int i;
    char op;
    double value;
    for (i = 0; i < 10; ++i) {
        cout << "Select math operator(+,-,*,/): ";
        cin >> op;
        cout << "Enter a real number for the math: ";
        cin >> value;
        switch (op) {
        case '+':
            cout << cc.getValue() << " + " << value;
            cout << " = " << cc.add(value) << endl;
            break;
        case '-':
            cout << cc.getValue() << " - " << value;
            cout << " = " << cc.substract(value) << endl;
            break;
        case '*':
            cout << cc.getValue() << " * " << value;
            cout << " = " << cc.multiply(value) << endl;
            break;
        case '/':
            cout << cc.getValue() << " / " << value;
            cout << " = " << cc.divide(value) << endl;
            break;
        }
    }

    cout << endl << endl;
    for (i = 0; i < 10; ++i) {
        cout << "Stored the last math operation: ";
        bool flag = cc.lastOperation(op, value);
        if (!flag)
            cout << "None" << endl;
        else
            cout << op << ", " << value << endl;
        if (flag) {
            cc.undo();
            cout << "Undo the last math operation..." << endl;
            cout << "Value inside the class object: ";
            cout << cc.getValue() << endl;
        }
    }
    cout << "Value inside the class object: ";
    cout << cc.getValue() << endl;

    return 0;
}
