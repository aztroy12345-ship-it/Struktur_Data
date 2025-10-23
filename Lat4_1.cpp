// Lat_4_1.cpp
#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;
    int S[MAX];
    int top = -1;

    cout << "Lat_4.1 - Masukkan data (999 untuk selesai)\n";
    while (true) {
        int x; cout << "Input: "; cin >> x;
        if (x == 999) { cout << "Selesai.\n"; break; }

        if (x >= 60) {
            if (top >= MAX - 1) {
                cout << "Stack Penuh\n";
                break;
            } else {
                S[++top] = x;
                cout << "Di-PUSH: " << x << " (top=" << top << ")\n";
            }
        } else { // x < 60
            if (top == -1) {
                cout << "Stack Kosong\n";
                break;
            } else {
                int val = S[top--];
                cout << "POP -> " << val << " (karena input < 60)\n";
            }
        }
    }

    // tampilkan isi akhir (opsional)
    cout << "Isi stack sekarang (dari top ke bottom): ";
    if (top == -1) cout << "Kosong\n";
    else {
        for (int i = top; i >= 0; --i) cout << S[i] << (i==0? "\n":" ");
    }
    return 0;
}

