//IKRAM IRIANSYAH
//2311102184
#include <iostream>
#include <iomanip>

using namespace std;

//Fungsi untuk menampilkan graph dalam format matriks
void TampilGraph_184(int JumlahSimpul_2311102184, string* NamaSimpul_2311102184, int** BobotSimpul_184) {
    //menampilkan baris pertama berupa simpul nama kota
    cout << setw(10) << " ";
    for (int i = 0; i < JumlahSimpul_2311102184; i++) {
        cout << setw(10) << NamaSimpul_2311102184[i];
    }
    cout << endl;

    // Menampilkan bobot kota secara matriks
    for (int baris_184 = 0; baris_184 < JumlahSimpul_2311102184; baris_184++) {
        cout << setw(10) << NamaSimpul_2311102184[baris_184];
        for (int kolom_184 = 0; kolom_184 < JumlahSimpul_2311102184; kolom_184++) {
            cout << setw(10) << BobotSimpul_184[baris_184][kolom_184];
        }
        cout << endl;
    }
}

int main() {
    int JumlahSimpul_2311102184;
    int Nomor_184 = 1;
    int Bobot_184;

    cout << "--- PROGRAM GRAPH SEDERHANA ---" << endl;

    //User menginputkan jumlah simpul (jumlah kota)
    cout << "Masukkan jumlah simpul = ";
    cin >> JumlahSimpul_2311102184;

    //membuat array NamaSimpul_2311102184 yang dialokasikan secara dinamis berdasarkan input jumlah simpul
    string* NamaSimpul_2311102184 = new string[JumlahSimpul_2311102184];

    //user memasukkan nama simpul (nama kota)
    cout << "--- Masukkan nama simpul ---" << endl; 
    for (int i = 0; i < JumlahSimpul_2311102184; i++) {
        cout << "Masukkan nama simpul " << Nomor_184++ << " = ";
        cin >> NamaSimpul_2311102184[i];
    }
    cout << endl;

    //membuat array BobotSimpul_184 yang dialokasikan secara dinamis berdasarkan input jumlah simpul
    int** BobotSimpul_184 = new int*[JumlahSimpul_2311102184];
    for (int i = 0; i < JumlahSimpul_2311102184; i++) {
        BobotSimpul_184[i] = new int[JumlahSimpul_2311102184]();
    }

    //user emasukkan bobot antar simpul
    cout << "--- Masukkan Bobot Antar Simpul ---" << endl;
    for (int i = 0; i < JumlahSimpul_2311102184; i++) {
        for (int j = 0; j < JumlahSimpul_2311102184; j++) {
            if (i != j) {
                cout << "Bobot " << NamaSimpul_2311102184[i] << " --> " << NamaSimpul_2311102184[j] << " = ";
                cin >> Bobot_184;
                BobotSimpul_184[i][j] = Bobot_184;
            }
        }
    }
    cout << endl;

    //memanggil fungsi TampilGraph_184
    TampilGraph_184(JumlahSimpul_2311102184, NamaSimpul_2311102184, BobotSimpul_184);

    return 0;
}