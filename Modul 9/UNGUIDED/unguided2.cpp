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