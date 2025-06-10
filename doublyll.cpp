#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int data) {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class DoubleLinkedList {
public:
    Node* head;
    Node* tail;

    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertTail(int val){
        Node* newNode=new Node(val);
        if(tail == NULL){
            head= newNode;
            tail = newNode;
            return;
        }
        tail -> next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void posInsert(int val , int pos){
        if(pos==1){
            insertHead(val);
            return;
        }
        Node* temp = head;
        int count = 1;

        while(count < pos-1  &&  temp->next!=NULL){
            temp = temp->next;
            count++;
        }

        if(temp -> next == NULL){
            insertTail(val);
            return;
        }

        Node* newNode = new Node(val);

        newNode -> next = temp->next;
        newNode->prev = temp;

        newNode->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteHead(){
        if(head == NULL){
            return;
        }

        Node* temp = head;
        head = head->next;

        if(head==NULL){
            tail = NULL;
        } else {
            head -> prev = NULL;
        }

        free(temp);
    }

    void deleteTail(){
        if(head == NULL){
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if(tail == NULL){
            head =NULL;
        } else {
            tail->next = NULL;
        }

        free(temp);
    }

    void deletePos(int pos){
        Node* temp = head;
        int count = 1;

        while(temp!=NULL && count<pos){
            temp = temp -> next;
            count++;
        }

        if(temp == NULL){
            return;
        }

        if(temp -> prev != NULL){
            temp->prev->next = temp->next;
        } else {
            head = temp -> next;
        }

        if(temp->next!=NULL){
            temp->next->prev = temp->prev;
        } else {
            tail = temp -> prev;
        }

        free(temp);
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoubleLinkedList dll;
    dll.insertHead(3);
    dll.insertHead(2);
    dll.insertHead(1);
    dll.display(); // Output: 1 <-> 2 <-> 3 <-> NULL
    return 0;
}