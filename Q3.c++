#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str) {
    int left = 0, right = str.length() - 1;

    while (left < right) {
        // Skip spaces on the left and right
        if (str[left] == ' ') {
            left++;
            continue;
        }
        if (str[right] == ' ') {
            right--;
            continue;
        }

        // Compare characters while ignoring case sensitivity
        if (str[left] != str[right] && (str[left] + 32 != str[right] && str[left] - 32 != str[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    string userInput;
    cout << "Enter a string: ";
    getline(cin, userInput);
    
    if (isPalindrome(userInput)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    
    return 0;
}
#include<iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of matrix: ";
    cin >> size;
    
    int matrix[50][50];
    cout << "Enter the elements of matrix: ";
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            cin >> matrix[row][col];
        }
    }

    int top = 0, bottom = size - 1, left = 0, right = size - 1;

    while (top <= bottom && left <= right) {
        // Print top row
        for (int col = left; col <= right; col++) {
            cout << matrix[top][col] << " ";
        }
        top++;

        // Print right column
        for (int row = top; row <= bottom; row++) {
            cout << matrix[row][right] << " ";
        }
        right--;

        // Print bottom row
        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                cout << matrix[bottom][col] << " ";
            }
            bottom--;
        }

        // Print left column
        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                cout << matrix[row][left] << " ";
            }
            left++;
        }
    }

    return 0;
}