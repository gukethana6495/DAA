#include <iostream>
using namespace std;

struct Node {
    int a, b;
    int count;
};

int main() {
    Node n;

    // inserting values
    n.a = 10;
    n.count = 1;

    n.b = 20;
    n.count = 2;

    // display
    cout << "2-3 Tree Node values: ";
    if (n.count >= 1) cout << n.a << " ";
    if (n.count == 2) cout << n.b;

    return 0;
}