#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool rightThread;

    Node(int val) : data(val), left(nullptr), right(nullptr), rightThread(false) {}
};

class ThreadedBinaryTree {
private:
    Node* root;

public:
    ThreadedBinaryTree() : root(nullptr) {}

    // Function to insert a value into the threaded binary tree
    void insert(int val) {
        Node* newNode = new Node(val);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* curr = root;
        Node* parent = nullptr;
        while (curr != nullptr) {
            if (val < curr->data) {
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    newNode->right = curr;
                    newNode->rightThread = true;
                    return;
                }
                curr = curr->left;
            } else {
                if (!curr->rightThread || curr->right == nullptr) {
                    newNode->right = curr->right;
                    curr->right = newNode;
                    curr->rightThread = true;
                    newNode->rightThread = false;  // Corrected this line
                    return;
                }
                curr = curr->right;
            }
        }
         parent->right = newNode;
    newNode->right = nullptr;
    newNode->rightThread = false;
    }

    // Function to search for a value in the threaded binary tree
    Node* search(int val) {
        Node* curr = root;
        while (curr != nullptr) {
            if (val == curr->data) return curr;
            else if (val < curr->data) curr = curr->left;
            else if (curr->rightThread) return curr->right;  // Corrected this line
            else curr = curr->right;
        }
        return nullptr;
    }

    // Function to perform inorder traversal of the threaded binary tree
    void inorderTraversal() {
        Node* curr = root;
        while (curr != nullptr) {
            while (curr->left != nullptr)
                curr = curr->left;
            cout << curr->data << " ";

            while (curr->rightThread) {
                curr = curr->right;
                if (curr == nullptr) return;
                cout << curr->data << " ";
            }
            curr = curr->right;
        }
    }
};

int main() {
    cout<<"Hello";
    ThreadedBinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(17);

    cout << "Inorder traversal: ";
    tree.inorderTraversal();
    cout << endl;

    int searchValue = 7;
    Node* result = tree.search(searchValue);
    if (result != nullptr)
        cout << "Found " << searchValue << " in the tree." << endl;
    else
        cout << searchValue << " not found in the tree." << endl;

    return 0;
}
