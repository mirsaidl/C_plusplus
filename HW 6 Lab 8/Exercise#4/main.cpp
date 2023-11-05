#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hour;
    int min;
    int sec;

public:
    // Constructor to initialize Time object
    Time(int h, int m, int s) : hour(h), min(m), sec(s) {};

    // Print time in 12-hour format
    void printTime() const {
        if (hour <= 23 && hour > 12) {
            // If the hour is in the afternoon/evening, subtract 12 to display in 12-hour format
            cout << setfill('0') << setw(2) << hour - 12 << ":";
            cout << setfill('0') << setw(2) << min << ":";
            cout << setfill('0') << setw(2) << sec << endl;
        }
        else {
            // For morning hours (before 12 PM), display time as is
            cout << setfill('0') << setw(2) << hour << ":";
            cout << setfill('0') << setw(2) << min << ":";
            cout << setfill('0') << setw(2) << sec << endl;
        }
    }

    // Non-const version of printTime for the Time object
    void printTime() {
        // Display time in 24-hour format (no conversion)
        cout << setfill('0') << setw(2) << hour << ":";
        cout << setfill('0') << setw(2) << min << ":";
        cout << setfill('0') << setw(2) << sec << endl;
    }
};

int main() {
    const Time t0{ 7, 3, 5 }; // Constant Time object t0
    Time t1{ 13, 45, 9 };    // Non-constant Time object t1
    const Time t2{ t1 };     // Constant Time object t2 initialized from t1

    cout << "t0: ";
    t0.printTime(); // Display t0 time in 12-hour format
    cout << "t1: ";
    t1.printTime(); // Display t1 time in 24-hour format
    cout << "t2: ";
    t2.printTime(); // Display t2 time in 12-hour format

    return 0;
}



