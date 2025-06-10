#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    
    Node(int data) {
        val = data;
        next = NULL;
    }
};

void insertAtHead(Node* &head,int value) {
    Node* newNode = new Node(value);
    newNode -> next = head;
    head = newNode;
}

void insertAtTail(Node* &head,int val) {

    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return; 
    }

    Node* temp = head;

    while(temp -> next!=NULL){
        temp = temp -> next;
    }

    temp->next = newNode;
}

void insertAtPosition(Node* &head, int val, int pos) {
    if (pos < 0) {
        return;
    }
    
    if (pos == 0) {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    int currPos = 0;
    while (temp != NULL && currPos < pos - 1) {
        temp = temp->next;
        currPos++;
    }

    if (temp == NULL) {
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtHead(Node* &head) {
    if (head == NULL) return;
    Node* temp = head;
    
    head = head->next;
    free(temp);
}

void deleteAtTail(Node* &head) {
    if (head == NULL) return;
    Node* secondLast = head;

    while(secondLast -> next -> next != NULL) {
        secondLast = secondLast -> next;
    }

    Node* temp = secondLast -> next;
    secondLast -> next = NULL;
    free(temp);
}

void deleteAtPos(Node* &head, int pos) {
    if (head == NULL || pos < 0) return;

    if (pos == 0) {
        deleteAtHead(head);
        return;
    }

    Node* prev = head;
    int currPos = 0;
    while (prev != NULL && currPos < pos - 1) {
        prev = prev->next;
        currPos++;
    }

    if (prev == NULL || prev->next == NULL) return;

    Node* temp = prev->next;
    prev->next = temp->next;
    free(temp);
}

void display(Node* head) {
    Node* temp = head;
    while(temp!=NULL){
        cout << temp -> val << " -> ";
        temp = temp -> next;
    }
    cout << "NULL";
}

int main() {
    Node* head = new Node(1);
    insertAtHead(head,2);
    insertAtHead(head,3);

    insertAtTail(head,4);
    insertAtTail(head,5);

    insertAtPosition(head,8,4);

    deleteAtHead(head);
    deleteAtTail(head);
    deleteAtPos(head,2);

    display(head);
    return 0;
}