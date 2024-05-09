#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void insert(TreeNode *&root, int val)
{
    if (root == nullptr)
    {
        root = new TreeNode(val);
        return;
    }

    if (val < root->data)
    {
        insert(root->left, val);
    }
    else
    {
        insert(root->right, val);
    }
}

int longestPath(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int leftDepth = longestPath(root->left);
    int rightDepth = longestPath(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

int minValue(TreeNode *root)
{
    if (root == nullptr)
    {
        cerr << "Tree is empty!" << endl;
        exit(EXIT_FAILURE);
    }

    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root->data;
}

void swapChildren(TreeNode *root)
{
    if (root == nullptr)
        return;

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    swapChildren(root->left);
    swapChildren(root->right);
}

bool search(TreeNode *root, int val)
{
    if (root == nullptr)
        return false;

    if (root->data == val)
        return true;

    if (val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}

void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void deleteTree(TreeNode *&root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}

int main()
{
    TreeNode *root = nullptr;

    int values[] = {5, 3, 7, 2, 4, 6, 8};
    int numValues = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < numValues; ++i)
    {
        insert(root, values[i]);
    }

    cout << "BST (Inorder Traversal): ";
    inorderTraversal(root);
    cout << endl;

    insert(root, 9);
    cout << "BST after inserting 9 (Inorder Traversal): ";
    inorderTraversal(root);
    cout << endl;

    cout << "Number of nodes in the longest path from root: " << longestPath(root) << endl;

    cout << "Minimum value in the BST: " << minValue(root) << endl;

    swapChildren(root);
    cout << "BST after swapping left and right pointers (Mirror - Inorder Traversal): ";
    inorderTraversal(root);
    cout << endl;

    int searchValue = 6;
    if (search(root, searchValue))
    {
        cout << searchValue << " is found in the BST." << endl;
    }
    else
    {
        cout << searchValue << " is not found in the BST." << endl;
    }

    deleteTree(root);

    return 0;
}