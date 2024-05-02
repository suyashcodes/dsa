#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    // Helper functions for insertion and finding longest path
    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        return node;
    }

    int findLongestPath(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = findLongestPath(node->left);
        int rightHeight = findLongestPath(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

public:
    BST() {
        root = nullptr;
    }

    // Functionalities you requested
    void insert(int data) {
        root = insert(root, data);
    }

    int findLongestPath() {
        return findLongestPath(root);
    }

    int findMin() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return -1; // Or throw an exception
        }

        Node* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current->data;
    }

    void mirror() {
        mirror(root);
    }

    void mirror(Node* node) {
        if (node == nullptr) {
            return;
        }

        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }

    bool search(int data) {
        Node* current = root;
        while (current != nullptr) {
            if (data == current->data) {
                return true;
            } else if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }
};

int main() {
    BST bst;

    // Example usage
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Longest path: " << bst.findLongestPath() << endl;
    cout << "Minimum value: " << bst.findMin() << endl;

    // Mirror the tree
    bst.mirror();
    cout << "Search for 70: " << (bst.search(70) ? "Found" : "Not found") << endl;


    return 0;
}
