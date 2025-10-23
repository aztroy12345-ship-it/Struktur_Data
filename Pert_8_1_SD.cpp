#include <iostream>
using namespace std;

#define MAX 5

// Deklarasi Double Ended Queue
class DQueue {
private:
    int front;
    int rear;
    int count;
    int ele[MAX];

public:
    DQueue();
    int isFull();
    int isEmpty();
    void insertDQueueAtRear(int item);
    int deleteDQueueAtFront(int* item);
    void insertDQueueAtFront(int item);
    int deleteDQueueAtRear(int* item);
};

// Inisialisasi Double Ended Queue
DQueue::DQueue() {
    front = 0;
    rear = -1;
    count = 0;
}

// Untuk memeriksa apakah DQueue sudah penuh
int DQueue::isFull() {
    return (count == MAX);
}

// Untuk memeriksa apakah DQueue kosong
int DQueue::isEmpty() {
    return (count == 0);
}

// Masukkan item ke DQueue di bagian belakang
void DQueue::insertDQueueAtRear(int item) {
    if (isFull()) {
        cout << "\nQueue Overflow";
        return;
    }

    rear = (rear + 1) % MAX;
    ele[rear] = item;
    count++;

    cout << "\nDimasukkan di Belakang FRONT : " << front << ", REAR : " << rear;
    cout << "\nItem dimasukkan : " << item << endl;
}

