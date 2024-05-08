# <h1 align="center">Laporan Praktikum Modul 6 - Stack</h1>
<p align="center">Ikram Ikriansyah - 2311102184</p>

## Dasar Teori

### A. STACK

Stack adalah struktur data linear yang mengikuti prinsip Last In First Out (LIFO), yang berarti elemen terakhir yang dimasukkan akan menjadi elemen pertama yang dikeluarkan.[1] Dalam pemrograman C++, Stack dapat diimplementasikan dengan menggunakan array atau linked list.[2]

### Berikut adalah penjelasan singkat tentang stack

1. Operasi Dasar:
- push(x): Menambahkan elemen x ke bagian atas Stack.
- pop(): Menghapus dan mengembalikan elemen dari bagian atas Stack.
- top(): Mengembalikan elemen yang berada di bagian atas Stack tanpa menghapusnya.
- isEmpty(): Memeriksa apakah Stack kosong atau tidak.

2. Implementasi dengan Array:
- Gunakan sebuah array untuk menyimpan elemen-elemen Stack.
- Gunakan variabel top untuk melacak indeks elemen teratas.
- Operasi push menambahkan elemen baru di indeks top dan menaikkan nilai top.
- Operasi pop mengembalikan elemen di indeks top dan menurunkan nilai top.

3. Implementasi dengan Linked List:
- Gunakan struktur Node yang berisi data dan pointer ke node berikutnya.
- Pointer top menunjuk ke node teratas pada Stack.
- Operasi push membuat node baru dan mengubah top untuk menunjuk ke node tersebut.
- Operasi pop mengembalikan data dari node yang ditunjuk top dan mengubah top untuk menunjuk ke node sebelumnya.

4. Aplikasi Stack:
- Pembalik string atau angka.
- Evaluasi ekspresi dengan notasi reverse polish.
- Penerapan rekursi dalam program.
- Penerapan algoritma traversal pada graph dan tree.

## Guided 

### 1. Latihan Stack Sederhana

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

#### Deskripsi guided 1
Progam diatas menjalankan implementasi struktur data stack menggunakan array, dengan menyediakan operasi-operasi dasar seperti push, pop, peek, dan lainnya.

## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat yang diinputkan dalam program stack adalah palindrom atau tidak.

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
![Output-Unguided1](https://github.com/IkramIriansyah486/Structure-Data-Assignment/tree/main/Modul%206/Laprak/Output-Unguided1.png)

#### Deskripsi program unguided 1
Dalam program ini menggunakan struktur data stack untuk memeriksa apakah sebuah kata atau kalimat merupakan palindrom atau bukan dengan cara membandingkan setengah huruf di awal dengan setengah huruf di akhir secara terbalik.

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata.

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
![Output-Unguided2](https://github.com/IkramIriansyah486/Structure-Data-Assignment/tree/main/Modul%206/Laprak/Output-Unguided2.png)

#### Deskripsi program unguided 2
Program diatas ini menggunakan struktur data stack untuk membalik urutan karakter dalam sebuah string dengan cara mendorong setiap karakter kedalam stack, kemudian mengeluarkan karakter-karakter tersebut dari stack dalam urutan terbalik untuk membentuk string hasil pembalikan.

## Kesimpulan
Stack dapat diimplementasikan dalam C++ menggunakan array maupun linked list. Implementasi dengan array melibatkan penggunaan sebuah array untuk menyimpan elemen-elemen Stack dan variabel top untuk melacak indeks elemen teratas. Sementara implementasi dengan linked list melibatkan penggunaan struktur Node yang berisi data dan pointer ke node berikutnya, serta pointer top yang menunjuk ke node teratas.

Stack memiliki banyak aplikasi dalam pemrograman, seperti pembalik string atau angka, evaluasi ekspresi dengan notasi reverse polish, penerapan rekursi, dan algoritma traversal pada graph dan tree. Kompleksitas waktu rata-rata untuk operasi push dan pop pada Stack adalah O(1), yang membuatnya efisien untuk operasi penambahan dan penghapusan elemen.

## Referensi
[1] Reddy, P. K. (2019). Data Structures and Algorithms: Concepts, Techniques and Applications (1st ed.). Prentice Hall.
<br>[2] Sahni, S. (2020). Data Structures, Algorithms, and Applications in C++ (2nd ed.). Universities Press.