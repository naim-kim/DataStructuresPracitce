#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
    int key;
    string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int k, string v) {
        key = k;
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* addRecursive(TreeNode* node, int key, string value) {
        if (node == nullptr) {
            return new TreeNode(key, value);
        }

        if (key < node->key) {
            node->left = addRecursive(node->left, key, value);
        } else if (key > node->key) {
            node->right = addRecursive(node->right, key, value);
        } else {
            cout << key << " is already in the tree" << endl;
        }

        return node;
    }

    TreeNode* deleteRecursive(TreeNode* node, int key) {
        if (node == nullptr) {
            cout << key << " is not in the tree" << endl;
            return nullptr;
        }

        if (key < node->key) {
            node->left = deleteRecursive(node->left, key);
        } else if (key > node->key) {
            node->right = deleteRecursive(node->right, key);
        } else {
            if (node->left == nullptr) {
                TreeNode* rightChild = node->right;
                delete node;
                return rightChild;
            } else if (node->right == nullptr) {
                TreeNode* leftChild = node->left;
                delete node; 
                return leftChild;
            }

            TreeNode* minR = findMin(node->right);
            node->key = minR->key;
            node->value = minR->value;
            node->right = deleteRecursive(node->right, minR->key);
        }
        return node;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void printInorderRecursive(TreeNode* node) {
        if (node != nullptr) {
            printInorderRecursive(node->left);
            cout << "(" << node->key << ", " << node->value << ")" << endl;
            printInorderRecursive(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void add(int key, string value) {
        root = addRecursive(root, key, value);
    }

    void remove(int key) {
        root = deleteRecursive(root, key);
    }

    void printInorder() {
        printInorderRecursive(root);
    }
};

void run_bst() {
    BinarySearchTree bst;
    cout << "Welcome to Binary Search Tree program!" << endl;
    cout << "Commands:" << endl;
    cout << "  a key value : Add a node with key and value" << endl;
    cout << "  d key       : Delete the node with key" << endl;
    cout << "  p           : Print the nodes in inorder traversal" << endl;
    cout << "  q           : Quit the program" << endl;
    cout << "Enter your commands:\n";

    while (true) {
        char command;
        string line;
        int key;
        string value;

        // Get input
        getline(cin, line);
        istringstream iss(line);

        iss >> command;

        if (command != 'a' && command != 'd' && command != 'p' && command != 'q') {
            cout << "Invalid command.." << endl;
            continue;
        }

        if (command == 'q') {
            break;
        } else if (command == 'a') {
            if (!(iss >> key)) {
                cout << "Invalid key. :(" << endl;
                continue;
            }
            iss >> value;
            bst.add(key, value);
        } else if (command == 'd') {
            if (!(iss >> key)) {
                cout << "Invalid key. :(" << endl;
                continue;
            }
            bst.remove(key);
        } else if (command == 'p') {
            bst.printInorder();
        }
    }
}

int main() {
    run_bst();
    return 0;
}