#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node structure
struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = NULL;
    }
};

// Comparator for priority queue (min-heap)
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print Huffman codes
void printCodes(Node* root, string str) {
    if (!root)
        return;

    // Leaf node
    if (root->data != '$')
        cout << root->data << ": " << str << endl;

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Main Huffman function
void huffmanCoding(vector<char> data, vector<int> freq) {
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create leaf nodes
    for (int i = 0; i < data.size(); i++) {
        pq.push(new Node(data[i], freq[i]));
    }

    // Build tree
    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Print codes
    printCodes(pq.top(), "");
}

// Main function
int main() {
    vector<char> data = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    huffmanCoding(data, freq);

    return 0;
}