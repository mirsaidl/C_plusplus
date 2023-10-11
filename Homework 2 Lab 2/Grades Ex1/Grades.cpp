#include <iostream>
using namespace std;

int main()
{
    int grade;
    cout << "Enter your score of exam: ";
    cin >> grade;
    
    if (90 <= grade && grade <= 100)
        cout << "Congratulations!!! Your grade is: A";
    else if (80 <= grade && grade <= 89)
        cout << "Your grade is: B";
    else if (70 <= grade && grade <= 79)
        cout << "Your grade is: C";
    else if (60 <= grade && grade <= 69)
        cout << "Your grade is: D";
    else if (0 <= grade && grade <= 59)
        cout << "Sorry. Your grade is: F";
    else
        cout << "End of the program!";


}