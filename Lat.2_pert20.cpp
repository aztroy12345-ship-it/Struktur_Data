#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insert(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;

    if (head == NULL) {
        head = baru;
        head->next = head;
    } else {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = baru;
        baru->next = head;
    }
}

void hapus() {
    if (head == NULL) return;

    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        Node *hapus = head;
        temp->next = head->next;
        head = head->next;
        delete hapus;
    }
}

void traverse() {
    if (head == NULL) return;
    Node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    traverse();
    hapus();
    traverse();
    return 0;
}

