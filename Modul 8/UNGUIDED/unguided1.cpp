//IKRAM IRIANSYAH
//2311102184

#include<iostream>

using namespace std;

//Prosedur untuk menampilkan huruf-huruf didalam kalimat
void TampilkanHurufKalimat_184(char ArrayKalimat_184[], int PanjangKalimat_184){
    for(int i = 0; i < PanjangKalimat_184; i++){ //perulangan for untuk menampilkan huruf
        cout << ArrayKalimat_184[i] << '\t';
    }
    cout << endl;
}

//Prosedur untuk mengurutkan huruf sesuai abjad menggunakan bubble sort
void BubbleSort_184(char ArrayKalimat_184[], int PanjangKalimat_184){
    bool Urut_184 = true; //deklarasi variabel boolean Urut_184 dengan nilai true
    int j = 0; //deklarasi variabel j dengan nilai 0 yang digunanakn dalam perulangan
    char temp_184; //deklarasi variabel temp_184 untuk menampung huruf sementara
    while(Urut_184){ //jika variabel boolean Urut_184 bernilai true, maka ulangi
        Urut_184 = false; //variabel Urut_184 menjadi false
        j++; //nilai j bertambah
        for(int i = 0; i < PanjangKalimat_184 - j; i++){ //perulangan untuk mengurutkan huruf
            if(ArrayKalimat_184[i] > ArrayKalimat_184[i + 1]){  //Jika nilai ArrayKalimat_184 index ke i lebih besar dari nilai index selanjutnya, maka lanjutkan
                temp_184 = ArrayKalimat_184[i]; //masukkan nilai ArrayKalimat_184 index ke i kedalam variabel temp_184
                ArrayKalimat_184[i] = ArrayKalimat_184[i + 1]; //masukkan nilai ArrayKalimat_184 index ke i + 1 kedalam ArrayKalimat_184 index ke i
                ArrayKalimat_184[i + 1] = temp_184; //masukkan nilai variabel temp_184 kedalam ArrayKalimat_184 index ke i + 1
                Urut_184 = true; //variabel boolean Urut_184 menjadi true
            }
        }
    }
}

//Prosedur untuk mencari huruf didalam kalimat menggunakan binary search
void BinarySearch_184(char ArrayKalimat_184[], int PanjangKalimat_184, char HurufYangDicari_184){
    int awal_184, tengah_184, akhir_184, Posisi_184; //Deklarasi variabel awal_184, tengah_184, akhir_184, posisi_184
    bool b_flag = false; //deklarasi variabel boolean b_flag dengan nilai false
    awal_184 = 0; //nilai variabel awal_184 adalah 0
    akhir_184 = PanjangKalimat_184; //nilai variabel akhir_184 adalah nilai varaibel PanjangKalimat_184
    while(!b_flag && awal_184 <= akhir_184){ //Jika b_flag false & nilai awal_184 kurang dari sama dengan nilai akhir_184, maka lanjutkan
        tengah_184 = (awal_184 + akhir_184)/2; //hitung nilai tengah_184
        if(HurufYangDicari_184 == ArrayKalimat_184[tengah_184]){ //jika huruf yang dicari berada di tengah, maka
            Posisi_184 = tengah_184; //nilai variabel posisi_151 sama dengan nilai variabel tengah_184
            b_flag = true; //b_flag menjadi true
            break; //perulangan selesai
        } else if(HurufYangDicari_184 < ArrayKalimat_184[tengah_184]){ //jika huruf yang dicari posisinya kurang dari tengah_184 (berada di kiri), maka
            akhir_184 = tengah_184 - 1; //nilai akhir_151 adalah nilai tengah_184 dikurang 1 
        } else if(HurufYangDicari_184 > ArrayKalimat_184[tengah_184]){ //jika huruf yang dicari posisinya lebih dari tengah_184 (berada di kanan), maka
            awal_184 = tengah_184 + 1; //nilai awal_184 adalah nilai tengah_184 ditambah 1
        }
    }
    if(b_flag){ //jika b_flag true (huruf ditemukan), maka 
        //tampilkan huruf ditemukan beserta indexnya
        cout << "Huruf " << HurufYangDicari_184 << " ditemukan pada index ke-";
        for(int i = 0; i < PanjangKalimat_184; i++){
            if(HurufYangDicari_184 == ArrayKalimat_184[i]){
                cout << i;
                if(ArrayKalimat_184[i + 1] == HurufYangDicari_184){
                    cout << ", ";
                }
            }
        }
    } else { //jika b_flag false (huruf tidak ditemukan), maka tampilkan "Huruf tidak ditemukan"
        cout << "Huruf " << HurufYangDicari_184 << " tidak ditemukan" << endl;
    }
}

int main(){
    string InputKalimat_184, KalimatTanpaSpasi_184; //deklarasi variabel string InputKalimat_184 dan KalimatTanpaSpasi_184
    int PanjangKalimat_184; //deklarasi variabel integer PanjangKalimat_184
    char HurufYangDicari_184; //deklarasi variabel char HurufYangDicari_184
    cout << "--- PROGRAM MENCARI HURUF DALAM KALIMAT ---" << endl;
    cout << "Masukkan kalimat = "; 
    getline(cin, InputKalimat_184); //kalimat yang diinputkan user dimasukkan kedalam variabel InputKalimat_184
    cout << endl;

    // Menghapus karakter spasi dari kalimat
    KalimatTanpaSpasi_184 = ""; //variabel KalimatTanpaSpasi_184 dikosongkan
    //perulangan for-each yang mengiterasi setiap karakter atau huru didalam kalimat yang diinputkan user
    for(char c : InputKalimat_184){
        if(c != ' ') { //jika huruf atau karakter yang diperiksa saat ini bukan spasi, maka masukkan kedalam variabel KalimatTanpaSpasi_184
            KalimatTanpaSpasi_184 += c; 
        }
    }

    //menghitung panjang kalimat
    PanjangKalimat_184 = KalimatTanpaSpasi_184.length();

    //memasukkan setiap karakter dalam kalimat kedalam array char ArrayKalimat_184 dengan ukuran PanjangKalimat_184
    char ArrayKalimat_184[PanjangKalimat_184];
    for(int i = 0; i < PanjangKalimat_184; i++){
        ArrayKalimat_184[i] = KalimatTanpaSpasi_184[i]; //masukkan semua huruf yang tersimpan di KalimatTanpaSpasi_184 kedalam array ArrayKalimat_184[]
    }

    //Menampilkan setiap huruf dalam kalimat sebelum di urutkan
    cout << "Urutan huruf dalam kalimat sebelum diurutkan (spasi dihilangkan) = " << endl;
    TampilkanHurufKalimat_184(ArrayKalimat_184, PanjangKalimat_184); //pemanggilan prosedur TampilkanHurufKalimat()
    cout << endl;

    //Menampilkan setiap huruf dalam kalimat setelah di urutkan
    cout << "Urutan huruf dalam kalimat setelah diurutkan (spasi dihilangkan) = " << endl;
    BubbleSort_184(ArrayKalimat_184, PanjangKalimat_184); //pemanggilan prosedur BubbleSort_184()
    TampilkanHurufKalimat_184(ArrayKalimat_184, PanjangKalimat_184); //pemanggilan prosedur TampilkanHurufKalimat() dengan huruf yang sudah diurutkan secara ascending
    cout << endl;

    //User menginputkan huruf yang ingin dicari
    cout << "Masukkan huruf yang ingin dicari = ";
    cin >> HurufYangDicari_184; 

    //Pemanggilan prosedur BinarySearch_184()
    BinarySearch_184(ArrayKalimat_184, PanjangKalimat_184, HurufYangDicari_184);

    return 0;
}