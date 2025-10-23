// Lat_4_4.cpp  (potongan: pop & cetak sampai kosong)
#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;
    int S[MAX];
    int top = -1;

    // contoh: isi stack dengan data contoh agar bisa melakukan POP
    S[++top] = 10;
    S[++top] = 20;
    S[++top] = 30;
    cout << "Isi awal stack (top ke bottom): ";
    for (int i = top; i >= 0; --i) cout << S[i] << (i==0? "\n":" ");

    cout << "\nMelakukan POP hingga kosong:\n";
    while (top != -1) {
        cout << "POP -> " << S[top--] << "\n";
    }
    cout << "Stack sekarang kosong.\n";
    return 0;
}

