 # <h1 align="center">Laporan Praktikum Modul 7 - QUEUE</h1>
<p align="center">Ikram Iriansyah</p>
  <P align="center">2311102184</p>

## Dasar Teori

### QUEUE

Queue atau antrian adalah struktur data linier yang mengikuti prinsip First-In-First-Out (FIFO)[1]. Elemen baru ditambahkan di bagian belakang antrian (enqueue) dan elemen lama diambil dari bagian depan (dequeue). Queue sering digunakan dalam aplikasi seperti simulasi antrian, penjadwalan proses, dan manajemen buffer jaringan. Queue dapat diimplementasikan menggunakan array atau linked list[2]. Contoh pada perpustakaan menyediakan kelas queue yang dapat digunakan secara langsung. 

### Operasi utama pada queue meliputi:

-Enqueue: Menambahkan elemen baru ke bagian belakang antrian. Operasi ini biasanya disebut juga "push" atau "insert".

-Dequeue: Menghapus elemen yang berada di bagian depan antrian. Operasi ini biasanya disebut juga "pop" atau "remove".

-Front: Mengakses atau melihat elemen yang berada di bagian depan antrian tanpa menghapusnya.

-Rear/Back: Mengakses atau melihat elemen yang berada di bagian belakang antrian.

-isEmpty: Memeriksa apakah queue dalam keadaan kosong atau tidak.

-isFull: Memeriksa apakah queue dalam keadaan penuh atau tidak (jika menggunakan implementasi array dengan ukuran tetap).

### Queue dapat diimplementasikan dengan beberapa cara, antara lain:

## Menggunakan Array:
 -Array statis: Queue diimplementasikan menggunakan array dengan ukuran tetap. Memiliki keterbatasan kapasitas dan dapat terjadi kondisi overflow jika antrian penuh.
 
 -Array dinamis (circular array): Untuk mengatasi keterbatasan array statis, digunakan circular array yang melakukan wrap-around saat mencapai ujung array.

## Menggunakan Linked List:
 Queue diimplementasikan dengan linked list, di mana setiap node menyimpan data dan pointer ke node berikutnya. Tidak memiliki batasan kapasitas seperti array statis dan dapat tumbuh secara dinamis.

## Beberapa operasi utama pada kelas Queue meliputi:
-push(const T& val): Menambahkan elemen baru ke bagian belakang antrian.

-pop(): Menghapus elemen dari bagian depan antrian.

-front(): Mengakses elemen di bagian depan antrian tanpa menghapusnya.

-back(): Mengakses elemen di bagian belakang antrian.

-empty(): Memeriksa apakah antrian kosong atau tidak.

-size(): Mendapatkan jumlah elemen dalam antrian.

### Implementasi Queue dengan prioritas dapat menggunakan struktur data seperti heap atau binary search tree. Queue memiliki berbagai aplikasi dalam pemrograman, seperti:

-Memodelkan antrian dalam sistem nyata (antrian di bank, kasir, printer, dll).

-Algoritma Breadth-First Search (BFS) pada graf.

-Manajemen buffer jaringan.

-Penjadwalan proses dalam sistem operasi.

-Pemrosesan batch dalam sistem komputer.

   
## Guided 

### Latihan

```C++
#include<iostream>

using namespace std;

const int MaksimalAntrian = 5;
int front = 0;
int back = 0;
string QueueTeller[5];

//Mengecek apakah antrian sudah penuh atau belum
bool isFull(){
    if(back == MaksimalAntrian){
        return true;
    } else {
        return false;
    }
}

//Mengecek apakah antrian masih kosong atau tidak
bool isEmpty(){
    if(back == 0){
        return true;
    } else {
        return false;
    }
}

//Menambah antrian
void TambahData(string nama){
    if(isFull()){
        cout << "Antrian sudah penuh" << endl;
    } else if(!isFull()){
        if(isEmpty()){
            QueueTeller[0] = nama;
            front++;
            back++;
        } else if(!isEmpty()){
            QueueTeller[back] = nama;
            back++;
        }
    }
}

//Mengurangi antrian
void KurangAntrian(){
    if(isEmpty()){
        cout << "Antrian masih kosong" << endl;
    } else if(!isEmpty()){
        for(int i = 0; i < back; i++){
            QueueTeller[i] =  QueueTeller[i+1];
        }
        back--;
    }
}

//Menghitung banyak antrian
int Count(){
    return back;
}

//Menghapus seluruh antrian
void ClearQueue(){
    if(isEmpty()){
        cout << "Antrian masih kosong" << endl;
    } else if(!isEmpty()){
        for(int i = 0; i < back; i++){
            QueueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

//Melihat Antrian
void ViewQueue(){
    cout << "Data antrian = " << endl;
    for(int i = 0; i < MaksimalAntrian; i++){
        if(QueueTeller[i] != ""){
            cout << i+1 << ". " << QueueTeller[i] << endl;
        } else {
            cout << i+1 << ". " << "(kosong)" << endl;
        }
    }
    cout << endl;
}

//main fungsi
int main(){
    //Menambah 3 data nama kedalam antrian
    TambahData("Alya");
    TambahData("Kiki");
    TambahData("Artika");

    //menampilkan data yang sudah ditambahkan
    ViewQueue();

    //mengurangi data
    KurangAntrian();

    //menampilkan data setelah dikurangi
    ViewQueue();

    //menghapus seluruh antrian
    ClearQueue();

    //menampilkan data setelah dihapus
    ViewQueue();
}
```

#### Output :
![Output-guided1-modul7](https://github.com/IkramIriansyah486/Structure-Data-Assignment/Modul 7/LAPRAK/Output-Guided1-Modul7.png)

Program ini merupakan implementasi struktur data Queue (Antrian) menggunakan array statis. Program ini digunakan untuk mengelola antrian pada sebuah teller dengan kapasitas maksimal 5 orang.


## Unguided 


### 1) Ubahlah penerapan konsep queue pada bagian guided dari array menjadilinked list

```C++
//IKRAM IRIANSYAH
//2311102184

#include<iostream>

using namespace std;

//Deklarasi struct node
struct node{ //node berisi variabel nama_151 dan pointer next
    string nama_184;
    node *next;
};
    node *front; //deklarasi node front 
    node *back; //deklarasi node back

//Prosedur inisialisasi node front dan back sebagai NULL
void Inisialisasi_184(){ 
    front = NULL;
    back = NULL;
}

//Fungsi untuk mengecek apakah queue kosong atau tidak
bool isEmpty_184(){
    if (front == 0){
        return true; //jika antrian pertama tidak ada, maka antrian kosong (kembalikan true)
    } else {
        return false; //jika antrian pertama ada, maka antrian tidak kosong (kembalikan false)
    }
}

//Prosedur untuk menambahkan data pada antrian
void TambahData_184(string name_184){
    node *baru = new node; //tambah node baru
    baru->nama_184 = name_184; //node baru berisi variabel name_151
    baru->next = NULL; //next dari node baru adalah NULL
    if(isEmpty_184() == true){ //jika antrian kosong, maka lanjutkan
        front = back = baru; //node baru sebagai front dan back
        back->next = NULL; //node selanjutnya dari node baru adalah NULL
    } else if(isEmpty_184() == false){ //jika antrian tidak kosong, maka lanjutkan
        back->next = baru; //node baru sebagai node selanjutnya dari antrian yang sudah ada
        back = baru; //node baru sebagai back
    }
}

//Prosedur untuk mengurangi antrian (lanjut ke antrian selanjutnya)
void KurangiAntrian_184(){
    node *hapus; //inisialisasi node hapus
    if(isEmpty_184() == true){ //jika antrian kosong, maka tampilkan "Antrian masih kosong!"
        cout << "Antrian masih kosong!" << endl;
    } else if(isEmpty_184() == false){ //jika antrian tidak kosong, maka lanjutkan
        if(front->next != NULL){ //jika node selanjutnya setelah antrian pertama bukan NULL, maka lanjutkan
            hapus = front; //node hapus sebagai front
            front = front->next; //pindahkan front ke node selanjutnya setelah node pertama
            delete hapus; //hapus node pertama
        } else { //jika tidak ada node selanjutnya setelah antrian pertama, maka lanjutkan
            front = back = NULL; //front dan back adalah NULL
        }
    }
}

//Fungsi untuk menghitung jumlah antrian
int HitungAntrian_184(){
    node *hitung; //inisialisasi node hitung
    hitung = front; //node hitung sebagai front
    int jumlah_184 = 0; //inisialisasi variabel jumlah_151
    while(hitung != NULL){ //jika node hitung bukan NULL, maka ulangi
        hitung = hitung->next; //node hitung berlanjut ke node selanjutnya
        jumlah_184++; //variabel jumlah_151 bertambah nilainya
    }
    return jumlah_184; //kembalikan nilai variabel jumlah_151
}

//Prosedur untuk menghapus seluruh antrian
void HapusAntrian_184(){
    node *hapus, *bantu; //inisialisasi node hapus dan node bantu
    bantu = front; //node bantu sebagai front
    while(bantu != NULL){ ///jika node bantu bukan NULL, maka ulangi
        hapus = bantu; //node hapus sama dengan node bantu
        bantu = bantu->next; //node selanjutnya dari posisi node bantu saat ini, juga merupakan node bantu
        delete hapus; //hapus seluruh node yang merupakan node bantu
    }
    front = back = NULL; //front dan back sebagai NULL
}

//Prosedur untuk menampilkan antrian
void LihatAntrian_184(){
    node *bantu; //inisialisasi node bantu
    bantu = front; //node bantu sebagai front
    if(isEmpty_184() == true){ //jika antrian kosong, maka tampilkan "Antrian kosong!" 
        cout << "Antrian kosong!" << endl; 
    } else if(isEmpty_184() == false){ //jika antrian tidak kosong, maka lanjutkan
        cout << "--- Antrian saat ini ---" << endl;  
        int NomorAntrian_184 = 1; //inisialisasi variabel NomorAntrian_151 dengan nilai 1
        while(bantu != NULL){ //jika node bantu bukan NULL, maka ulangi
            cout << NomorAntrian_184 << ". " << bantu->nama_184 << endl; //tampilkan antrian dengan nomor urutnya
            bantu = bantu->next; //node bantu berlanjut ke node selanjutnya
            NomorAntrian_184++; //nomor antrian bertambah
        }
    }
    cout << endl;
}

int main(){
    //Menambah 3 data nama kedalam antrian
    TambahData_184("Aura");
    TambahData_184("Dewi");
    TambahData_184("Kartika");

    //Menampilkan data yang sudah ditambahkan
    LihatAntrian_184();

    //Mengurangi data
    KurangiAntrian_184();

    //menampilkan data setelah dikurangi
    LihatAntrian_184();

    //Menghapus seluruh antrian
    HapusAntrian_184();

    //menampilkan data setelah dihapus
    LihatAntrian_184();
    
    return 0;
}
```

#### Hasil Output
![Output-unguided1-modul7](https://github.com/IkramIriansyah486/Structure-Data-Assignment/Modul 7/LAPRAK/Output-UnGuided1-Modul7.png)

program ini mendemonstrasikan operasi-operasi dasar pada struktur data Antrian (Queue) menggunakan Linked List, seperti enqueue (menambahkan data ke antrian), dequeue (mengeluarkan data dari depan antrian), menghitung jumlah data dalam antrian, dan mengosongkan antrian.


### 2) Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa


```C++
//IKRAM IRIANSYAH
//2311102184
#include<iostream>

using namespace std;

//Deklarasi struct node
struct node{ //node berisi variabel NamaMahasiswa_184, NIM_184, dan pointer next
    string NamaMahasiswa_184;
    string NIM_184;
    node *next;
};
    node *front; //Deklarasi node front
    node *back; //Deklarasi node back

//Prosedur inisialisasi node front dan back sebagai NULL
void Inisialisasi_184(){ 
    front = NULL;
    back = NULL;
}

//Fungsi untuk mengecek apakah queue kosong atau tidak
bool isEmpty_184(){
    if (front == 0){
        return true; //jika antrian pertama tidak ada, maka antrian kosong (kembalikan true)
    } else {
        return false; //jika antrian pertama ada, maka antrian tidak kosong (kembalikan false)
    }
}

//Prosedur untuk menambahkan data pada antrian
void TambahData_184(string Name_184, string NIM_184){
    node *baru = new node; //tambah node baru
    baru->NamaMahasiswa_184 = Name_184; //node baru berisi nama mahasiswa dan NIM 
    baru->NIM_184 = NIM_184; 
    baru->next = NULL; //next dari node baru adalah NULL
    if(isEmpty_184() == true){ //jika antrian kosong, maka lanjutkan
        front = back = baru; //node baru sebagai front dan back
        back->next = NULL; //node selanjutnya dari node baru adalah NULL
    } else if(isEmpty_184() == false){ //jika antrian tidak kosong, maka lanjutkan
        back->next = baru; //node baru sebagai node selanjutnya dari antrian yang sudah ada
        back = baru; //node baru sebagai back
    }
}

//Prosedur untuk mengurangi antrian (lanjut ke antrian selanjutnya)
void KurangiAntrian_184(){
    node *hapus; //inisialisasi node hapus
    if(isEmpty_184() == false){ //jika antrian tidak kosong, maka lanjutkan
        if(front->next != NULL){ //jika node selanjutnya setelah antrian pertama bukan NULL, maka lanjutkan
            hapus = front; //node hapus sebagai front
            front = front->next; //pindahkan front ke node selanjutnya setelah node pertama
            delete hapus; //hapus node pertama
        } else { //jika tidak ada node selanjutnya setelah antrian pertama, maka lanjutkan
            front = back = NULL; //front dan back adalah NULL
        }
    }
}

//Fungsi untuk menghitung jumlah antrian
int HitungAntrian_184(){
    node *hitung; //inisialisasi node hitung
    hitung = front; //node hitung sebagai front
    int jumlah_184 = 0; //inisialisasi variabel jumlah_184
    while(hitung != NULL){ //jika node hitung bukan NULL, maka ulangi
        hitung = hitung->next; //node hitung berlanjut ke node selanjutnya
        jumlah_184++; //variabel jumlah_184 bertambah nilainya
    }
    return jumlah_184; //kembalikan nilai variabel jumlah_151
}

//Prosedur untuk menghapus seluruh antrian
void HapusAntrian_184(){
    node *hapus, *bantu; //inisialisasi node hapus dan node bantu
    bantu = front; //node bantu sebagai front
    while(bantu != NULL){ ///jika node bantu bukan NULL, maka ulangi
        hapus = bantu; //node hapus sama dengan node bantu
        bantu = bantu->next; //node selanjutnya dari posisi node bantu saat ini, juga merupakan node bantu
        delete hapus; //hapus seluruh node yang merupakan node bantu
    }
    front = back = NULL; //front dan back sebagai NULL
}

//Prosedur untuk menampilkan antrian
void LihatAntrian_184(){
    node *bantu; //inisialisasi node bantu
    bantu = front; //node bantu sebagai front
    if(isEmpty_184() == true){ //jika antrian kosong, maka tampilkan "Antrian kosong!" 
        cout << "Antrian kosong!" << endl; 
    } else if(isEmpty_184() == false){ //jika antrian tidak kosong, maka lanjutkan
        cout << "--- Antrian Saat Ini ---" << endl; 
        int NomorAntrian_184 = 1; //inisialisasi variabel NomorAntrian_184 dengan nilai 1
        while(bantu != NULL){ //jika node bantu bukan NULL, maka ulangi
            cout << NomorAntrian_184 << ". " << bantu->NamaMahasiswa_184 << " - " << bantu->NIM_184 << endl; //tampilkan antrian dengan nomor urut, nama mahasiswa - NIM
            bantu = bantu->next; //node bantu berlanjut ke node selanjutnya
            NomorAntrian_184++; //nomor antrian bertambah
        }
    }
    cout << endl;
}

int main(){
    string NamaMahasiswa_184, NIM_184; 
    int Pilih_184; 
    char Yakin_184;
    MenuUtama:
    cout << "----- MENU ANTRIAN MAHASISWA -----" << endl; //Tampilan menu antrian mahasiswa
    cout << "1. Tambah antrian" << endl;
    cout << "2. Kurangi antrian" << endl;
    cout << "3. Hitung jumlah antrian" << endl;
    cout << "4. Hapus antrian" << endl;
    cout << "5. Lihat antrian" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilihan Anda [1-6] = ";
    cin >> Pilih_184;
    cout << endl;
    switch(Pilih_184){ //switch case berdasarkan pilihan user
        case 1: //jika user memilih 1, maka tampilkan menu tambah antrian
            cout << "--- Tambah Antrian ---" << endl;
            cout << "Masukkan nama mahasiswa = ";
            cin >> NamaMahasiswa_184;
            cout << "Masukkan NIM mahasiswa = ";
            cin >> NIM_184;
            TambahData_184(NamaMahasiswa_184, NIM_184); //pemanggilan prosedur TambahData_184 dengan parameter nama mahasiswa dan NIM
            cout << "Data mahasiswa telah tersimpan!" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2: //jika user memilih 2, maka tampilkan menu kurangi antrian
            cout << "--- Kurangi Antrian ---" << endl;
            if(isEmpty_184() == true){ //Jika antrian kosong, maka tampilkan "Antrian masih kosong!"
                cout << "Antrian masih kosong!" << endl;
            } else { //jika antrian tidak kosong, maka lanjutkan
                cout << "Apakah anda ingin mengurangi antrian (menghapus antrian pertama)? [y/n] = "; //validasi keyakinan user untuk mengurangi antrian
                cin >> Yakin_184;
                if(Yakin_184 == 'y' || Yakin_184 == 'Y'){ //jika user menginputkan y atau Y, maka lanjutkan
                    KurangiAntrian_184(); //pemanggilan prosedur KurangiAntrian_184()
                    cout << "Antrian telah dikurangi" << endl;
                } else if(Yakin_184 == 'n' || Yakin_184== 'Y'){ //jika user menginputkan n atau N, maka tampilkan "Aksi dibatalkan"
                    cout << "Aksi dibatalkan" << endl;
                }
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 3: //jika user memilih 3, maka tampilkan menu Hitung Jumlah Antrian
            cout << "--- Hitung Jumlah Antrian ---" << endl;
            cout << "Anrian yang tersimpan saat ini sebanyak " << HitungAntrian_184() << endl; //Pemanggilan fungsi HitungAntrian_184()
            cout << endl;
            goto MenuUtama;
            break;
        case 4: //jika user memilih 4, maka tampilkan menu hapus antrian
            cout << "--- Hapus Antrian ---" << endl;
            cout << "Apakah Anda yakin untuk menghapus seluruh antrian? [y/n] = "; //validasi keyakinan user untuk menghapus seluruh antrian
            cin >> Yakin_184;
            if(Yakin_184 == 'y' || Yakin_184 == 'Y'){ //jika user menginputkan y atau Y, maka lanjutkan
                HapusAntrian_184(); //pemanggilan prosedur HapusAntrian_151()
                cout << "Antrian telah dihapus" << endl;
            } else if(Yakin_184 == 'n' || Yakin_184 == 'N'){ //jika user menginputkan n atau N, maka tampilkan "Aksi dibatalkan"
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 5: //jika user memilih 5, maka tampilkan antrian
            LihatAntrian_184(); //pemanggilan prosedur LihatAntrian_151()
            cout << endl;
            goto MenuUtama;
            break;
        case 6:
            cout << "Anda keluar dari program" << endl;
            cout << endl;
            return 0;
            break;
        default: //jika user memilih selain 1-5, maka tampilkan "Pilihan yang anda masukkan salah!"
            cout << "Pilihan yang anda masukkan salah!" << endl;
            cout << endl;
            goto MenuUtama;
            break;
    }
}
```

#### Hasil Output
![Output-Unguided2](ttps://github.com/IkramIriansyah486/Structure-Data-Assignment/Modul 7/LAPRAK/Output-Unguided2-Modul7.png)

 program ini mendemonstrasikan operasi-operasi dasar pada struktur data Antrian (Queue) menggunakan Linked List, seperti enqueue (menambahkan data ke antrian), dequeue (mengeluarkan data dari depan antrian), menghitung jumlah data dalam antrian, dan mengosongkan antrian. Dan menambahkan unsur dari nama mahasiswa dan NIM sebagai inputannya.





## Kesimpulan
pada materi ini dapat di simpulkan bahwa queue memungkinkan pengelolaan aliran data atau objek secara terurut dan efisien, serta memfasilitasi berbagai aplikasi dan algoritma yang melibatkan antrian atau pemrosesan data berurutan.

## Referensi
[1] Joseph Teguh Santoso. (2021). "STRUKTUR DATA dan ALGORITMA (Bagian 1)". Penerbit Yayasan Prima Agus Teknik, 7(1), 1-333. Retrieved from https://penerbit.stekom.ac.id/index.php/yayasanpat/article/view/288. 
<br>[2] Triase, Triase. (2020). "Struktur Data: Diktat Edisi Revisi." (2020). Retrieved from http://repository.uinsu.ac.id/id/eprint/9717.
<br>[3] Sindar, Anita. (2019). "STRUKTUR DATA DAN ALGORITMA DENGAN C++". Serang: CV. AA. RIZKY.