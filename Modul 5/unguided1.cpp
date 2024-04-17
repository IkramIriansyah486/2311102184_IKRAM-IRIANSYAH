//IKRAM IRIANSYAH
//2311102184

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(long long key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Mahasiswa {
    long long NIM;
    string Nama; 
    int Nilai;
    Mahasiswa* next;
    Mahasiswa(long long NIM, string Nama, int Nilai) : NIM(NIM), Nama(Nama), Nilai(Nilai), next(nullptr) {} // Constructor
};

// Class hash table
class HashTable {
private:
    Mahasiswa** table;

public:
    HashTable() { // Constructor
        table = new Mahasiswa*[MAX_SIZE]();
    }

    ~HashTable() { // Destructor
        for (int i = 0; i < MAX_SIZE; i++) { // Menghapus semua node yang ada
            Mahasiswa* current = table[i]; // Menunjuk ke index yang sudah ditentukan
            while (current != nullptr) {
                Mahasiswa* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void Insert(long long NIM, string Nama, int Nilai) {
        int index = hash_func(NIM); // Menggunakan fungsi hash untuk menentukan index
        Mahasiswa* current = table[index]; // Menunjuk ke index yang sudah ditentukan
        while (current != nullptr) {
            if (current->NIM == NIM) {
                current->Nilai = Nilai;
                return;
            }
            current = current->next;
        }
        Mahasiswa* mahasiswa = new Mahasiswa(NIM, Nama, Nilai);
        mahasiswa->next = table[index]; // Menunjuk ke node selanjutnya
        table[index] = mahasiswa; // Menunjuk ke node yang baru dibuat
    }

    Mahasiswa* SearchNIM(long long NIM) {
        int index = hash_func(NIM); // Menggunakan fungsi hash untuk menentukan index
        Mahasiswa* current = table[index]; // Menunjuk ke index yang sudah ditentukan
        while (current != nullptr) {
            if (current->NIM == NIM) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Searching by value range (80 - 90)
    void SearchNilai(int StartScoreRange, int EndScoreRange) {
        cout << left << setw(15) << "-NAME-" << setw(20) << "-NIM-" << right << setw(2) << "-SCORE-" << endl;
        for (int i = 0; i < MAX_SIZE; i++) { // Untuk setiap index yang ada di tabel hash table ini, akan diiterasi satu per satu untuk mencari data yang sesuai dengan range yang diinginkan
            Mahasiswa* current = table[i];
            while (current != nullptr) {
                if (current->Nilai >= StartScoreRange && current->Nilai <= EndScoreRange) { // Jika nilai mahasiswa berada di dalam range yang diinginkan
                    cout << left << setw(15) << current->Nama << setw(20) << current->NIM << right << setw(6) << current->Nilai << endl; // Maka data mahasiswa tersebut akan ditampilkan
                }
                current = current->next;
            }
        }
    }

    // Deletion
    void Remove(long long NIM) {
    int index = hash_func(NIM); // Menggunakan fungsi hash untuk menentukan index
    Mahasiswa* current = table[index]; // Menunjuk ke index yang sudah ditentukan
    Mahasiswa* prev = nullptr;
    
    while (current != nullptr) { // Iterasi untuk mencari data yang akan dihapus
        if (current->NIM == NIM) { // Jika data ditemukan
            if (prev == nullptr) { // Jika data yang akan dihapus berada di awal index
                table[index] = current->next; // Maka index akan menunjuk ke node selanjutnya
            } else {
                prev->next = current->next; // Jika data yang akan dihapus berada di tengah atau akhir index, maka node sebelumnya akan menunjuk ke node setelahnya
            }
            delete current; // Menghapus node yang diinginkan
            cout << "\nCongrats! NIM " << NIM << " has been erased from existence!" << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    
    // Jika NIM tidak ditemukan
    cout << "\nHuh? NIM " << NIM << " is nowhere to be found." << endl;
}


    // Traversal
    void Traverse() {
        cout << left << setw(17) << "-NAME-" << setw(17) << "-NIM-" << setw(12) << "-SCORE-" << endl;
        for (int i = 0; i < MAX_SIZE; i++) { // Diiterasi untuk setiap index yang ada di tabel hash table ini
            Mahasiswa* current = table[i]; // Menunjuk ke index yang sudah ditentukan
            while (current != nullptr) { // Iterasi untuk menampilkan data mahasiswa
                cout << left << setw(17) << current->Nama << setw(19) << current->NIM << setw(12) << current->Nilai << endl;
                current = current->next;
        }
    }
}
};

int main() {
    HashTable ht; // Membuat objek hash table

    cout << "\n-=-=-=- PROGRAM HASH TABLE DATA MAHASISWA -=-=-=-" << endl;

    while (true) {
        cout << "\n-=- MENU -=-";
        cout << "\n1. Add Data Mahasiswa";
        cout << "\n2. Delete Data Mahasiswa";
        cout << "\n3. Search Data by NIM Mahasiswa";
        cout << "\n4. Search Score by Range";
        cout << "\n5. Show Data Mahasiswa";
        cout << "\n6. Exit";
        cout << "\nChoose your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\n-=-= ADD DATA MAHASISWA =-=-" << endl;
                long long NIM;
                string Nama;
                int Nilai;
                cout << "Enter the student's name: ";
                cin.ignore(); // Untuk menghindari bug cin getline
                getline(cin, Nama); // Menggunakan getline untuk input string yang mengandung spasi
                cout << "Enter the NIM: ";
                cin >> NIM;
                cout << "Input the score: ";
                cin >> Nilai;
                ht.Insert(NIM, Nama, Nilai); // Memasukkan data mahasiswa ke dalam hash table
                cout << "\nSuccess! You have added the student data of " << Nama << " with the NIM " << NIM << " and the score " << Nilai << endl;
                break;
            }
            case 2: {
                cout << "\n-=-= DELETE DATA MAHASISWA =-=-" << endl;
                long long NIM;
                cout << "Input which NIM to delete: ";
                cin >> NIM;
                ht.Remove(NIM); // Menghapus data mahasiswa dari hash table
                break;
            }
            case 3: {
                cout << "\n-=-= SEARCH DATA BY NIM MAHASISWA =-=-" << endl;
                long long NIM;
                cout << "Input NIM to search for their data: ";
                cin >> NIM;
                Mahasiswa* mahasiswa = ht.SearchNIM(NIM); // Mencari data mahasiswa berdasarkan NIM
                if (mahasiswa != nullptr) // Jika data ditemukan
                    cout << "\nThe NIM " << NIM << " belongs to " << mahasiswa->Nama << " and has the score of " << mahasiswa->NIM << endl; // Maka data mahasiswa tersebut akan ditampilkan
                else
                    cout << "\nWhoops! Data not found!" << endl;
                break;
            }
            case 4: {
                cout << "\n-=-= SEARCH SCORE BY RANGE =-=-" << endl;
                int StartScoreRange, EndScoreRange;
                cout << "Range starts from Score: ";
                cin >> StartScoreRange;
                cout << "to Score: ";
                cin >> EndScoreRange;
                cout << "\nStudent(s) with the score between " << StartScoreRange << "-" << EndScoreRange << " are:\n";
                ht.SearchNilai(StartScoreRange, EndScoreRange); // Mencari data mahasiswa berdasarkan range nilai
                break;
            }
            case 5: {
                cout << "\n" << right << setw(8) << "" << "-=-= MAHASISWA DATA =-=-" << endl;
                ht.Traverse(); // Menampilkan data mahasiswa yang ada di hash table
                break;
            }
            case 6:
                cout << "\nThank you!";
                return 0;
            default:
                cout << "\nWhat did you just type..?" << endl;
        }
    }
}