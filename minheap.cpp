#include <iostream>
using namespace std;

#define MAX 100

class MinHeap {
    int arr[MAX];
    int size;

public:
    MinHeap() {
        size = 0;
    }

    // Insert element
    void insert(int val) {
        if (size == MAX) {
            cout << "Heap is full\n";
            return;
        }

        // Insert at end
        int i = size;
        arr[i] = val;
        size++;

        // Heapify up
        while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Delete root (minimum)
    void deleteMin() {
        if (size <= 0) {
            cout << "Heap is empty\n";
            return;
        }

        // Replace root with last element
        arr[0] = arr[size - 1];
        size--;

        heapify(0);
    }

    // Heapify (top-down)
    void heapify(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] < arr[smallest])
            smallest = left;

        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    // Display heap
    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;

    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(2);

    cout << "Heap elements: ";
    h.display();

    h.deleteMin();

    cout << "After deleting min: ";
    h.display();

    return 0;
}