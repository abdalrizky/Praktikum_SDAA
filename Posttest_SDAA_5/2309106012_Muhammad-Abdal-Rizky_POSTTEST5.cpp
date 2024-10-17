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
Node *top = nullptr;

// variabel pointer untuk queue
Node *front = nullptr;
Node *rear = nullptr;

int jumlahTempatNongkrong = 0;

Node *createNode() {
    Node *nodeBaru = new Node;

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
void push(Node **top) {
    Node *nodeBaru = createNode();
    nodeBaru->next = *top;
    *top = nodeBaru;
    jumlahTempatNongkrong++;

    system("cls");
    cout << "Tempat nongkrong berhasil ditambahkan ke stack." << endl;
}

void pop(Node **top) {
    if (*top == nullptr) {
        system("cls");
        cout << "Stack underflow. Tidak ada tempat nongkrong di stack." << endl;
        return;
    }

    Node *temp = *top;
    *top = (*top)->next;

    delete temp;
    jumlahTempatNongkrong--;

    system("cls");
    cout << "Tempat nongkrong berhasil dihapus dari stack." << endl;
}
// akhir fungsi stack

// fungsi queue
void enqueue(Node **front, Node **rear) {
    Node *nodeBaru = createNode();

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

void dequeue(Node **front) {
    if (!*front) {
        cout << "Antrian kosong." << endl;
        return;
    }

    Node *temp = *front;
    *front = (*front)->next;

    delete temp;
    jumlahTempatNongkrong--;
    cout << "Tempat nongkrong berhasil dihapus dari antrian." << endl;
}
// akhir fungsi queue

void tampilkanTempatNongkrong(Node *node) {
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

// fungsi merge sort
void splitList(Node *source, Node **frontRef, Node **backRef) {
    Node *fast;
    Node *slow;
    slow = source;
    fast = source->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

Node *mergeSortedLists(Node *a, Node *b) {
    Node *result = nullptr;

    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;

    if (a->data.rating <= b->data.rating) {
        result = a;
        result->next = mergeSortedLists(a->next, b);
    } else {
        result = b;
        result->next = mergeSortedLists(a, b->next);
    }

    return result;
}

void mergeSort(Node **headRef) {
    Node *head = *headRef;
    Node *a;
    Node *b;

    if ((head == nullptr) || (head->next == nullptr)) {
        return;
    }

    splitList(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);

    *headRef = mergeSortedLists(a, b);
}
// akhir fungsi merge sort

// fungsi quick sort
Node *getTail(Node *cur) {
    while (cur != nullptr && cur->next != nullptr)
        cur = cur->next;
    return cur;
}

Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd) {
    Node *pivot = end;
    Node *prev = nullptr, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->data.rating > pivot->data.rating) {
            if ((*newHead) == nullptr)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        } else {
            if (prev)
                prev->next = cur->next;

            Node *tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == nullptr)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

Node *quickSortRecur(Node *head, Node *end) {
    if (!head || head == end)
        return head;

    Node *newHead = nullptr, *newEnd = nullptr;

    Node *pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = nullptr;

        newHead = quickSortRecur(newHead, tmp);
        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(Node **headRef) {
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
}
// akhir fungsi quick sort

// menampilkan pilihan metode sorting
void sortTempatNongkrong(Node **head, int mode) {
    if (*head == nullptr) {
        cout << "Belum ada tempat nongkrong yang ditambahkan." << endl;
        return;
    }
    int sortingMode;
    system("cls");
    cout << "Pilih metode sorting:" << endl;
    cout << "[1] Merge Sort (Ascending)" << endl;
    cout << "[2] Quick Sort (Descending)" << endl;
    cout << "Pilih metode sorting >> ";
    cin >> sortingMode;

    if (sortingMode == 1) {
        system("cls");
        mergeSort(head);
        cout << "Daftar tempat nongkrong telah diurutkan dengan Merge Sort (Ascending) berdasarkan rating" << endl;
    } else if (sortingMode == 2) {
        system("cls");
        quickSort(head);
        cout << "Daftar tempat nongkrong telah diurutkan dengan Quick Sort (Descending) berdasarkan rating" << endl;
    } else {
        cout << "Metode sorting tidak valid." << endl;
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
        cout << "[4] Sorting tempat nongkrong favorit" << endl;
        cout << "[5] Keluar dari program" << endl;
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
            system("cls");
            if (mode == 1) {
                sortTempatNongkrong(&top, mode);
            } else {
                sortTempatNongkrong(&front, mode);
            }
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