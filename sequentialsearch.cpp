#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int key, i;
    int n = 5;
    bool found = false;

    cout << "Enter element to search: ";
    cin >> key;

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            found = true;
            break;
        }
    }

    if(found)
        cout << "Element found at position " << i + 1;
    else
        cout << "Element not found";

    return 0;
}