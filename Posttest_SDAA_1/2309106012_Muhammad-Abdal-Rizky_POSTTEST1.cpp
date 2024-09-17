// Nama: Muhammad Abdal Rizky
// NIM: 2309106012
// Kelas: A1'23

#include <iostream>
using namespace std;

int hitungPascal(int baris, int kolom) {
    if (kolom == 0 || kolom == baris) {
        return 1;
    } else {
        return hitungPascal(baris-1, kolom-1) + hitungPascal(baris-1, kolom);
    }
}

void cetakPascal(int tingkat) {
    for (int i = 0; i < tingkat; i++) {
        for (int j = 0; j <= i; j++) {
            cout << hitungPascal(i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int tingkat = 3;
    cetakPascal(tingkat);
    return 0;
}