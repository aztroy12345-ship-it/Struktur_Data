#include <iostream>

#define MAX 5

using namespace std;

// Deklarasi Circular Queue
class CirQueue
{
private:
    int front;
    int rear;
    int count;
    int ele[MAX];

public:
    CirQueue();
    bool isFull() const;
    bool isEmpty() const;
    bool insertQueue(int item);     // mengembalikan true jika sukses
    bool deleteQueue(int *item);    // mengembalikan true jika sukses
};

// Inisialisasi Circular Queue
CirQueue::CirQueue()
{
    front = 0;
    rear = -1;
    count = 0;
}

// Untuk mengecek queue sudah penuh atau belum
bool CirQueue::isFull() const
{
    return (count == MAX);
}

// Untuk memeriksa antrian kosong atau tidak
bool CirQueue::isEmpty() const
{
    return (count == 0);
}

// Sisipkan item ke dalam antrian melingkar
bool CirQueue::insertQueue(int item)
{
    if (isFull())
    {
        cout << "\nQueue Overflow";
        return false;
    }

    rear = (rear + 1) % MAX;
    ele[rear] = item;
    count++;

    cout << "\ndimasukkan item : " << item;
    return true;
}

// Hapus item dari circular queue
bool CirQueue::deleteQueue(int *item)
{
    if (isEmpty())
    {
        cout << "\nQueue Underflow";
        return false;
    }

    *item = ele[front];
    front = (front + 1) % MAX;
    count--;
    return true;
}

int main()
{
    int item;
    CirQueue q;

    // mencoba memasukkan 6 item ke queue berkapasitas 5
    q.insertQueue(10);
    q.insertQueue(20);
    q.insertQueue(30);
    q.insertQueue(40);
    q.insertQueue(50);

    // percobaan ke-6 -> harus gagal (Overflow)
    if (!q.insertQueue(60)) {
        cout << "  (insert ke-6 gagal seperti yang diharapkan)\n";
    }

    // hapus sampai kosong (dengan pengecekan)
    while (q.deleteQueue(&item)) {
        cout << "\nItem dihapus: " << item << endl;
    }

    // cobalah hapus lagi -> akan memicu Underflow (dan tidak crash)
    if (!q.deleteQueue(&item)) {
        cout << "  (delete setelah kosong gagal seperti yang diharapkan)\n";
    }

    // tambahkan lagi setelah kosong untuk menguji lingkaran
    q.insertQueue(60);

    if (q.deleteQueue(&item)) {
        cout << "\nItem dihapus: " << item << endl;
    }

    cout << "\nSelesai.\n";
    return 0;
}

