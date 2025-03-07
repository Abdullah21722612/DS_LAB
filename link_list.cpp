#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    string name;
    node *next;

    node(string name)
    {
        this->name = name;
        this->next = NULL;
    }
};

int main()
{
    node *head = NULL, *newnode, *temp;

    while (1)
    {
        string name;
        cout << "Enter data (type 'exit' to end): ";
        cin >> name;

        if (name == "exit")
        {
            break;
        }

        newnode = new node(name);

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    while (head != NULL)
    {
        cout << head->name << " ";
        head = head->next;
    }
}