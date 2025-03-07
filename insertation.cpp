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

void traverseList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";  
        head = head->next;          
    }
    cout << endl;
}

void insertAfterAbdullah(Node* head, string newName) {
    Node* temp = head;


    while (temp != nullptr) {
        if (temp->data == "Name") { 
            Node* newNode = new Node(newName);
            newNode->next = temp->next;  
            temp->next = newNode;       
            return;
        }
        temp = temp->next;
    }
}

int main() {
    Node* head = new Node("Mehid");
    head->next = new Node("Israfil");
    head->next->next = new Node("Name");
    head->next->next->next = new Node("Faruk");


    cout << "Before insertion: ";
    traverseList(head);
    cout << endl;

    insertAfterAbdullah(head, "Abdullah");

    cout << "After insertion: ";
    traverseList(head);

    return 0;
}