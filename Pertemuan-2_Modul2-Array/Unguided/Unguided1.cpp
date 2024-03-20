#include <iostream>

using namespace std;

int main() {
    const int SIZE = 10;
    int data[SIZE];
    int genap[SIZE], ganjil[SIZE];
    int genap_count = 0, ganjil_count = 0;

    // Input data dari pengguna
    cout << "Masukkan 10 angka secara berurutan: ";
    for (int i = 0; i < SIZE; ++i) {
        cin >> data[i];
    }

    // Memisahkan nomor genap dan ganjil
    for (int i = 0; i < SIZE; ++i) {
        if (data[i] % 2 == 0) {
            genap[genap_count++] = data[i];
        } else {
            ganjil[ganjil_count++] = data[i];
        }
    }

    // Menampilkan data array
    cout << "Data Array: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    // Menampilkan nomor genap
    cout << "Nomor Genap: ";
    for (int i = 0; i < genap_count; ++i) {
        cout << genap[i] << " ";
    }
    cout << endl;

    // Menampilkan nomor ganjil
    cout << "Nomor Ganjil: ";
    for (int i = 0; i < ganjil_count; ++i) {
        cout << ganjil[i] << " ";
    }
    cout << endl;

    return 0;
}
