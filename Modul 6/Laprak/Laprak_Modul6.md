# <h1 align="center">Laporan Praktikum Modul 6 - Stack</h1>
<p align="center">Ikram Ikriansyah - [NIM]</p>

## Dasar Teori

## Guided 

### 1. [Soal guided no 1]
```C++

#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
return (top == maksimal);
}

bool isEmpty() {
return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " <<
arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();

    return 0;
}

```
Deskripsi guided 1
Progam diatas menjalankan implementasi struktur data stack menggunakan array, dengan menyediakan operasi-operasi dasar seperti push, pop, peek, dan lainnya.

## Unguided 

### 1. [Soal Unguided 1]

```C++

//Ikram Iriansyah
//2311102184

#include <iostream>
#include <stack>
#include <string>
#include <locale>

using namespace std;

// Fungsi untuk menghapus karakter non-alphanumeric dari sebuah string
string removeNonAlphanumeric(string str) {
    string result = "";
    for (char c : str) {
        if (isalnum(c)) { // isalnum() memeriksa apakah karakter adalah alfanumerik
            result += tolower(c); // Mengubah karakter menjadi huruf kecil
        }
    }
    return result;
}

// Fungsi untuk menentukan apakah sebuah string adalah palindrom
bool isPalindrome(string str) {
    stack<char> charStack;
    int length = str.length();

    // Menambahkan setengah karakter pertama ke stack
    for (int i = 0; i < length / 2; i++) {
        charStack.push(str[i]);
    }

    // Memeriksa setengah karakter kedua dengan stack
    for (int i = (length + 1) / 2; i < length; i++) {
        if (charStack.top() != str[i]) {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main() {
    string input;
    cout << "Masukkan kalimat: ";
    getline(cin, input);

    // Menghapus karakter non-alphanumeric dan mengubah menjadi huruf kecil
    string cleanedInput = removeNonAlphanumeric(input);

    if (isPalindrome(cleanedInput)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}

```
#### Output:
![Screenshot Output Unguided ...]

Deskripsi program unguided 1
Dalam program ini menggunakan struktur data stack untuk memeriksa apakah sebuah kata atau kalimat merupakan palindrom atau bukan dengan cara membandingkan setengah huruf di awal dengan setengah huruf di akhir secara terbalik.

### 2. [Soal unguided no 2]

```C++

// Ikram Iriansyah
// 2311102184

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string reverseString(string str)
{
    stack<char> charStack;
    string reversed = "";

    // Mendorong setiap huruf ke dalam stack
    for (char c : str)
    {
        charStack.push(c);
    }

    // Mengeluarkan huruf dari stack untuk membentuk string terbalik
    while (!charStack.empty())
    {
        reversed += charStack.top();
        charStack.pop();
    }

    return reversed;
}

int main()
{
    string input;
    cout << "Masukkan Kata: ";
    getline(cin, input);

    string reversed = reverseString(input);
    cout << "Data: " << reversed << endl;

    return 0;
}

```
#### Output:
![Screenshot Output Unguided ...]

Deskripsi program unguided 2
Program diatas ini menggunakan struktur data stack untuk membalik urutan karakter dalam sebuah string dengan cara mendorong setiap karakter kedalam stack, kemudian mengeluarkan karakter-karakter tersebut dari stack dalam urutan terbalik untuk membentuk string hasil pembalikan.

## Kesimpulan

## Referensi
