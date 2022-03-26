#include<iostream>
#include<bits/stdc++.h>

using namespace std;



struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* CreateNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
/* Function to insert element in binary tree */
 
Node* InsertNode(Node* root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }
 
    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
}
 
/* Inorder traversal of a binary tree */
 
void inorder(Node* temp)
{
    if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}

/* Preorder traversal of a binary tree */
 
void preorder(Node* temp)
{
    if (temp == NULL)
        return;
    cout << temp->data << ' ';
    preorder(temp->left);
    preorder(temp->right);
}

/* Postorder traversal of a binary tree */
 
void postorder(Node* temp)
{
    if (temp == NULL)
        return;
    
    preorder(temp->left);
    preorder(temp->right);
    cout << temp->data << ' ';
}

/* Levelorder traversal of a binary tree */
 
void levelorder(Node* temp)
{
    if (temp == NULL)
        return;
    cout << temp->data << ' ';
    preorder(temp->left);
    cout << temp->data << ' ';
    preorder(temp->right);
   
}

// Driver code
int main()
{
    Node* root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);
 
    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;
    cout << "Preorder traversal before insertion: ";
    preorder(root);
    cout << endl;
    cout << "postorder traversal before insertion: ";
    postorder(root);
    cout << endl;
    cout << "level order traversal before insertion: ";
    levelorder(root);
    cout << endl;
    return 0;
}