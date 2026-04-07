#include <iostream>
using namespace std;

struct Game {
    string namaGame;
    string genreGame;
    int hargaGame;
};

void tambahGame(Game *dataGame, int &jumlahGame) {
    cout << "\n=== Tambah Game ===\n";

    cout << "Nama Game   : ";
    cin >> dataGame[jumlahGame].namaGame;

    cout << "Genre Game  : ";
    cin >> dataGame[jumlahGame].genreGame;

    cout << "Harga Game  : ";
    cin >> dataGame[jumlahGame].hargaGame;

    jumlahGame++;
}

void tampilGame(Game *dataGame, int jumlahGame) {
    cout << "\n=== Data Koleksi Game ===\n";

    if (jumlahGame == 0) {
        cout << "Belum ada data game.\n";
    } else {
        for (int i = 0; i < jumlahGame; i++) {
            cout << "\nGame ke-" << i + 1 << endl;
            cout << "Nama  : " << dataGame[i].namaGame << endl;
            cout << "Genre : " << dataGame[i].genreGame << endl;
            cout << "Harga : " << dataGame[i].hargaGame << endl;
        }
    }
}

int main() {
    Game dataGame[100];
    int jumlahGame = 0;
    int pilihanMenu;

    do {
        cout << "\n=== Sistem Pendataan Koleksi Game ===\n";
        cout << "1. Tambah Game\n";
        cout << "2. Tampilkan Game\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihanMenu;

        if (pilihanMenu == 1) {
            tambahGame(dataGame, jumlahGame);
        } else if (pilihanMenu == 2) {
            tampilGame(dataGame, jumlahGame);
        }

    } while (pilihanMenu != 3);

    cout << "Terimakasih sudah mampir datang lagi yahhh sahabat.\n";
    return 0;
}