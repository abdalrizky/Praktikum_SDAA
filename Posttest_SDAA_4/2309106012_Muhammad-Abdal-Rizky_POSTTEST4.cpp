#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct TempatNongkrong {
    string nama;
    string alamat;
    double rating;
    string jamOperasional;
};

struct Node {
    TempatNongkrong data;
    Node *next;
};

// variabel pointer untuk stack
Node* top = nullptr;

// variabel pointer untuk queue
Node* front = nullptr;
Node* rear = nullptr;

int jumlahTempatNongkrong = 0;

Node* createNode() {
    Node* nodeBaru = new Node;

    cout << "Masukkan nama tempat nongkrong: ";
    cin.ignore();
    getline(cin, nodeBaru->data.nama);

    cout << "Masukkan alamat tempat nongkrong: ";
    getline(cin, nodeBaru->data.alamat);

    cout << "Masukkan rating tempat nongkrong: ";
    cin >> nodeBaru->data.rating;

    cout << "Masukkan jam operasional tempat nongkrong: ";
    cin.ignore();
    getline(cin, nodeBaru->data.jamOperasional);

    nodeBaru->next = nullptr;
    return nodeBaru;
}

// fungsi stack
void push(Node** top) {
    Node* nodeBaru = createNode();
    nodeBaru->next = *top;
    *top = nodeBaru;
    jumlahTempatNongkrong++;

    system("cls");
    cout << "Tempat nongkrong berhasil ditambahkan ke stack." << endl;
}

void pop(Node** top) {
    if (*top == nullptr) {
        system("cls");
        cout << "Stack underflow. Tidak ada tempat nongkrong di stack." << endl;
        return;
    }

    Node* temp = *top;
    *top = (*top)->next;

    delete temp;
    jumlahTempatNongkrong--;

    system("cls");
    cout << "Tempat nongkrong berhasil dihapus dari stack." << endl;
}
// akhir fungsi stack

// fungsi queue
void enqueue(Node** front, Node** rear) {
    Node* nodeBaru = createNode();

    if (!*front) {
        *front = nodeBaru;
    } else {
        (*rear)->next = nodeBaru;
    }

    *rear = nodeBaru;
    jumlahTempatNongkrong++;

    system("cls");
    cout << "Tempat nongkrong berhasil ditambahkan ke antrian." << endl;
}

void dequeue(Node** front) {
    if (!*front) {
        cout << "Antrian kosong." << endl;
        return;
    }

    Node* temp = *front;
    *front = (*front)->next;

    delete temp;
    jumlahTempatNongkrong--;
    cout << "Tempat nongkrong berhasil dihapus dari antrian." << endl;
}
// akhir fungsi queue

void tampilkanTempatNongkrong(Node* node) {
    if (node == nullptr) {
        cout << "Belum ada tempat nongkrong yang ditambahkan." << endl;
        return;
    }

    int nomorData = 1;
    while (node != nullptr) {
        cout << nomorData << ". Nama: " << node->data.nama << endl;
        cout << "Alamat: " << node->data.alamat << endl;
        cout << "Rating: " << fixed << setprecision(2) << node->data.rating << endl;
        cout << "Jam Operasional: " << node->data.jamOperasional << endl;
        cout << "===============================================" << endl;
        node = node->next;
        nomorData++;
    }
}

int main() {
    system("cls");

    cout << "===========================================================" << endl;
    cout << "Selamat datang di program Daftar Tempat Nongkrong Favorit!" << endl;
    cout << "===========================================================" << endl;
    cout << "Di sini kamu bisa menyimpan tempat nongkrong favoritmu." << endl;
    cout << "===========================================================" << endl;

    int pilihan, mode;

    cout << "[1] Mode Stack" << endl;
    cout << "[2] Mode Queue" << endl;
    cout << "Pilih mode >> ";
    cin >> mode;

    switch (mode)
    {
        case 1:
            system("cls");
            cout << "Mode Stack" << endl;
            break;
        case 2:
            system("cls");
            cout << "Mode Queue" << endl;
            break;
        default:
            break;
    }

    do {
        cout << "[1] Tampilkan tempat nongkrong favorit" << endl;
        cout << "[2] Tambah tempat nongkrong favorit" << endl;
        cout << "[3] Hapus tempat nongkrong favorit" << endl;
        cout << "[4] Keluar dari program" << endl;
        cout << "Pilih menu >> ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            system("cls");
            if (mode == 1) {
                tampilkanTempatNongkrong(top);
            } else {
                tampilkanTempatNongkrong(front);
            }
            break;
        case 2:
            system("cls");
            if (mode == 1) {
                push(&top);
            } else {
                enqueue(&front, &rear);
            }
            break;
        case 3:
            system("cls");
            if (mode == 1) {
                pop(&top);
            } else {
                dequeue(&front);
            }
            break;
        case 4:
            cout << "Terima kasih." << endl;
            return 0;
        default:
            system("cls");
            cout << "Menu tidak valid. Silakan ulangi." << endl;
        }
    } while (pilihan != 4);

    return 0;
}