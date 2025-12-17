#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int data[10];
    int n = 10, temp;

    cout << "Data awal:\n";
    for (int i = 0; i < n; i++) {
        data[i] = rand() % 100;
        cout << data[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++) {
        cout << "\nLangkah ke-" << i + 1 << ":\n";
        for (int j = 0; j < n - 1 - i; j++) {
            if (data[j] > data[j + 1]) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
            for (int k = 0; k < n; k++)
                cout << data[k] << " ";
            cout << endl;
        }
    }
    return 0;
}

