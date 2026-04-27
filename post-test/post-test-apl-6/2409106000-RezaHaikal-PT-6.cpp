#include <iostream>
using namespace std;

struct Barang {
    int id;
    string nama;
};

int binarySearch(Barang *arr, int n, int cariID) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if ((arr + mid)->id == cariID) {
            return mid;
        } else if ((arr + mid)->id < cariID) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int linearSearch(Barang *arr, int n, string cariNama) {
    for (int i = 0; i < n; i++) {
        if ((arr + i)->nama == cariNama) {
            return i;
        }
    }
    return -1;
}

int main() {
    Barang data[5] = {
        {113, "Laptop"},
        {115, "Mouse"},
        {117, "Keyboard"},
        {119, "Monitor"},
        {111, "Printer"}
    };

    int pilihan;

    cout << "=== MENU SEARCHING ===" << endl;
    cout << "1. Cari berdasarkan ID (Binary Search)" << endl;
    cout << "2. Cari berdasarkan Nama (Linear Search)" << endl;
    cout << "Pilih: ";
    cin >> pilihan;

    if (pilihan == 1) {
        int id;
        cout << "Masukkan ID yang dicari: ";
        cin >> id;

        int hasil = binarySearch(data, 5, id);

        if (hasil != -1) {
            cout << "Data ditemukan: "
                 << data[hasil].id << " - "
                 << data[hasil].nama << endl;
        } else {
            cout << "Data tidak ditemukan!" << endl;
        }

    } else if (pilihan == 2) {
        string nama;
        cout << "Masukkan Nama yang dicari: ";
        cin >> nama;

        int hasil = linearSearch(data, 5, nama);

        if (hasil != -1) {
            cout << "Data ditemukan: "
                 << data[hasil].id << " - "
                 << data[hasil].nama << endl;
        } else {
            cout << "Data tidak ditemukan!" << endl;
        }

    } else {
        cout << "Pilihan tidak valid!" << endl;
    }

    return 0;
}