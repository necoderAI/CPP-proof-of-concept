#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Node {
    int key;
    int value;
    Node* left;
    Node* right;
};

class SortedHashTree {
public:
    SortedHashTree() {
        root = nullptr;
    }

    void insert(int key, int value) {
        root = insertRecursive(root, key, value);
        hashTable[key] = value;
    }

    int search(int key) {
        auto it = hashTable.find(key);
        if (it != hashTable.end()) {
            return it->second;
        }
        return -1;
    }

    void printInOrder() {
        inOrderTraversal(root);
    }

private:
    Node* root;
    std::unordered_map<int, int> hashTable;

    Node* insertRecursive(Node* current, int key, int value) {
        if (current == nullptr) {
            Node* newNode = new Node;
            newNode->key = key;
            newNode->value = value;
            newNode->left = newNode->right = nullptr;
            return newNode;
        }

        if (key < current->key) {
            current->left = insertRecursive(current->left, key, value);
        } else if (key > current->key) {
            current->right = insertRecursive(current->right, key, value);
        }

        return current;
    }

    void inOrderTraversal(Node* current) {
        if (current != nullptr) {
            inOrderTraversal(current->left);
            std::cout << "Key: " << current->key << ", Value: " << current->value << std::endl;
            inOrderTraversal(current->right);
        }
    }
};

int main() {
    SortedHashTree tree;

    tree.insert(5, 50);
    tree.insert(3, 30);
    tree.insert(7, 70);
    tree.insert(1, 10);
    tree.insert(9, 90);

    std::cout << "In-order traversal of Sorted Hash Tree:" << std::endl;
    tree.printInOrder();

    std::cout << "Searching for key 7: " << tree.search(7) << std::endl;
    std::cout << "Searching for key 4: " << tree.search(4) << std::endl;

    return 0;
}
