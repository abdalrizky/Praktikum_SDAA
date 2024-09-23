// Nama: Muhammad Abdal Rizky
// NIM: 2309106012
// Kelas: A1'23

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

TempatNongkrong tempatNongkrongFavorit[10] = {
    {"Nibung", "Jalan Pramuka 6, Samarinda Utara", 4.98, "8.00-22.00"},
};

int jumlahTempatNongkrong = 1;

void tampilkanTempatNongkrong()
{

    if (jumlahTempatNongkrong != 0)
    {
        for (int i = 0; i < jumlahTempatNongkrong; i++)
        {
            cout << i + 1 << ". Nama: " << tempatNongkrongFavorit[i].nama << endl;
            cout << "Alamat: " << tempatNongkrongFavorit[i].alamat << endl;
            cout << "Rating: " << fixed << setprecision(2) << tempatNongkrongFavorit[i].rating << endl;
            cout << "Jam Operasional: " << tempatNongkrongFavorit[i].jamOperasional << endl;
            cout << "===============================================" << endl;
        }
    } else {
        cout << "Belum ada tempat nongkrong favorit yang ditambahkan." << endl;
        return;
    }
    
}

void tambahTempatNongkrong(string *nama, string alamat, double rating, string jamOperasional) {
    if (jumlahTempatNongkrong < 10) {
        tempatNongkrongFavorit[jumlahTempatNongkrong].nama = *nama;
        tempatNongkrongFavorit[jumlahTempatNongkrong].alamat = alamat;
        tempatNongkrongFavorit[jumlahTempatNongkrong].rating = rating;
        tempatNongkrongFavorit[jumlahTempatNongkrong].jamOperasional = jamOperasional;
        jumlahTempatNongkrong++;
        cout << "Tempat nongkrong favorit berhasil ditambahkan." << endl;
    } else {
        cout << "Maaf, daftar favorit ini sudah penuh. Silakan hapus salah satu kemudian tambahkan kembali." << endl;
    }
}

void ubahTempatNongkrong(int index, string nama, string alamat, double rating, string jamOperasional) {
    if (nama != "") {
        tempatNongkrongFavorit[index].nama = nama;
    }

    if (alamat != "") {
        tempatNongkrongFavorit[index].alamat = alamat;
    }

    if (rating != 0) {
        tempatNongkrongFavorit[index].rating = rating;
    }

    if (jamOperasional != "") {
        tempatNongkrongFavorit[index].jamOperasional = jamOperasional;
    }

    if (nama != "" || alamat != "" || rating != 0 || jamOperasional != "") {
        cout << "Tempat nongkrong favorit berhasil diubah." << endl;
    } else {
        cout << "Tindakan dibatalkan." << endl;
    }
}

void hapusTempatNongkrong(int index) {
    for (int i = index; i < jumlahTempatNongkrong; i++) {
        tempatNongkrongFavorit[i] = tempatNongkrongFavorit[i + 1];
    }
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
            
            tampilkanTempatNongkrong();
            break;
        case 2: {
            system("cls");

            string nama, alamat, jamOperasional;
            double rating;

            cout << "Masukkan nama tempat nongkrong: ";
            cin.ignore();
            getline(cin, nama);

            cout << "Masukkan alamat tempat nongkrong: ";
            cin.ignore();
            getline(cin, alamat);

            cout << "Masukkan rating tempat nongkrong: ";
            cin >> rating;

            cout << "Masukkan jam operasional tempat nongkrong: ";
            cin.ignore();
            getline(cin, jamOperasional);

            system("cls");

            tambahTempatNongkrong(&nama, alamat, rating, jamOperasional);
            break;
        }
        case 3: {
            system("cls");

            if (jumlahTempatNongkrong == 0) {
                cout << "Belum ada tempat nongkrong. Silakan tambah terlebih dahulu." << endl;
                break;
            }

            string namaBaru, alamatBaru, jamOperasionalBaru;
            double ratingBaru;

            tampilkanTempatNongkrong();

            cout << "Pilih nomor tempat nongkrong yang ingin diubah: ";
            int nomor;
            cin >> nomor;

            if (nomor < 1 || nomor > jumlahTempatNongkrong) {
                system("cls");
                cout << "Nomor tempat nongkrong tidak valid." << endl;
                break;
            }

            cout << "Masukkan nama tempat nongkrong baru (kosongkan jika tidak ingin diubah): ";
            cin.ignore();
            getline(cin, namaBaru);

            cout << "Masukkan alamat tempat nongkrong baru (kosongkan jika tidak ingin diubah): ";
            cin.ignore();
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

            tampilkanTempatNongkrong();

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
