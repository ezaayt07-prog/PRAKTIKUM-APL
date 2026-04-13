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
    cin >> (*(dataGame + jumlahGame)).namaGame;

    cout << "Genre Game  : ";
    cin >> (*(dataGame + jumlahGame)).genreGame;

    cout << "Harga Game  : ";
    cin >> (*(dataGame + jumlahGame)).hargaGame;

    jumlahGame++;
}

void tampilGame(Game *dataGame, int jumlahGame) {
    cout << "\n=== Data Koleksi Game ===\n";

    if (jumlahGame == 0) {
        cout << "Belum ada data game.\n";
    } else {
        for (int i = 0; i < jumlahGame; i++) {
            cout << "\nGame ke-" << i + 1 << endl;
            cout << "Nama  : " << (*(dataGame + i)).namaGame << endl;
            cout << "Genre : " << (*(dataGame + i)).genreGame << endl;
            cout << "Harga : " << (*(dataGame + i)).hargaGame << endl;
        }
    }
}

void bubbleSortNama(Game *dataGame, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((dataGame + j)->namaGame > (dataGame + j + 1)->namaGame) {
                swap(*(dataGame + j), *(dataGame + j + 1));
            }
        }
    }
}

void selectionSortHarga(Game *dataGame, int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if ((dataGame + j)->hargaGame > (dataGame + maxIndex)->hargaGame) {
                maxIndex = j;
            }
        }
        swap(*(dataGame + i), *(dataGame + maxIndex));
    }
}

void insertionSortGenre(Game *dataGame, int n) {
    for (int i = 1; i < n; i++) {
        Game key = *(dataGame + i);
        int j = i - 1;

        while (j >= 0 && (dataGame + j)->genreGame > key.genreGame) {
            *(dataGame + j + 1) = *(dataGame + j);
            j--;
        }
        *(dataGame + j + 1) = key;
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
        cout << "3. Sort Nama (Ascending)\n";
        cout << "4. Sort Harga (Descending)\n";
        cout << "5. Sort Genre (Ascending)\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihanMenu;

        if (pilihanMenu == 1) {
            tambahGame(dataGame, jumlahGame);
        } 
        else if (pilihanMenu == 2) {
            tampilGame(dataGame, jumlahGame);
        } 
        else if (pilihanMenu == 3) {
            bubbleSortNama(dataGame, jumlahGame);
            cout << "Data diurutkan berdasarkan NAMA (A-Z)\n";
        } 
        else if (pilihanMenu == 4) {
            selectionSortHarga(dataGame, jumlahGame);
            cout << "Data diurutkan berdasarkan HARGA (Tertinggi)\n";
        } 
        else if (pilihanMenu == 5) {
            insertionSortGenre(dataGame, jumlahGame);
            cout << "Data diurutkan berdasarkan GENRE (A-Z)\n";
        }

    } while (pilihanMenu != 6);

    cout << "Terimakasih sudah mampir datang lagi yahhh sahabat.\n";
    return 0;
}