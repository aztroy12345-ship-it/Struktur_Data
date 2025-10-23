// Lat_4_3.cpp  (potongan: push sampai penuh)
#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;
    int S[MAX];
    int top = -1;

    cout << "Lat_4.3 - Isi stack sampai penuh (999 untuk berhenti)\n";
    while (true) {
        if (top >= MAX - 1) {
            cout << "Stack Penuh! Tidak bisa PUSH lagi.\n";
            break;
        }
        int x; cout << "Masukkan nilai untuk PUSH (999 = stop): "; cin >> x;
        if (x == 999) { cout << "Pengisian dihentikan.\n"; break; }
        S[++top] = x;
        cout << "Di-PUSH: " << x << " (top=" << top << ")\n";
    }

    cout << "Isi akhir stack (top ke bottom): ";
    if (top == -1) cout << "Kosong\n";
    else {
        for (int i = top; i >= 0; --i) cout << S[i] << (i==0? "\n":" ");
    }
    return 0;
}

