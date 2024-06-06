
# <h1 align="center">Laporan Praktikum Modul 4 - Linked List Circular & Non-Circular</h1>
<p align="center">Ikram Iriansyah - 2311102184</p>

## Dasar Teori
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer. Suatu simpul atau node harus mempunyai satu atau lebih elemen struktur atau class yang berisi data. Pada suatu linked list, terdiri dari 2 elemen yaitu elemen pada awal list (head) dan elemen pada akhir list (tail). Berdasarkan cara hubungan antar elemennya, linked list terbagi menjadi 2 yaitu linked list circular dan linked list non-circular. 

### A. Linked List Non-Circular
Linked List Non-Circular merupakan linked list yang terdiri dari sejumlah node di mana setiap node memiliki pointer berikutnya ke elemen berikut. Node berikutnya dari node terakhir atau tail suatu linked list non-circular adalah NULL, yang menunjukkan akhir list[2]. Pada linked list non-circular tidak ada siklus atau lingkaran dalam struktur linked list. Dengan kata lain, tidak ada elemen yang menunjuk kembali ke elemen sebelumnya. Proses traversal dari awal hingga akhir linked list akan mencapai elemen terakhir dan kemudian berakhir. Operasi yang bisa dilakukan untuk memanipulasi linked list non-circular antara lain deklarasi node, inisialisasi node head dan tail, mengecek isi node, menambah node (depan, belakang, tengah), mengubah isi node (depan, belakang, tengah), menghapus node (depan, belakang, tengah), menghapus list, dan menampilkan list.
Berikut merupakan ilustrasi dari linked list non-circular.

- Ilustrasi Single Linked List Non-Circular (SLLNC)

![Ikram_Ilustrasi-SLLNC]()

Pada single linked list non-circular, suatu node terdiri dari data yang disimpan dan pointer next yang merujuk pada node selanjutnya. Proses ini berlanjut hingga node terakhir atau tail. Pointer next dari tail merujuk pada NULL atau kosong. 

- Ilustrasi Double Linked List Non-Circular (DLLNC)

![Ikram_Ilustrasi-DLLNC]()
Pada double linked list non-circular, suatu node terdiri dari data yang disimpan, pointer next yang merujuk pada node selanjutnya, dan pointer prev yang merujuk pada node sebelumnya. Pointer prev dari node pertama atau head merujuk pada NULL atau kosong dan pointer next dari node terakhir atau tail merujuk pada NULL atau kosong.

### B. Linked List Circular
Berbeda dengan linked list non-circular, linked list circular merupakan variasi dari linked list di mana elemen terakhir ditautkan ke elemen pertama, sehingga membentuk lingkaran melingkar[3]. Pada linked list circular, terdapat siklus dalam struktur linked list, di mana elemen terakhir menunjuk kembali ke elemen pertama, dan iterasi melalui linked list akan terus berputar mengelilingi siklus.
Pada linked list circular juga tidak ada elemen yang menunjuk ke null, karena seluruh linked list membentuk siklus tertutup. Sama seperti linked list non-circular, operasi yang bisa dilakukan untuk memanipulasi linked list circular antara lain deklarasi node, inisialisasi node head dan tail, mengecek isi node, menambah node (depan, belakang, tengah), mengubah isi node (depan, belakang, tengah), menghapus node (depan, belakang, tengah), menghapus list, dan menampilkan list.
Berikut merupakan ilustrasi dari linked list non-circular.

- Ilustrasi Single Linked List Circular (SLLC)

![Ikram_Ilustrasi-SLLC]()

Pada single linked list circular, suatu node terdiri dari data yang disimpan dan pointer next yang merujuk pada node selanjutnya. Proses ini berlanjut hingga node terakhir atau tail. Pointer next dari tail merujuk pada node pertama atau head.

- Ilustrasi Double Linked List Circular (DLLC)

![Ikram_Ilustrasi-DLLC]()

Pada double linked list circular, suatu node terdiri dari data yang disimpan, pointer next yang merujuk pada node selanjutnya, dan pointer prev yang merujuk pada node sebelumnya. Pointer prev dari node pertama atau head merujuk node terakhir atau tail dan pointer next dari node terakhir atau tail merujuk pada node pertama atau head. 

## Guided 

### 1. Linked List Non Circular
```C++
#include<iostream>

using namespace std;

//PROGRAM SINGLE LINKED LIST NON-CIRCULAR

//Deklarasi Struct node
struct node{
    int data;
    node *next;
};
    node *head;
    node *tail;

//inisialisasi node head & tail
void init(){
    head = NULL;
    tail = NULL;
}

//Pengecekan isi list
bool isEmpty(){
    if(head == NULL){
        return true;
    } else {
        return false;
    }
}

//Prosedur tambah depan
void TambahDepan(int nilai){
    node *baru = new node;
    baru->data = nilai;
    baru->next = NULL;
    if(isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
}

//Prosedur tambah belakang
void TambahBelakang(int nilai){
    node *baru = new node;
    baru->data = nilai;
    baru->next = NULL;
    if(isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

//Prosedur hitung list
int HitungList(){
    node *hitung;
    hitung = head;
    int jumlah = 0;
    while(hitung != NULL){
        hitung = hitung->next;
        jumlah++;
    }
    return jumlah;
}

//Prosedur tambah tengah
void TambahTengah(int nilai, int posisi){
    if(posisi < 1 || posisi > HitungList()){
        cout << "Node yang ingin ditambahkan diluar jangkauan" << endl;
    } else if(posisi == 1){
        cout << "Node yang ingin ditambahkan bukan di tengah" << endl;
    } else {
        node *bantu;
        node *baru = new node;
        baru->data = nilai;
        //transvering
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//Prosedur hapus depan
void HapusDepan(){
    node *hapus;
    if(isEmpty() == false){
        if(head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

//Prosedur hapus belakang
void HapusBelakang(){
    node *hapus, *bantu;
    if(isEmpty() == false){
        if(head != tail){
            hapus = tail;
            bantu = head;
            while(bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

//Prosedur Hapus tengah
void HapusTengah(int posisi){
    node *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > HitungList()){
        cout << "Posisi diluar jangkauan" << endl;
    } else if(posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        int nomor = 1;
        bantu = head;
        while(nomor <= posisi){
            if(nomor == posisi - 1){
                sebelum = bantu;
            } else if(nomor == posisi){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

//Prosedur ubah depan
void UbahDepan(int nilai){
    if(isEmpty() == 0){
        head->data = nilai;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Prosedur ubah tengah
void UbahTengah(int nilai, int posisi){
    node *bantu;
    if(isEmpty() == false){
        if(posisi < 1 || posisi > HitungList()){
            cout << "Posisi diluar jangkauan" << endl;
        } else if(posisi == 1){
            cout << "node bukan node tengah" << endl;
        } else {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = nilai;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Prosedur ubah belakang
void UbahBelakang(int nilai){
    if(isEmpty() == false){
        tail->data = nilai;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Prosedur hapus list
void Clearlist(){
    node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

//Prosedur tampilka list
void TampilList(){
    node *bantu;
    bantu = head;
    if(isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main(){
    init();
    TambahDepan(3);
    TampilList();
    TambahBelakang(5);
    TampilList();
    TambahDepan(2);
    TampilList();
    TambahDepan(1);
    TampilList();
    HapusDepan();
    TampilList;
    HapusBelakang();
    TampilList();
    TambahTengah(7, 2);
    TampilList();
    HapusTengah(2);
    TampilList();
    UbahDepan(1);
    TampilList();
    UbahBelakang(8);
    TampilList();
    UbahTengah(11, 2);
    TampilList();

    return 0;
}
```
#### Deskripsi Program
Kode diatas merupakan penerapan dari single linked list non-circular. Pada program ini terdapat beberapa fungsi dan prosedur yang digunakan untuk memanipulasi list antara lain menambah data, menghapus data, dan mengubah isi data. Berikut adalah nama-nama fungsi dan prosedur yang ada beserta kegunaannya.
- void init(); digunakan untuk inisialisasi node head dan tail linked list sebagai NULL.
- bool isEmpty(); digunakan untuk memeriksa apakah linked list kosong atau tidak.
- void TambahDepan(int nilai); digunakan untuk menambahkan elemen baru di depan linked list dengan nilai tertentu.
- void TambahBelakang(int nilai); digunakan untuk menambahkan elemen baru di belakang linked list dengan nilai tertentu.
- int HitungList(); digunakan untuk menghitung jumlah elemen dalam linked list.
- void TambahTengah(int nilai, int posisi); digunakan untuk menambahkan elemen baru di tengah linked list pada posisi tertentu.
- void HapusDepan(); digunakan untuk menghapus elemen pertama dari linked list.
- void HapusBelakang(); digunakan untuk menghapus elemen terakhir dari linked list.
- void HapusTengah(int posisi); digunakan untuk menghapus elemen pada posisi tertentu dari linked list.
- void UbahDepan(int nilai); digunakan untuk mengubah nilai elemen pertama dari linked list.
- void UbahTengah(int nilai, int posisi); digunakan untuk mengubah nilai elemen pada posisi tertentu dari linked list.
- void UbahBelakang(int nilai); digunakan untuk mengubah nilai elemen terakhir dari linked list.
- void Clearlist(); digunakan untuk menghapus seluruh elemen dari linked list.
- void TampilList(); digunakan untuk menampilkan seluruh elemen dalam linked list.
<br>Kemudian pada int main(), operasi-operasi ini dipanggil untuk menguji fungsi-fungsi tersebut dalam program.

### 2. Linked List Circular

```C++
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node{
    string data;
    Node* next;
};

Node* head, * tail, * baru, * bantu, * hapus;

//Inisialisasi node head & tail
void init(){
    head = NULL;
    tail = head;
}

//Pengecekan isi list
int isEmpty(){
    if (head == NULL){
        return 1; // true
    } else {
        return 0; // false
    }
}

//Buat Node Baru
void buatNode(string data){
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

//Hitung List
int hitungList(){
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

//Tambah Depan
void insertDepan(string data){
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1){
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head){
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

//Tambah Belakang
void insertBelakang(string data){
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1){
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head){
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

//Tambah Tengah
void insertTengah(string data, int posisi){
    if (isEmpty() == 1){
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//Hapus Depan
void hapusDepan(){
    if (isEmpty() == 0){
        hapus = head;
        tail = head;
        if (hapus->next == head){
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus){
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang(){
    if (isEmpty() == 0){
        hapus = head;
        tail = head;
        if (hapus->next == head){
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head){
                hapus = hapus->next;
            }
            while (tail->next != hapus){
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi){
    if (isEmpty() == 0){
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1){
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList(){
    if (head != NULL){
        hapus = head->next;
        while (hapus != head){
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil(){
    if (isEmpty() == 0){
        tail = head;
        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main(){
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    
    return 0;
}
```
#### Deskripsi Program
Kode diatas merupakan penerapan dari single linked list circular. Sama seperti guided 1, pada program ini terdapat beberapa fungsi dan prosedur yang digunakan untuk memanipulasi list antara lain menambah data, menghapus data, dan mengubah isi data. Berikut adalah nama-nama fungsi dan prosedur yang ada beserta kegunaannya.
- void init(); digunakan untuk inisialisasi node head dan tail linked list sebagai NULL.
- bool isEmpty(); digunakan untuk memeriksa apakah linked list kosong atau tidak.
- void buatNode(string data); digunakan untuk membuat node baru.
- int hitungList(); digunakan untuk menghitung jumlah elemen dalam linked list.
- void insertDepan(string data); digunakan untuk menambahkan elemen baru di depan linked list.
- void insertBelakang(string data); digunakan untuk menambahkan elemen baru di belakang linked list.
- void insertTengah(string data, int posisi); digunakan untuk menambahkan elemen baru di tengah linked list pada posisi tertentu.
- void hapusDepan(); digunakan untuk menghapus elemen pertama dari linked list.
- void hapusBelakang(); digunakan untuk menghapus elemen terakhir dari linked list.
- void hapusTengah(int posisi); digunakan untuk menghapus elemen pada posisi tertentu dari linked list.
- void clearList(); digunakan untuk menghapus seluruh elemen dari linked list.
- void tampil(); digunakan untuk menampilkan seluruh elemen dalam linked list.
<br>Kemudian pada int main(), operasi-operasi ini dipanggil untuk menguji fungsi-fungsi tersebut dalam program.

## Unguided 
Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user.

### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa! 
berikut contoh tampilan output dari nomor 1:

![Ikram_Soal-Unguided1-1]()
![Ikram_Soal-Unguided1-2]()

```C++
//IKRAM IRIANSYAH
//2311102184

#include<iostream>
#include<iomanip>

using namespace std;

//deklarasi struct node
struct node{
    string Nama_184;
    string NIM_184;
    node *next;
};
    node *head;
    node *tail;

//Inisialisasi node head & tail
void Inisialisasi_184(){
    head = NULL;
    tail = NULL;
}

//fungsi pengecekan
bool isEmpty_184(){
    if(head == NULL){
        return true;
    } else {
        return false;
    }
}

//prosedur hitung node
int HitungNode_184(){
    node *hitung = head;
    int jumlah_184 = 0;
    while (hitung != NULL){
        hitung = hitung->next;
        jumlah_184++;
    }
    return jumlah_184;
}

//prosedur tambah depan
void TambahDepan_184(string Name_184, string NIM_184){
    node *baru = new node;
    baru->Nama_184 = Name_184;
    baru->NIM_184 = NIM_184;
    baru->next = NULL;
    if(isEmpty_184() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
}

//prosedur tambah belakang
void TambahBelakang_184(string Name_184, string NIM_184){
    node *baru = new node;
    baru->Nama_184 = Name_184;
    baru->NIM_184 = NIM_184;
    baru->next = NULL;
    if(isEmpty_184() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

//prosedur tambah tengah
void TambahTengah_184(string Name_184, string NIM_184, int Position_184){
    if(Position_184 < 1 || Position_184 > HitungNode_184()){
        cout << "Node yang ingin ditambah diluar jangkauan!" << endl;
    } else if(Position_184 == 1){
        cout << "Node yang ingin ditambah bukan ditengah!"<< endl;
    } else {
        node *bantu = head;
        node *baru = new node;
        baru->Nama_184 = Name_184;
        baru->NIM_184 = NIM_184;
        int hitung_184 = 1;
        while(hitung_184 < Position_184 - 1){
            bantu = bantu->next;
            hitung_184++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//prosedur hapus depan
void HapusDepan_184(){
    node *hapus;
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

//fungsi tampil data depan
string TampilDepan_184(){
    string NamaYangDihapus_184 = "";
    if(isEmpty_184() == false){
        NamaYangDihapus_184 = head->Nama_184;
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_184;
}

//prosedur hapus belakang
void HapusBelakang_184(){
    node *hapus, *bantu;
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(head != tail){
            hapus = tail;
            bantu = head;
            while(bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

//fungsi tampil data belakang
string TampilBelakang_184(){
    string NamaYangDihapus_184 = "";
    if(isEmpty_184() == false){
        NamaYangDihapus_184 = tail->Nama_184;
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_184;
}


//prosedur hapus tengah
void HapusTengah_184(int posisi_184){
    if(posisi_184 < 1 || posisi_184 > HitungNode_184()){ 
        cout << "Posisi node yang akan dihapus offside" << endl;
    } else if(posisi_184 == 1){
        cout << "Node yang ingin dihapus bukan node tengah" << endl;
    } else {
        node *hapus, *bantu, *bantu2;
        bantu = head;
        int nomor_184 = 1;
        while(nomor_184 <= posisi_184){
            if(nomor_184 == posisi_184 - 1){
                bantu2 = bantu;
            } else if(nomor_184 == posisi_184){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor_184++; 
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

//fungsi tampil data tengah
string TampilTengah_184(int Position_184){
    string NamaYangDihapus_184 = "";
    node *tampil = head;
    node *bantu;
    if(isEmpty_184() == false){
        int nomor_184 = 1;
        while (nomor_184 <= Position_184 - 1){
            if(nomor_184 == Position_184 - 1){
                bantu = tampil;
            }
            tampil = tampil->next;
            nomor_184++;
        }
        bantu->next = tampil;
        NamaYangDihapus_184 = tampil->Nama_184;       
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_184;
}

//prosedur Ubah depan
void UbahDepan_184(string NewName_184, string NewNIM_184){
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        head->Nama_184 = NewName_184;
        head->NIM_184 = NewNIM_184;
    }
}

//prosedur ubah belakang
void UbahBelakang_184(string NewName_184, string NewNIM_184){
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        tail->Nama_184 = NewName_184;
        tail->NIM_184 = NewNIM_184;
    }
}

//prosedur ubah tengah
void UbahTengah_184(string NewName_184, string NewNIM_184, int Position_184){
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(Position_184 < 1 || Position_184 > HitungNode_184()){
            cout << "Node yang ingin diubah diluar jangkauan!" << endl;
        } else if(Position_184 == 1){
            cout << "Node yang ingin diubah bukan ditengah!" << endl;
        } else {
            node *bantu;
            bantu = head;
            int nomor_184 = 1;
            while(nomor_184 < Position_184){
                bantu = bantu->next;
                nomor_184++;
            }
           bantu->Nama_184 = NewName_184;
           bantu->NIM_184 = NewNIM_184;
        }
    }
}

//prosedur hapus list
void HapusList_184(){
    node *hapus;
    node *bantu = head;
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        while(bantu != NULL){
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;   
        }
        head = tail = NULL;
    }
}

//prosedur tampil list
void TampilList_184(){
    node *bantu = head;
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        cout << "------------------------------------------" << endl;
        cout << "|         NAMA         |       NIM       |" << endl;
        cout << "------------------------------------------" << endl;
        while(bantu != NULL){
            cout << "|" << setw(22) << left << bantu->Nama_184 << "|" << setw(17) << left << bantu->NIM_184 << "|" << endl;
            bantu = bantu->next;
        }
        cout << "------------------------------------------" << endl;
    }
}

int main(){
    int Position_184, Choose_184;
    string Name_184, OldName_184, NIM_184, OldNIM_184;
    char Yakin_184;
    Inisialisasi_184();
    MenuUtama:
    cout << "------- PROGRAM SINGLE LINKED LIST -------" << endl;
    cout << "-------------- NON-CIRCULAR --------------" << endl; 
    cout << "| 1. TAMBAH DEPAN                        |" << endl;
    cout << "| Menambahkan data pada awal list        |" << endl;
    cout << "| 2. TAMBAH BELAKANG                     |" << endl;
    cout << "| Menambahkan data pada akhir list       |" << endl;
    cout << "| 3. TAMBAH TENGAH                       |" << endl;
    cout << "| Menambahkan data pada urutan tertentu  |" << endl;
    cout << "| 4. UBAH DEPAN                          |" << endl;
    cout << "| Mengubah data pada urutan pertama      |" << endl;
    cout << "| 5. UBAH BELAKANG                       |" << endl;
    cout << "| Mengubah data pada urutan terakhir     |" << endl;
    cout << "| 6. UBAH TENGAH                         |" << endl;
    cout << "| Mengubah data pada urutan tertentu     |" << endl;
    cout << "| 7. HAPUS DEPAN                         |" << endl;
    cout << "| Menghapus data urutan pertama          |" << endl;
    cout << "| 8. HAPUS BELAKANG                      |" << endl;
    cout << "| Menghapus data urutan terakhir         |" << endl;
    cout << "| 9. HAPUS TENGAH                        |" << endl;
    cout << "| Menghapus data urutan tertentu         |" << endl;
    cout << "| 10. HAPUS LIST                         |" << endl;
    cout << "| Menghapus seluruh data                 |" << endl;
    cout << "| 11. TAMPILKAN                          |" << endl;
    cout << "| Menampilkan list data yang tersimpan   |" << endl;
    cout << "| 0. KELUAR                              |" << endl;
    cout << "| Keluar dari program                    |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Masukkan pilihan anda = ";
    cin >> Choose_184;
    cout << endl;
    switch(Choose_184){
        case 1:
            cout << "-------------- TAMBAH DEPAN --------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_184;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_184;
            TambahDepan_184(Name_184, NIM_184);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2:
            cout << "------------ TAMBAH BELAKANG -------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_184;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_184;
            TambahBelakang_184(Name_184, NIM_184);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 3:
            cout << "------------- TAMBAH TENGAH --------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_184;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_184;
            cout << "Posisi data = ";
            cin >> Position_184;
            TambahTengah_184(Name_184, NIM_184, Position_184);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 4:
            cout << "----------------- UBAH DEPAN -----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_184;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_184;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_184;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_184;
            UbahDepan_184(Name_184, NIM_184);
            cout << "Data mahasiswa " << OldName_184 << " (" << OldNIM_184 << ") telah diganti dengan data mahasiswa baru " << Name_184 << " (" << NIM_184 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 5:
            cout << "--------------- UBAH BELAKANG ----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_184;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_184;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_184;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_184;
            UbahBelakang_184(Name_184, NIM_184);
            cout << "Data mahasiswa " << OldName_184 << " (" << OldNIM_184 << ") telah diganti dengan data mahasiswa baru " << Name_184 << " (" << NIM_184 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 6:
            cout << "---------------- UBAH TENGAH -----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_184;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_184;
            cout << "Posisi data lama pada list = ";
            cin >> Position_184;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_184;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_184;
            UbahTengah_184(Name_184, NIM_184, Position_184);
            cout << "Data mahasiswa " << OldName_184 << " (" << OldNIM_184 << ") pada posisi ke-" << Position_184 << " telah diganti dengan data mahasiswa baru " << Name_184 << " (" << NIM_184 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 7:
            cout << "---------------- HAPUS DEPAN -----------------" << endl;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilDepan_184() << "? [y/n] = ";
            cin >> Yakin_184;
            if(Yakin_184 == 'y' || Yakin_184 == 'Y'){
                HapusDepan_184();
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_184 == 'n' || Yakin_184 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 8:
            cout << "--------------- HAPUS BELAKANG ---------------" << endl;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilBelakang_184() << "? [y/n] = ";
            cin >> Yakin_184;
            if(Yakin_184 == 'y' || Yakin_184 == 'Y'){
                HapusBelakang_184();
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_184 == 'n' || Yakin_184 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 9:
            cout << "---------------- HAPUS TENGAH ----------------" << endl;
            cout << "Masukkan posisi data yang ingin dihapus = ";
            cin >> Position_184;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilTengah_184(Position_184) << "? [y/n] = ";
            cin >> Yakin_184;
            if(Yakin_184 == 'y' || Yakin_184 == 'Y'){
                HapusTengah_184(Position_184);
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_184 == 'n' || Yakin_184 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 10:
            cout << "----------------- HAPUS LIST -----------------" << endl;
            cout << "Apakah anda yakin untuk menghapus semua data? [y/n] = ";
            cin >> Yakin_184;
            if(Yakin_184 == 'y' || Yakin_184 == 'Y'){
                HapusList_184();
                cout << "List telah terhapus" << endl; 
            } else if(Yakin_184 == 'n' || Yakin_184 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 11:
            cout << "-------------- TAMPIL LIST ---------------" << endl;
            TampilList_184();
            cout << endl;
            goto MenuUtama;
            break;
        case 0:
            cout << "Anda keluar dari program" << endl;
            return 0;
            break;
        default:
            cout << "Pilihan anda tidak tersedia" << endl;
            cout << endl;
            goto MenuUtama;
            break;
    }
}
```
#### Output:

##### Output 1 (Tampilan Menu Utama)
![Ikram_Output-Unguided1-1]()

##### Output 2 (Tampilan Menu Tambah Depan)
![Ikram_Output-Unguided1-2]()

##### Output 3 (Tampilan Menu Tambah Belakang)
![Ikram_Output-Unguided1-3]()

##### Output 4 (Tampilan Menu Tambah Tengah)
![Ikram_Output-Unguided1-4]()

##### Output 5 (Tampilan Menu Ubah Depan)
![Ikram_Output-Unguided1-5]()

##### Output 6 (Tampilan Menu Ubah Belakang)
![Ikram_Output-Unguided1-6]()

##### Output 7 (Tampilan Menu Ubah Tengah)
![Ikram_Output-Unguided1-7]()

##### Output 8 (Tampilan Menu Hapus Depan)
![Ikram_Output-Unguided1-8]()

##### Output 9 (Tampilan Menu Hapus Belakang)
![Ikram_Output-Unguided1-9]()

##### Output 10 (Tampilan Menu Hapus Tengah)
![Ikram_Output-Unguided1-10]()

##### Output 11 (Tampilan Menu Hapus List)
![Ikram_Output-Unguided1-11]()

##### Output 12 (Tampilan Menu Tampil List)
![Ikram_Output-Unguided1-12]()

##### Output 13 (Tampilan Menu Keluar)
![Ikram_Output-Unguided1-13]()

### Deskripsi Program
Kode diatas merupakan program implementasi dari single linked list non-circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. Pada program ini terdapat beberapa fungsi dan prosedur yang digunakan untuk memanipulasi list, antara lain :
- void Inisialisasi_151(); digunakan untuk inisialisasi node head & tail sebagai NULL.
- bool isEmpty_151(); digunakan untuk mengecek isi list kosong atau tidak.
- int HitungNode_151(); digunakan untuk menghitung jumlah node yang tersimpan.
- void TambahDepan_151(string Name_151, string NIM_151); digunakan untuk menambah node pada awal list.
- void TambahBelakang_151(string Name_151, string NIM_151); digunakan untun menambah node pada akhir list.
- void TambahTengah_151(string Name_151, string NIM_151, int Position_151); digunakan untuk menambah node pada urutan tertentu.
- void HapusDepan_151(); digunakan untuk menghapus node pertama pada list.
- string TampilDepan_151(); digunakan untuk menampilkan data pertama pada list.
- void HapusBelakang_151(); digunakan untuk menghapus node terakhir pada list.
- string TampilBelakang_151(); digunakan untuk menampilkan data terakhir pada list.
- void HapusTengah_151(int posisi_151); digunakan untuk menghapus node urutan tertentu pada list.
- string TampilTengah_151(int Position_151); digunakan untuk menampilkan data urutan tertentu pada list.
- void UbahDepan_151(string NewName_151, string NewNIM_151); digunakan untuk mengubah isi data pada urutan pertama.
- void UbahBelakang_151(string NewName_151, string NewNIM_151); digunakan untuk mengubah isi data pada urutan terakhir.
- void UbahTengah_151(string NewName_151, string NewNIM_151, int Position_151); digunakan untuk mengubah isi data pada urutan tertentu.
- void HapusList_151(); digunakan untuk menghapus list yang tersimpan.
- void TampilList_151(); digunakan untuk menampilkan list yang tersimpan.
<br>Kemudian pada int main() terdapat percabangan switchcase yang setiap menunya merepresentasikan kegunaan fungsi dan prosedur yang ada.  

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan! (Gunakan insert depan, belakang atau tengah)

![Ikram_Soal-Unguided2]()

```C++
//IKRAM IRIANSYAH
//2311102184

#include<iostream>
#include<iomanip>

using namespace std;

//deklarasi struct node
struct node{
    string Nama_184;
    string NIM_184;
    node *next;
};
    node *head;
    node *tail;

//Inisialisasi node head & tail
void Inisialisasi_184(){
    head = NULL;
    tail = NULL;
}

//fungsi pengecekan
bool isEmpty_184(){
    if(head == NULL){
        return true;
    } else {
        return false;
    }
}

//prosedur hitung node
int HitungNode_184(){
    node *hitung = head;
    int jumlah_184 = 0;
    while (hitung != NULL){
        hitung = hitung->next;
        jumlah_184++;
    }
    return jumlah_184;
}

//prosedur tambah depan
void TambahDepan_184(string Name_184, string NIM_184){
    node *baru = new node;
    baru->Nama_184 = Name_184;
    baru->NIM_184 = NIM_184;
    baru->next = NULL;
    if(isEmpty_184() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
}

//prosedur tambah belakang
void TambahBelakang_184(string Name_184, string NIM_184){
    node *baru = new node;
    baru->Nama_184 = Name_184;
    baru->NIM_184 = NIM_184;
    baru->next = NULL;
    if(isEmpty_184() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

//prosedur tambah tengah
void TambahTengah_184(string Name_184, string NIM_184, int Position_184){
    if(Position_184 < 1 || Position_184 > HitungNode_184()){
        cout << "Node yang ingin ditambah diluar jangkauan!" << endl;
    } else if(Position_184 == 1){
        cout << "Node yang ingin ditambah bukan ditengah!"<< endl;
    } else {
        node *bantu = head;
        node *baru = new node;
        baru->Nama_184 = Name_184;
        baru->NIM_184 = NIM_184;
        int hitung_184 = 1;
        while(hitung_184 < Position_184 - 1){
            bantu = bantu->next;
            hitung_184++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//prosedur hapus depan
void HapusDepan_184(){
    node *hapus;
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

//fungsi tampil data depan
string TampilDepan_184(){
    string NamaYangDihapus_184 = "";
    if(isEmpty_184() == false){
        NamaYangDihapus_184 = head->Nama_184;
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_184;
}

//prosedur hapus belakang
void HapusBelakang_184(){
    node *hapus, *bantu;
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(head != tail){
            hapus = tail;
            bantu = head;
            while(bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

//fungsi tampil data belakang
string TampilBelakang_184(){
    string NamaYangDihapus_184 = "";
    if(isEmpty_184() == false){
        NamaYangDihapus_184 = tail->Nama_184;
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_184;
}


//prosedur hapus tengah
void HapusTengah_184(int posisi_184){
    if(posisi_184 < 1 || posisi_184 > HitungNode_184()){ 
        cout << "Posisi node yang akan dihapus offside" << endl;
    } else if(posisi_184 == 1){
        cout << "Node yang ingin dihapus bukan node tengah" << endl;
    } else {
        node *hapus, *bantu, *bantu2;
        bantu = head;
        int nomor_184 = 1;
        while(nomor_184 <= posisi_184){
            if(nomor_184 == posisi_184 - 1){
                bantu2 = bantu;
            } else if(nomor_184 == posisi_184){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor_184++; 
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

//fungsi tampil data tengah
string TampilTengah_184(int Position_184){
    string NamaYangDihapus_184 = "";
    node *tampil = head;
    node *bantu;
    if(isEmpty_184() == false){
        int nomor_184 = 1;
        while (nomor_184 <= Position_184 - 1){
            if(nomor_184 == Position_184 - 1){
                bantu = tampil;
            }
            tampil = tampil->next;
            nomor_184++;
        }
        bantu->next = tampil;
        NamaYangDihapus_184 = tampil->Nama_184;       
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_184;
}

//prosedur Ubah depan
void UbahDepan_184(string NewName_184, string NewNIM_184){
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        head->Nama_184 = NewName_184;
        head->NIM_184 = NewNIM_184;
    }
}

//prosedur ubah belakang
void UbahBelakang_184(string NewName_184, string NewNIM_184){
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        tail->Nama_184 = NewName_184;
        tail->NIM_184 = NewNIM_184;
    }
}

//prosedur ubah tengah
void UbahTengah_184(string NewName_184, string NewNIM_184, int Position_184){
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(Position_184 < 1 || Position_184 > HitungNode_184()){
            cout << "Node yang ingin diubah diluar jangkauan!" << endl;
        } else if(Position_184 == 1){
            cout << "Node yang ingin diubah bukan ditengah!" << endl;
        } else {
            node *bantu;
            bantu = head;
            int nomor_184 = 1;
            while(nomor_184 < Position_184){
                bantu = bantu->next;
                nomor_184++;
            }
           bantu->Nama_184 = NewName_184;
           bantu->NIM_184 = NewNIM_184;
        }
    }
}

//prosedur hapus list
void HapusList_184(){
    node *hapus;
    node *bantu = head;
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        while(bantu != NULL){
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;   
        }
        head = tail = NULL;
    }
}

//prosedur tampil list
void TampilList_184(){
    node *bantu = head;
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        cout << "------------------------------------------" << endl;
        cout << "|         NAMA         |       NIM       |" << endl;
        cout << "------------------------------------------" << endl;
        while(bantu != NULL){
            cout << "|" << setw(22) << left << bantu->Nama_184 << "|" << setw(17) << left << bantu->NIM_184 << "|" << endl;
            bantu = bantu->next;
        }
        cout << "------------------------------------------" << endl;
    }
}

int main(){
    int Position_184, Choose_184;
    string Name_184, OldName_184, NIM_184, OldNIM_184;
    char Yakin_184;
    Inisialisasi_184();
    MenuUtama:
    cout << "------- PROGRAM SINGLE LINKED LIST -------" << endl;
    cout << "-------------- NON-CIRCULAR --------------" << endl; 
    cout << "| 1. TAMBAH DEPAN                        |" << endl;
    cout << "| Menambahkan data pada awal list        |" << endl;
    cout << "| 2. TAMBAH BELAKANG                     |" << endl;
    cout << "| Menambahkan data pada akhir list       |" << endl;
    cout << "| 3. TAMBAH TENGAH                       |" << endl;
    cout << "| Menambahkan data pada urutan tertentu  |" << endl;
    cout << "| 4. UBAH DEPAN                          |" << endl;
    cout << "| Mengubah data pada urutan pertama      |" << endl;
    cout << "| 5. UBAH BELAKANG                       |" << endl;
    cout << "| Mengubah data pada urutan terakhir     |" << endl;
    cout << "| 6. UBAH TENGAH                         |" << endl;
    cout << "| Mengubah data pada urutan tertentu     |" << endl;
    cout << "| 7. HAPUS DEPAN                         |" << endl;
    cout << "| Menghapus data urutan pertama          |" << endl;
    cout << "| 8. HAPUS BELAKANG                      |" << endl;
    cout << "| Menghapus data urutan terakhir         |" << endl;
    cout << "| 9. HAPUS TENGAH                        |" << endl;
    cout << "| Menghapus data urutan tertentu         |" << endl;
    cout << "| 10. HAPUS LIST                         |" << endl;
    cout << "| Menghapus seluruh data                 |" << endl;
    cout << "| 11. TAMPILKAN                          |" << endl;
    cout << "| Menampilkan list data yang tersimpan   |" << endl;
    cout << "| 0. KELUAR                              |" << endl;
    cout << "| Keluar dari program                    |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Masukkan pilihan anda = ";
    cin >> Choose_184;
    cout << endl;
    switch(Choose_184){
        case 1:
            cout << "-------------- TAMBAH DEPAN --------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_184;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_184;
            TambahDepan_184(Name_184, NIM_184);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2:
            cout << "------------ TAMBAH BELAKANG -------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_184;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_184;
            TambahBelakang_184(Name_184, NIM_184);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 3:
            cout << "------------- TAMBAH TENGAH --------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_184;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_184;
            cout << "Posisi data = ";
            cin >> Position_184;
            TambahTengah_184(Name_184, NIM_184, Position_184);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 4:
            cout << "----------------- UBAH DEPAN -----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_184;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_184;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_184;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_184;
            UbahDepan_184(Name_184, NIM_184);
            cout << "Data mahasiswa " << OldName_184 << " (" << OldNIM_184 << ") telah diganti dengan data mahasiswa baru " << Name_184 << " (" << NIM_184 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 5:
            cout << "--------------- UBAH BELAKANG ----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_184;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_184;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_184;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_184;
            UbahBelakang_184(Name_184, NIM_184);
            cout << "Data mahasiswa " << OldName_184 << " (" << OldNIM_184 << ") telah diganti dengan data mahasiswa baru " << Name_184 << " (" << NIM_184 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 6:
            cout << "---------------- UBAH TENGAH -----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_184;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_184;
            cout << "Posisi data lama pada list = ";
            cin >> Position_184;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_184;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_184;
            UbahTengah_184(Name_184, NIM_184, Position_184);
            cout << "Data mahasiswa " << OldName_184 << " (" << OldNIM_184 << ") pada posisi ke-" << Position_184 << " telah diganti dengan data mahasiswa baru " << Name_184 << " (" << NIM_184 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 7:
            cout << "---------------- HAPUS DEPAN -----------------" << endl;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilDepan_184() << "? [y/n] = ";
            cin >> Yakin_184;
            if(Yakin_184 == 'y' || Yakin_184 == 'Y'){
                HapusDepan_184();
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_184 == 'n' || Yakin_184 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 8:
            cout << "--------------- HAPUS BELAKANG ---------------" << endl;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilBelakang_184() << "? [y/n] = ";
            cin >> Yakin_184;
            if(Yakin_184 == 'y' || Yakin_184 == 'Y'){
                HapusBelakang_184();
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_184 == 'n' || Yakin_184 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 9:
            cout << "---------------- HAPUS TENGAH ----------------" << endl;
            cout << "Masukkan posisi data yang ingin dihapus = ";
            cin >> Position_184;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilTengah_184(Position_184) << "? [y/n] = ";
            cin >> Yakin_184;
            if(Yakin_184 == 'y' || Yakin_184 == 'Y'){
                HapusTengah_184(Position_184);
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_184 == 'n' || Yakin_184 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 10:
            cout << "----------------- HAPUS LIST -----------------" << endl;
            cout << "Apakah anda yakin untuk menghapus semua data? [y/n] = ";
            cin >> Yakin_184;
            if(Yakin_184 == 'y' || Yakin_184 == 'Y'){
                HapusList_184();
                cout << "List telah terhapus" << endl; 
            } else if(Yakin_184 == 'n' || Yakin_184 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 11:
            cout << "-------------- TAMPIL LIST ---------------" << endl;
            TampilList_184();
            cout << endl;
            goto MenuUtama;
            break;
        case 0:
            cout << "Anda keluar dari program" << endl;
            return 0;
            break;
        default:
            cout << "Pilihan anda tidak tersedia" << endl;
            cout << endl;
            goto MenuUtama;
            break;
    }
}
```
#### Output:

##### Output 1 (Tambah Data Jawad)
![Ikram_Output-Unguided2-1]()

##### Output 2 (Tambah Data Nama Sendiri (Ikram))
![Ikram_Output-Unguided2-2]()

##### Output 3 (Tambah Data Farrel)
![Ikram_Output-Unguided2-3]()

##### Output 4 (Tambah Data Denis)
![Ikram_Output-Unguided2-4](h)

##### Output 5 (Tambah Data Anis)
![Ikram_Output-Unguided2-5]()

##### Output 6 (Tambah Data Bowo)
![Ikram_Output-Unguided2-6]()

##### Output 7 (Tambah Data Gahar)
![Ikram_Output-Unguided2-7]()

##### Output 8 (Tambah Data Udin)
![Ikram_Output-Unguided2-8]()

##### Output 9 (Tambah Data Ucok)
![Ikram_Output-Unguided2-9]()

##### Output 10 (Tambah Data Budi)
![Ikram_Output-Unguided2-10]()

##### Output 11 (Tampilkan Semua Data)
![Ikram_Output-Unguided2-11]()

#### Deskripsi Program
Program pada unguided 2 merupakan program yang sama dengan yang ada pada unguided 1. Pada unguided 2 praktikan diminta untuk menginputkan atau menambahkan beberapa data nama mahasiswa dan NIM menggunakan prosedur TambahDepan_184(), TambahBelakang_184(), ataupun TambahTengah_184(). Pada urutan kedua, praktikan diminta mengisi data nama dan NIM masing-masing. Setelah itu praktikan diminta untuk menampilkan semua data yang telah diinputkan menggunakan prosedur TampilList_184(). 

### 3. Lakukan perintah berikut!

![Ikram_Soal-Unguided3]()

```C++
//IKRAM IRIANSYAH
//2311102184

#include<iostream>
#include<iomanip>

using namespace std;

//deklarasi struct node
struct node{
    string Nama_184;
    string NIM_184;
    node *next;
};
    node *head;
    node *tail;

//Inisialisasi node head & tail
void Inisialisasi_184(){
    head = NULL;
    tail = NULL;
}

//fungsi pengecekan
bool isEmpty_184(){
    if(head == NULL){
        return true;
    } else {
        return false;
    }
}

//prosedur hitung node
int HitungNode_184(){
    node *hitung = head;
    int jumlah_184 = 0;
    while (hitung != NULL){
        hitung = hitung->next;
        jumlah_184++;
    }
    return jumlah_184;
}

//prosedur tambah depan
void TambahDepan_184(string Name_184, string NIM_184){
    node *baru = new node;
    baru->Nama_184 = Name_184;
    baru->NIM_184 = NIM_184;
    baru->next = NULL;
    if(isEmpty_184() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
}

//prosedur tambah belakang
void TambahBelakang_184(string Name_184, string NIM_184){
    node *baru = new node;
    baru->Nama_184 = Name_184;
    baru->NIM_184 = NIM_184;
    baru->next = NULL;
    if(isEmpty_184() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

//prosedur tambah tengah
void TambahTengah_184(string Name_184, string NIM_184, int Position_184){
    if(Position_184 < 1 || Position_184 > HitungNode_184()){
        cout << "Node yang ingin ditambah diluar jangkauan!" << endl;
    } else if(Position_184 == 1){
        cout << "Node yang ingin ditambah bukan ditengah!"<< endl;
    } else {
        node *bantu = head;
        node *baru = new node;
        baru->Nama_184 = Name_184;
        baru->NIM_184 = NIM_184;
        int hitung_184 = 1;
        while(hitung_184 < Position_184 - 1){
            bantu = bantu->next;
            hitung_184++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//prosedur hapus depan
void HapusDepan_184(){
    node *hapus;
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

//fungsi tampil data depan
string TampilDepan_184(){
    string NamaYangDihapus_184 = "";
    if(isEmpty_184() == false){
        NamaYangDihapus_184 = head->Nama_184;
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_184;
}

//prosedur hapus belakang
void HapusBelakang_184(){
    node *hapus, *bantu;
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(head != tail){
            hapus = tail;
            bantu = head;
            while(bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

//fungsi tampil data belakang
string TampilBelakang_184(){
    string NamaYangDihapus_184 = "";
    if(isEmpty_184() == false){
        NamaYangDihapus_184 = tail->Nama_184;
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_184;
}


//prosedur hapus tengah
void HapusTengah_184(int posisi_184){
    if(posisi_184 < 1 || posisi_184 > HitungNode_184()){ 
        cout << "Posisi node yang akan dihapus offside" << endl;
    } else if(posisi_184 == 1){
        cout << "Node yang ingin dihapus bukan node tengah" << endl;
    } else {
        node *hapus, *bantu, *bantu2;
        bantu = head;
        int nomor_184 = 1;
        while(nomor_184 <= posisi_184){
            if(nomor_184 == posisi_184 - 1){
                bantu2 = bantu;
            } else if(nomor_184 == posisi_184){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor_184++; 
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

//fungsi tampil data tengah
string TampilTengah_184(int Position_184){
    string NamaYangDihapus_184 = "";
    node *tampil = head;
    node *bantu;
    if(isEmpty_184() == false){
        int nomor_184 = 1;
        while (nomor_184 <= Position_184 - 1){
            if(nomor_184 == Position_184 - 1){
                bantu = tampil;
            }
            tampil = tampil->next;
            nomor_184++;
        }
        bantu->next = tampil;
        NamaYangDihapus_184 = tampil->Nama_184;       
    } else {
        cout << "List masih kosong" << endl;
    }
    return NamaYangDihapus_184;
}

//prosedur Ubah depan
void UbahDepan_184(string NewName_184, string NewNIM_184){
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        head->Nama_184 = NewName_184;
        head->NIM_184 = NewNIM_184;
    }
}

//prosedur ubah belakang
void UbahBelakang_184(string NewName_184, string NewNIM_184){
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        tail->Nama_184 = NewName_184;
        tail->NIM_184 = NewNIM_184;
    }
}

//prosedur ubah tengah
void UbahTengah_184(string NewName_184, string NewNIM_184, int Position_184){
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        if(Position_184 < 1 || Position_184 > HitungNode_184()){
            cout << "Node yang ingin diubah diluar jangkauan!" << endl;
        } else if(Position_184 == 1){
            cout << "Node yang ingin diubah bukan ditengah!" << endl;
        } else {
            node *bantu;
            bantu = head;
            int nomor_184 = 1;
            while(nomor_184 < Position_184){
                bantu = bantu->next;
                nomor_184++;
            }
           bantu->Nama_184 = NewName_184;
           bantu->NIM_184 = NewNIM_184;
        }
    }
}

//prosedur hapus list
void HapusList_184(){
    node *hapus;
    node *bantu = head;
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        while(bantu != NULL){
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;   
        }
        head = tail = NULL;
    }
}

//prosedur tampil list
void TampilList_184(){
    node *bantu = head;
    if(isEmpty_184() == true){
        cout << "List masih kosong!" << endl;
    } else {
        cout << "------------------------------------------" << endl;
        cout << "|         NAMA         |       NIM       |" << endl;
        cout << "------------------------------------------" << endl;
        while(bantu != NULL){
            cout << "|" << setw(22) << left << bantu->Nama_184 << "|" << setw(17) << left << bantu->NIM_184 << "|" << endl;
            bantu = bantu->next;
        }
        cout << "------------------------------------------" << endl;
    }
}

int main(){
    int Position_184, Choose_184;
    string Name_184, OldName_184, NIM_184, OldNIM_184;
    char Yakin_184;
    Inisialisasi_184();
    MenuUtama:
    cout << "------- PROGRAM SINGLE LINKED LIST -------" << endl;
    cout << "-------------- NON-CIRCULAR --------------" << endl; 
    cout << "| 1. TAMBAH DEPAN                        |" << endl;
    cout << "| Menambahkan data pada awal list        |" << endl;
    cout << "| 2. TAMBAH BELAKANG                     |" << endl;
    cout << "| Menambahkan data pada akhir list       |" << endl;
    cout << "| 3. TAMBAH TENGAH                       |" << endl;
    cout << "| Menambahkan data pada urutan tertentu  |" << endl;
    cout << "| 4. UBAH DEPAN                          |" << endl;
    cout << "| Mengubah data pada urutan pertama      |" << endl;
    cout << "| 5. UBAH BELAKANG                       |" << endl;
    cout << "| Mengubah data pada urutan terakhir     |" << endl;
    cout << "| 6. UBAH TENGAH                         |" << endl;
    cout << "| Mengubah data pada urutan tertentu     |" << endl;
    cout << "| 7. HAPUS DEPAN                         |" << endl;
    cout << "| Menghapus data urutan pertama          |" << endl;
    cout << "| 8. HAPUS BELAKANG                      |" << endl;
    cout << "| Menghapus data urutan terakhir         |" << endl;
    cout << "| 9. HAPUS TENGAH                        |" << endl;
    cout << "| Menghapus data urutan tertentu         |" << endl;
    cout << "| 10. HAPUS LIST                         |" << endl;
    cout << "| Menghapus seluruh data                 |" << endl;
    cout << "| 11. TAMPILKAN                          |" << endl;
    cout << "| Menampilkan list data yang tersimpan   |" << endl;
    cout << "| 0. KELUAR                              |" << endl;
    cout << "| Keluar dari program                    |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Masukkan pilihan anda = ";
    cin >> Choose_184;
    cout << endl;
    switch(Choose_184){
        case 1:
            cout << "-------------- TAMBAH DEPAN --------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_184;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_184;
            TambahDepan_184(Name_184, NIM_184);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2:
            cout << "------------ TAMBAH BELAKANG -------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_184;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_184;
            TambahBelakang_184(Name_184, NIM_184);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 3:
            cout << "------------- TAMBAH TENGAH --------------" << endl;
            cout << "-- Masukkan data yang ingin ditambahkan --" << endl;
            cout << "Nama Mahasiswa = ";
            cin >> Name_184;
            cout << "NIM Mahasiswa = ";
            cin >> NIM_184;
            cout << "Posisi data = ";
            cin >> Position_184;
            TambahTengah_184(Name_184, NIM_184, Position_184);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 4:
            cout << "----------------- UBAH DEPAN -----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_184;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_184;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_184;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_184;
            UbahDepan_184(Name_184, NIM_184);
            cout << "Data mahasiswa " << OldName_184 << " (" << OldNIM_184 << ") telah diganti dengan data mahasiswa baru " << Name_184 << " (" << NIM_184 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 5:
            cout << "--------------- UBAH BELAKANG ----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_184;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_184;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_184;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_184;
            UbahBelakang_184(Name_184, NIM_184);
            cout << "Data mahasiswa " << OldName_184 << " (" << OldNIM_184 << ") telah diganti dengan data mahasiswa baru " << Name_184 << " (" << NIM_184 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 6:
            cout << "---------------- UBAH TENGAH -----------------" << endl;
            cout << "------- Masukkan data yang akan diubah -------" << endl;
            cout << "--- Data Lama ---" << endl;
            cout << "Nama Mahasiswa lama = ";
            cin >> OldName_184;
            cout << "NIM Mahasiswa lama = ";
            cin >> OldNIM_184;
            cout << "Posisi data lama pada list = ";
            cin >> Position_184;
            cout << "--- Data Baru ---" << endl;
            cout << "Nama mahasiswa baru = "; 
            cin >> Name_184;
            cout << "NIM mahasiswa baru = ";
            cin >> NIM_184;
            UbahTengah_184(Name_184, NIM_184, Position_184);
            cout << "Data mahasiswa " << OldName_184 << " (" << OldNIM_184 << ") pada posisi ke-" << Position_184 << " telah diganti dengan data mahasiswa baru " << Name_184 << " (" << NIM_184 << ")" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 7:
            cout << "---------------- HAPUS DEPAN -----------------" << endl;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilDepan_184() << "? [y/n] = ";
            cin >> Yakin_184;
            if(Yakin_184 == 'y' || Yakin_184 == 'Y'){
                HapusDepan_184();
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_184 == 'n' || Yakin_184 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 8:
            cout << "--------------- HAPUS BELAKANG ---------------" << endl;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilBelakang_184() << "? [y/n] = ";
            cin >> Yakin_184;
            if(Yakin_184 == 'y' || Yakin_184 == 'Y'){
                HapusBelakang_184();
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_184 == 'n' || Yakin_184 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 9:
            cout << "---------------- HAPUS TENGAH ----------------" << endl;
            cout << "Masukkan posisi data yang ingin dihapus = ";
            cin >> Position_184;
            cout << "Apakah anda yakin untuk menghapus data mahasiswa " << TampilTengah_184(Position_184) << "? [y/n] = ";
            cin >> Yakin_184;
            if(Yakin_184 == 'y' || Yakin_184 == 'Y'){
                HapusTengah_184(Position_184);
                cout << "Data telah dihapus" << endl;
            } else if(Yakin_184 == 'n' || Yakin_184 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 10:
            cout << "----------------- HAPUS LIST -----------------" << endl;
            cout << "Apakah anda yakin untuk menghapus semua data? [y/n] = ";
            cin >> Yakin_184;
            if(Yakin_184 == 'y' || Yakin_184 == 'Y'){
                HapusList_184();
                cout << "List telah terhapus" << endl; 
            } else if(Yakin_184 == 'n' || Yakin_184 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 11:
            cout << "-------------- TAMPIL LIST ---------------" << endl;
            TampilList_184();
            cout << endl;
            goto MenuUtama;
            break;
        case 0:
            cout << "Anda keluar dari program" << endl;
            return 0;
            break;
        default:
            cout << "Pilihan anda tidak tersedia" << endl;
            cout << endl;
            goto MenuUtama;
            break;
    }
}
```
#### Output:

##### Output 1 (Tambah Data Wati Diantara Farrel dan Denis)
![Ikram_Output-Unguided3-1]()

##### Output 2 (Hapus Data Denis)
![Ikram_Output-Unguided3-2]()

##### Output 3 (Tambah Data Owi Diawal)
![Ikram_Output-Unguided3-3]()

##### Output 4 (Tambah Data David Diakhir)
![Ikram_Output-Unguided3-4]()

##### Output 5 (Ubah Data Udin Menjadi Idin)
![Ikram_Output-Unguided3-5]()

##### Output 6 (Ubah Data Terakhir Mnejadi Lucy)
![Ikram_Output-Unguided3-6]()

##### Output 7 (Hapus Data Awal)
![Ikram_Output-Unguided3-7]()

##### Output 8 (Ubah Data Awal Menjadi Bagas)
![Ikram_Output-Unguided3-8]()

##### Output 9 (Hapus Data Akhir)
![Ikram_Output-Unguided3-9]()

##### Output 10 (Tampilkan Seluruh Data)
![Ikram_Output-Unguided3-10]()

#### Deskripsi Program
Program pada unguided 3 merupakan program yang sama dengan yang ada pada unguided 1. Setelah menginputkan data nama mahasiswa dan NIM pada unguided 2, kali ini praktikan diminta untuk melakukan operasi tertentu, antara lain :
- Menambahkan data Wati - 23300004 diantara Farrel dan Denis.
- Menghapus data Denis.
- Menambah data Owi - 2330000 pada awal list.
- Menambah data David - 23300100 pada akhir list.
- Mengubah data Udin menjadi Idin - 23300045.
- Mengubah data terakhir pada list menjadi Lucy - 23300101.
- Menghapus data pertama pada list.
- Mengubah data pertaama pada list menjadi Bagas - 23300002.
- Menghapus data terakhir pada list.
- Menampilkan seluruh data yang tersimpan.

## Kesimpulan
Linked list adalah struktur data yang terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer. Berdasarkan cara hubungan antar elemennya, linked list terbagi menjadi 2 yaitu linked list non-circular dan linked list circular. 

Linked list non-circular adalah linked list yang tidak terdapat siklus lingkaran atau dengan kata lain proses traversal dari awal hingga akhir linked list akan mencapai elemen terakhir dan kemudian berakhir. Linked list non-circular terbagi menjadi 2, yaitu Single Linked List Non-Circular (SLLNC) dan Double Linked List Non-Circular (DLLNC). Pada SLLNC node selanjutnya dari tail adalah NULL dan pada DLLNC node sebelum head dan node setelah tail adalah NULL.

Linked list circular adalah linked list yang membentuk siklus lingkaran karena elemen terakhir menunjuk kembali ke elemen pertama, sehingga tidak ada elemen yang menunjuk ke NULL. Iterasi melalui linked list akan terus berputar mengelilingi siklus. Linked list circular terbagi menjadi 2, yaitu Single Linked List Circular (SLLC) dan Double Linked List Circular (DLLC). Pada SLLC node selanjutnya dari tail adalah head dan pada DLLC node sebelum head adalah tail dan node setelah tail adalah head.

## Referensi
[1] Triase. 2020. "Diktat Edisi Revisi : STRUKTUR DATA". Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Santoso, Joseph Teguh. 2021. "Struktur Data dan Algoritma : Bagian 1". Semarang : Yayasan Prima Agus Teknik.
<br>[3] Musiafa, Zayid. 2022. "Struktur Data dan Implementasi Algoritma (SDIA): Pemrograman Python C C++ Java". (n.p.): ZAYID MUSIAFA.
