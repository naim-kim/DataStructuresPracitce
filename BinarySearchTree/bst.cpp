#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Define a structure for a node in the Binary Search Tree
struct TreeNode {
    int key;                // Key of the node
    string value;           // Value associated with the key
    TreeNode* left;         // Pointer to the left child node
    TreeNode* right;        // Pointer to the right child node

    // Constructor to initialize the node with key and value
    TreeNode(int k, string v) {
        key = k;
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

// Define a class for Binary Search Tree operations
class BinarySearchTree {
private:
    TreeNode* root;         // Pointer to the root node of the tree

    // Private recursive function to add a node to the tree
    TreeNode* addRecursive(TreeNode* node, int key, string value) {
        // If the current node is null, create a new node
        if (node == nullptr) {
            return new TreeNode(key, value);
        }

        // If key is less than the current node's key, go left
        if (key < node->key) {
            node->left = addRecursive(node->left, key, value);
        } 
        // If key is greater than the current node's key, go right
        else if (key > node->key) {
            node->right = addRecursive(node->right, key, value);
        } 
        // If key already exists, print a message
        else {
            cout << key << " is already in the tree" << endl;
        }

        return node;
    }

    // Private recursive function to delete a node from the tree
    TreeNode* deleteRecursive(TreeNode* node, int key) {
        // If node is null, key doesn't exist
        if (node == nullptr) {
            cout << key << " is not in the tree" << endl;
            return nullptr;
        }

        // If key is less than the current node's key, go left
        if (key < node->key) {
            node->left = deleteRecursive(node->left, key);
        } 
        // If key is greater than the current node's key, go right
        else if (key > node->key) {
            node->right = deleteRecursive(node->right, key);
        } 
        // If key is found, delete the node
        else {
            // If the node has only one child or no child
            if (node->left == nullptr) {
                TreeNode* rightChild = node->right;
                delete node;
                return rightChild;
            } else if (node->right == nullptr) {
                TreeNode* leftChild = node->left;
                delete node; 
                return leftChild;
            }
            // If the node has two children, replace it with the smallest node in the right subtree
            TreeNode* minR = findMin(node->right);
            node->key = minR->key;
            node->value = minR->value;
            node->right = deleteRecursive(node->right, minR->key);
        }
        return node;
    }

    // Private function to find the smallest node in a subtree
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Private recursive function to print the nodes in inorder traversal
    void printInorderRecursive(TreeNode* node) {
        if (node != nullptr) {
            printInorderRecursive(node->left);
            cout << "(" << node->key << ", " << node->value << ")" << endl;
            printInorderRecursive(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Public function to add a node to the tree
    void add(int key, string value) {
        root = addRecursive(root, key, value);
    }

    // Public function to remove a node from the tree
    void remove(int key) {
        root = deleteRecursive(root, key);
    }

    // Public function to print the nodes in inorder traversal
    void printInorder() {
        printInorderRecursive(root);
    }
};

// Function to run the Binary Search Tree program
void run_bst() {
    BinarySearchTree bst;
    cout << "Welcome to Binary Search Tree program!" << endl;
    cout << "Commands:" << endl;
    cout << "  a key value : Add a node with key and value" << endl;
    cout << "  d key       : Delete the node with key" << endl;
    cout << "  p           : Print the nodes in inorder traversal" << endl;
    cout << "  q           : Quit the program" << endl;
    cout << "Enter your commands:\n";

    // Infinite loop to accept user commands
    while (true) {
        char command;
        string line;
        int key;
        string value;

        // Get input
        getline(cin, line);
        istringstream iss(line);

        iss >> command;

        // Check for valid command
        if (command != 'a' && command != 'd' && command != 'p' && command != 'q') {
            cout << "Invalid command.." << endl;
            continue;
        }

        // Process the command
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

// Main function
int main() {
    run_bst();  // Run the Binary Search Tree program
    return 0;
}
