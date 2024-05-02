#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        left=right=nullptr;
    }
};

class BST{
    private:
    Node *root;
    Node* insert(Node *n, int data){
        if(n==nullptr) return new Node(data);
        else if(data<n->data){
            n->left=  insert(n->left, data);
        }
        else if(data>n->data){
            n->right= insert(n->right,data);
        }
        return n;

    }

    int findLongestPath(Node *n){
        if(n==nullptr) return 0;

        int leftH = findLongestPath(n->left);
        int rightH = findLongestPath(n->right);

        return max(leftH,rightH)+1;
    }
    void mirror(Node *n){
        if(n==nullptr){
            return;
        }
        swap(n->left,n->right);
        mirror(n->left);
        mirror(n->right);
    }
    bool search(Node *n,int data){
        Node *current = n;
        while(current!=nullptr){
            if(current->data==data) return 1;
            if(data < current->data){
                current = current->left;
            }
            else if(data > current->data){
                current = current->right;
            }
        }
        return false;
    }

    public:
    BST(){
        root = nullptr;
    }
    void insert(int data){
        root = insert(root,data);
    }
    int findLongestPath(){
        return findLongestPath(root);
    }
    int findMin(){
        if(root==nullptr){
            cout<<"\nTree is empty\n";
            return -1;
        }

        Node *current = root;
        while(current->left != nullptr){
            current = current->left;
        }
        return current->data;
    }
    void mirror(){
        mirror(root);
    }
    void search(int data){
        cout<<data<<" is  "<<(search(root,data)? "Found" : "Not Found");
    }
};

int main(){
    BST bst;
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
    bst.search(70);


    return 0;
    
}