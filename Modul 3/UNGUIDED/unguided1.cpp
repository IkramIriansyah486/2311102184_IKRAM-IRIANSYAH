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