#include <iostream>
using namespace std;

int main() {
    long x[12][14];
    unsigned int alamat_awal = 0x1000; // &x[0][0]
    int baris = 2, kolom = 4, total_kolom = 14;
    int ukuran_long = 4;

    int offset = (baris * total_kolom) + kolom;
    unsigned int alamat_x = alamat_awal + (offset * ukuran_long);

    cout << "Alamat awal &x[0][0] = 0x" << hex << alamat_awal << endl;
    cout << "Offset = " << dec << offset << endl;
    cout << "Ukuran long = " << ukuran_long << " byte" << endl;
    cout << "Alamat &x[2][4] = 0x" << hex << alamat_x << endl;

    return 0;
}

