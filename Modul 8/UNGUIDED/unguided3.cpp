//IKRAM IRIANSYAH
//2311102184

#include<iostream>

using namespace std;

int main(){
    int ArrayData_184[10] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; //Deklarasi array bernama ArrayData_184 dengan ukuran 10 
    int CariAngka_184; //Deklarasi variabel CariAngka_184 yang menampung angka yang ingin dicari
    int JumlahAngka_184 = 0; //Deklarasi variabel JumlahAngka_184 dengan nilai 0 untuk menghitung jumlah angka yang ingin dicari yang ada pada array
    int IndexAngka_184[10]; //Deklarasi array IndexAngka_184 dengan ukuran 10 untuk menyimpan index dari angka yang dicari didalam array ArrayData_184
    int j = 0; //Deklarasi variabel j
    cout << "--- PROGRAM PENGHITUNG ANGKA DALAM ARRAY ---" << endl;
    cout << "Diketahui sebuah array berisi data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;
    cout << "Masukkan angka yang ingin dihitung jumlahnya = "; //User memasukkan angka yang ingin dihitung jumlahnya
    cin >> CariAngka_184;
    cout << endl;

    //Sequential Search
    for(int i = 0; i < 10; i++){
        if(ArrayData_184[i] == CariAngka_184){ //Jika setiap data yang tersimpan pada array ArrayData_184 sama dengan angka yang diinputkan user yang ingin dihitung jumlahnya, maka lanjutkan
            JumlahAngka_184++; //variabel JumlahAngka_184 bertambah nilainya
            IndexAngka_184[j++] = i; //nilai i dimasukkan ke array IndexAngka_184 indeks ke j++ (0)
        }
    }

    if(JumlahAngka_184 != 0){ //jika variabel JumlahAngka_184 nilainya tidak sama dengan 0, maka lanjutkan
        cout << "Array tersebut memiliki angka " << CariAngka_184 << " sebanyak " << JumlahAngka_184 << endl;
        cout << "Ditemukan pada index ke-";
        //perulangan untuk menampilkan index dari angka yang dicari
        for(int i = 0; i < JumlahAngka_184; i++){
            cout << IndexAngka_184[i];
            if(i < j - 1){
                cout << ", ";
            }
        }
    } else { //jika variabel JumlahAngka_184 nilainya sama dengan 0, maka lanjutkan
        cout << "Array tersebut tidak berisi angka " << CariAngka_184 << endl;
    }
    
    return 0; 
}