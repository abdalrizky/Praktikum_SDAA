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

Node *head = nullptr;
int jumlahTempatNongkrong = 0;

void tampilkanTempatNongkrong(Node *head)
{
    if (head == nullptr) {
        cout << "Belum ada tempat nongkrong favorit yang ditambahkan." << endl;
        return;
    }
    
    int nomorData = 1;
    while (head != nullptr)
    {
        cout << nomorData << ". Nama: " << head->data.nama << endl;
        cout << "Alamat: " << head->data.alamat << endl;
        cout << "Rating: " << fixed << setprecision(2) << head->data.rating << endl;
        cout << "Jam Operasional: " << head->data.jamOperasional << endl;
        cout << "===============================================" << endl;
        head = head->next;
        nomorData++;
    }
    
}

void tambahTempatNongkrong(string nama, string alamat, double rating, string jamOperasional) {
    Node *nodeBaru = new Node;

    nodeBaru->data.nama = nama;
    nodeBaru->data.alamat = alamat;
    nodeBaru->data.rating = rating;
    nodeBaru->data.jamOperasional = jamOperasional;
    nodeBaru->next = nullptr;

    if (head == nullptr) {
        head = nodeBaru;
    } else {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }

    jumlahTempatNongkrong++;
    cout << "Tempat nongkrong favorit berhasil ditambahkan." << endl;
}

void ubahTempatNongkrong(int index, string nama, string alamat, double rating, string jamOperasional) {
    Node *temp = head;

    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    if (nama != "") {
        temp->data.nama = nama;
    }

    if (alamat != "") {
        temp->data.alamat = alamat;
    }

    if (rating != 0) {
        temp->data.rating = rating;
    }

    if (jamOperasional != "") {
        temp->data.jamOperasional = jamOperasional;
    }

    if (nama != "" || alamat != "" || rating != 0 || jamOperasional != "") {
        cout << "Tempat nongkrong favorit berhasil diubah." << endl;
    } else {
        cout << "Tindakan dibatalkan." << endl;
    }
    
}

void hapusTempatNongkrong(int index) {
    Node* temp;

    if (index == 0) {
        temp = head;
        head = head->next;
    } else {
        Node *current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
    }

    delete temp;
    jumlahTempatNongkrong--;
    cout << "Tempat nongkrong favorit berhasil dihapus." << endl;
}

int main()
{
    system("cls");

    cout << "===========================================================" << endl;
    cout << "Selamat datang di program Daftar Tempat Nongkrong Favorit!" << endl;
    cout << "===========================================================" << endl;
    cout << "Di sini kamu bisa menyimpan tempat nongkrong favoritmu." << endl;
    cout << "===========================================================" << endl;

    int pilihan;

    do {
        cout << "[1] Tampilkan tempat nongkrong favorit" << endl;
        cout << "[2] Tambah tempat nongkrong favorit" << endl;
        cout << "[3] Ubah rincian tempat nongkrong favorit" << endl;
        cout << "[4] Hapus tempat nongkrong favorit" << endl;
        cout << "[5] Keluar dari program" << endl;
        cout << "Pilih menu >> ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            system("cls");

            if (jumlahTempatNongkrong != 0) {
                cout << "===============================================" << endl;
                cout << "Menampilkan " << jumlahTempatNongkrong << " data." << endl;
                cout << "===============================================" << endl;
            }
            
            tampilkanTempatNongkrong(head);
            break;
        case 2: {
            system("cls");

            string nama, alamat, jamOperasional;
            double rating;

            cout << "Masukkan nama tempat nongkrong: ";
            cin.ignore();
            getline(cin, nama);

            cout << "Masukkan alamat tempat nongkrong: ";
            getline(cin, alamat);

            cout << "Masukkan rating tempat nongkrong: ";
            cin >> rating;

            cout << "Masukkan jam operasional tempat nongkrong: ";
            cin.ignore();
            getline(cin, jamOperasional);

            system("cls");

            tambahTempatNongkrong(nama, alamat, rating, jamOperasional);
            break;
        }
        case 3: {
            system("cls");

            if (jumlahTempatNongkrong == 0) {
                cout << "Belum ada tempat nongkrong. Silakan tambah terlebih dahulu." << endl;
                break;
            }

            tampilkanTempatNongkrong(head);

            cout << "Pilih nomor tempat nongkrong yang ingin diubah: ";
            int nomor;
            cin >> nomor;

            if (nomor < 1 || nomor > jumlahTempatNongkrong) {
                system("cls");
                cout << "Nomor tempat nongkrong tidak valid." << endl;
                break;
            }

            string namaBaru, alamatBaru, jamOperasionalBaru;
            double ratingBaru;

            cout << "Masukkan nama tempat nongkrong baru (kosongkan jika tidak ingin diubah): ";
            cin.ignore();
            getline(cin, namaBaru);

            cout << "Masukkan alamat tempat nongkrong baru (kosongkan jika tidak ingin diubah): ";
            getline(cin, alamatBaru);

            cout << "Masukkan rating tempat nongkrong baru (isi 0 jika tidak ingin diubah): ";
            cin >> ratingBaru;

            cout << "Masukkan jam operasional tempat nongkrong baru (kosongkan jika tidak ingin diubah): ";
            cin.ignore();
            getline(cin, jamOperasionalBaru);

            system("cls");

            ubahTempatNongkrong(nomor - 1, namaBaru, alamatBaru, ratingBaru, jamOperasionalBaru);
            break;
        }
        case 4:
            system("cls");

            if (jumlahTempatNongkrong == 0) {
                cout << "Belum ada tempat nongkrong. Silakan tambah terlebih dahulu." << endl;
                break;
            }

            tampilkanTempatNongkrong(head);

            int nomor;
            cout << "Masukkan nomor tempat nongkrong yang ingin dihapus: ";
            cin >> nomor;

            if (nomor < 1 || nomor > jumlahTempatNongkrong) {
                system("cls");
                cout << "Nomor tempat nongkrong tidak valid." << endl;
                break;
            }

            system("cls");

            hapusTempatNongkrong(nomor - 1);
            break;
        case 5:
            cout << "Terima kasih." << endl;
            return 0;
        default:
            system("cls");
            cout << "Menu tidak valid. Silakan ulangi." << endl;
        }  
          
    } while (pilihan != 5);

    return 0;
}
