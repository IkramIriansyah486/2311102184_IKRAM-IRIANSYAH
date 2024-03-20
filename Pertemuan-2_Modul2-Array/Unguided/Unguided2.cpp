#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    cout << "===================================================\n";
    cout << ">>>>>>>>>>> Program Array Tiga Dimensi <<<<<<<<<<<<\n";
    cout << "===================================================\n";
    cout << endl;

    cout << "Masukkan Jumlah Elemen Array Ke-1 : ";
    cin >> a;
    cout << "Masukkan Jumlah Elemen Array Ke-2 : ";
    cin >> b;
    cout << "Masukkan Jumlah Elemen Array Ke-3 : ";
    cin >> c;
    cout << endl;

    // Input nilai elemen array
    int arr [a][b][c];
    cout << "==> Masukkan Nilai Elemen Array <==\n";

    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            for(int k=0; k<c; k++){
                cout << "Elemen Array Indeks Ke [" << i << "][" << j << "][" << k << "] = ";
                cin >> arr[i][j][k];
            }
        }
        cout << endl;
    }

    cout << "\n===================================\n";
    cout << "==> Tampilan Nilai Elemen Array <==\n";
    cout << "===================================\n";

    //Menampilkan nilai yang kita inputkan
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            for(int k=0; k<c; k++){
                cout << "Tampilan Nilai Array Indeks Ke [" << i << "][" << j << "][" << k << "] = "<< arr[i][j][k] << endl;
            }
        }
        cout << endl;
    }

    cout << "\n================================\n";
    cout << "==> Tampilan Array 3 Dimensi <==\n";
    cout << "================================\n";

    //Tampilan array
    for (int i=0; i<a; i++){
        for (int j=0; j<b; j++){
            for (int k=0; k<c; k++){
                cout << arr[i][j][k] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "===================================================="<< endl;

    return 0;
}