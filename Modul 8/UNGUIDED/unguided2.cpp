//IKRAM IRIANSYAH
//2311102184

#include<iostream>

using namespace std;

//Prosedur sequential search untuk mencari huruf vokal 
void SequentialSearch_184(char ArrayKalimat_184[], int PanjangKalimat_184){
    int JumlahHurufVokal_184 = 0; //deklarasi variabel JumlahHurufVokal dengan nilai 0
    char HurufVokal_184[PanjangKalimat_184]; //deklarasi array HurufVokal dengan ukuran PanjangKalimat_184 untuk menyimpan huruf vokal yang ditemukan dalam kalimat
    for(int i = 0; i < PanjangKalimat_184; i++){ //perulangan untuk memeriksa setiap huruf didalm kalimat
        //jika dalam ArrayKalimat_184[] index ke i ditemukan huruf vokal (a, A, i, I, u, U, e, E, o, O), maka 
        if(ArrayKalimat_184[i] == 'a' || ArrayKalimat_184[i] == 'A' || ArrayKalimat_184[i] == 'i' || ArrayKalimat_184[i] == 'I' || ArrayKalimat_184[i] == 'u' || ArrayKalimat_184[i] == 'U' || ArrayKalimat_184[i] == 'e' || ArrayKalimat_184[i] == 'E' || ArrayKalimat_184[i] == 'o' || ArrayKalimat_184[i] == 'O'){
            HurufVokal_184[JumlahHurufVokal_184] = ArrayKalimat_184[i]; //masukkan huruf vokal tersebut kedalam array HurufVokal[] 
            JumlahHurufVokal_184++; //variabel JumlahHurufVokal bertambah nilainya
        }
    }
    if(JumlahHurufVokal_184 != 0){ //jika nilai variabel JumlahHurufVokal bukan sama dengan 0 (ditemukan huruf vokal), maka tampilkan jumlah huruf vokal yang ditemukan beserta huruf-hurufnya
        cout << "Kalimat ini memiliki " << JumlahHurufVokal_184 << " huruf vokal, yaitu : ";
        for(int i = 0; i < JumlahHurufVokal_184; i++){
            cout << HurufVokal_184[i];
            if(i < JumlahHurufVokal_184 - 1){
                cout << ", ";
            }
        }
    } else { //jika nilai variabel JumlahHurufVokal sama dengan 0 (tidak ditemukan huruf vokal), maka tampilkan "Kalimat ini tidak memiliki huruf vokal"
        cout << "Kalimat ini tidak memiliki huruf vokal" << endl;
    }
}

int main(){
    string InputKalimat_184; //deklarasi variabel string InputKalimat_184 
    int PanjangKalimat_184; //deklarasi variabel integer PanjangKalimat_184
    cout << "--- PROGRAM PENGHITUNG HURUF VOKAL ---" << endl;
    cout << "Masukkan kalimat = ";
    getline(cin, InputKalimat_184); //user memasukkan kalimat kemudian disimpan pada variabel InputKalimat_184
    cout << endl;

    //Menghitung panjang karakter dalam kalimat
    PanjangKalimat_184 = InputKalimat_184.length();

    //memasukkan karakter dalam kalimat kedalam array
    char ArrayKalimat_184[PanjangKalimat_184]; //deklarasi array char ArrayKalimat[] dengan ukuran PanjangKalimat_184
    //perulangan for-each yang memecah kalimat dalam InputKalimat_184 mejadi huruf-huruf penyusunnya, kemudian masukkan huruf-huruf tersebut kedalam ArrayKalimat[]
    for(int i = 0; i < PanjangKalimat_184; i++){
        ArrayKalimat_184[i] = InputKalimat_184[i];
    }

    //pemanggilan prosedur SequentialSearch_184() untuk mencari huruf vokal, menghitung jumlahnya, dan menampilkan huruf-hurufnya
    SequentialSearch_184(ArrayKalimat_184, PanjangKalimat_184);

    return 0;
}