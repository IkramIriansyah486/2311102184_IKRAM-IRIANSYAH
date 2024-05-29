# <h1 align="center">Laporan Praktikum Modul 9 - Graph and Tree</h1>
<p align="center">Ikram Iriansyah - 2311102184</p>

## Dasar Teori
### A. Graph
Graf adalah sekumpulan simpul/vertex/titik/node didalam bidang 2 dimemnsi yang dihubungkan dengan sekumpulan garis atau sisi[1]. Graf merupakan suatu sistem yang terdiri atas suatu himpunan objek V = {v1, v2, …} yang disebut himpunan titik dan sebuah koleksi E = {ei, e2, …} yang merupakan koleksi sisi sedemikian hingga tiap sisi ek dikaitkan dengan suatu pasangan tak-terurut (v1, vj)[2]. Teori graf lahir pada tahun 1736 melalui tulisan Euler yang berisi tentang upaya pemecahan masalah jembatan Konigsberg yang sangat terkenal di Eropa. Graph dapat digunakan untuk merepresentasikan objek-objek diskrit dan hubungan antara objek-objek tersebut. Secara matematis, Graph dinyatakan dengan :
<br>G = (V, E)
<br>Dengan G menyatakan graph, V menyatakan simpul (vertex), dan E menyatakan sisi (edge)
<br>Simpul pada graf dapat dinomori dengan huruf seperti a, b, c, d, dst atau bisa dengan bilangan asli 1, 2, 3, dst atau gabungan keduanya. Sedangkan sisi yang menghubungkan simpul a dan b dinyatakan dalam sepasang (a,b) atau dinyatakan dalam lambang e1, e2, e3, dst. Berikut merupakan contoh graf.

![Ikram_Contoh-Graph](https://github.com/IkramIriansyah486/Structure-Data-Assignment/blob/main/Modul%209/LAPRAK/Ikran_Contoh-Graph.png)

Dalam kehidupan sehari-hari, graph digunakan untuk mencari rute terpendek pada GPS, memodelkan struktur internet dan routing data, perencanaan rute dan jadwal transportasi umum, dll.
<br>Terdapat beberapa jenis graph, antara lain sebagai berikut[1].

#### 1. Graph Berarah (Directed Graph)
Graph berarah adalah jenis graph di mana setiap sisi (edge) memiliki arah tertentu. Dalam graf berarah, sisi-sisi tersebut disebut panah (arc), yang menghubungkan sepasang simpul (vertex) dengan urutan tertentu, sehingga setiap urutan simpul mempunyai arti tersendiri. Berikut merupakan contoh graph berarah.

![Ikram_Contoh-Graph-Berarah](https://github.com/IkramIriansyah486/Structure-Data-Assignment/blob/main/Modul%209/LAPRAK/Ikram_Contoh-Graph-Berarah.png)

#### 2. Graph Tak Berarah (Undirected Graph)
Graph tak berarah adalah jenis graph di mana setiap sisi (edge) tidak memiliki arah tertentu. Pada graph tak berarah, urutan simpul dalam sebuah busur tidak dipentingkan. Berikut merupakan contoh graph tak berarah.

![Ikram_Contoh-Graph-TakBerarah]()

#### 3. Graph Berbobot (Weight Graph)
Graph berbobot adalah jenis graph yang memiliki bobot pada setiap sisinya. Bobot sebuah busur dapat menyatakan panjang sebuah jalan dari 2 buah titik, jumlah rata-rata kendaraan perhari yang melalui sebuah jalan, dll. Berikut contoh graph berbobot. 

![Ikram_Contoh-Graph-Berbobot]()

Graph dapat direpresentasikan dalam berbagai bentuk, antara lain matriks ketetanggaan, matrik bersisian, dan senarai ketetanggaan[2].

#### 1. Representasi Graph Menggunakan Matriks
Matriks berbobot W untuk graf berbobot G dengan n simpul adalah matriks berukuran n × n, di mana elemen W[i][j] menyatakan bobot dari sisi yang menghubungkan simpul i ke simpul j. Jika tidak ada sisi yang menghubungkan i dan j, maka W[i][j] biasanya diisi dengan nilai tertentu (seperti ∞ atau 0) untuk menunjukkan tidak adanya koneksi. Berikut contoh representasi graph menggunakan matriks.

![Ikram_Representasi-Matriks]()

#### 2. Representasi Graph Menggunakan Linked List
Representasi graph menggunakan linked list adalah metode untuk menyimpan graph yang menghubungkan simpul-simpulnya melalui daftar terhubung, di mana setiap sisi graf memiliki bobot yang terkait. Berikut contoh representasi graph menggunakan linked list.

![Ikram_Representasi-LinkedList]()

### B. Pohon (Tree)
Pohon adalah struktur data yang mirip dengan daftar tertaut tetapi alih-alih setiap simpul menunjuk hanya ke simpul berikutnya secara linier, setiap simpul menunjuk ke sejumlah simpul[3]. Pohon adalah contoh struktur data non-linier. Struktur data tree digunakan untuk menyimpan data-data hirarki seperti pohon keluarga, skema pertandingan, struktur organisasi. Terdapat beberapa istilah dalam pohon, antara lain sebagai berikut[4].

![Ikram_Istilah-Tree]()

- Root (akar) adalah node dengan hirarki tertinggi.
- Parent adalah node yang berada satu level di atas node yang ditinjau (parent adalah node yang memiliki child).
- Sibling adalah node-node yang memiliki parent yang sama dengan node yang ditinjau.
- Child adalah node yang berada dibawah node parent.
- Leaf adalah node yang tidak memiliki child.
- Subtree adalah pohon yang terdiri dari sebuah simpul (node) dalam pohon utama beserta semua turunannya (descendants).
- Level atau aras adalah posisi atau kedalaman suatu simpul (node) dalam pohon, dimulai dari level 0 pada node root.
- Size adalah banyaknya node dalam suatu tree.
- Height adalah banyaknya tingkatan atau level dalam suatu tree.
- Degree adalah banyaknya child dalam suatu node.
- Descendant adalah seluruh node yang terletak setelah node tertentu dan terletak pada jalur yang sama.

Untuk membuat struktur data tree pada bahasa pemrograman C++, dapat dilakukan beberapa operasi, antara lain sebagai berikut.

- Create; digunakan untuk membuat tree baru.
- Clear; digunakan untuk menghapus tree.
- isEmpty; digunakan untuk memeriksa apaah tree kosong atau tidak.
- insert (left or right); digunakan untuk menambah node child (kanan maupun kiri).
- Find; digunakan untuk mencari root, parent, left child, atau right child dari suatu node.
- Update; digunakan untuk mengubah isi dari node yang ditunjuk.
- Retrieve; digunakan untuk mengetahui isi dari node yang ditujuk.
- Charasteristic; digunakan untuk mengetahui karakteristik dari suatu tree, yakni size, height, dan average length-nya
- Traverse; digunakan untuk mengunjungi seluruh node dengan cara traversal. Terdapat 3 metode traverse, yaitu PreOrder (mencetak root - child kiri - child kanan), InOrder (mencetak child kiri - root - kanan), dan PostOrder (mencetak child kiri - child kanan - root).

## Guided 

### 1. Program Graph

```C++
#include <iostream>
#include <iomanip>

using namespace std;

//Deklarasi array simpul yang berisi nama-nama kota
string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

//Deklarasi array busur 2 dimensi yang berisi bobot atau nilai antar kota
int busur[7][7]= {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

//Prosedur TampilGraph untuk menampilkan kota dengan bobot jarak ke kota lainnya
void TampilGraph(){
    for(int baris = 0; baris < 7; baris++){
        cout << " " << setiosflags(ios :: left) << setw(15) << simpul[baris] << " : ";
        for(int kolom = 0; kolom < 7; kolom++){
            if(busur[baris][kolom] != 0){
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        } cout << endl;
    }
}

int main(){
    //Pemanggilan prosedur TampilGraph
    TampilGraph();

    return 0;
}
```

#### Deskripsi Program
Kode diatas merupakan program implementasi graph sederhana. Pada program ini terdapat beberapa simpul yang merepresentasikan nama-nama kota dan busur yang merepresentasikan bobot atau jarak antar kota. Pada awal program dideklarasikan array `simpul` dengan ukuran 7 yang berisi nama-nama kota. kemudian dideklarasikan array 2 dimensi bernama `busur` berukuran 7x7 yang berisi bobot atau nilai antar kota. Kemudian dideklarasikan prosedur bernama `TampilGraph` untuk menampilkan kota-kota beserta bobotnya dalam bentuk matriks. Pada int main() dipanggil prosedur `TampilGraph` untuk menampilkan matriks tersebut.

### 2. Program Tree
```C++
#include <iostream>
#include <iomanip>
    using namespace std;

//Deklarasi struct pohon yang nodenya berisi variabel data
struct Pohon{
    char data;
    Pohon *left, *right, *parent; //deklarasi node left, right, dan parent 
};
Pohon *root, *baru; //Deklarasi node root dan node baru

//Prosudr inisialisasi
void init(){
    root = NULL; //Menyatakan node root adalah NULL
}

//Fungsi isEmpty untuk memeriksa apakah tree kosong atau tidak
bool isEmpty(){
    return root == NULL;
}

//Prosedur buatNode untuk membuat node baru
void buatNode(char data){
    if (isEmpty())
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat sebagai root."
             << endl;
    }
    else
    {
        cout << "\n Tree sudah ada!" << endl;
    }
}

//Fungsi untuk membuat node child kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kiri !" << endl;
                return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
                return baru;
        }
    }
}

//Fungsi untuk membuat node child kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kanan !" << endl;
                return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
                return baru;
        }
    }
}

//Prosedur untuk mengupdate nilai suatu node
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi "
                 << data << endl;
        }
    }
}

//Prosedur untuk menunjuk suatu node
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data node : " << node->data << endl;
        }
    }
}

//Prosedur untuk mencari suatu node kemudian menampilkan root, parent, sibling, dan child node tersebut
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
//Prosedur untuk menampilkan traversal secara pre order
void preOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

//Prosedur untuk menampilkan traversal secara in order
void inOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

//Prosedur untuk menampilkan traversal secara post order
void postOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

//Prosedur untuk menhapus sebuah node didalam tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

//Prosedur untuk menghapus sub tree
void deleteSub(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}

//Prosedur untuk menghapus seluruh tree
void clear()
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    }
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}

//Fungsi untuk memeriksa jumlah node (size) didalam tree
int size(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

//Fungsi untuk memeriksa level atau aras (height) tree
int height(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

//Prosedur untuk memeriksa karakteristik tree
void characteristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}

int main()
{
    buatNode('A'); //buat node A sebagai root
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ; //deklarasi node B-J
    
    nodeB = insertLeft('B', root), //tambah node B sebagai child kiri node A
    nodeC =  insertRight('C', root), //tambah node C sebagai child kanan node A
    nodeD = insertLeft('D', nodeB), //tambah node D sebagai child kiri node B
    nodeE = insertRight('E', nodeB), //tambah node e sebagai child kanan node B
    nodeF = insertLeft('F', nodeC), //tambah node F sebagai child kiri node C
    nodeG = insertLeft('G', nodeE), //tambah node G sebagai child kiri node E
    nodeH = insertRight('H', nodeE), //tambah node H sebagai child kanan node E
    nodeI = insertLeft('I', nodeG), //tambah node I sebagai child kiri node G
    nodeJ = insertRight('J', nodeG); //tambah node J sebagai child kanan node G

    update('Z', nodeC); //update (ubah) nama node C menjadi Z
    update('C', nodeC); //update (ubah) kembali nama node C menjadi C

    retrieve(nodeC); //Tunjuk node C

    find(nodeC); //Mencari node C dan menampilkan root, parent, sibling, dan child node tersebut

    characteristic(); //Menampilkan karakteristik tree

    //Menampilkan traversal tree secara pre order
    cout << "PreOrder : " << endl;
    preOrder(root);
    cout << "\n" << endl;

    //menampilkan traversal tree secara in order
    cout << "InOrder : " << endl;
    inOrder(root);
    cout << "\n" << endl;

    //menampilkan traversal tree secara post order
    cout << "PostOrder : " << endl;
    postOrder(root);
    cout << "\n" << endl;

    return 0;
}
```

#### Deskripsi Program
Kode diatas merupakan program implementasi tree atau pohon menggunakan struct. Manipulasi tree pada program ini menggunakan fungsi dan prosedur yang telah dituliskan pada bagian int main(). Setiap fungsi dan prosedur memiliki aksi berbeda beda. Terdapat beberapa fungsi dan prosedur yang dapat digunakan untuk memanipulasi tree, antara lain :
- struct Pohon; digunakan untuk mendeklarasikan struct Pohon.
- void init(); digunakan untuk menginisialisasi root sebagai NULL.
- bool isEmpty(); digunakan untuk memeriksa apakah tree kosong atau tidak.
- void buatNode(char data); digunakan untuk membuat tree baru (membuat node root).
- Pohon *insertLeft(char data, Pohon *node); digunakan untuk membuat node child kiri.
- Pohon *insertRight(char data, Pohon *node)l digunakan untuk membuat node child kanan.
- void update(char data, Pohon *node); digunakan untuk mengubah isi suatu node.
- void retrieve(Pohon *node); digunakan untuk mengetahui isi suatu node.
- void find(Pohon *node); digunakan untuk mencari node dan menampilkan root, parent, sibling, dan child node tersebut.
- void preOrder(Pohon *node = root); digunakan untuk mencetak traversal secara PreOrder.
- void inOrder(Pohon *node = root); digunakan untuk mencetak traversal secara InOrder.
- void postOrder(Pohon *node = root); digunakan untuk mencetak traversal secara PostOrder.
- void deleteTree(Pohon *node); digunakan untuk menghapus sebuah node dalam tree.
- void deleteSub(Pohon *node); digunakna untuk menghapus subtree.
- void clear(); digunakan untuk menghapus seluruh tree.
- int size(Pohon *node = root); digunakan untuk menghitung jumlah node dalam tree.
- int height(Pohon *node = root); digunakan untuk menghitung level tree.
- void characteristic(); digunakan untuk mencetak karakteristik tree.

Kemudian pada int main() dilakukan beberapa operasi yaitu membuat node akar, membuat child kiri dan kanan, mengupdate node, menunjuk node, mencari node, mecetak karakteristik tree, menampilkan traversal tree secara preorder, menampilkan traversal tree secara inorder, menampilkan traversal tree secara postorder.

## Unguided 

Cantumkan NIM pada salah satu variabel di dalam program.
Contoh : int nama_22102003;

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.
Berikut contoh output program :

![Dhimas_Contoh-Output-Unguided1](https://github.com/Masdim37/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan9_Modul9_Graph-dan-Tree/Laprak/Dhimas_Contoh-Output-Unguided1.png)

```C++
//IKRAM IRIANSYAH
//2311102184
#include <iostream>
#include <iomanip>

using namespace std;

//Fungsi untuk menampilkan graph dalam format matriks
void TampilGraph_184(int JumlahSimpul_2311102184, string* NamaSimpul_2311102184, int** BobotSimpul_184) {
    //menampilkan baris pertama berupa simpul nama kota
    cout << setw(10) << " ";
    for (int i = 0; i < JumlahSimpul_2311102184; i++) {
        cout << setw(10) << NamaSimpul_2311102184[i];
    }
    cout << endl;

    // Menampilkan bobot kota secara matriks
    for (int baris_184 = 0; baris_184 < JumlahSimpul_2311102184; baris_184++) {
        cout << setw(10) << NamaSimpul_2311102184[baris_184];
        for (int kolom_184 = 0; kolom_184 < JumlahSimpul_2311102184; kolom_184++) {
            cout << setw(10) << BobotSimpul_184[baris_184][kolom_184];
        }
        cout << endl;
    }
}

int main() {
    int JumlahSimpul_2311102184;
    int Nomor_184 = 1;
    int Bobot_184;

    cout << "--- PROGRAM GRAPH SEDERHANA ---" << endl;

    //User menginputkan jumlah simpul (jumlah kota)
    cout << "Masukkan jumlah simpul = ";
    cin >> JumlahSimpul_2311102184;

    //membuat array NamaSimpul_2311102184 yang dialokasikan secara dinamis berdasarkan input jumlah simpul
    string* NamaSimpul_2311102184 = new string[JumlahSimpul_2311102184];

    //user memasukkan nama simpul (nama kota)
    cout << "--- Masukkan nama simpul ---" << endl; 
    for (int i = 0; i < JumlahSimpul_2311102184; i++) {
        cout << "Masukkan nama simpul " << Nomor_184++ << " = ";
        cin >> NamaSimpul_2311102184[i];
    }
    cout << endl;

    //membuat array BobotSimpul_184 yang dialokasikan secara dinamis berdasarkan input jumlah simpul
    int** BobotSimpul_184 = new int*[JumlahSimpul_2311102184];
    for (int i = 0; i < JumlahSimpul_2311102184; i++) {
        BobotSimpul_184[i] = new int[JumlahSimpul_2311102184]();
    }

    //user memasukkan bobot antar simpul
    cout << "--- Masukkan Bobot Antar Simpul ---" << endl;
    for (int i = 0; i < JumlahSimpul_2311102184; i++) {
        for (int j = 0; j < JumlahSimpul_2311102184; j++) {
            if (i != j) {
                cout << "Bobot " << NamaSimpul_2311102184[i] << " --> " << NamaSimpul_2311102184[j] << " = ";
                cin >> Bobot_184;
                BobotSimpul_184[i][j] = Bobot_184;
            }
        }
    }
    cout << endl;

    //memanggil fungsi TampilGraph_184
    TampilGraph_184(JumlahSimpul_2311102184, NamaSimpul_2311102184, BobotSimpul_184);

    return 0;
}
```

#### Output:

![Dhimas_Output-Unguided1]()

#### Deskripsi Program
Kode diatas merupakan program penerapa graph sederhana. Pada awal program terdapat prosedur `TampilGraph_184` yang digunakan untuk menampilkan simpul-simpul (nama-nama kota) beserta busurnya (bobot atau nilai antar simpul). Pada int main() user diminta memasukkan jumlah simpul, kemudian disimpan pada variabel `JumlahSimpul_2311102184`. Kemudian program mendeklarasikan array dinamis bernama `NamaSimpul_2311102184[]` dengan ukuran nilai variabel `JumlahSimpul_2311102184`. Kemudian user diminta menginputkan nama-nama simpul yang kemudian disimpan pada array `NamaSimpul_2311102184[]` menggunakan perulangan. Kemudian program mendeklarasikan array dinamis 2 dimensi bernama `BobotSimpul_184[]` dengan ukuran nilai variabel `JumlahSimpul_2311102184`. Kemudian user diminta memasukkan bobot antar simpul yang kemudian nilainya dimasukkan menggunakan perulangan kedalam array `BobotSimpul_184[]`. Setelah itu program memanggil prosedur `TampilGraph_184` untuk menampilkan simpul-simpul beserta busurnya (bobot) dalam bentuk matriks.

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++
//IKRAM IRIANSYAH
//2311102184
#include <iostream>
#include <iomanip>

using namespace std;

//Deklarasi struct Pohon_2311102184 yang berisi variabel data
struct Pohon_2311102184{
    char data;
    Pohon_2311102184 *left, *right, *parent; //deklarasi node left, right, dan parent didalam struct Pohon_2311102184
};

Pohon_2311102184 *root, *baru; //deklarasi node root dan baru

//Prosedur inisialisasi root sebagai NULL
void init_184(){
    root = NULL;
}

//Fugsi isEmpty_184 untuk memeriksa apakah tree kosong atau tidak
bool isEmpty_184(){
    return root == NULL;
}

//Prosedur BuatNode_184 untuk membuat node root
void BuatNode_184(char data_184){
    if (isEmpty_184()){
        root = new Pohon_2311102184();
        root->data = data_184;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data_184 << " berhasil dibuat sebagai root." << endl;
    }
}

//Fungsi untuk menambahkan node child kiri
Pohon_2311102184 *TambahKiri_184(char data_184, Pohon_2311102184*node){
    if (!isEmpty_184()){
        if(node->left != NULL) {
            cout << "\n Node " << node->data << " sudah ada child kiri !" << endl;
            return NULL;
        } else {
            Pohon_2311102184 *baru = new Pohon_2311102184();
            baru->data = data_184;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data_184 << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

//Fungsi untuk menambahkan node child kanan
Pohon_2311102184 *TambahKanan_184(char data_184, Pohon_2311102184 *node){
    if(!isEmpty_184()){
        if(node->right != NULL){
            cout << "\n Node " << node->data << " sudah ada child kanan !" << endl;
            return NULL;
        } else {
            Pohon_2311102184 *baru = new Pohon_2311102184();
            baru->data = data_184;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data_184 << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

//Fungsi untuk mencari Node berdasarkan char data
Pohon_2311102184* CariNodeByData_184(Pohon_2311102184 *node, char data_184){
    if (node == NULL) {
        return NULL;
    }
    if (node->data == data_184) {
        return node;
    }
    Pohon_2311102184 *foundNode = CariNodeByData_184(node->left, data_184);
    if (foundNode == NULL) {
        foundNode = CariNodeByData_184(node->right, data_184);
    }
    return foundNode;
}

//Prosedur untuk mengupdate (mengubah) nama suatu node
void UpdateNode_184(char data_184, Pohon_2311102184 *node){
    if(!isEmpty_184()){
        if(node){
            char temp = node->data;
            node->data = data_184;
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data_184 << endl;
        }
    }
}

//Prosedur untuk menunjuk suatu node
void Retrieve_184(Pohon_2311102184 *node){
    if(!isEmpty_184()){
        if(node){
            cout << "\n Data node : " << node->data << endl;
        }
    }
}

//Prosedur untuk mencari node dan menampilkan root, parent, sibling, dan child node tersebut 
void CariNode_184(Pohon_2311102184 *node){
    if(isEmpty_184()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (!node){
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if(!node->parent){
                cout << " Parent : (tidak punya parent)" << endl;
            } else {
                cout << " Parent : " << node->parent->data << endl;
            }

            if(node->parent != NULL && node->parent->left != node && node->parent->right == node){
                cout << " Sibling : " << node->parent->left->data << endl;
            } else if(node->parent != NULL && node->parent->right != node && node->parent->left == node){
                cout << " Sibling : " << node->parent->right->data << endl;
            } else {
                cout << " Sibling : (tidak punya sibling)" << endl;
            }

            if(!node->left){
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            } else {
                cout << " Child Kiri : " << node->left->data << endl;
            }

            if(!node->right){
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            } else {
                cout << " Child Kanan : " << node->right->data << endl;
            }
        }
    }
}

//Penelusuran (Traversal)
//Prosedur untuk menampilkan traversal secara pre order
void preOrder_184(Pohon_2311102184 *node = root){
    if(isEmpty_184()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if(node != NULL){
            cout << " " << node->data << ", ";
            preOrder_184(node->left);
            preOrder_184(node->right);
        }
    }
}

//prosedur untuk menampilkan traversal secara in order
void inOrder_184(Pohon_2311102184 *node = root){
    if(isEmpty_184()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if(node != NULL){
            inOrder_184(node->left);
            cout << " " << node->data << ", ";
            inOrder_184(node->right);
        }
    }
}

//prosedur untuk menampilkan traversal secara post order
void postOrder_184(Pohon_2311102184 *node = root){
    if(isEmpty_184()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if(node != NULL){
            postOrder_184(node->left);
            postOrder_184(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

//Prosedur untuk menghapus suatu node pada tree
void HapusNodeTree_184(Pohon_2311102184 *node){
    if (isEmpty_184()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if(node != NULL){
            if(node != root){
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            HapusNodeTree_184(node->left);
            HapusNodeTree_184(node->right);
            if(node == root){
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

//prosedur untuk menghapus sub tree
void HapusSubTree_184(Pohon_2311102184 *node){
    if(isEmpty_184()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        HapusNodeTree_184(node->left);
        HapusNodeTree_184(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}

//prosedur untuk menghapus seluruh tree
void HapusTree_184(){
    if(isEmpty_184()){
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    } else {
        HapusNodeTree_184(root);
        cout << "\n Tree berhasil dihapus." << endl;
    }
}

//fungsi untuk menghitung jumlah node (size) yang ada pada tree
int CekSizeTree_184(Pohon_2311102184 *node = root){
    if(isEmpty_184()){
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if(!node){
            return 0;
        } else {
            return 1 + CekSizeTree_184(node->left) + CekSizeTree_184(node->right);
        }
    }
}

//fungsi untuk menghitung level atau aras (height) tree
int CekHeightTree_184(Pohon_2311102184 *node = root){
    if(isEmpty_184()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if(!node){
            return 0;
        } else {
            int heightKiri_184 = CekHeightTree_184(node->left);
            int heightKanan_184 = CekHeightTree_184(node->right);
            if (heightKiri_184 >= heightKanan_184){
                return heightKiri_184 + 1;
            } else {
                return heightKanan_184 + 1;
            }
        }
    }
}

//prosedur untuk menampilkan karakteristik tree
void KarakteristikTree_184(){
    cout << "\n Size Tree : " << CekSizeTree_184() << endl;
    cout << " Height Tree : " << CekHeightTree_184() << endl;
    cout << " Average Node of Tree : " << CekSizeTree_184() / CekHeightTree_184() << endl;
    cout << endl;
}

//Prosedur untuk menampilkan child (kiri dan kanan) suatu node
void TampilkanChildNode_184(Pohon_2311102184 *node){
    if (node) {
        if (node->left) {
            cout << "Child Kiri: " << node->left->data << endl;
        } else {
            cout << "Child Kiri: (tidak punya Child kiri)" << endl;
        }
        if (node->right) {
            cout << "Child Kanan: " << node->right->data << endl;
        } else {
            cout << "Child Kanan: (tidak punya Child kanan)" << endl;
        }
    } else {
        cout << "\n Node yang ditunjuk tidak ada!" << endl;
    }
}

//prosedur untuk menampilan node keturunan (descendant node) dari suatu node 
void TampilkanDescendantNode_184(Pohon_2311102184 *node){
    if (node) {
        cout << "Keturunan node (descendant node) " << node->data << ": ";
        preOrder_184(node->left);
        preOrder_184(node->right);
        cout << endl;
    } else {
        cout << "\n Node yang ditunjuk tidak ada!" << endl;
    }
}


int main(){
    int Pilihan_184;
    char Data_184, DataParent_184, DataNodeLama_184, Yakin_184;
    Pohon_2311102184 *ParentNode, *NodeLama, *NodeYangDitunjuk; //deklarasi node ParentNode, NodeLama, dan NodeYangDitunjuk

    do{ //perulangan do-while untuk menampilkan menu
        Menu:
        cout << "--- PROGRAM SIMULASI GRAPH DAN TREE ---" << endl;
        cout << "1. Buat Node Akar" << endl;
        cout << "2. Tambah Node Kiri" << endl;
        cout << "3. Tambah Node Kanan" << endl;
        cout << "4. Update Node" << endl;
        cout << "5. Retrieve (tunjuk) Node" << endl;
        cout << "6. Cari Node" << endl;
        cout << "7. Tampilkan Child (Anak) Node" << endl;
        cout << "8. Tampilkan Descendant Node (Keturunan Node)" << endl;
        cout << "9. Hapus Subtree" << endl;
        cout << "10. Hapus Tree" << endl;
        cout << "11. Tampilkan Karakteristik Tree" << endl;
        cout << "12. Tampilkan Traversal PreOrder" << endl;
        cout << "13. Tampilkan Traversal InOrder" << endl;
        cout << "14. Tampilkan Traversal PostOrder" << endl;
        cout << "15. Keluar" << endl;
        cout << "Pilihan anda [1 - 15] = ";
        cin >> Pilihan_184;
        cout << endl;


        //swtich-case berdasarkan inputan user
        switch (Pilihan_184){
            case 1: //jika memilih 1, maka tampilkan menu buat node akar
                if(isEmpty_184()){
                    cout << "--- BUAT NODE AKAR ---" << endl;
                    cout << "Masukkan huruf node akar = ";
                    cin >> Data_184;
                    BuatNode_184(Data_184);
                    cout << endl;
                } else {
                    cout << "Tree sudah ada!" << endl;
                    cout << endl;
                }
                break;
            case 2: //jika memilih 2, maka tampilkan menu tambah node kiri
                if(!isEmpty_184()){
                    cout << "--- TAMBAH NODE KIRI ---" << endl;
                    cout << "Masukkan kode node kiri = ";
                    cin >> Data_184;
                    cout << "Masukkan kode node parent = ";
                    cin >> DataParent_184;
                    ParentNode = CariNodeByData_184(root, DataParent_184);
                    if(ParentNode){
                        TambahKiri_184(Data_184, ParentNode);
                        cout << endl;
                    } else {
                        cout << "Node parent tidak ditemukan!" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 3: //jika memilih 3, maka tampilkan menu tambah node kanan
                if(!isEmpty_184()){
                    cout << "--- TAMBAH NODE KANAN ---" << endl;
                    cout << "Masukkan kode node kanan = ";
                    cin >> Data_184;
                    cout << "Masukkan kode node parent = ";
                    cin >> DataParent_184;
                    ParentNode = CariNodeByData_184(root, DataParent_184);
                    if(ParentNode){
                        TambahKanan_184(Data_184, ParentNode);
                        cout << endl;
                    } else {
                        cout << "Node parent tidak ditemukan!" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 4: //jika memilih 4, maka tampilkan menu update node
                if(!isEmpty_184()){
                    cout << "--- UPDATE NODE ---" << endl;
                    cout << "Masukkan kode node baru = ";
                    cin >> Data_184;
                    cout << "Masukkan kode node yang ingin diupdate = ";
                    cin >> DataNodeLama_184;
                    NodeLama = CariNodeByData_184(root, DataNodeLama_184);
                    if(NodeLama){
                        UpdateNode_184(Data_184, NodeLama);
                        cout << endl;
                    } else {
                        cout << "Data node lama tidak ditemukan!" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 5: //jika memilih 5, maka tampilkan menu retrieve node (tunjuk node)
                if(!isEmpty_184()){
                    cout << "--- RETRIEVE NODE ---" << endl;
                    cout << "Masukkan node yang ingin ditunjuk = ";
                    cin >> Data_184;
                    NodeYangDitunjuk = CariNodeByData_184(root, Data_184);
                    if(NodeYangDitunjuk){
                        Retrieve_184(NodeYangDitunjuk);
                        cout << endl;
                    } else {
                        cout << "Node yang ingin ditunjuk tidak ditemukan!" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                } 
                break;
            case 6: //jika memilih 6, maka tampilkan menu cari node
                if(!isEmpty_184()){
                    cout << "--- CARI NODE ---" << endl;
                    cout << "Masukkan kode node yang ingin dicari = ";
                    cin >> Data_184;
                    NodeYangDitunjuk = CariNodeByData_184(root, Data_184);
                    if(NodeYangDitunjuk){
                        CariNode_184(NodeYangDitunjuk);
                        cout << endl;
                    } else {
                        cout << "Node yang ingin dicari tidak ditemukan!" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 7: //jika memilih 7, maka tampilkan menu tampilkan child suatu node
                if(!isEmpty_184()){
                    cout << "--- TAMPILKAN CHILD SUATU NODE ---" << endl;
                    cout << "Masukkan kode node yang ingin ditampilkan child-nya = ";
                    cin >> Data_184;
                    NodeYangDitunjuk = CariNodeByData_184(root, Data_184);
                    if(NodeYangDitunjuk){
                        TampilkanChildNode_184(NodeYangDitunjuk);
                        cout << endl;
                    } else {
                        cout << "Node yang ingin ditampilkan child-nya tidak ditemukan!" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 8: //jika memilih 8, maka tampilkan menu tampilkan descendant node
                if(!isEmpty_184()){
                    cout << "--- TAMPILKAN DESCENDANT NODE (KETURUNAN SUATU NODE) ---" << endl;
                    cout << "Masukkan kode node yang ingin ditampilkan keturunannya = ";
                    cin >> Data_184;
                    NodeYangDitunjuk = CariNodeByData_184(root, Data_184);
                    if(NodeYangDitunjuk){
                        TampilkanDescendantNode_184(NodeYangDitunjuk);
                        cout << endl;
                    } else {
                        cout << "Node yang igin ditampilkan keturunannya tidak ditemukan!" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 9: //jika memilih 9, maka tampilkan menu hapus subtree
                if(!isEmpty_184()){
                    cout << "--- HAPUS SUBTREE ---" << endl;
                    cout << "Masukkan kode node sebagai root subtree yang ingin dihapus = ";
                    cin >> Data_184;
                    NodeYangDitunjuk = CariNodeByData_184(root, Data_184);
                    if(NodeYangDitunjuk){
                        HapusSubTree_184(NodeYangDitunjuk);
                        cout << endl;
                    } else {
                        cout << "Node sebagai root subtree tidak ditemukan!" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 10: //jika memilih 10, maka tampilkan menu hapus tree
                if(!isEmpty_184()){
                    cout << "--- HAPUS TREE ---" << endl;
                    cout << "Apakah anda yakin untuk menghapus seluruh tree? [y/n] = ";
                    cin >> Yakin_184;
                    if(Yakin_184 ==  'Y' || 'y'){
                        HapusTree_184();
                        cout << endl;
                    } else if(Yakin_184 == 'N' || 'n'){
                        cout << "Aksi dibatalkan" << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 11: //jika memilih 11, maka tampilkan menu karakteristik tree
                if(!isEmpty_184()){
                    cout << "--- KARAKTERISTIK TREE ---" << endl;
                    KarakteristikTree_184();
                } else {
                    cout << "Tree masih kosong!" << endl;
                    cout << endl;
                }
                break;
            case 12: //jika memilih 12, maka tampilkan menu traversal preorder
                cout << "--- TRAVERSAL PREORDER ---" << endl;
                preOrder_184(root);
                cout << endl;
                cout << endl;
                break;
            case 13: //jika memilih 13, maka tampilkan menu traversal inorder
                cout << "--- TRAVERSAL INORDER ---" << endl;
                inOrder_184(root);
                cout << endl;
                cout << endl;
                break;
            case 14: //jika memilih 14, maka tampilkan menu traversal postorder
                cout << "--- TRAVERSAL POSTORDER ---" << endl;
                postOrder_184(root);
                cout << endl;
                cout << endl;
                break;
            case 15: //jika memilih 15, maka keluar dari program
                cout << "Anda keluar dari program" << endl;
                return 0;
                break;
            default: //output jika memilih selain 1 - 15
                cout << "Pilihan anda tidak tersedia!" << endl;
                cout << endl;
                goto Menu;
                break;
        }
    } while(Pilihan_184 != 0); //menu akan ditampilkan berulang ketika variabel Pilihan_184 bukan sama dengan 0
}
```

#### Output:

Gunakan fungsi BuatNode_184, TambahKanan_184, dan TambahKiri_184 untuk membuat tree seperti gambar berikut.

![Dhimas_Tree-Unguided2]()

##### Menambahkan Node A (Root)
![Dhimas_Output-Unguided2-1]()

##### Menambahkan Node B (Child Kiri Node A)
![Dhimas_Output-Unguided2-2]()

##### Menambahkan Node C (Child Kanan Node A)
![Dhimas_Output-Unguided2-3]()

##### Menambahkan Node D (Child Kiri Node B)
![Dhimas_Output-Unguided2-4]()

##### Menambahkan Node E (Child Kanan Node B)
![Dhimas_Output-Unguided2-5]()

##### Menambahkan Node F (Child Kanan Node C)
![Dhimas_Output-Unguided2-6]()

##### Menambahkan Node G (Child Kiri Node E)
![Dhimas_Output-Unguided2-7]()

##### Menambahkan Node H (Child Kanan Node E)
![Dhimas_Output-Unguided2-8]()

##### Update Node F Menjadi M
![Dhimas_Output-Unguided2-9]()

##### Retrieve (Tunjuk) Node M
![Dhimas_Output-Unguided2-10]()

##### Cari Node E
![Dhimas_Output-Unguided2-11]()

##### Tampilkan Child Node B
![Dhimas_Output-Unguided2-12]()

##### Tampilkan Descendant Node B
![Dhimas_Output-Unguided2-13]()

##### Hapus Subtree Dengan Root Node C
![Dhimas_Output-Unguided2-14]()

##### Tampilkan Karakteristik Tree
![Dhimas_Output-Unguided2-15]()

##### Tampilkan Traversal Secara PreOrder
![Dhimas_Output-Unguided2-16]()

##### Tampilkan Traversal Secara InOrder
![Dhimas_Output-Unguided2-17]()

##### Tampilkan Traversal Secara PostOrder
![Dhimas_Output-Unguided2-18]()

##### Hapus Tree
![Dhimas_Output-Unguided2-19]()

##### Keluar Dari Program
![Dhimas_Output-Unguided2-20]()

#### Deskripsi Program
Kode diatas merupakan program implementasi tree menggunakan struct. Manipulasi tree pada program ini menggunakan menu-menu yang dapat dipilih oleh user. Setiap pilihan menu akan melakukan aksi yang berbeda beda. Terdapat beberapa fungsi dan prosedur yang dapat digunakan untuk memanipulasi tree, antara lain :
- struct Pohon_2311102184; mendeklarasikan struct Pohon
- void init_184(); digunakan untuk menginisialisasi root seagai NULL
- bool isEmpty_184(); digunakan untuk memeriksa apakah tree masih kosong atau tidak
- void BuatNode_184(char data_184); digunakan untuk membuat node root (akar)
- Pohon_2311102184 *TambahKiri_184(char data_184, Pohon_2311102184 *node); digunakan untuk membuat child kiri suatu node
- Pohon_2311102184 *TambahKanan_184(char data_184, Pohon_2311102184 *node); digunakan untuk membuat child kanan suatu node
- Pohon_2311102184* CariNodeByData_184(Pohon_2311102184 *node, char data_184); digunakan untuk menujuk suatu node berdasarkan inputan char
- void UpdateNode_184(char data_184, Pohon_2311102184 *node); digunakan untuk mengupdate isi suatu node
- void Retrieve_184(Pohon_2311102184 *node); digunakan untuk menunjuk suatu node
- void CariNode_184(Pohon_2311102184 *node); digunakan untuk mencari node dan menampilkan root, parent, sibling, dan child node tersebut
- void preOrder_184(Pohon_2311102184 *node = root); digunakan untuk menampilkan traversal tree secara preOrder
- void inOrder_184(Pohon_2311102184 *node = root); digunakan untuk menampilkan traversal tree secara inOrder
- void postOrder_184(Pohon_2311102184 *node = root); digunakan untuk menampilkan traversal tree secara postOrder
- void HapusNodeTree_184(Pohon_2311102184 *node); digunakan untuk menghapus sebuah node pada tree
- void HapusSubTree_184(Pohon_2311102184 *node); digunakan untuk menghapus sub tree (kecuali node rootnya)
- void HapusTree_184(); digunakan untuk menghapus seluruh tree
- int CekSizeTree_184(Pohon_2311102184 *node = root); digunakan untuk mengecek jumlah node (size) pada tree
- int CekHeightTree_184(Pohon_2311102184 *node = root); digunakan untuk mengecek level atau aras (height) tree
- void KarakteristikTree_184(); digunakan untuk menampilkan karakteristik tree
- void TampilkanChildNode_184(Pohon_2311102184 *node); digunakan untuk menampilkan child suatu tree
- void TampilkanDescendantNode_184(Pohon_2311102184 *node); digunakan untuk menampilkan descendant node (node keturunan) suatu node
<br>Kemudian pada int main() terdapat beberapa menu dengan fungsinya masing-masing. Jika user memilih 1, maka masuk ke menu Buat Node Akar; jika user memilih 2, maka masuk ke menu Tambah Node Kiri; jika user memilih 3, maka masuk ke menu Tambah Node Kanan; jika user memilih 4, maka masuk ke menu Update Node; jika user memilih 5, maka masuk ke menu Retrieve (Tunjuk) Node; jika user memilih 6, maka masuk ke menu Cari Node; jika user memilih 7, maka masuk ke menu Tampilkan Child (Anak) Node; jika user memilih 8, maka masuk ke menu Tampilkan Descendant Node (Keturunan Node); jika user memilih 9, maka masuk ke menu Hapus Subtree; jika user memilih 10, maka masuk ke menu Hapus Tree; jika user memilih 11, maka masuk ke menu Tampilkan Karakteristik Tree; jika user memilih 12, maka masuk ke menu Tampilkan Traversal PreOrder; jika user memilih 13, maka masuk ke menu Tampilkan Traversal InOrder; jika user memilih 14, maka masuk ke menu Tampilkan Traversal PostOrder; dan jika user memilih 15, maka keluar dari program.

## Kesimpulan
Graph adalah sekumpulan simpul didalam bidang 2 dimemnsi yang dihubungkan dengan sekumpulan sisi. Secara matematis, graph dituliskan dengan G = (V, E) dengan G adalah graph, V adalah vertex (simpul), dan E adalah edge (sisi). Terdapat 3 jenis graph, yaitu graph berarah (jenis graph di mana setiap sisi (edge) memiliki arah tertentu), graph tak berarah (jenis graph di mana setiap sisi (edge) tidak memiliki arah tertentu), dan graph berbobot (jenis graph yang memiliki bobot pada setiap sisinya). Graph dapat direpresentasikan menggunakan matriks maupun linked list.

Tree (pohon) adalah struktur data yang setiap simpulnya menunjuk ke sejumlah simpul lain. Pohon adalah contoh struktur data non-linier. Terdapat beberapa istilah dalah struktur data tree, yaitu root, parent, sibling, leaf, child, subtree, level, size, height, degree, descendant, dll.

## Referensi
[1] Triase, Triase. (2020). "Struktur Data: Diktat Edisi Revisi." Retrieved from http://repository.uinsu.ac.id/id/eprint/9717.
<br>[2] Buhaerah, M., Busrah, Z., & Sanjaya, H. (2022). "Teori Graf dan Aplikasinya". Makassar: LSQ Makassar. Retrieved from https://repository.iainpare.ac.id/id/eprint/3489/1/2021%20Teori%20Graf.pdf.
<br>[3] Joseph Teguh Santoso. (2021). "STRUKTUR DATA dan ALGORITMA (Bagian 1)". Penerbit Yayasan Prima Agus Teknik, 7(1), 1-333. Retrieved from https://penerbit.stekom.ac.id/index.php/yayasanpat/article/view/288.
