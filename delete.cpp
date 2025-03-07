#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    string data;
    Node* next; 

    Node(string value) {
        data = value;
        next = nullptr;
    }
};
Node* deleteNode(Node* head, int position)
{
    Node* prev;
    Node* temp = head;

    if (temp == NULL)
        return head;

    if (position == 1) {
        head = temp->next;
        free(temp);
        return head;
    }

    for (int i = 1; i != position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
    else {
        cout << "Data not present\n";
    }

    return head;
}

void traverseList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";  
        head = head->next;          
    }
    cout << endl;
}

int main() {
    Node* head = new Node("Mehid");
    head->next = new Node("Israfil");
    head->next->next = new Node("Name");
    head->next->next->next = new Node("Faruk");


    cout << "Original list: ";
    traverseList(head);
    cout << endl;

    int position = 3;
    head = deleteNode(head, position);

    cout << "List after deletion : ";
    traverseList(head);
    
    return 0;
}