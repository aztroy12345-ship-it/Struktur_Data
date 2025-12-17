#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    float nilai;
    Mahasiswa *next;
};

Mahasiswa *head = NULL;

// INSERT DATA (PUSH)
void push() {
    Mahasiswa *baru = new Mahasiswa;
    cin.ignore();
    cout << "Nama   : "; getline(cin, baru->nama);
    cout << "NIM    : "; getline(cin, baru->nim);
    cout << "Gender : "; getline(cin, baru->gender);
    cout << "Nilai  : "; cin >> baru->nilai;

    baru->next = head;
    head = baru;

    cout << "Data berhasil ditambahkan\n";
}

// HAPUS DATA (POP)
void pop() {
    if (head == NULL) {
        cout << "Stack kosong\n";
    } else {
        Mahasiswa *hapus = head;
        head = head->next;
        delete hapus;
        cout << "Data berhasil dihapus\n";
    }
}

// CETAK DATA
void cetak() {
    if (head == NULL) {
        cout << "Stack kosong\n";
    } else {
        Mahasiswa *bantu = head;
        cout << "\nDATA MAHASISWA\n";
        while (bantu != NULL) {
            cout << "Nama   : " << bantu->nama << endl;
            cout << "NIM    : " << bantu->nim << endl;
            cout << "Gender : " << bantu->gender << endl;
            cout << "Nilai  : " << bantu->nilai << endl;
            cout << "----------------------\n";
            bantu = bantu->next;
        }
    }
}

int main() {
    int pilih;
    do {
        cout << "\nMENU STACK (Linked List + Head)\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: cetak(); break;
            case 4: cout << "Program selesai\n"; break;
            default: cout << "Pilihan salah\n";
        }
    } while (pilih != 4);

    return 0;
}

