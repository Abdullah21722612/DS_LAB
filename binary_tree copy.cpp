#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

node *build(node *root)
{
    int numbers[] = {50, 25, 19, 8, 43, 41, 45, 70, 91, 80, 75, 120, 110, 125, 140};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < n; i++)
    {
        root = insert(root, numbers[i]);
    }

    return root;
}

node *inorder(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

    return root;
}

bool searchNode(node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == key)
    {
        return true;
    }

    if (key < root->data)
    {
        return searchNode(root->left, key);
    }
    else
    {
        return searchNode(root->right, key);
    }
}

int main()
{
    node *root = NULL;

    root = build(root);

    cout << "In-order traversal of the BST: ";
    inorder(root);
    cout << endl
         << endl;

    int search = 8;
    cout << "Enter the value to search: \n";

    if (searchNode(root, search))
    {
        cout << "Value " << search << " found in the tree." << endl;
    }
    else
    {
        cout << "Value " << search << " not found in the tree." << endl;
    }

    return 0;
}