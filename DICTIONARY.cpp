#include <iostream>
#include <string>

using namespace std;

// Node structure for the BST
struct Node {
    string key;
    string meaning;
    Node* left;
    Node* right;

    Node(string k, string m) : key(k), meaning(m), left(nullptr), right(nullptr) {}
};

class Dictionary {
private:
    Node* root;

    // Helper function for finding a node with a specific key
    Node* findNode(Node* current, const string& key) const {
        if (current == nullptr || current->key == key) {
            return current;
        }
        return key < current->key ? findNode(current->left, key) : findNode(current->right, key);
    }

    // Helper function for in-order traversal (ascending order)
    void inorder(Node* current) const {
        if (current != nullptr) {
            inorder(current->left);
            cout << current->key << ": " << current->meaning << endl;
            inorder(current->right);
        }
    }

    // Helper function for reverse in-order traversal (descending order)
    void reverseInorder(Node* current) const {
        if (current != nullptr) {
            reverseInorder(current->right);
            cout << current->key << ": " << current->meaning << endl;
            reverseInorder(current->left);
        }
    }

    // Helper function to insert a new node recursively
    Node* insert(Node* current, const string& key, const string& meaning) {
        if (current == nullptr) {
            return new Node(key, meaning);
        }

        if (key < current->key) {
            current->left = insert(current->left, key, meaning);
        } else if (key > current->key) {
            current->right = insert(current->right, key, meaning);
        } else { // Duplicate key, update the meaning
            current->meaning = meaning;
        }
        return current;
    }

    // Helper function to delete a node recursively
    Node* deleteNode(Node* current, const string& key) {
        if (current == nullptr) {
            return current;
        }

        if (key < current->key) {
            current->left = deleteNode(current->left, key);
        } else if (key > current->key) {
            current->right = deleteNode(current->right, key);
        } else {
            // Node found for deletion
            if (current->left == nullptr && current->right == nullptr) {
                delete current;
                current = nullptr;
            } else if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                current = temp;
            } else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                current = temp;
            } else {
                // Find the inorder successor (leftmost node in the right subtree)
                Node* temp = current->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                current->key = temp->key;
                current->meaning = temp->meaning;
                current->right = deleteNode(current->right, temp->key);
            }
        }
        return current;
    }

public:
    Dictionary() : root(nullptr) {}

    // Add a new keyword-meaning pair
    void Add(const string& key, const string& meaning) {
        root = insert(root, key, meaning);
    }

    // Delete a keyword-meaning pair
    bool Delete(const string& key) {
        root = deleteNode(root, key);
        return root != nullptr; // Return true if deletion successful
    }

    // Update the meaning of a keyword
    bool Update(const string& key, const string& meaning) {
        Node* node = findNode(root, key);
        if (node != nullptr) {
            node->meaning = meaning;
            return true;
        }
        return false; // Keyword not found
    }

    // Search for a keyword and return its meaning (if found)
    string Search(const string& key) const {
        Node* node = findNode(root, key);
                return node != nullptr ? node->meaning : ""; // Return empty string if not found
    }

    // Display all entries in ascending order
    void DisplayAscending() const {
        inorder(root);
    }

    // Display all entries in descending order
    void DisplayDescending() const {
        reverseInorder(root);
    }

    // Maximum comparisons for finding a keyword (height of the BST)
    int MaxComparisons() const {
        return getHeight(root);
    }

private:
    // Helper function to calculate the height of the BST
    int getHeight(Node* current) const {
        if (current == nullptr) {
            return 0;
        }
        int leftHeight = getHeight(current->left);
        int rightHeight = getHeight(current->right);
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    Dictionary dict;

    dict.Add("apple", "a sweet, red fruit");
    dict.Add("banana", "a yellow, curved fruit");
    dict.Add("cat", "a furry, domesticated animal");

    cout << "Dictionary (ascending):\n";
    dict.DisplayAscending();

    cout << "\nSearch for 'cat': " << dict.Search("cat") << endl;

    dict.Update("banana", "a yellow, elongated fruit");

    cout << "\nDictionary after update:\n";
    dict.DisplayAscending();

    dict.Delete("apple");

    cout << "\nDictionary after deletion:\n";
    dict.DisplayAscending();

    cout << "\nMaximum comparisons for search: " << dict.MaxComparisons() << endl;

    return 0;
}

