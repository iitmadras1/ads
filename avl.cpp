#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        height = 1; // New node is initially at height 1
        left = right = nullptr;
    }
};

// Utility function to get the height of a node
int getHeight(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Utility function to calculate the balance factor of a node
int getBalanceFactor(Node* node) {
    return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Function to perform a right rotation
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    // Perform rotation
    x->right = y;
    y->left = T;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // New root
}

// Function to perform a left rotation
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    // Perform rotation
    y->left = x;
    x->right = T;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // New root
}

// Function to insert a node into the AVL Tree
Node* insertNode(Node* root, int value) {
    Node* stack[100]; // Stack for iterative insertion
    int top = -1;

    Node* newNode = new Node(value);

    // Step 1: Perform standard BST insertion
    Node* parent = nullptr;
    Node* current = root;

    while (current != nullptr) {
        parent = current;
        stack[++top] = current; // Push current node onto stack

        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            cout << "Duplicate values are not allowed in AVL Tree.\n";
            return root;
        }
    }

    if (parent == nullptr) {
        return newNode; // Tree was empty
    }

    if (value < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    // Step 2: Update heights and rebalance the tree iteratively
    while (top >= 0) {
        current = stack[top--];

        // Update height
        current->height = max(getHeight(current->left), getHeight(current->right)) + 1;

        // Get balance factor
        int balance = getBalanceFactor(current);

        // Left Left Case
        if (balance > 1 && value < current->left->data) {
            if (top >= 0) {
                if (stack[top]->left == current) {
                    stack[top]->left = rotateRight(current);
                } else {
                    stack[top]->right = rotateRight(current);
                }
            } else {
                root = rotateRight(current);
            }
            break;
        }

        // Right Right Case
        if (balance < -1 && value > current->right->data) {
            if (top >= 0) {
                if (stack[top]->left == current) {
                    stack[top]->left = rotateLeft(current);
                } else {
                    stack[top]->right = rotateLeft(current);
                }
            } else {
                root = rotateLeft(current);
            }
            break;
        }

        // Left Right Case
        if (balance > 1 && value > current->left->data) {
            current->left = rotateLeft(current->left);
            if (top >= 0) {
                if (stack[top]->left == current) {
                    stack[top]->left = rotateRight(current);
                } else {
                    stack[top]->right = rotateRight(current);
                }
            } else {
                root = rotateRight(current);
            }
            break;
        }

        // Right Left Case
        if (balance < -1 && value < current->right->data) {
            current->right = rotateRight(current->right);
            if (top >= 0) {
                if (stack[top]->left == current) {
                    stack[top]->left = rotateLeft(current);
                } else {
                    stack[top]->right = rotateLeft(current);
                }
            } else {
                root = rotateLeft(current);
            }
            break;
        }
    }

    return root;
}

// In-order traversal
void inOrder(Node* root) {
    if (root == nullptr) return;

    Node* stack[100];
    int top = -1;
    Node* current = root;

    while (current != nullptr || top >= 0) {
        while (current != nullptr) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}

int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        cout << "\nAVL Tree Operations:\n";
        cout << "1. Insert a node\n";
        cout << "2. Display In-Order Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insertNode(root, value);
            break;
        case 2:
            cout << "In-Order Traversal: ";
            inOrder(root);
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
