#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

// Class representing an integer array
class IntArray
{
private:
    int m_len{ 0 };
    int* m_data{ nullptr };

public:
    // Constructor to initialize the array with a given length
    IntArray(int len)
        : m_len{ len }
    {
        m_data = new int[m_len];
    }

    // Destructor to free dynamically allocated memory
    ~IntArray() {
        if (m_data) delete[] m_data;
    }

    // Getter function to retrieve the array data
    int* getData() const {
        return m_data;
    }

    // Getter function to retrieve the array length
    int getLength() const {
        return m_len;
    }
};

// Class for handling operations on IntArray objects
class IntArrayHandler
{
private:
    IntArray* m_array;
public:
    // Constructor to initialize with an IntArray object
    IntArrayHandler(IntArray* array) : m_array{ array } {}

    // Set the current IntArray object
    void setIntArray(IntArray* array) {
        m_array = array;
    }

    // Set the elements of the array with the given data
    void setArray(int* data, int len) {
        if (m_array && data) {
            int arrayLen = m_array->getLength();
            int* arrayData = m_array->getData();
            for (int i = 0; i < arrayLen && i < len; ++i) {
                arrayData[i] = data[i];
            }
        }
    }

    // Display the elements of the array
    void displayArray() const {
        if (m_array) {
            int* arrayData = m_array->getData();
            int arrayLen = m_array->getLength();
            for (int i = 0; i < arrayLen; ++i) {
                cout << "[ " << setw(2) << i << "] " << arrayData[i] << endl;
            }
        }
    }

    // Calculate and display statistics of the array
    void stat() const {
        if (m_array) {
            int* arrayData = m_array->getData();
            int arrayLen = m_array->getLength();
            int sum = 0;

            for (int i = 0; i < arrayLen; ++i) {
                sum += arrayData[i];
            }

            cout << "# of elements: " << arrayLen << endl;
            cout << "Sum: " << sum << endl;
            cout << "Average: " << fixed << setprecision(2) << static_cast<double>(sum) / arrayLen << endl;
        }
    }
};

const int arSize = 20;

int main() {
    int i;
    int data1[arSize], data2[arSize];
    IntArray ar1{ arSize }, ar2{ arSize };
    srand((unsigned int)time(NULL));
    for (i = 0; i < arSize; ++i) {
        data1[i] = rand() % 100;
        data2[i] = rand() % 100;
    }

    // Create IntArrayHandler objects and perform operations
    IntArrayHandler handler{ &ar1 };
    handler.setArray(data1, arSize);
    cout << "== ar1: displayArray() ===" << endl;
    handler.displayArray();
    cout << "====== ar1: stat() =======" << endl;
    handler.stat();
    cout << "==========================" << endl;

    handler.setIntArray(&ar2);
    handler.setArray(data2, arSize);
    cout << endl << "== ar2: displayArray() ===" << endl;
    handler.displayArray();
    cout << "====== ar2: stat() =======" << endl;
    handler.stat();
    cout << "==========================" << endl;

    return 0;
}
