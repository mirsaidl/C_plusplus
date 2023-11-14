#include <iostream>
using namespace std;

class Apple {
private:
    string color;
    string fruit;

public:
    Apple(string c, string f = "apple") : color(c), fruit(f) {};

    string getName() const {
        return fruit;
    }

    string getColor() const {
        return color;
    }
};

class Banana : public Apple {
public:
    Banana(string f = "banana", string c = "yellow") : Apple(c, f) {};
};

class RedBanana : public Banana {
public:
    // Constructor for RedBanana, inheriting from Banana
    // Calls the Banana constructor to set the fruit and color
   
    RedBanana(string f = "red banana", string c = "red") : Banana(f, c) {};
};

int main() {
    Apple a{ "red" };
    Banana b;
    RedBanana c;
    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    return 0;
}
