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

Mahasiswa *FIRST = NULL;
Mahasiswa *LAST  = NULL;

// Membuat simpul baru
Mahasiswa* buatNode(string nama, string nim, string gender, float nilai) {
    Mahasiswa *p = new Mahasiswa;
    p->nama = nama;
    p->nim = nim;
    p->gender = gender;
    p->nilai = nilai;
    p->next = NULL;
    return p;
}

// Insert data terurut berdasarkan NIM
void insertData() {
    string nama, nim, gender;
    float nilai;

    cout << "Nama   : "; cin.ignore(); getline(cin, nama);
    cout << "NIM    : "; getline(cin, nim);
    cout << "Gender : "; getline(cin, gender);
    cout << "Nilai  : "; cin >> nilai;

    Mahasiswa *p = buatNode(nama, nim, gender, nilai);

    if (FIRST == NULL) {
        FIRST = LAST = p;
        p->next = FIRST;
    } else if (nim < FIRST->nim) {
        p->next = FIRST;
        FIRST = p;
        LAST->next = FIRST;
    } else {
        Mahasiswa *q = FIRST;
        while (q->next != FIRST && q->next->nim < nim) {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
        if (q == LAST) {
            LAST = p;
        }
    }
    cout << "Data berhasil ditambahkan.\n";
}

// Hapus data berdasarkan NIM
void hapusData() {
    if (FIRST == NULL) {
        cout << "Data kosong.\n";
        return;
    }

    string nim;
    cout << "Masukkan NIM yang akan dihapus: ";
    cin >> nim;

    Mahasiswa *q = FIRST, *prev = LAST;

    do {
        if (q->nim == nim) {
            if (q == FIRST) {
                FIRST = FIRST->next;
                LAST->next = FIRST;
            } else if (q == LAST) {
                LAST = prev;
                LAST->next = FIRST;
            } else {
                prev->next = q->next;
            }
            delete q;
            cout << "Data berhasil dihapus.\n";
            return;
        }
        prev = q;
        q = q->next;
    } while (q != FIRST);

    cout << "Data tidak ditemukan.\n";
}

// Cetak seluruh data
void cetakData() {
    if (FIRST == NULL) {
        cout << "Data kosong.\n";
        return;
    }

    Mahasiswa *q = FIRST;
    cout << "\n=== DATA MAHASISWA ===\n";
    do {
        cout << "Nama   : " << q->nama << endl;
        cout << "NIM    : " << q->nim << endl;
        cout << "Gender : " << q->gender << endl;
        cout << "Nilai  : " << q->nilai << endl;
        cout << "---------------------\n";
        q = q->next;
    } while (q != FIRST);
}

int main() {
    int pilih;
    do {
        cout << "\nCIRCULAR SINGLY LINKED LIST\n";
        cout << "===========================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilihan (1-4): ";
        cin >> pilih;

        switch (pilih) {
            case 1: insertData(); break;
            case 2: hapusData(); break;
            case 3: cetakData(); break;
            case 4: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan salah.\n";
        }
    } while (pilih != 4);

    return 0;
}

