#include <iostream>
using namespace std;

// Function to find fake coin index
int findFake(int arr[], int left, int right) {
    // Base case: only one coin
    if (left == right)
        return left;

    int mid = (left + right) / 2;

    int sumLeft = 0, sumRight = 0;

    // Calculate sum of left half
    for (int i = left; i <= mid; i++)
        sumLeft += arr[i];

    // Calculate sum of right half
    for (int i = mid + 1; i <= right; i++)
        sumRight += arr[i];

    // Compare sums
    if (sumLeft < sumRight)
        return findFake(arr, left, mid);     // fake in left
    else
        return findFake(arr, mid + 1, right); // fake in right
}

int main() {
    int coins[] = {10, 10, 10, 9, 10, 10}; // 9 is fake (lighter)
    int n = sizeof(coins) / sizeof(coins[0]);

    int index = findFake(coins, 0, n - 1);

    cout << "Fake coin found at index: " << index << endl;
    cout << "Fake coin value: " << coins[index];

    return 0;
}