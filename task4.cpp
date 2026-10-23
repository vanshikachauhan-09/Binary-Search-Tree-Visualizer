#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* root = NULL;

Node* insertNode(Node* node, int x, bool& done) {
    if (node == NULL) {
        Node* n = new Node;
        n->data = x;
        n->left = NULL;
        n->right = NULL;
        done = true;
        return n;
    }
    if (x < node->data)
        node->left = insertNode(node->left, x, done);
    else if (x > node->data)
        node->right = insertNode(node->right, x, done);
    return node;
}

Node* deleteNode(Node* node, int x, bool& done) {
    if (node == NULL) return NULL;
    if (x < node->data) {
        node->left = deleteNode(node->left, x, done);
    } else if (x > node->data) {
        node->right = deleteNode(node->right, x, done);
    } else {
        done = true;
        if (node->left == NULL) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        if (node->right == NULL) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* next = node->right;
        while (next->left != NULL) next = next->left;
        node->data = next->data;
        bool ignore = false;
        node->right = deleteNode(node->right, next->data, ignore);
    }
    return node;
}

void searchNode(int x) {
    Node* cur = root;
    cout << "Path: ";
    while (cur != NULL) {
        cout << cur->data << " ";
        if (x == cur->data) {
            cout << "-> found\n";
            return;
        }
        if (x < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    cout << "-> not found\n";
}

void inorder(Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void preorder(Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

void show(Node* node, int space) {
    if (node == NULL) return;
    space += 6;
    show(node->right, space);
    cout << string(space - 6, ' ') << node->data << "\n";
    show(node->left, space);
}

void display() {
    cout << "\nTree (right on top, left at bottom):\n";
    if (root == NULL) cout << "(empty tree)\n";
    show(root, 0);
    cout << "\n";
}

void clearTree(Node* node) {
    if (node == NULL) return;
    clearTree(node->left);
    clearTree(node->right);
    delete node;
}

int main() {
    int choice = -1;
    int x;
    bool done;

    while (choice != 0) {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Inorder\n5. Preorder\n6. Postorder\n7. Display\n0. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) break;

        if (choice >= 1 && choice <= 3) {
            cout << "Enter value: ";
            if (!(cin >> x)) break;
        }

        if (choice == 1) {
            done = false;
            root = insertNode(root, x, done);
            if (done) cout << x << " inserted\n";
            else cout << x << " already exists\n";
            display();
        } else if (choice == 2) {
            done = false;
            root = deleteNode(root, x, done);
            if (done) cout << x << " deleted\n";
            else cout << x << " not found\n";
            display();
        } else if (choice == 3) {
            searchNode(x);
        } else if (choice == 4) {
            cout << "Inorder: ";
            inorder(root);
            cout << "\n";
        } else if (choice == 5) {
            cout << "Preorder: ";
            preorder(root);
            cout << "\n";
        } else if (choice == 6) {
            cout << "Postorder: ";
            postorder(root);
            cout << "\n";
        } else if (choice == 7) {
            display();
        } else if (choice != 0) {
            cout << "Invalid choice\n";
        }
    }

    clearTree(root);
    cout << "Goodbye\n";
    return 0;
}