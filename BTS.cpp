#include <iostream>

using namespace std;

class node
{
public:
    int value;
    node *left;
    node *right;

    node(int val)
    {
        this->value = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void insert_node(node *&root, int v)
{
    node *new_node = new node(v);

    if(root == NULL)
    {
        root = new_node;
        return;
    }

    if (v > root->value)
    {
        insert_node(root ->left,v);
    }
    else
    {
        insert_node(root ->right,v);
    }
    
}

node *search_node(node *root,int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    
    if(root ->value == key)
    {
        return root;
    }
    else if(root ->value > key)
    {
        return search_node(root->left, key);
    }
    else
    {
        return search_node(root->right, key);
    }
}

int main()
{
    node *root = NULL;
    int x;

    cout << "Tree value: ";
    while (true)
    {

        cin >> x;

        if (x == -1)
        {
            break;
        }
        insert_node(root, x);
    }

    int key;
    cout << "search value: ";
    cin >> x;

    if(search_node(root, key) != 0)
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found!";
    }
}
