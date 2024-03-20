#include <iostream>

using namespace std;

int main() {
    int size;
    cout << "Masukkan jumlah elemen dalam array: ";
    cin >> size;

    // Memastikan ukuran array tidak negatif atau nol
    if (size <= 0) {
        cout << "Ukuran array harus lebih besar dari 0." << endl;
        return 1;
    }

    int array[size];
    cout << "Masukkan elemen-elemen array: ";
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    // Inisialisasi nilai maksimum dan minimum dengan elemen pertama array
    int max = array[0];
    int min = array[0];
    int sum = 0;

    // Mencari nilai maksimum, minimum, dan menghitung jumlah elemen
    for (int i = 0; i < size; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
        sum += array[i];
    }

    // Menghitung rata-rata
    float average = static_cast<float>(sum) / size;

    // Menampilkan hasil
    cout << "Nilai maksimum: " << max << endl;
    cout << "Nilai minimum: " << min << endl;
    cout << "Nilai rata-rata: " << average << endl;

    return 0;
}