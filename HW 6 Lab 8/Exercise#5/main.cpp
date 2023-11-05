#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

const int arSize = 20;

class IntArray {
private:
    int m_len{ 0 };
    int* m_data{ nullptr };

public:
    IntArray(int len)
        : m_len{ len }
    {
        m_data = new int[m_len]; 
    }

    // Friend functions
    friend void setArray(IntArray& ar, int date[], const int arSize);
    friend void displayArray(IntArray& ar);

   
    ~IntArray() {
        if (m_data) delete[] m_data;
    }
};

// Function to set the contents of the IntArray using an array
void setArray(IntArray& ar, int date[], int arSize) {
    ar.m_len = arSize; // Update the length

    // Allocate new memory for the array and copy the data from the input array
    ar.m_data = new int[ar.m_len];
    for (int i = 0; i < ar.m_len; ++i) {
        ar.m_data[i] = date[i];
    }
}

// Function to display the contents of the IntArray
void displayArray(IntArray& ar) {
    for (int i = 0; i < ar.m_len; i++) {
        cout << "[" << i + 1 << "] " << ar.m_data[i] << endl;
    }
}

int main() {
    int i;
    int data[arSize];
    IntArray ar{ arSize }; 
    srand(static_cast<unsigned int>(time(NULL)));
    for (i = 0; i < arSize; ++i) {
        data[i] = rand() % 100;
    }
    setArray(ar, data, arSize);
    displayArray(ar); 

    return 0;
}
