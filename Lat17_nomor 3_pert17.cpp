#include <iostream>
using namespace std;

int main() {
    int data[7] = {8, 22, 7, 9, 31, 5, 13};
    int n = 7;
    int temp;

    cout << "Data sebelum diurutkan:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    // Proses Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (data[j] > data[j + 1]) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    cout << "\n\nData setelah diurutkan (Bubble Sort):\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    return 0;
}

