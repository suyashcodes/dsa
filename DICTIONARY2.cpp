#include <iostream>
#include <string>

struct Node {
    std::string key;
    std::string mean;
    Node* left;
    Node* right;
    Node(std::string k, std::string m): key(k), mean(m), left(nullptr), right(nullptr) {}
};

class Dictionary {
private:
    Node* root;

    Node* insert(Node* current, std::string k, std::string m) {
        if (current == nullptr) {
            return new Node(k, m);
        } else if (k < current->key) {
            current->left = insert(current->left, k, m);
        } else if (k > current->key) {
            current->right = insert(current->right, k, m);
        } else {
            current->mean = m;
        }
        return current;
    }

    Node* deleteN(Node* current, const std::string& key) {
        if (current == nullptr) {
            return current;
        } else if (key < current->key) {
            current->left = deleteN(current->left, key);
        } else if (key > current->key) {
            current->right = deleteN(current->right, key);
        } else {
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
                Node* temp = current->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                current->key = temp->key;
                current->mean = temp->mean;
                current->right = deleteN(current->right, temp->key);
            }
        }
        return current;
    }

    Node* findNode(Node* current, std::string key) {
        if (current == nullptr) {
            return nullptr;
        } else if (current->key == key) {
            return current;
        } else {
            return key < current->key ? findNode(current->left, key) : findNode(current->right, key);
        }
    }

    void inorder(Node* current) {
        if (current != nullptr) {
            inorder(current->left);
            std::cout << "Key : " << current->key << " Meaning : " << current->mean << std::endl;
            inorder(current->right);
        }
    }

    void reverseinorder(Node* current) {
        if (current != nullptr) {
            reverseinorder(current->right);
            std::cout << "Key : " << current->key << " Meaning : " << current->mean << std::endl;
            reverseinorder(current->left);
        }
    }

    int getHeight(Node* current) {
        if (current == nullptr) return 0;
        int lefth = getHeight(current->left);
        int righth = getHeight(current->right);

        return std::max(lefth, righth) + 1;
    }

public:
    Dictionary() : root(nullptr) {}

    std::string search(std::string key) {
        Node* node = findNode(root, key);
        return node != nullptr ? node->mean : "Not Found";
    }

    void insert(std::string k, std::string m) {
        root = insert(root, k, m);
    }

    void deleteN(std::string k) {
        root = deleteN(root, k);
    }

    bool update(std::string key, std::string mean) {
        Node* temp = findNode(root, key);
        if (temp != nullptr) {
            temp->mean = mean;
            return true;
        }
        return false;
    }

    void displayAscending() {
        inorder(root);
    }

    void displayDescending() {
        reverseinorder(root);
    }

    int maxComparisons() {
        return getHeight(root);
    }

    ~Dictionary() {
        // Implement destructor to deallocate memory
        destroyTree(root);
    }

private:
    void destroyTree(Node* current) {
        if (current != nullptr) {
            destroyTree(current->left);
            destroyTree(current->right);
            delete current;
        }
    }
};

int main() {
    Dictionary dict;
    dict.insert("apple", "a apple");
    dict.insert("banana", "a banana");
    dict.insert("cat", "a cat");

    std::cout << "Dictionary (ascending):\n";
    dict.displayAscending();

    std::cout << "\nSearch for 'cat': " << dict.search("cat") << std::endl;

    dict.update("banana", "a yellow, elongated fruit");

    std::cout << "\nDictionary after update:\n";
    dict.displayAscending();

    dict.deleteN("apple");

    std::cout << "\nDictionary after deletion:\n";
    dict.displayAscending();

    std::cout << "\nMaximum comparisons for search: " << dict.maxComparisons() << std::endl;

    return 0;
}
