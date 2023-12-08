#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

const int arraySize = 20;

void fillArray(int* arr, int index) {
    if (index < arraySize) {
        arr[index] = -20 + rand() % (50 + 20 + 1);
        fillArray(arr, index + 1);
    }
}

void printArray(const int* arr, int index) {
    if (index < arraySize) {
        std::cout << std::setw(4) << arr[index];
        printArray(arr, index + 1);
    }
    else {
        std::cout << std::endl;
    }
}

void processArray(int* arr, int& count, int& sum, int index) {
    if (index < arraySize) {
        if (!(arr[index] > 0 || arr[index] % 5 == 0)) {
            count++;
            sum += arr[index];
            arr[index] = 0;
        }
        processArray(arr, count, sum, index + 1);
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    int myArray[arraySize] = { 0 };

    fillArray(myArray, 0);

    std::cout << "Original Array: ";
    printArray(myArray, 0);

    int count = 0, sum = 0;
    processArray(myArray, count, sum, 0);

    std::cout << "Count of elements satisfying the criteria: " << count << std::endl;
    std::cout << "Sum of elements satisfying the criteria: " << sum << std::endl;
    std::cout << "Modified Array: ";
    printArray(myArray, 0);
    return 0;
}
