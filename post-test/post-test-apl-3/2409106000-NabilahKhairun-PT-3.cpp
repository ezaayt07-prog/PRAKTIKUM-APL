#include <iostream>
using namespace std;

#define MAX 100

struct Game {
    string nama;
    string genre;
    int tahun;
};

struct User {
    string nama;
    string nim;
    Game game[MAX];
    int jumlahGame;
};

User users[MAX];
int jumlahUser = 0;

void registerUser(User users[], int &jumlahUser);
bool loginUser(User users[], int jumlahUser, int &indexUser);
void menuUtama(User &u);

void tambahGame(User &u);
void tampilGame(User &u);
void ubahGame(User &u);
void hapusGame(User &u);

void tampilRekursif(User &u, int i);

void garis();
void garis(int n);

int main() {
    int pilihan;
    int indexUser;
    int percobaan = 0;
    bool login = false;

    do {
        cout << "\n=== MENU AWAL ===\n";
        cout << "1. Register\n2. Login\n3. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            registerUser(users, jumlahUser);
        }
        else if (pilihan == 2) {
            while (percobaan < 3 && !login) {
                login = loginUser(users, jumlahUser, indexUser);
                percobaan++;

                if (!login)
                    cout << "Login gagal!\n";
            }

            if (login) {
                cout << "Login berhasil!\n";
                menuUtama(users[indexUser]);
            } else {
                cout << "Gagal 3x, program berhenti!\n";
                return 0;
            }
        }

    } while (pilihan != 3);

    cout << "Program selesai\n";
}

void registerUser(User users[], int &jumlahUser) {
    cout << "\n=== REGISTER ===\n";
    cout << "Nama: "; cin >> users[jumlahUser].nama;
    cout << "NIM : "; cin >> users[jumlahUser].nim;
    users[jumlahUser].jumlahGame = 0;
    jumlahUser++;
}

bool loginUser(User users[], int jumlahUser, int &indexUser) {
    string nama, nim;
    cout << "\n=== LOGIN ===\n";
    cout << "Nama: "; cin >> nama;
    cout << "NIM : "; cin >> nim;

    for (int i = 0; i < jumlahUser; i++) {
        if (users[i].nama == nama && users[i].nim == nim) {
            indexUser = i;
            return true;
        }
    }
    return false;
}

void menuUtama(User &u) {
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
            case 1: tambahGame(u); break;
            case 2: tampilGame(u); break;
            case 3: ubahGame(u); break;
            case 4: hapusGame(u); break;
        }

    } while (pilih != 5);
}

void tambahGame(User &u) {
    cout << "\nNama Game: "; cin >> u.game[u.jumlahGame].nama;
    cout << "Genre    : "; cin >> u.game[u.jumlahGame].genre;
    cout << "Tahun    : "; cin >> u.game[u.jumlahGame].tahun;
    u.jumlahGame++;
}

void tampilGame(User &u) {
    garis(30);
    cout << "\nNo\tNama\tGenre\tTahun\n";
    garis();

    tampilRekursif(u, 0); 

    garis(30);
}

void tampilRekursif(User &u, int i) {
    if (i >= u.jumlahGame) return;

    cout << i+1 << "\t"
         << u.game[i].nama << "\t"
         << u.game[i].genre << "\t"
         << u.game[i].tahun << endl;

    tampilRekursif(u, i+1);
}

void ubahGame(User &u) {
    int i;
    tampilGame(u);
    cout << "Pilih nomor: ";
    cin >> i;

    i--;
    cout << "Nama baru: "; cin >> u.game[i].nama;
}

void hapusGame(User &u) {
    int i;
    tampilGame(u);
    cout << "Pilih nomor: ";
    cin >> i;

    i--;
    for (int j = i; j < u.jumlahGame-1; j++) {
        u.game[j] = u.game[j+1];
    }
    u.jumlahGame--;
}

void garis() {
    cout << "---------------------------\n";
}

void garis(int n) {
    for (int i = 0; i < n; i++)
        cout << "=";
    cout << endl;
}