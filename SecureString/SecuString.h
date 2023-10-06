#ifndef __SECU_STRING__
#define __SECU_STRING__

#include <iostream>
using namespace std;

class SecuString {
private:
    string message;    // Store the message
    string password;   // Store the password

public:
    // Constructor to initialize the message and password
    SecuString(string u, string p) : message(u), password(p) {};

    // Pointers to the message and password for direct access
    string* msg = &message;
    string* pass = &password;

    // Function to set the message if the provided password matches
    bool SetMessage(string m, string p);

    // Function to get the message if the provided password matches
    string GetMessage(string p);

    // Function to change the password if the provided old password matches
    bool ChangePW(string old_p, string new_p);
};

#endif
