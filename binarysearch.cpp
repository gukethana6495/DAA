#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;   // element found

        else if (arr[mid] < key)
            left = mid + 1;   // search right half

        else
            right = mid - 1;  // search left half
    }

    return -1; // element not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 30;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}