#include <iostream>
#include <string>
using namespace std;

// Struktur Node
struct Node {
    string nama;
    int nim;
    char gender;
    int nilai;
    Node* prev;
    Node* next;
};

// Pointer head
Node* head = NULL;

// Fungsi membuat node baru
Node* createNode(string nama, int nim, char gender, int nilai) {
    Node* baru = new Node();
    baru->nama = nama;
    baru->nim = nim;
    baru->gender = gender;
    baru->nilai = nilai;
    baru->prev = NULL;
    baru->next = NULL;
    return baru;
}

// INSERT DATA (TERURUT NAIK BERDASARKAN NIM)
void insertData() {
    string nama;
    int nim, nilai;
    char gender;

    cout << "Masukkan NIM     : ";
    cin >> nim;
    cin.ignore();
    cout << "Masukkan Nama    : ";
    getline(cin, nama);
    cout << "Masukkan Gender (L/P): ";
    cin >> gender;
    cout << "Masukkan Nilai   : ";
    cin >> nilai;

    Node* baru = createNode(nama, nim, gender, nilai);

    // Jika list kosong
    if (head == NULL) {
        head = baru;
        return;
    }

    // Jika data di depan
    if (nim < head->nim) {
        baru->next = head;
        head->prev = baru;
        head = baru;
        return;
    }

    // Sisipkan di posisi sesuai NIM
    Node* temp = head;
    while (temp->next != NULL && temp->next->nim < nim) {
        temp = temp->next;
    }

    baru->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = baru;

    temp->next = baru;
    baru->prev = temp;
}

// HAPUS DATA (BERDASARKAN NIM)
void hapusData() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    int nim;
    cout << "Masukkan NIM yang akan dihapus: ";
    cin >> nim;

    Node* temp = head;

    // Jika data pertama
    if (temp->nim == nim) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
        cout << "Data berhasil dihapus.\n";
        return;
    }

    // Cari node
    while (temp != NULL && temp->nim != nim) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Data dengan NIM tersebut tidak ditemukan.\n";
        return;
    }

    // Hapus node
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;
    cout << "Data berhasil dihapus.\n";
}

// CETAK DATA
void cetakData() {
    if (head == NULL) {
        cout << "List masih kosong!\n";
        return;
    }

    cout << "\nDATA MAHASISWA:\n";
    cout << "NIM\tNAMA\tGENDER\tNILAI\n";
    cout << "-------------------------------------\n";

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->nim << "\t"
             << temp->nama << "\t"
             << temp->gender << "\t"
             << temp->nilai << endl;
        temp = temp->next;
    }
}

// MAIN PROGRAM (MENU)
int main() {
    int pilihan;

    do {
        cout << "\nLIN. DOUBLY LINKED LIST\n";
        cout << "=============================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilihan (1 - 4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: insertData(); break;
            case 2: hapusData(); break;
            case 3: cetakData(); break;
            case 4: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 4);

    return 0;
}

