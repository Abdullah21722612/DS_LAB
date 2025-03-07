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
Node* reverseList(Node* head) {

    Node *curr = head, *prev = nullptr, *next;

    while (curr != nullptr) {
      
        next = curr->next;
      
        curr->next = prev;
      
        prev = curr;
        curr = next;
    }
      
    return prev;
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
    head->next->next = new Node("Abdullah");
    head->next->next->next = new Node("Faruk");


    cout << "Original list: ";
    traverseList(head);
    cout << endl;

    head = reverseList(head);

    cout << "Reversed Linked List: : ";
    traverseList(head);
    
    return 0;
}