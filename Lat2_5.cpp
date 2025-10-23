#include <iostream>
using namespace std;

int main() {
    int x[2][3][5];
    unsigned int alamat_diketahui = 0x12EF; // &x[1][1][4]
    int baris_diketahui = 1, kolom_diketahui = 1, depth_diketahui = 4;
    int baris_dicari = 0, kolom_dicari = 0, depth_dicari = 3;
    int kolom_total = 3, depth_total = 5;
    int ukuran_int = 4;

    int index_diketahui = (baris_diketahui * kolom_total * depth_total) +
                          (kolom_diketahui * depth_total) + depth_diketahui;
    int index_dicari = (baris_dicari * kolom_total * depth_total) +
                       (kolom_dicari * depth_total) + depth_dicari;

    int selisih = index_diketahui - index_dicari;
    unsigned int alamat_dicari = alamat_diketahui - (selisih * ukuran_int);

    cout << "Alamat &x[1][1][4] = 0x" << hex << alamat_diketahui << endl;
    cout << "Selisih indeks = " << dec << selisih << endl;
    cout << "Ukuran int = " << ukuran_int << " byte" << endl;
    cout << "Alamat &x[0][0][3] = 0x" << hex << alamat_dicari << endl;

    return 0;
}

