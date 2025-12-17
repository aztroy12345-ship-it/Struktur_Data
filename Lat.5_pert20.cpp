#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *front = NULL, *rear = NULL;

void enqueue(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (rear == NULL)
        front = rear = baru;
    else {
        rear->next = baru;
        rear = baru;
    }
}

void dequeue() {
    if (front == NULL) return;
    Node *hapus = front;
    front = front->next;
    delete hapus;
    if (front == NULL) rear = NULL;
}

void tampil() {
    Node *temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    tampil();
    dequeue();
    tampil();
    return 0;
}

