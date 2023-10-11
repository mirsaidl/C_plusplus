#include <iostream>
using namespace std;

int GetMaximum(int*, int);
int GetMinimum(int*, int);
double GetAverage(int*, int);


int main()
{
    int size;
    cout << "# of data want to input: ";
    cin >> size;
    
    int* array;
    array = new int[size];

    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". Input an integer: ";
        cin >> array[i];
    }

    cout << "Maximum value is " << GetMaximum(array, size) << endl;
    cout << "Minimum value is " << GetMinimum(array, size) << endl;
    cout << "Average value is " << GetAverage(array, size) << endl;

    delete[] array;
}

int GetMaximum(int* array, int size) {
    int max = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}
int GetMinimum(int* array, int size) {
    int min = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] < min)
            min = array[i];
    }

    return min;
}
double GetAverage(int* array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    
    double avg = double(sum) / double(size);

    return avg;

}