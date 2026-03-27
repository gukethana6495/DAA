#include <iostream>
using namespace std;

// Function to find safe position
int josephus(int n, int k) {
    if (n == 1)
        return 0;

    return (josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k;

    cout << "Enter number of people: ";
    cin >> n;

    cout << "Enter step count (k): ";
    cin >> k;

    int safePosition = josephus(n, k) + 1; // +1 for 1-based index

    cout << "Safe Position: " << safePosition << endl;

    return 0;
}