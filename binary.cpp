#include <iostream>
using namespace std;

class BinaryHeap {
    int *arr;
    int capacity;
    int size;

public:
    BinaryHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[cap];
    }

    // Insert element
    void insert(int val) {
        if (size == capacity) {
            cout << "Heap Overflow\n";
            return;
        }

        int i = size++;
        arr[i] = val;

        // Heapify up
        while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Heapify down
    void heapify(int i) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && arr[left] < arr[smallest])
            smallest = left;

        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    // Delete minimum element
    void deleteMin() {
        if (size <= 0) {
            cout << "Heap Underflow\n";
            return;
        }

        arr[0] = arr[size - 1];
        size--;
        heapify(0);
    }

    // Display heap
    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    BinaryHeap h(10);

    h.insert(15);
    h.insert(10);
    h.insert(20);
    h.insert(5);

    cout << "Heap elements: ";
    h.display();

    h.deleteMin();

    cout << "After deletion: ";
    h.display();

    return 0;
}