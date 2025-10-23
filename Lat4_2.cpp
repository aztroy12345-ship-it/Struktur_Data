// Lat_4_2.cpp
#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;
    int S[MAX];
    int top = -1;

    cout << "Lat_4.2 - Masukkan data (999 sebagai end-of-data)\n";
    while (true) {
        int x; cout << "Input: "; cin >> x;
        if (x == 999) {
            cout << "End of data (999). Proses push selesai.\n";
            break;
        }
        if (top >= MAX - 1) {
            cout << "Stack Penuh! Tidak bisa menambah data. Hentikan input.\n";
            break;
        }
        S[++top] = x;
        cout << "Di-PUSH: " << x << " (top=" << top << ")\n";
        if (top >= MAX - 1) { cout << "Stack kini penuh.\n"; break; }
    }

    cout << "\nMengeluarkan (POP) semua isi stack:\n";
    while (top != -1) {
        cout << "POP -> " << S[top--] << "\n";
    }
    cout << "Stack kosong.\n";
    return 0;
}

