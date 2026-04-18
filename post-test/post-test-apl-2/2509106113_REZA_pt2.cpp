#include <iostream>
using namespace std;

#define MAX 100

struct Detail {
    string genre;
    int tahun;
};

struct User {
    string nama;
    string nim;
};

struct Game {
    string namaGame;
    Detail detail;
};

User user[MAX];
Game game[MAX];

int jumlahUser = 0;
int jumlahGame = 0;

void registerUser() {
    cout << "\n=== REGISTER ===\n";
    cout << "Nama: ";
    cin >> user[jumlahUser].nama;
    cout << "NIM : ";
    cin >> user[jumlahUser].nim;
    jumlahUser++;
    cout << "Register berhasil!\n";
}

bool loginUser() {
    string nama, nim;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "\n=== LOGIN ===\n";
        cout << "Nama: ";
        cin >> nama;
        cout << "NIM : ";
        cin >> nim;

        for (int i = 0; i < jumlahUser; i++) {
            if (nama == user[i].nama && nim == user[i].nim) {
                cout << "Login berhasil!\n";
                return true;
            }
        }

        percobaan++;
        cout << "Login gagal! (" << percobaan << ")\n";
    }

    return false;
}

void tambahGame() {
    cout << "\n=== TAMBAH GAME ===\n";
    cin.ignore();
    cout << "Nama Game: ";
    getline(cin, game[jumlahGame].namaGame);
    cout << "Genre    : ";
    getline(cin, game[jumlahGame].detail.genre);
    cout << "Tahun    : ";
    cin >> game[jumlahGame].detail.tahun;

    jumlahGame++;
}

void tampilGame() {
    cout << "\n=== DATA GAME ===\n";

    if (jumlahGame == 0) {
        cout << "Belum ada data!\n";
        return;
    }

    cout << "No | Nama Game | Genre | Tahun\n";
    cout << "---------------------------------\n";

    for (int i = 0; i < jumlahGame; i++) {
        cout << i+1 << " | "
             << game[i].namaGame << " | "
             << game[i].detail.genre << " | "
             << game[i].detail.tahun << endl;
    }
}

void ubahGame() {
    int index;
    tampilGame();
    cout << "Pilih nomor: ";
    cin >> index;

    if (index > 0 && index <= jumlahGame) {
        cin.ignore();
        cout << "Nama baru: ";
        getline(cin, game[index-1].namaGame);
        cout << "Genre baru: ";
        getline(cin, game[index-1].detail.genre);
        cout << "Tahun baru: ";
        cin >> game[index-1].detail.tahun;
    } else {
        cout << "Tidak valid!\n";
    }
}

void hapusGame() {
    int index;
    tampilGame();
    cout << "Pilih nomor: ";
    cin >> index;

    if (index > 0 && index <= jumlahGame) {
        for (int i = index-1; i < jumlahGame-1; i++) {
            game[i] = game[i+1];
        }
        jumlahGame--;
        cout << "Data dihapus!\n";
    } else {
        cout << "Tidak valid!\n";
    }
}

void menu() {
    int pilih;
    do {
        cout << "\n=== MENU GAME ===\n";
        cout << "1. Tambah Game\n";
        cout << "2. Tampilkan Game\n";
        cout << "3. Ubah Game\n";
        cout << "4. Hapus Game\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tambahGame(); break;
            case 2: tampilGame(); break;
            case 3: ubahGame(); break;
            case 4: hapusGame(); break;
            case 5: cout << "Keluar...\n"; break;
            default: cout << "Tidak valid!\n";
        }

    } while (pilih != 5);
}

int main() {
    int pilih;

    do {
        cout << "\n=== MENU AWAL ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    menu();
                } else {
                    cout << "Gagal login 3x. Program berhenti.\n";
                    return 0;
                }
                break;
            case 3:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan salah!\n";
        }

    } while (pilih != 3);

    return 0;
}