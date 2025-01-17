#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void travellinked(Node* head){
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data<<' ';
        current = current->next;
    }
    cout << '\n';
}

Node* insertend(Node* head, int in){
    Node *current = head;
    Node *newNode = new Node(in);
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

Node* insertfront(Node* head, int in){
    Node *newNode = new Node(in);
    newNode->next = head;
    return newNode;
}

void* deleteall(Node *head){
    Node *currnode = head;
    Node *nextnode = head;
    while (currnode != nullptr)
    {
        nextnode = currnode->next;
        delete currnode;
        currnode = nextnode;
    }
    return;
}

Node* insertat(Node* head, int in, int pos) {
    if (pos == 0) {
        return insertfront(head, in);
    }

    Node* current = head;
    for (int i = 0; i < pos - 1 && current != nullptr; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        return head; // Position is out of bounds
    }

    Node* newNode = new Node(in);
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

Node* deleteNode(Node* head, int key) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != key) {
        current = current->next;
    }

    if (current->next == nullptr) {
        return head; // Key not found
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return head;
}