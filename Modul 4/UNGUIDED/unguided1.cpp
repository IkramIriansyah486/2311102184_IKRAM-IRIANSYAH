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