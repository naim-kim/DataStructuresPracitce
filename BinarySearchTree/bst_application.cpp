#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <map>
#include <algorithm>
using namespace std;

// Define a structure for a node in the Binary Search Tree
struct TreeNode {
    string key;             // Key of the node (source word)
    string value;           // Value associated with the key (target word)
    TreeNode* left;         // Pointer to the left child node
    TreeNode* right;        // Pointer to the right child node

    // Constructor to initialize the node with key and value
    TreeNode(string k, string v) {
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
    TreeNode* addRecursive(TreeNode* node, string key, string value) {
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
        // If key already exists, update the value
        else {
            node->value = value;
        }

        return node;
    }

    // Private function to search for a key in the tree and return its value
    string searchRecursive(TreeNode* node, string key) {
        // If node is null, key doesn't exist
        if (node == nullptr) {
            return "";
        }

        // If key is found, return its value
        if (key == node->key) {
            return node->value;
        }
        // If key is less than the current node's key, search left subtree
        else if (key < node->key) {
            return searchRecursive(node->left, key);
        }
        // If key is greater than the current node's key, search right subtree
        else {
            return searchRecursive(node->right, key);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Public function to add a node to the tree
    void add(string key, string value) {
        root = addRecursive(root, key, value);
    }

    // Public function to search for a key in the tree
    string search(string key) {
        return searchRecursive(root, key);
    }
};

// Function to revise text based on the map
void reviseText(const string& textFile, const string& mapFile) {
    BinarySearchTree bst;

    // Read map file and build BST
    ifstream mapFileStream(mapFile);
    if (!mapFileStream.is_open()) {
        cout << "Unable to open map file." << endl;
        return;
    }

    string line;
    while (getline(mapFileStream, line)) {
        istringstream iss(line);
        string source, target;
        if (getline(iss, source, ':') && getline(iss, target)) {
            // Add mappings to the BST
            bst.add(source, target);
        }
    }
    mapFileStream.close();

    // Read and revise text file
    ifstream textFileStream(textFile);
    if (!textFileStream.is_open()) {
        cout << "Unable to open text file." << endl;
        return;
    }

    while (getline(textFileStream, line)) {
        istringstream iss(line);
        string revisedLine;
        string word;
        bool firstWord = true;

        while (iss >> word) {
            // Check if the word is in the BST
            string replacement = bst.search(word);
            if (!replacement.empty()) {
                word = replacement;
            }

            // Append the revised word to the revised line
            if (firstWord) {
                revisedLine += word;
                firstWord = false;
            } else {
                revisedLine += " " + word;
            }
        }

        // Output the revised line
        cout << revisedLine << endl;
    }
    textFileStream.close();
}

// Main function
int main() {
    string textFile, mapFile;

    // Get input file names from the user
    cout << "Enter the text file name: ";
    getline(cin, textFile);
    cout << "Enter the map file name: ";
    getline(cin, mapFile);

    // Revise the text based on the map and print the revised text
    reviseText(textFile, mapFile);

    return 0;
}
