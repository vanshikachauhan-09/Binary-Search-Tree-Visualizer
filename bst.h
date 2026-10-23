#ifndef BST_H
#define BST_H

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;
    Node* insertNode(Node* node, int x, bool& done);
    Node* removeNode(Node* node, int x, bool& done);
    void clear(Node* node);
    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);
    void show(Node* node, int space);

public:
    BST();
    ~BST();
    bool insert(int x);
    bool remove(int x);
    bool search(int x);
    void inorder();
    void preorder();
    void postorder();
    void display();
};

#endif
