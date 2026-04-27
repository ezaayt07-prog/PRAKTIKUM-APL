#include <iostream>
#include <stdexcept>
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
        {111, "Printer"},
        {113, "Laptop"},
        {115, "Mouse"},
        {117, "Keyboard"},
        {119, "Monitor"}
    };

    int pilihan;

    cout << "=== MENU SEARCHING ===" << endl;
    cout << "1. Cari berdasarkan ID (Binary Search)" << endl;
    cout << "2. Cari berdasarkan Nama (Linear Search)" << endl;
    cout << "Pilih: ";
    cin >> pilihan;

    try {
        if (cin.fail()) {
            throw invalid_argument("Input harus angka!");
        }

        if (pilihan == 1) {
            int id;
            cout << "Masukkan ID: ";
            cin >> id;

            if (cin.fail()) {
                throw invalid_argument("ID harus berupa angka!");
            }

            int hasil = binarySearch(data, 5, id);

            if (hasil == -1) {
                throw runtime_error("Data tidak ditemukan!");
            }

            cout << "Data ditemukan: "
                 << data[hasil].id << " - "
                 << data[hasil].nama << endl;

        } else if (pilihan == 2) {
            string nama;
            cout << "Masukkan Nama: ";
            cin >> nama;

            int hasil = linearSearch(data, 5, nama);

            if (hasil == -1) {
                throw runtime_error("Data tidak ditemukan!");
            }

            cout << "Data ditemukan: "
                 << data[hasil].id << " - "
                 << data[hasil].nama << endl;

        } else {
            throw invalid_argument("Pilihan menu tidak valid!");
        }

    } catch (exception &e) {
        cout << "ERROR: " << e.what() << endl;
    }

    return 0;
}