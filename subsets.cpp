#include <iostream>
using namespace std;

int set[10], n, target;

// function to find subsets
void subset(int index, int sum) {
    if (sum == target) {
        cout << "Subset: ";
        for (int i = 0; i < index; i++)
            cout << set[i] << " ";
        cout << endl;
        return;
    }

    if (sum > target)
        return;

    for (int i = index; i < n; i++) {
        swap(set[index], set[i]);          // choose element
        subset(index + 1, sum + set[index]);
        swap(set[index], set[i]);          // backtrack
    }
}

int main() {
    n = 4;
    int arr[] = {1, 2, 3, 4};

    // copy array
    for (int i = 0; i < n; i++)
        set[i] = arr[i];

    target = 5;

    cout << "Subsets with sum " << target << " are:\n";
    subset(0, 0);

    return 0;
}