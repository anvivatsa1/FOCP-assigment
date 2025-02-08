//write a program that performs the following operations on an array
//Accept an integer array of user-defined size.
//Reverse and display the array.
//Find and display the second largest and second smallest elements.
#include <iostream>
using namespace std;

void acceptArray(int arr[], int size) {
    cout << "Please enter " << size << " numbers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void reverseArray(int arr[], int size) {
    cout << "The reversed array is: ";
    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void findSecondLargestAndSmallest(int arr[], int size) {
    int smallest = INT_MAX, secondSmallest = INT_MAX;
    int largest = INT_MIN, secondLargest = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }

        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    cout << "The second smallest number is: " << secondSmallest << endl;
    cout << "The second largest number is: " << secondLargest << endl;
}

int main() {
    int size;
    cout << "How many numbers will you enter? ";
    cin >> size;

    int arr[size];
    acceptArray(arr, size);
    reverseArray(arr, size);
    findSecondLargestAndSmallest(arr, size);

    return 0;
}