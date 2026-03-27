#include <iostream>
using namespace std;

#define MAX 100

class MaxHeap {
    int arr[MAX];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    // Insert element
    void insert(int val) {
        if (size == MAX) {
            cout << "Heap is full\n";
            return;
        }

        int i = size;
        arr[i] = val;
        size++;

        // Heapify up
        while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Delete root (maximum)
    void deleteMax() {
        if (size <= 0) {
            cout << "Heap is empty\n";
            return;
        }

        arr[0] = arr[size - 1];
        size--;

        heapify(0);
    }

    // Heapify (top-down)
    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
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
    MaxHeap h;

    h.insert(10);
    h.insert(40);
    h.insert(15);
    h.insert(30);

    cout << "Heap elements: ";
    h.display();

    h.deleteMax();

    cout << "After deleting max: ";
    h.display();

    return 0;
}