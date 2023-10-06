#include "SecuString.h"
#include <iostream>
#include <string>
using namespace std;

// Function to set the message if the provided password matches the stored password
bool SecuString::SetMessage(string m, string p) {
    if (p == password) {
        *msg = m; 
        return true;  // Return true if the message is set successfully
    }
    else {
        return false;  // Return false if the password does not match
    }
}

// Function to get the message if the provided password matches the stored password
string SecuString::GetMessage(string p) {
    string noequal = "No real stored message. Invalid Password..";

    if (p == password) {
        return message;  // Return the stored message if the password matches
    }
    else {
        return noequal;  // Return an error message if the password does not match
    }
}

bool SecuString::ChangePW(string old_p, string new_p) {
    if (old_p == password) {
        *pass = new_p;
        return true;  // Return true if the password is changed successfully
    }
    else {
        return false;  // Return false if the old password does not match
    }
}
