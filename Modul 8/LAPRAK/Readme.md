# <h1 align="center">Laporan Praktikum Modul 8 - Algoritma Searching</h1>
<p align="center">Ikram Iriansyah - 2311102184</p>

## Dasar Teori

### A. Searching
Searching (pencarian) pada struktur data mengacu pada proses algoritmik untuk memeriksa, menemukan, mengambil posisi elemen tertentu (target) dari kumpulan elemen seperti array, list, linked list, tree, dan lain sebagainya di dalam struktur data[1]. Algoritma searching digunakan untuk melakukan akses cepat ke data terkait, sehingga dapat mengoptimalkan kinerja program dengan mengurangi waktu komputasi dan penggunaan sumber daya. Terdapat 2 algoritma searching yang biasa digunakan, antara lain sebagai berikut.

#### 1. Sequential Seacrh
Sequential search adalah algoritma pencarian yang paling sederhana. Sequential search disebut juga sebagai linear search (pencarian linear). Sequential search bekerja dengan cara membandingkan setiap elemen yang tersimpan dalam suatu struktur data (misal : array) secara berurutan, dimulai dari elemen pertama, sampai elemen yang diinginkan ditemukan atau semua elemen telah dibandingkan[2]. Sequential search dapat dilakukan pada elemen data yang tidak diurutkan maupun pada elemen data yang diurutkan. Proses pencarian sequential akan singkat jika data yang diolah sedikit. Apabila data yang diolah banyak, prosesnya akan memakan waktu yang lama, sehingga algoritma sequential search hanya direkomendasikan untuk struktur data yang memuat jumlah data yang sedikit.

Berikut ilustrasi sequential search pada array =

![Ikram_Ilustrasi-Sequential-Search-Array](https://github.com/IkramIriansyah486/Structure-Data-Assignment/blob/main/Modul%208/LAPRAK/Ikram_Ilustrasi-Sequential-Search-Array.png)

#### 2. Binary Search
Binary Search adalah algoritma pencarian data pada suatu struktur data (misal : array) yang telah terurut, metode ini lebih efisien daripada metode pencarian linier (sequential search) karena membutuhkan waktu komputasi yang lebih sedikit[3]. Binary search bekerja dengan membagi separuh dari jumlah data yang dicari (membagi jumlah data keseluruhan menjadi 2 bagian, yaitu bagian kanan dan kiri) sehingga memperkecil lokasi pencarian sampai menjadi satu data. Dengan teknik ini data akan dibuang setengah dari jumlah data seluruhnya. Apabila ditemukan kecocokan data maka program akan mengembalikan output, jika tidak pencarian akan terus berlanjut hingga akhir dari pembagian jumlah data tersebut[4]. Algoritma binary search memerlukan data yang sudah terurut sehingga diperlukan metode sorting data (mengurutkan data) seperti bubble sort, selection sort, insertion sort, dll sebelum mencari data menggunakan metode binary search. Dikarenakan algoritma binary search hanya membutuhkan waktu komputasi yang lebih sedikit, algoritma ini sangat direkomendasikan untuk diimplementasikan pada struktur data dengan jumlah data yang besar. Hal ini karena binary search memiliki kompleksitas waktu O(log n), yang jauh lebih efisien dibandingkan dengan sequential search yang memiliki kompleksitas waktu O(n). Dengan demikian, binary search dapat mengoptimalkan kinerja program secara signifikan, terutama ketika berhadapan dengan dataset yang besar.

Berikut ilustrasi binary search pada array =

![Ikram_Ilustrasi-Binary-Search-Array](https://github.com/IkramIriansyah486/Structure-Data-Assignment/blob/main/Modul%208/LAPRAK/Ikram_Ilustrasi-Binary-Search-Array.png)

## Guided 

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data

```C++
#include <iostream>

using namespace std;

int main(){
    int n = 10; //deklarasi variabel n sebagai ukuran array
    int data[10] = {9, 4, 1, 7, 5, 12, 4, 13, 3, 10}; //deklarasi array data 
    int cari = 10; //deklarasi variabel cari dengan nilai 10 (angka yang dicari adalah 10)
    bool ketemu = false; //deklarasi variabel boolean ketemu dengan nilai false
    int i; //deklarasi variabel i

    //Sequential Search untuk mencari angka 10
    for(i=0; i < n; i++){
        if(data[i] == cari){ //jika nilai pada array data index ke i adalah 10, maka 
            ketemu = true; //ubah variabel boolean ketemu menjadi true
            break; //perulangan berhenti
        }
    }

    cout << "Program Sequential Search" << endl;
    cout << "Data = {9, 4, 1, 7, 5, 12, 4, 13, 3, 10}" << endl; //menampilkan isi array data

    if(ketemu){ //jika angka 10 ditemukan, maka tampilkan
        cout << "\nAngka " << cari << " ditemukan pada indeks ke " << i << endl; 
    } else { //jika angka 10 tidak ditemukan, maka tampilkan
        cout << "Data tidak ditemukan!" << endl;
    }

    return 0;
}
```

#### Deskripsi Program
Kode diatas merupakan program implementasi sequential search sederhana untuk melakukan pencarian data. Pada awal program dideklarasikan array bernama `data` dengan ukuran 10 beserta isinya yaitu 9, 4, 1, 7, 5, 12, 4, 13, 3, 10. Kemudian dideklarasikan variabel `n` dan `cari` dengan nilai 10 (variabel `n` menandakan panjang array sedangkan variabel `cari` menunjukkan angka yang ingin dicari), variabel boolean `ketemu` dengan nilai false, dan variabel `i`. Program ini bertujuan untuk mencari angka 10 didalam array tersebut dan menampilkan indexnya. Sequential search pada program ini diimplementasikan dengan pengulangan for yang membandingkan setiap elemen atau data yang tersimpan didalam array apakah sesuai dengan angka yang ingin dicari (dalam hal ini angka 10). Jika angka yang dicari ditemukan, maka akan menampilkan "angka (10) ditemukan pada index ke (index angka 10 didalam array `data`)". Jika angka yang dicari tidak ditemukan, maka akan menampilkan "Data tidak ditemukan!".

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search

```C++
#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;

int dataArray[7] = {1, 8, 2, 5, 4, 9, 7}; //deklarasi array dataArray beserta isinya
int cari; //deklarasi variabel cari

//prosedur Selection_Sort untuk mengurutkan data secara ascending
void Selection_Sort(){
    int temp, min, i, j; 
    for(i = 0; i < 7; i++){ //perulangan for untuk memeriksa setiap data 
        min = i; //nilai min adalah 0
        for(j = i + 1; j < 7; j++){ //nilai j adalah 1
            if(dataArray[j] < dataArray[min]){ //jika nilai pada dataArray index ke j (1) kurang dari nilai pada dataArray index ke i (0), maka 
                min = j; //nilai min adalah j
            }
        }
        temp = dataArray[i]; //masukkan nilai pada dataArray index ke i kedalam temp
        dataArray[i] = dataArray[min]; //isi dataArray index ke i dengan dataArray index min (j)
        dataArray[min] = temp; //isi dataArray index min (j) dengan nilai temp
    }
}

//prosedur BinarySearch untuk mencari data
void BinarySearch(){
    int awal, akhir, tengah; //deklarasi variabel awal, akhir, tengah
    bool b_flag = false; //deklarasi variabel boolean b_flag dengan nilai false 
    awal = 0; //nilai awal adalah 0
    akhir = 6; //nilai akhir adalah 6
    while(!b_flag && awal <= akhir){
        tengah = (awal + akhir)/2; //menghitung nilai tengah
        if(dataArray[tengah] == cari){ //jika data yang dicari berada di tengah, maka
            b_flag = true; //ubah b_flag menjadi true
        } else if(dataArray[tengah] < cari){  //jika data yang dicari lebih besar dari data yang ditengah (data berada di kanan), maka
            awal = tengah + 1; //nilai awal adalah tengah + 1
        } else { //jika data yang dicari lebih kecil dari data yang ditengah (data berada di kiri), maka
            akhir = tengah - 1; //nilai akhir adalah tengah - 1
        }
    }
    if(b_flag){ //jika data ditemukan, maka tampilkan 
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    } else { //jika data tidak ditemukan, maka tampilkan
        cout << "\nData tidak ditemukan" << endl;
    }
}

int main(){
    cout << "BINARY SEARCH" << endl;
    cout << "\nData : ";
    //Perulangan untuk menampilkan data
    for(int x = 0; x < 7; x++){
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    //user menginputkan data yang ingin dicari
    cout << "Masukkan data yang ingin dicari : ";
    cin >> cari;
    
    cout << "\nData diurutkan : ";
    Selection_Sort(); //pemanggilan prosedur Selection_Sort() untuk mengurutkan data secara ascending

    //Perulangan untuk menampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++){
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    BinarySearch(); //pemanggilan prosedur BinarySearch() untuk mencari data yang ingin dicari
    _getche();
    return 0;
}
```

#### Deskripsi Program
Kode diatas merupakan program implementasi binary search untuk mencari data pada array. Syarat untuk mencari suatu data menggunakan algoritma binary search adalah data harus diurutkan terlebih dahulu sehingga pada program ini juga memuat algoritma selection sort untuk mengurutkan data secara ascending. Pada awal program dideklarasikan array bernama `dataArray[]` dengan ukuran 7 beserta isinya yaitu 1, 8, 2, 5, 4, 9, 7; serta dideklarasikan variabel `cari` untuk menyimpan data atau angka yang ingin dicari. Pada program ini juga terdapat 2 prosedur yaitu :
- void Selection_Sort(); merupakan prosedur sorting menggunakan algoritma selection sort yang digunakan untuk mengurutkan data secara ascending (dari terkecil ke terbesar).
- void BinarySearch(); merupakan prosedur searching menggunakan algoritma binary search yang digunakan untuk mencari suatu data yang disimpan pada array `dataArray[]` dan menampilkan indexnya

Berikut cara kerja program :
- Program menampilkan isi dari `dataArray[]` berupa angka-angka
- user memasukkan angka yang ingin dicari kemudian disimpan pada variabel `cari`
- Program memanggil prosedur `Selection_Sort()` untuk mengurutkan data dari terkecil ke terbesar (ascending). Selection sort bekerja dengan membandingkan elemen sekarang dengan elemen selanjutnya, apabila elemen selanjutnya nilainya lebih kecil daripada elemen sekarang, maka tukar posisi keduanya. Proses ini diulang hingga data terakhir dalam array diperiksa
- Program menampilkan data yang telah diurutkan
- Program memanggil prosedur `BinarySearch()` untuk mencari data didalam array `dataArray[]`. Jika data ditemukan maka tampilkan index data tersebut, sedangkan jika data tidak ditemukan maka tampilkan "Data tidak ditemukan". Binary search bekerja dengan membagi array menjadi 2 bagian (kiri dan kanan yang dipisahkan dengan tengah). Apabila data yang dicari nilainya lebih kecil dari data yang ditengah, maka program akan memproses data bagian kiri, sebaliknya Apabila data yang dicari nilainya lebih besar dari data yang ditengah, maka program akan memproses data bagian kanan. Kemudian bagian data tersebut akan dibagi 2 lagi menjadi bagian kiri dan kanan. Proses ini akan berulang hingga bagian kanan dan kiri hanya terdiri dari 1 data saja.

## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
//IKRAM IRIANSYAH
//2311102184

#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;

int dataArray[7] = {1, 8, 2, 5, 4, 9, 7}; //deklarasi array dataArray beserta isinya
int cari; //deklarasi variabel cari

//prosedur Selection_Sort untuk mengurutkan data secara ascending
void Selection_Sort(){
    int temp, min, i, j; 
    for(i = 0; i < 7; i++){ //perulangan for untuk memeriksa setiap data 
        min = i; //nilai min adalah 0
        for(j = i + 1; j < 7; j++){ //nilai j adalah 1
            if(dataArray[j] < dataArray[min]){ //jika nilai pada dataArray index ke j (1) kurang dari nilai pada dataArray index ke i (0), maka 
                min = j; //nilai min adalah j
            }
        }
        temp = dataArray[i]; //masukkan nilai pada dataArray index ke i kedalam temp
        dataArray[i] = dataArray[min]; //isi dataArray index ke i dengan dataArray index min (j)
        dataArray[min] = temp; //isi dataArray index min (j) dengan nilai temp
    }
}

//prosedur BinarySearch untuk mencari data
void BinarySearch(){
    int awal, akhir, tengah; //deklarasi variabel awal, akhir, tengah
    bool b_flag = false; //deklarasi variabel boolean b_flag dengan nilai false 
    awal = 0; //nilai awal adalah 0
    akhir = 6; //nilai akhir adalah 6
    while(!b_flag && awal <= akhir){
        tengah = (awal + akhir)/2; //menghitung nilai tengah
        if(dataArray[tengah] == cari){ //jika data yang dicari berada di tengah, maka
            b_flag = true; //ubah b_flag menjadi true
        } else if(dataArray[tengah] < cari){  //jika data yang dicari lebih besar dari data yang ditengah (data berada di kanan), maka
            awal = tengah + 1; //nilai awal adalah tengah + 1
        } else { //jika data yang dicari lebih kecil dari data yang ditengah (data berada di kiri), maka
            akhir = tengah - 1; //nilai akhir adalah tengah - 1
        }
    }
    if(b_flag){ //jika data ditemukan, maka tampilkan 
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    } else { //jika data tidak ditemukan, maka tampilkan
        cout << "\nData tidak ditemukan" << endl;
    }
}

int main(){
    cout << "BINARY SEARCH" << endl;
    cout << "\nData : ";
    //Perulangan untuk menampilkan data
    for(int x = 0; x < 7; x++){
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    //user menginputkan data yang ingin dicari
    cout << "Masukkan data yang ingin dicari : ";
    cin >> cari;
    
    cout << "\nData diurutkan : ";
    Selection_Sort(); //pemanggilan prosedur Selection_Sort() untuk mengurutkan data secara ascending

    //Perulangan untuk menampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++){
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    BinarySearch(); //pemanggilan prosedur BinarySearch() untuk mencari data yang ingin dicari
    _getche();
    return 0;
}
```

#### Output:

##### Output Jika Huruf Ditemukan
![Ikram-Output-Unguided 1-1]()

##### Output Jika Huruf Tidak Ditemukan
![Ikram-Output-Unguided 1-2]()

#### Deskripsi Program
Kode diatas merupakan program untuk mencari sebuah huruf pada sebuah kalimat yang diinputkan user kemudian menampilkan indexnya. Program ini menggunakan algoritma binary search untuk mencari huruf yang dimaksud. Dikarenakan syarat untuk menggunakan binary search adalah data atau huruf harus sudah dalam bentuk terurut, maka pada program ini juga disertakan algoritma bubble sort untuk mengurutkan huruf secara ascending (dari terkecil ke terbesar). 

Berikut cara kerja program :
- Pada awal int main(), program mendeklarasikan variabel `InputKalimat_184`, `KalimatTanpaSpasi_184`, `PanjangKalimat_184`, dan `HurufYangDicari_184`.
- user menginputkan kalimat yang ingin dicari hurufnya, kalimat ini dimasukkan kedalam variabel `InputKalimat_184`
- Program melakukan perulangan for-each yang memecah kalimat yang diinputkan menjadi elemen atau huruf-huruf penyusunnya. Kemudian jika elemen yang saat ini diperiksa bukan sama dengan spasi, maka masukkan elemen atau huruf tersebut ke variabel `KalimatTanpaSpasi_184`
- Program menghitung panjang elemen atau huruf yang disimpan pada variabel `KalimatTanpaSpasi_184`. Nilai panjang elemen tersebut disimpan pada variabel `PanjangKalimat_184`
- Program melakukan perulangan untuk memasukkan semua huruf yang tersimpan di variabel `KalimatTanpaSpasi_184` kedalam array `ArrayKalimat_184[]` yang kemudian array tersebut akan digunakan sebagai parameter dalam prosedur `TampilkanHurufKalimat_184()`, `BubbleSort_184()`, dan `BinarySearch_184()`
- Program akan memanggil prosedur `TampilkanHurufKalimat_184()` untuk menampilkan huruf-huruf penyusun kalimat yang diinputkan user dengan karakter spasi yang sudah terhapus
- Kemudian program akan mengurutkan huruf-huruf tersebut secara ascending (dari terkecil dan terbesar) dengan menggunakan prosedur `ubbleSort_184()` dan menampilkannya kembali menggunakan prosedur `TampilkanHurufKalimat_184()`
- Kemudian user diminta memasukkan huruf yang ingin dicari didalam array beserta nomor indexnya. huruf yang diinputkan user akan dimasukkan kedalam variabel `HurufYangDicari_184`.
- Program akan memanggil prosedur `BinarySearch_184()` untuk mencari huruf tersebut dan menampilkan nomor indexnya. Apabila huruf tersebut ditemukan, maka akan menampilkan "Huruf `HurufYangDicari_184` ditemukan pada index ke-(nomor index huruf)". Sedangkan apabila huruf tersebut tidak ditemukan, maka akan menampilkan "Huruf `HurufYangDicari_184` tidak ditemukan".
Binary search bekerja dengan membagi array menjadi 2 bagian (kiri dan kanan yang dipisahkan dengan tengah). Apabila data atau huruf yang dicari nilainya lebih kecil dari data yang ditengah, maka program akan memproses data bagian kiri, sebaliknya Apabila data atau huruf yang dicari nilainya lebih besar dari data yang ditengah, maka program akan memproses data bagian kanan. Kemudian bagian data tersebut akan dibagi 2 lagi menjadi bagian kiri dan kanan. Proses ini akan berulang hingga bagian kanan dan kiri hanya terdiri dari 1 data saja.


### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
//IKRAM IRIANSYAH
//2311102184

#include<iostream>

using namespace std;

//Prosedur sequential search untuk mencari huruf vokal 
void SequentialSearch_184(char ArrayKalimat_184[], int PanjangKalimat_184){
    int JumlahHurufVokal_184 = 0; //deklarasi variabel JumlahHurufVokal dengan nilai 0
    char HurufVokal_184[PanjangKalimat_184]; //deklarasi array HurufVokal dengan ukuran PanjangKalimat_184 untuk menyimpan huruf vokal yang ditemukan dalam kalimat
    for(int i = 0; i < PanjangKalimat_184; i++){ //perulangan untuk memeriksa setiap huruf didalm kalimat
        //jika dalam ArrayKalimat_184[] index ke i ditemukan huruf vokal (a, A, i, I, u, U, e, E, o, O), maka 
        if(ArrayKalimat_184[i] == 'a' || ArrayKalimat_184[i] == 'A' || ArrayKalimat_184[i] == 'i' || ArrayKalimat_184[i] == 'I' || ArrayKalimat_184[i] == 'u' || ArrayKalimat_184[i] == 'U' || ArrayKalimat_184[i] == 'e' || ArrayKalimat_184[i] == 'E' || ArrayKalimat_184[i] == 'o' || ArrayKalimat_184[i] == 'O'){
            HurufVokal_184[JumlahHurufVokal_184] = ArrayKalimat_184[i]; //masukkan huruf vokal tersebut kedalam array HurufVokal[] 
            JumlahHurufVokal_184++; //variabel JumlahHurufVokal bertambah nilainya
        }
    }
    if(JumlahHurufVokal_184 != 0){ //jika nilai variabel JumlahHurufVokal bukan sama dengan 0 (ditemukan huruf vokal), maka tampilkan jumlah huruf vokal yang ditemukan beserta huruf-hurufnya
        cout << "Kalimat ini memiliki " << JumlahHurufVokal_184 << " huruf vokal, yaitu : ";
        for(int i = 0; i < JumlahHurufVokal_184; i++){
            cout << HurufVokal_184[i];
            if(i < JumlahHurufVokal_184 - 1){
                cout << ", ";
            }
        }
    } else { //jika nilai variabel JumlahHurufVokal sama dengan 0 (tidak ditemukan huruf vokal), maka tampilkan "Kalimat ini tidak memiliki huruf vokal"
        cout << "Kalimat ini tidak memiliki huruf vokal" << endl;
    }
}

int main(){
    string InputKalimat_184; //deklarasi variabel string InputKalimat_184 
    int PanjangKalimat_184; //deklarasi variabel integer PanjangKalimat_184
    cout << "--- PROGRAM PENGHITUNG HURUF VOKAL ---" << endl;
    cout << "Masukkan kalimat = ";
    getline(cin, InputKalimat_184); //user memasukkan kalimat kemudian disimpan pada variabel InputKalimat_184
    cout << endl;

    //Menghitung panjang karakter dalam kalimat
    PanjangKalimat_184 = InputKalimat_184.length();

    //memasukkan karakter dalam kalimat kedalam array
    char ArrayKalimat_184[PanjangKalimat_184]; //deklarasi array char ArrayKalimat[] dengan ukuran PanjangKalimat_184
    //perulangan for-each yang memecah kalimat dalam InputKalimat_184 mejadi huruf-huruf penyusunnya, kemudian masukkan huruf-huruf tersebut kedalam ArrayKalimat[]
    for(int i = 0; i < PanjangKalimat_184; i++){
        ArrayKalimat_184[i] = InputKalimat_184[i];
    }

    //pemanggilan prosedur SequentialSearch_184() untuk mencari huruf vokal, menghitung jumlahnya, dan menampilkan huruf-hurufnya
    SequentialSearch_184(ArrayKalimat_184, PanjangKalimat_184);

    return 0;
}
```

#### Output:

##### Output Jika Kalimat Memiliki Huruf Vokal
![Ikram_Output-Unguided 2-1]()

##### Output Jika Kalimat Tidak Memiliki Huruf Vokal
![Ikram_Output-Unguided 2-2]()

#### Deskripsi Program
Kode diatas merupakan program untuk menghitung jumlah huruf vokal yang ada dalam kalimat yang diinputkan user. Program ini menggunakan algoritma sequential search untuk mencari huruf vokal yang ada, menghitung jumlahnya, dan menampilkan huruf-hurufnya. 

Berikut cara kerja program :
- User menginputkan kalimat yang ingin dihitung jumlah huruf vokalnya. Kalimat tersebut akan disimpan dalam variabel `InputKalimat_184`
- Program akan menghitung panjang kalimat tersebut dan menyimpannya dalam variabel `PanjangKalimat_184`
- Program mendeklarasikan array bernama `ArrayKalimat_184` dengan panjang nilai variabel `PanjangKalimat_184`, array ini digunakan untuk menyimpan huruf-huruf penyusun kalimat yang telah diinputkan user
- Program akan memecah kalimat tersebut menjadi huruf-huruf penyusunnya, kemudian huruf-huruf tersebut akan disimpan pada `ArrayKalimat_184[]`
- Program memanggil prosedur `SequentialSearch_184()` untuk mencari huruf vokal diantara huruf-huruf penyusun kalimat tersebut, menghitung jumlahnya, dan menampilkan huruf-hurufnya. Prosedur ini bekerja dengan memeriksa setiap huruf yang tersimpan apabila terdapat huruf vokal (a, A, i, I, u, U, e, E, o, O), maka simpan huruf vokal tersebut dalam array `HurufVokal_184[]` dan jumlah huruf vokal tersebut disimpan pada variabel `JumlahHurufVokal_184`.
- Jika nilai variabel `JumlahHurufVokal_184` bukan sama dengan 0 (ditemukan huruf vokal), maka tampilkan jumlahnya beserta huruf-hurufnya
- Jika nilai variabel `JumlahHurufVokal_184` sama dengan 0 (tidak ditemukan huruf vokal), maka tampilkan "Kalimat ini tidak memiliki huruf vokal".

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
//IKRAM IRIANSYAH
//2311102184

#include<iostream>

using namespace std;

int main(){
    int ArrayData_184[10] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; //Deklarasi array bernama ArrayData_184 dengan ukuran 10 
    int CariAngka_184; //Deklarasi variabel CariAngka_184 yang menampung angka yang ingin dicari
    int JumlahAngka_184 = 0; //Deklarasi variabel JumlahAngka_184 dengan nilai 0 untuk menghitung jumlah angka yang ingin dicari yang ada pada array
    int IndexAngka_184[10]; //Deklarasi array IndexAngka_184 dengan ukuran 10 untuk menyimpan index dari angka yang dicari didalam array ArrayData_184
    int j = 0; //Deklarasi variabel j
    cout << "--- PROGRAM PENGHITUNG ANGKA DALAM ARRAY ---" << endl;
    cout << "Diketahui sebuah array berisi data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;
    cout << "Masukkan angka yang ingin dihitung jumlahnya = "; //User memasukkan angka yang ingin dihitung jumlahnya
    cin >> CariAngka_184;
    cout << endl;

    //Sequential Search
    for(int i = 0; i < 10; i++){
        if(ArrayData_184[i] == CariAngka_184){ //Jika setiap data yang tersimpan pada array ArrayData_184 sama dengan angka yang diinputkan user yang ingin dihitung jumlahnya, maka lanjutkan
            JumlahAngka_184++; //variabel JumlahAngka_184 bertambah nilainya
            IndexAngka_184[j++] = i; //nilai i dimasukkan ke array IndexAngka_184 indeks ke j++ (0)
        }
    }

    if(JumlahAngka_184 != 0){ //jika variabel JumlahAngka_184 nilainya tidak sama dengan 0, maka lanjutkan
        cout << "Array tersebut memiliki angka " << CariAngka_184 << " sebanyak " << JumlahAngka_184 << endl;
        cout << "Ditemukan pada index ke-";
        //perulangan untuk menampilkan index dari angka yang dicari
        for(int i = 0; i < JumlahAngka_184; i++){
            cout << IndexAngka_184[i];
            if(i < j - 1){
                cout << ", ";
            }
        }
    } else { //jika variabel JumlahAngka_184 nilainya sama dengan 0, maka lanjutkan
        cout << "Array tersebut tidak berisi angka " << CariAngka_184 << endl;
    }
    
    return 0; 
}
```

#### Output:

##### Output Jika Angka Yang Dicari Ditemukan 
![Ikram_Output-Unguided 3-1]()

##### Output Jika Angka Yang Dicari Tidak Ditemukan
![Ikram_Output-Unguided 3-2]()

#### Deskripsi Program
Kode diatas merupakan program yang dapat menghitung jumlah angka (dalam hal ini angka 4) yang ada didalam suatu array. Program ini memakai algoritma sequential search untuk mencari angka yang ingin dicari kemudian menampilkan jumlah angka tersebut yang tersimpan beserta nomor indexnya. Pada awal program dideklarasikan beberapa variabel dan array, antara lain : 
- array `ArrayData_184[]` dengan ukuran 10 beserta isinya yaitu 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. 
- Variabel `CariAngka_184` untuk menampung angka yang ingin dicari
- Variabel `JumlahAngka_184` dengan nilai 0 untuk menampung jumlah angka yang ingin dicari yang tersimpan didalam array `ArrayData_184[]`
- Array `IndexAngka_184[]` dengan ukuran 10 untuk menyimpan nomor index dari angka yang ingin dicari
- Variabel `j` dengan nilai 0 untuk digunakan dalam perulangan

Berikut cara kerja program :
- Program menampilkan menu "PROGRAM PENGHITUNG ANGKA DALAM ARRAY" kemudian menampilkan array beserta isinya yang sebelumnya telah dideklarasikan (dalam hal ini array `ArrayData_184[]`)
- user menginputkan angka yang ingin dicari apakah ada didalam array yang telah ditampilkan (misal angka 4). Angka tersebut akan dimasukkan kedalam variabel `CariAngka_184`
- Program akan menjalankan squential search, apabila dalam perulangan ditemukan angka yang dicari (angka 4), maka variabel `JumlahAngka_184` akan bertambah nilainya dan nilai index dari angka yang dicari (angka 4) akan dimasukkan kedalam array `IndexAngka_184[]`
- Jika nilai variabel `JumlahAngka_184` bukan sama dengan 0, maka akan menampilkan "Array tersebut memiliki angka `CariAngka_184` sebanyak `JumlahAngka_184`" dan dibawahnya akan menampilkan "Ditemukan pada index ke-(nomor index yang tersimpan di array `IndexAngka_184[]`)"
- Jika nilai variabel `JumlahAngka_184` sama dengan 0, maka akan menampilkan "Array tersebut tidak berisi angka `CariAngka_184`"

## Kesimpulan
Searching (pencarian suatu data) adalah hal yang penting dalam struktur data. Searching memungkinkan akses cepat ke data terkait, sehingga dapat mengoptimalkan kinerja program dengan mengurangi waktu komputasi. Terdapat 2 algoritma searching yang sering digunakan yaitu sequential search dan binary search. Sequential search bekerja dengan membandingkan setiap elemen yang tersimpan pada struktur data apakah sama dengan data yang dicari. Sequential search memiliki kompleksitas waktu O(n), artinya waktu pencarian meningkat secara linear dengan jumlah elemen. Binary search bekerja dengan membagi data keseluruhan menjadi 2 bagian (kanan dan kiri) yang dipisahkan dengan elemen tengah. Apabila elemen tengah nilainya kurang dari data yang dicari, maka pencarian dilakukan di bagian kanan. Sebaliknya apabila elemen tengah nilainya lebih dari data yang dicari, maka pencarian dilakukan di bagian kiri. Proses pembagian data ini terus berlanjut hingga menyisakan elemen tengah saja sebagai data yang dicari  atau ruang pencarian habis. Binary search memiliki kompleksitas waktu O(log n), yang membuatnya jauh lebih efisien untuk data yang jumlahnya lebih besar dibandingkan dengan sequential search.

## Referensi
[1] Putri, M. P., et al. (2022). "Algoritma dan Struktur Data". Bandung: Widina Bhakti Persada Bandung. ISBN 978-623-459-182-8. Retrieved from https://repository.penerbitwidina.com/id/publications/557434/. 
<br>[2] Wahyuni, W. S., Andryana, S., & Rahman, B. (2022). "Penggunaan Algoritma Sequential Searching Pada Aplikasi Perpustakaan Berbasis Web". JIPI (Jurnal Ilmiah Penelitian dan Pembelajaran Informatika), 7(2), 294-302. Retrieved from https://doi.org/10.29100/jipi.v7i2.2646. 
<br>[3] Mone, leonard, & Pekuwali, A. (2023). "Penerapan Algoritma Binary Search Pada Sistem Informasi Perpustakaan Di SMP Negeri 4 Mauliru". SENTIMAS: Seminar Nasional Penelitian Dan Pengabdian Masyarakat, 1(1), 360-367. Retrieved from https://journal.irpi.or.id/index.php/sentimas/article/view/738.
<br>[4] Sitompul, B. J. D., Yusupa, A., & Tuturoong, N. J. (2022). "IMPLEMENTASI ALGORITMA BINARY SEARCH PADA PENCARIAN DATA JEMAAT GEREJA HKBP MANADO". Jurnal Informatika Polinema, 9(1), 17–24. Retrieved from https://doi.org/10.33795/jip.v9i1.1123. 