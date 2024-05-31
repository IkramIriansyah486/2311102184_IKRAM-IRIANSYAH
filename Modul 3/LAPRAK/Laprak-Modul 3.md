# <h1 align="center">Laporan Praktikum Modul 3 - Linked List</h1>
<p align="center">Ikram Iriansyah - 2311102184</p>

## Dasar Teori
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer. Suatu simpul atau node harus mempunyai satu atau lebih elemen struktur atau class yang berisi data. Pada suatu linked list, terdiri dari 2 elemen yaitu elemen pada awal list (head) dan elemen pada akhir list (tail). Terdapat 2 jenis linked list, diantaranya adalah :

### A. Single Linked list
Umumnya "linked list" berarti single linked list. Single linked list adalah daftar terhubung yang setiap simpul pembentuknya mempunyai satu rantai(link) ke simpul lainnya. Single linked list terdiri dari sejumlah node dimana setiap node memiliki pointer yang merujuk ke elemen berikut (*next). Pointer next pada node terakhir akan menunjuk ke NULL. Ini menandakan akhir dari list. 
Berikut meupakan ilustrasi dari sebuah single linked list.

![Ikram_Ilustrasi-single-linked-list]()

### B. Double Linked List
Berbeda dengan single linked list, double linked list adalah linked list yang memiliki dua rantai(link); yaitu satu link atau pointer yang merujuk ke node berikutnya (*next) dan satu link atau pointer yang merujuk ke node sebelumnya (*prev)[2]. Keuntungan dari double linked list adalah bahwa dengan adanya 2 buah pointer, programmer dapat melakukan operasi penghapusan dan penambahan pada simpul mana saja secara efisien. Berikut merupakan ilustrasi dari double linked list.

![Ikram_Ilustrasi-double-linked-list]()

Secara garis besar, linked list memiliki kelebihan dan kekurangan. 
Kelebihan dari linked list antara lain :
- Memiliki ukuran yang dinamis, sehingga ukurannya dapat disesuaikan dengan kebutuhan
- Penambahan dan penghapusan elemen di tengah linked list bisa dilakukan dengan mudah dan efisien, tanpa memerlukan penggeseran elemen-elemen lainnya.
- Dapat digunakan sebagai dasar untuk struktur data lainnya seperti stack, queue, dan hash table.

Kekurangan dan linked list antara lain :
- Penggunaan Memori Tambahan untuk Pointer (*next dan *prev)
- Data didalam list tidak terurut

## Guided 

### 1. Latihan Single Linked List

```C++
#include<iostream>

using namespace std;

//Program single linked list non-circular
//Deklarasi struct node
struct node{
    int data;
    node *next;
};
    node *head;
    node *tail;

//inisialisasi node
void init(){
    head = NULL;
    tail = NULL;
}

//pengecekan
bool isEmpty(){
    if (head == NULL){
        return true;
    } else {
        return false;
    }
}

//Tambah depan
void insertdepan(int nilai){
    //buat node baru
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

//tambah belakang
void insertbelakang(int nilai){
    //buat node baru
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

//hitung jumlah list
int hitunglist(){
    node *hitung;
    hitung = head;
    int jumlah = 0;
    while(hitung != NULL){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

//tambah tengah
void inserttengah(int data, int posisi){
    if(posisi < 1 || posisi > hitunglist()){
        cout << "posisi diluar jangkauan" << endl;
    } else if(posisi == 1){
        cout << "posisi bukan posisi tengah" << endl;
    } else {
        node *baru, *bantu;
        baru = new node();
        baru->data = data;
        //transvering
        bantu = head;
        int nomor = 1;
        while(nomor < posisi - 1){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//hapus depan
void hapusdepan(){
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

//hapus belakang
void hapusbelakang(){
    node *hapus;
    node *bantu;
    if(isEmpty() == false){
        if(head != tail){
            hapus = tail;
            bantu = tail;
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

//hapus tengah
void hapustengah(int posisi){
    node *hapus, *bantu, *bantu2;
    if(posisi < 1 || posisi > hitunglist()){
        cout << "posisi diluar jangkauan" << endl;
    } else if(posisi == 1){
        cout << "posisi bukan posisi tengah" << endl;
    } else {
        int nomor = 1;
        bantu = head;
        while(nomor <= posisi){
            if(nomor == posisi - 1){
                bantu2 = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

//Ubah Depan
void ubahdepan(int data){
    if (isEmpty() == false){
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Tengah
void ubahtengah(int data, int posisi){
    node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitunglist() ){
            cout << "Posisi di luar jangkauan" << endl;
        } else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Belakang
void ubahbelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList(){
    node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil(){
    node *bantu;
    bantu = head;
    if (isEmpty() == false){
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
    insertdepan(3);
    tampil();
    insertbelakang(5);
    tampil();
    insertdepan(2);
    tampil();
    insertdepan(1);
    tampil();
    hapusdepan();
    tampil();
    hapusbelakang();
    tampil();
    inserttengah(7,2);
    tampil();
    hapustengah(2);
    tampil();
    ubahdepan(1);
    tampil();
    ubahbelakang(8);
    tampil();
    ubahtengah(11, 2);
    tampil();
    
    return 0;
}
```
#### Deskripsi Program :
Kode diatas merupakan program untuk memanipulasi single linked list. Terdapat beberapa fungsi yang digunakan untuk memanipulasi single linked list, antara lain fungsi untuk tambah node (depan, tangah, belakang), hapus node (depan, tengah, belakang, semua), ubah node (depan, tengah, belakang), hitung jumlah node/list, dan tampilkan list. Pada awal program terdapat struct node yang digunakan untuk mendeklarasikan sebuah node. Node tersebut berisi 2 blok memori yang terdiri dari nilai yang disimpan dan pointer next. Kemudian juga terdapat prosedur init untuk inisialisasi head dan tail bernilai NULL serta terdapat fungsi isEmpty yang digunakan untuk memeriksa apakah linked list kosong atau tidak. Pada bagian int main(), dilakukan beberapa aksi yang berkaitan dengan linked list, seperti menambah data, mengubah data, menghapus data, dan menampilkan data.

### 2. Latihan Double Linked List

```C++
#include<iostream>

using namespace std;

//deklarasi class node
class node{
    public:
    //node berisi data, pointer prev, dan pointer next
    int data;
    node* prev;
    node* next;
};

//deklarasi class doublelinkedist
class doublelinkedlist{
    public:
    node* head;
    node* tail;

    //inisialisasi head dan tail
    doublelinkedlist(){
        head == nullptr;
        tail = nullptr;
    }

    //prosedur menambah node
    void push(int data){
        node* newnode = new node;
        newnode->data = data;
        newnode->prev = nullptr;
        newnode->next = head;
        if(head != nullptr){
            head->prev = newnode;
        } else {
            tail = newnode;
        }
        head = newnode;
    }

    //prosedur menghapus node
    void pop(){
        if(head == nullptr){
            return;
        }
        node* temp = head;
        head = head->next;
        if(head != nullptr){
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    //prosedur mengupdate atau mengubah data suatu node
    bool update(int olddata, int newdata){
        node* current = head;
        while(current != nullptr){
            if(current->data == olddata){
                current->data = newdata;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    //prosedur menghapus semua node
    void deleteall(){
        node* current = head;
        while (current != nullptr) {
            node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    //prosedur menampilkan list
    void display(){
        node* current = head;
        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
};

int main(){
    doublelinkedlist list;
    while(true){
        //menu manipulasi double linked list
        cout << "1. add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1 : { //jika menginput 1, maka tambah node didepan
                int data;
                cout << "enter data to add : ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2 : { //jika menginput 2, maka hapus node didepan
                list.pop();
                break;
            }
            case 3 : { //jika menginput 3, maka ubah node didepan
                int olddata, newdata;
                cout << "enter old data : ";
                cin >> olddata;
                cout << "enter new data : ";
                cin >> newdata;
                bool update = list.update(olddata, newdata);
                if(!update){
                    cout << "data not found" << endl;
                }
                break;
            }
            case 4 : { //jika memilih 4, maka hapus semua node
                list.deleteall();
                break;
            }
            case 5 : { //jika memilih 5, maka tampilkan list
                list.display();
                break;
            }
            case 6 : { //jika memilih 6, maka keluar dari program
                return 0;
            }
            default : { //output jika menginput selain 1-6
                cout << "invalid choice" << endl;
                break;
            }
        }
    }

    return 0;
}
```

#### Deskripsi Program :
Kode diatas merupakan program untuk memanipulasi double linked list. Terdapat beberapa fungsi yang digunakan untuk memanipulasi double linked list, antara lain fungsi untuk tambah node, hapus suatu node, update atau ubah data suatu node, hapus semua node, dan tampilkan list. Pada awal program terdapat deklarasi class node yang digunakan untuk mendeklarasikan sebuah node. Node tersebut berisi 3 blok memori yang terdiri dari pointer prev, nilai yang disimpan, dan pointer next. Kemudian juga terdapat class public doublelinkedlist yang berisi Node* head dan Node* tail serta terdapat juga fungsi doublelinkedlist() untuk mendeklarasikan head & node sebagai nullptr. Pada bagian int main(), terdapat sebuah menu yang menggunakan percabangan switch case. Pada opsi 1 akan menjalankan fungsi push(), opsi 2 menjalankan fungsi pop(), opsi 3 menjalankan fungsi update(), opsi 4 menjalankan fungsi deleteAll(), opsi 5 menjalankan fungsi display(), dan opsi 6 akan mengakhiri program.

## Unguided 

### 1. Soal mengenai Single Linked List
Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut: </br>

![Ikram_Soal-Unguided1-Modul3]()

```C++
//IKRAM IRIANSYAH
//2311102184
#include<iostream>

using namespace std;

//Deklarasi Struct node
struct node{ //node berisi variable nama_184, umur_184, dan pointer next
    string nama_184;
    int umur_184;
    node *next;
};
    node *head; //deklrasi node sebagai head
    node *tail; //deklarasi node sebagai tail

//prosedur inisialisasi node
void inisialisasi_184(){
    //mengosongkan nilai head dan tail 
    head = NULL;
    tail = NULL;
}

//prosedur pengecekan head & tail
bool kosong_184(){
    if(head == NULL){
        return true; //jika head tidak ada isinya (NULL), maka true
    } else {
        return false; //jika head ada isinya, maka false
    }
}

//prosedur tambah depan
void TambahDepan_184(string name_184, int age_184){
    node *baru = new node; //tambah node baru
    baru->nama_184 = name_184; //isi node baru
    baru->umur_184 = age_184; //isi node baru
    baru->next = NULL; // next node nya NULL
    //ini artinya node baru tersebut blom digabung ke linked list
    if(kosong_184() == true){ //jika linked listnya masih kosong, maka node baru adalah head dan tailnya
        head = tail = baru;
        tail->next = NULL; //tail dari node baru = NULL
    } else {
        baru->next = head; //jika linked listnya tidak kosong, maka next node baru dihubungkan ke head linked list
        head = baru; //dan node baru dijadikan head
    }
}

//prosedur tambah belakang
void TambahBelakang_184(string name_184, int age_184){
    node *baru = new node; //tambah node baru
    baru->nama_184 = name_184; //isi node baru
    baru->umur_184 = age_184; //isi node baru
    baru->next = NULL; // next node nya NULL
    //ini artinya node baru tersebut blom digabung ke linked list
    if(kosong_184() == true){ //jika linked listnya masih kosong, maka node baru adalah head dan tailnya
        head = tail = baru;
        tail->next = NULL; //tail dari node baru = NULL
    } else {
        tail->next = baru; //jika linked listnya tidak kosong, maka next node baru dihubungkan ke head linked list
        tail = baru; //dan node baru dijadikan head
    }
}

//fungsi hitung node
int HitungNode_184(){
    node *hitung; //tambah node hitung
    hitung = head; //node hitung sebagai head
    int jumlah = 0;
    while(hitung != NULL){ //perulangan while
        jumlah++; //deklarasi variabel jumlah
        hitung = hitung->next; //jika next node hitung bukan NULL, maka variabel jumlah +1
    }
    return jumlah;
}

//prosedur tambah tengah
void TambahTengah_184(string name_184, int age_184, int posisi_184){
    if(posisi_184 < 1 || posisi_184 > HitungNode_184()){ //jika posisi node yang akan ditambahkan kurang dari 1 atau lebih dari jumlah node yang ada, maka tampilkan output
        cout << "Posisi node yang akan ditambahkan offside" << endl;
    } else if(posisi_184 == 1){ //jika posisi node yang akan ditambahkan adalah posisi pertama, maka tampilkan output
        cout << "Posisi node yang akan ditambahkan bukan di tengah" << endl;
    } else {
        //tambah node baru & node bantu
        node *baru, *bantu;
        baru = new node; //buat node baru
        baru->nama_184 = name_184; //isi node baru
        baru->umur_184 = age_184; //isi node baru
        baru->next = NULL; //next nodenya NULL
        //transvering
        bantu = head; //node bantu dijadikan head
        int nomor_184 = 1; //deklarasi variabel nomor_184
        //hitung posisi node baru akan ditambahkan sebagai node keberapa
        while(nomor_184 < posisi_184 - 1){ //ketika variabel nomor_184 kurang dari posisi node baru yang akan ditambahkan - 1, maka
            bantu = bantu->next; //node bantu berlanjut ke node selanjutnya sampai variabel nomor = posisi node baru yang akan ditambahkan
            nomor_184++; //variable nomor_184 +1
        }
        //maka akan diketahui posisi node baru yang akan ditambahkan berada dimana
        baru->next = bantu->next; // next node baru sama dengan next node bantu
        bantu->next = baru; //next node bantu sama dengan node baru 
    }
}

//prosedur hapus depan
void HapusDepan_184(){
    node *hapus; //tambah node hapus
    if(kosong_184() == false){ //jika head saat ini sudah ada nilainya, maka 
        if(head->next != NULL){ //jika next dari head saat ini tidak ada nilainya (NULL), maka
            hapus = head; //node hapus dijadikan head
            head = head->next; //yang dijadikan head adalah next dari head saat ini
            delete hapus; //delete node hapus
        } else { //jika next dari head saat ini ada nilainya, maka
            head = tail = NULL; //head dan tail = NULL
        }
    } else { //jika head saat ini tidak ada nilainya, maka tampilkan output
        cout << "List masih kosong!" << endl; 
    }
}

//prosedur hapus belakang
void HapusBelakang_184(){
    node *hapus; //tambah node hapus
    node *bantu; //tambah node bantu
    if (kosong_184() == false){ //jika head saat ini ada nilainya, maka
        if(head != tail){ //jika head saat ini bukan sama dengan tail saat ini, maka
            hapus = tail; //node hapus sebagai tail
            bantu = tail; //node bantu sebagai tail
            bantu = head; //node bantu sebagai head
            while(bantu->next != tail){ //ketika next dari node bantu bukan sama dengan tail, maka ulangi
                bantu = bantu->next; //node bantu berlanjut ke next dari bantu saat ini
            }
            tail = bantu; //tail adalah node bantu
            tail->next = NULL; //next dari tail adalah NULL
            delete hapus; //delete node hapus
        } else {
            head = tail = NULL;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
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

//prosedur ubah isi head
void UbahDepan_184(string name_184, int age_184){
    if(kosong_184() == false){
        head->nama_184 = name_184;
        head->umur_184 = age_184;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//prosedur ubah isi tail
void UbahBelakang_184(string name_184, int age_184){
    if(kosong_184() == false){
        tail->nama_184 = name_184;
        tail->umur_184 = age_184;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//prosedur ubah isi node tengah
void UbahTengah_184(string name_184, int age_184, int posisi_184){
    node *bantu;
    if(kosong_184() == false){
        if(posisi_184 < 1 || posisi_184 > HitungNode_184()){
            cout << "Node yang ingin diubah isinya diluar jangkauan" << endl;
        } else if(posisi_184 == 1){
            cout << "Node yang ingin diubah isinya bukan head" << endl;
        } else {
            bantu = head;
            int nomor_184 = 1;
            while(nomor_184 < posisi_184){
                nomor_184++;
                bantu = bantu->next;
            }
            bantu->nama_184 = name_184;
            bantu->umur_184 = age_184;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//prosedur hapus list
void HapusList_151(){
    node *bantu, *hapus;
    bantu = head;
    while(bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List sudah terhapus!" << endl;
}

//prosedur menampilkan list
void TampilList_184(){
    node *bantu;
    bantu = head;
    if(kosong_184() == false){
        cout << "- Nama -     - umur -" << endl; 
        for(int i=0; i<=HitungNode_184() && bantu != NULL; i++){
            cout << bantu->nama_184 << '\t' << '\t' << bantu->umur_184 << endl;
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main(){
    int Posisi_184, umur_184;
    char Yakin_184, Pilihan_184;
    string nama_184;
    MenuJawaban:
    cout << "--- MENU JAWABAN ---" << endl;
    cout << "a. Jawab poin a" << endl;
    cout << "b. Jawab poin b" << endl;
    cout << "c. Jawab poin c" << endl;
    cout << "d. Jawab poin d" << endl;
    cout << "e. Jawab poin e" << endl;
    cout << "f. Jawab poin f" << endl;
    cout << "g. exit" << endl;
    cout << "Pilihan anda = "; cin >> Pilihan_184;
    cout << endl;

    switch(Pilihan_184){
        case 'a' :
            //Jawaban poin a
            inisialisasi_184();
            cout << "- Masukkan Data Sesuai Urutan -" << endl;
            for(int i=1; i <= 8; i++){
                cout << "Masukkan data nama ke-" << i << " = ";
                cin >> nama_184;
                cout << "Masukkan umur data ke-" << i << " = ";
                cin >> umur_184;
                TambahBelakang_184(nama_184, umur_184);
            }
            cout << endl;
            TampilList_184();
            goto MenuJawaban;
            break;
        case 'b' :
            cout << "--- Menghapus data 'Akechi' ---" << endl;
            cout << "Masukkan posisi data Akechi = "; cin >> Posisi_184;
            cout << "Apakah anda yakin ingin menghapus data 'Akechi' yang berada di posisi ke-" << Posisi_184 << "? [y/n] = "; cin >> Yakin_184;
            if(Yakin_184 == 'y' || Yakin_184 == 'Y'){
                HapusTengah_184(6);
                cout << "Data telah dihapus" << endl;
                cout << endl;
            } else if(Yakin_184 =='n' || Yakin_184 == 'N'){
                cout << "Aksi dibatalkan" << endl;
                cout << endl;
            }
            TampilList_184();
            goto MenuJawaban;
            break;
        case 'c' :
            cout << "--- Tambahkan data 'Futaba, 18' diantara John dan Jane ---" << endl;
            cout << "Masukkan data nama = "; cin >> nama_184;
            cout << "Masukkan umur = "; cin >> umur_184;
            cout << "Masukkan posisi data yang ingin ditambahkan = "; cin >> Posisi_184;
            TambahTengah_184(nama_184, umur_184, Posisi_184);
            cout << endl;
            TampilList_184();
            goto MenuJawaban;
            break;
        case 'd' : 
            cout << "--- Tambahkan data 'Igor, 20' diawal ---" << endl;
            cout << "Masukkan data nama = "; cin >> nama_184;
            cout << "Masukkan umur = "; cin >> umur_184;
            TambahDepan_184(nama_184, umur_184);
            cout << endl;
            TampilList_184();
            goto MenuJawaban;
            break;
        case 'e' :
            cout << "--- Ubah data 'Michael' menjadi 'Reyn, 18' ---" << endl;
            cout << "Masukkan nama data baru = "; cin >> nama_184;
            cout << "Masukkan umur = "; cin >> umur_184;
            cout << "Masukkan posisi data lama yang ingin diubah = "; cin >> Posisi_184;
            UbahTengah_184(nama_184, umur_184, Posisi_184);
            cout << endl;
            TampilList_184();
            goto MenuJawaban;
            break;
        case 'f' :
            cout << "--- Tampilkan Seluruh Data ---" << endl;
            TampilList_184();
            goto MenuJawaban;
            break;
        case 'g' :
            cout << "Anda keluar dari program" << endl;
            return 0;
            break;
        default :
            cout << "Pilihan yang anda masukkan tidak tersedia" << endl;
            goto MenuJawaban;
            break;
    }
}
```
#### Output:

##### Output Poin a
![Ikram_Output-Unguided1-1]()

![Ikram_Output-Unguided1-1-1]()

##### Output Poin b
![Ikram_Output-Unguided1-2]()

##### Output Poin c
![Ikram_Output-Unguided1-3]()

##### Output Poin d
![Ikram_Output-Unguided1-4]()

##### Output Poin e
![Ikram_Output-Unguided1-5]()

##### Output Poin f
![Ikram_Output-Unguided1-6]()

#### Deskripsi Program :
Kode diatas merupakan program single linked list yang berisi biodata berupa nama dan umur. Pada awal program terdapat 'struct node' yang digunakan untuk mendeklarasikan node yang berisi data nama, data umur, dan pointer next. Kemudian terdapat prosedur 'inisialisasi_184' yang digunakan untuk inisialisasi node head dan tail yang bernilai NULL. Ada juga fungsi 'kosong_184' yang digunakan untuk mengecek apakah linked list tersebut kosong atau tidak. Kemudian terdapat beberapa fungsi dan prosedur yang digunakan untuk memanipulasi linked list, antara lain prosedur untuk menambahkan node (void 'TambahDepan_184()', void 'TambahBelakang_184()', void 'TambahTengah_184()'), prosedur untuk menghapus node (void 'HapusDepan_184()', void 'HapusTengah_184()', dan void 'HapusBelakang_184()'), prosedur untuk mengubah isi node (void 'UbahDepan_184()', void 'UbahTengah_184()', void 'UbahBelakang_184()'), fungsi untuk menghitung node (int 'HitungNode_184()'), prosedur hapus list (void 'HapusList_184()'), dan prosedur untuk menampilkan list (void 'TampilList_184()').

Pada bagian int main(), terdapat menu yang setiap opsinya menjawab poin-poin yang telah diberikan di soal. Opsi a digunakan untuk menginput data sesuai urutan yang telah ditentukan, opsi b digunakan untuk menghapus data Akechi, opsi c digunakan untuk menambahkan data 'Futaba, 18' diantara John dan Jane, opsi d digunakan untuk menambahkan data 'Igor, 20' diawal, opsi e digunakan untuk mengubah data 'Michael' menjadi 'Reyn, 18', opsi f digunakan untuk menampilkan hasil akhir list, dan terakhir opsi g digunakan untuk mengakhiri program.

### 2. Soal mengenai Double Linked List
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga. </br>

![Ikram_Soal-Unguided2-1-Modul3]()

Case :
1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific.
2. Hapus produk wardah.
3. Update produk Hanasui menjadi Cleora dengan harga 55.000.
4. Tampilkan menu seperti dibawah ini.
```C++
1. Tambah data
2. Hapus data
3. Update data
4. Tambah data urutan tertentu
5. Hapus data urutan tertentu
6. Hapus seluruh data
7. Tampilkan data
8. Exit
```
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :

![Ikram_Soal-Unguided2-2-Modul3]()

```C++
#include<iostream>
#include<iomanip>

using namespace std;

struct node{
    string barang_184;
    int harga_184;
    node *prev;
    node *next;
};
    node *head;
    node *tail;

//prosedur inisiaslisasi 
void Inisialisasi_184(){
    head = nullptr;
    tail = nullptr;
}

//prosedur tambah node
void TambahNode_184(string produk_184, int harga_184, int posisi_184){
    if(posisi_184 < 1 ){
        cout << "Node yang ingin ditambah diluar jangkauan" << endl;
    } else if(posisi_184 == 1){
        node *baru = new node;
        baru->barang_184 = produk_184;
        baru->harga_184 = harga_184;
        baru->next = head;
        baru->prev = nullptr;
        if(head != nullptr){
            head->prev = baru;
        } else {
            tail = baru;
        }
        head = baru;
    } else {
        node *current = head;
        node *baru = new node;
        baru->barang_184 = produk_184;
        baru->harga_184 = harga_184;
        baru->next = nullptr;
        baru->prev = nullptr;
        int hitung_184 = 1;
        while(hitung_184 < posisi_184 - 1){
            hitung_184++;
            current = current->next;
        }
        baru->next = current->next;
        baru->prev = current;
        if(current->next != nullptr){
            current->next->prev = baru;
        } else {
            tail = baru;
        }
        current->next = baru;
    }
}

//prosedur hapus node
void HapusNode_184(int posisi_184){
    if(posisi_184 < 1){
        cout << "Posisi node yang ingin dihapus diluar jangkauan" << endl;
    } else if(posisi_184 == 1){
        node *current = head;  // Simpan node pertama
        head = head->next;     // Geser head ke node berikutnya
        if(head != nullptr) {
            head->prev = nullptr;  // Tetapkan nullptr ke prev dari node baru pertama
        }
        delete current;  // Hapus node pertama
    } else {
        node *current = head;
        int hitung_184 = 1;
        while(hitung_184 < posisi_184){
            hitung_184++;
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
}

//fungsi update data
bool UpdateData_184(string ProdukLama_184, string ProdukBaru_184, int HargaBaru_184){
    node *current = head;
    while (current != nullptr){
        if(current->barang_184 == ProdukLama_184){
            current->barang_184 = ProdukBaru_184;
            current->harga_184 = HargaBaru_184;
            return true;
        }
        current = current->next;
    }
    return false;
}

//prosedur hapus semua data
void HapusSemua_184(){
    node *current = head;
    while(current != nullptr){
        node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

//prosedur tampilkan data
void TampilData_184(){
    node *current = head;
    if(head != nullptr){
        cout << left << setw(20) << "- Nama Produk -" << right << setw(5) << "- Harga -" << endl; 
        while(current != nullptr){
            cout << left << setw(20) << current->barang_184 << right << setw(7) << current->harga_184 << endl; 
            current = current->next;
        }
    }
    cout << endl;
}

int main(){
    int pilih_184, HargaBaru_184, PosisiProduk_184;
    string ProdukBaru_184, ProdukLama_184;
    char yakin_184;
    Inisialisasi_184();
    cout << "--- DAFTAR PRODUK SKINCARE ---" << endl;
    TambahNode_184("Hanasui", 30000, 1 );
    TambahNode_184("Wardah", 50000, 1);
    TambahNode_184("Skintific", 100000, 1);
    TambahNode_184("Somethinc", 150000, 1);
    TambahNode_184("Originote", 60000, 1);
    TampilData_184();

    MenuUtama:
    cout << "--- TOKO SKINCARE PURWOKERTO ---" << endl;
    cout << "1. Tambah data" << endl;
    cout << "2. Hapus data" << endl;
    cout << "3. Update data" << endl;
    cout << "4. Tambah data urutan tertentu" << endl;
    cout << "5. Hapus data urutan tertentu" << endl;
    cout << "6. Hapus seluruh data" << endl;
    cout << "7. Tampilkan data" << endl;
    cout << "8. exit" << endl;
    cout << "Pilihan anda = "; cin >> pilih_184;
    cout << endl;

    switch(pilih_184){
        case 1 :
            cout << "- Tambah Data Produk -" << endl;
            cout << "Masukkan nama produk yang ingin ditambahkan = "; cin >> ProdukBaru_184;
            cout << "Masukkan harga produk = "; cin >> HargaBaru_184;
            TambahNode_184(ProdukBaru_184, HargaBaru_184, 1);
            cout << "Produk telah ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2 :
            cout << "- Hapus Data Produk Pertama - " << endl;
            HapusNode_184(1);
            cout << "Data produk ke-1 telah dihapus" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 3 :
            cout << "- Update Data Produk -" << endl;
            cout << "Masukkan produk lama yang ingin diganti = ";cin >> ProdukLama_184;
            cout << "Masukkan nama produk baru = "; cin >> ProdukBaru_184;
            cout << "Masukkan harga produk baru = "; cin >> HargaBaru_184;
            UpdateData_184(ProdukLama_184, ProdukBaru_184, HargaBaru_184);
            cout << "Produk telah diupdate" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 4 :
            cout << "- Tambah Data Urutan Tertentu -" << endl;
            cout << "Masukkan nama produk yang ingin ditambahkan = "; cin >> ProdukBaru_184;
            cout << "Masukkan harga produk baru = "; cin >> HargaBaru_184;
            cout << "Masukkan posisi produk dalam database = "; cin >> PosisiProduk_184;
            TambahNode_184(ProdukBaru_184, HargaBaru_184, PosisiProduk_184);
            cout << "Produk telah ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 5 :
            cout << "- Hapus Data Urutan Tertentu -" << endl;
            cout << "Masukkan urutan produk yang ingin dihapus = "; cin >> PosisiProduk_184;
            HapusNode_184(PosisiProduk_184);
            cout << "Data produk urutan ke-" << PosisiProduk_184 << " telah dihapus" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 6 :
            cout << "- Hapus Seluruh Data -" << endl;
            cout << "Apakah anda yakin ingin menghapus semua produk? [y/n] = "; cin >> yakin_184;
            if(yakin_184 == 'y' || yakin_184 == 'Y'){
                HapusSemua_184();
                cout << "Semua data produk telah dihapus" << endl;
            } else if(yakin_184 == 'n' || yakin_184 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 7 :
            cout << "- Tampilkan Data -" << endl;
            TampilData_184();
            cout << endl;
            goto MenuUtama;
            break;
        case 8 :
            cout << "Anda keluar dari program" << endl;
            return 0;
        default :
            cout << "Pilihan yang anda masukkan tidak tersedia" << endl;
            cout << endl;
            goto MenuUtama;
            break;
    }    
}
```
#### Output:

##### Output 1 :
Tampilan menu utama.

![Ikram_Output-Unguided2-1]()

##### Output 2 :
Menambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific.

![Ikram_Output-Unguided2-2]()

##### Output 3 :
Hapus produk wardah.

![Ikram_Output-Unguided2-3]()

##### Output 4 :
Update produk Hanasui menjadi Cleora dengan harga 55.000.

![Ikram_Output-Unguided2-4]()

##### Output 5 :
Tampilan akhir data yang tersimpan.

![Ikram_Output-Unguided2-5]()

#### Deskripsi Program :
Kode diatas merupakan program double linked list yang berisi nama produk skincare beserta harganya. pada awal program terdapat 'struct node' yang digunakan untuk mendeklarasikan node yang berisi data nama barang, data harga, pointer prev, dan pinter next. Kemudian terdapat prosedur 'inisialisasi_184' yang digunakan untuk inisialisasi node head dan tail yang bernilai nullptr. Kemudian terdapat beberapa fungsi dan prosedur yang digunakan untuk memanipulasi double linked list, antara lain prosedur untuk menambahkan node (void 'TambahNode_184()'), prosedur untuk menghapus node (void 'HapusNode_184()'), fungsi untuk mengupdate atau mengubah data suatu node (bool 'UpdateData_184()'), prosedur untuk menghapus semua data (void 'HapusSemua_184()'), dan prosedur untuk menampilkan list (void 'TampilData_184()').

Pada bagian int main(), terdapat menu toko skincare purwokerto. Opsi 1 digunakan untuk menambah data, opsi 2 digunakan untuk menghapus data, opsi 3 digunakan untuk mengupdate data, opsi 4 digunakan untuk menambah data pada urutan tertentu, opsi 5 digunakan untuk menghapus data pada urutan tertentu, opsi 6 digunakan untuk menghapus seluruh data, opsi 7 digunakan untuk menampilkan data, dan terakhir opsi 8 digunakan untuk mengakhiri program.

## Kesimpulan
Linked list adalah struktur data yang terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer. terdapat 2 jenis linked list, yaitu single linked list dan double linked list. Pada single linked list, setiap nodenya terdiri dari 2 bagian, yaitu nilai yang ditampung dan pointer next. Sedangkan pada double linked list, setiap nodenya terdiri dari 3 bagian, yaitu nilai yang ditampung, pointer prev, dan pointer next. Masing-masing jenis Linked List ini memiliki kelebihan dalam hal penyisipan dan penghapusan elemen yang lebih efisien dibandingkan array. Namun, Linked List juga membutuhkan lebih banyak memori karena setiap nodenya memakai lebih dari 1 blok memori dan umumnya memiliki akses data yang lebih lambat.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Harihayati Mardzuki, Tati. (2020). Double Linked List. [Teaching Resource]. Diakses pada 26 Maret 2024 melalui http://repository.unikom.ac.id/id/eprint/64221.