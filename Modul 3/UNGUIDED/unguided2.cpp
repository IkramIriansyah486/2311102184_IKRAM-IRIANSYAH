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