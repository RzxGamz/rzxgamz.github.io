#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Kelas Buku
class Buku {
public:
    string judul;
    string penulis;
    int tahunTerbit;
    bool dipinjam;

    Buku(string judul, string penulis, int tahunTerbit) : judul(judul), penulis(penulis), tahunTerbit(tahunTerbit), dipinjam(false) {}

    void tampilkanInfo() {
        cout << "Judul: " << judul << endl;
        cout << "Penulis: " << penulis << endl;
        cout << "Tahun Terbit: " << tahunTerbit << endl;
        cout << "Status: " << (dipinjam ? "Dipinjam" : "Tersedia") << endl;
    }
};

// Kelas Anggota
class Anggota {
public:
    string nama;
    int nomorAnggota;
    vector<Buku*> bukuDipinjam;

    Anggota(string nama, int nomorAnggota) : nama(nama), nomorAnggota(nomorAnggota) {}

    void tampilkanInfo() {
        cout << "Nama: " << nama << endl;
        cout << "Nomor Anggota: " << nomorAnggota << endl;
        cout << "Buku yang Dipinjam:" << endl;
        for (Buku* buku : bukuDipinjam) {
            cout << "- " << buku->judul << endl;
        }
    }

    void pinjamBuku(Buku* buku) {
        if (!buku->dipinjam) {
            buku->dipinjam = true;
            bukuDipinjam.push_back(buku);
            cout << "Buku \"" << buku->judul << "\" berhasil dipinjam." << endl;
        } else {
            cout << "Buku \"" << buku->judul << "\" sedang dipinjam." << endl;
        }
    }

    void kembalikanBuku(Buku* buku) {
        auto it = find(bukuDipinjam.begin(), bukuDipinjam.end(), buku);
        if (it != bukuDipinjam.end()) {
            buku->dipinjam = false;
            bukuDipinjam.erase(it);
            cout << "Buku \"" << buku->judul << "\" berhasil dikembalikan." << endl;
        } else {
            cout << "Buku \"" << buku->judul << "\" tidak dipinjam oleh anggota ini." << endl;
        }
    }
};

// Kelas Perpustakaan
class Perpustakaan {
public:
    vector<Buku*> daftarBuku;
    vector<Anggota*> daftarAnggota;

    void tambahBuku(Buku* buku) {
        daftarBuku.push_back(buku);
    }

    void tambahAnggota(Anggota* anggota) {
        daftarAnggota.push_back(anggota);
    }

    Buku* cariBuku(string judul) {
        for (Buku* buku : daftarBuku) {
            if (buku->judul == judul) {
                return buku;
            }
        }
        return nullptr;
    }

    Anggota* cariAnggota(int nomorAnggota) {
        for (Anggota* anggota : daftarAnggota) {
            if (anggota->nomorAnggota == nomorAnggota) {
                return anggota;
            }
        }
        return nullptr;
    }

    void tampilkanDaftarBuku() {
        cout << "Daftar Buku:" << endl;
        for (Buku* buku : daftarBuku) {
            buku->tampilkanInfo();
            cout << "--------------------" << endl;
        }
    }

    void tampilkanDaftarAnggota() {
        cout << "Daftar Anggota:" << endl;
        for (Anggota* anggota : daftarAnggota) {
            anggota->tampilkanInfo();
            cout << "--------------------" << endl;
        }
    }
};

int main() {
    Perpustakaan perpustakaan;

    // Menambahkan buku
    perpustakaan.tambahBuku(new Buku("Harry Potter", "J.K. Rowling", 1997));
    perpustakaan.tambahBuku(new Buku("The Lord of the Rings", "J.R.R. Tolkien", 1954));
    perpustakaan.tambahBuku(new Buku("The Hobbit", "J.R.R. Tolkien", 1937));

    // Menambahkan anggota
    perpustakaan.tambahAnggota(new Anggota("Alice", 1001));
    perpustakaan.tambahAnggota(new Anggota("Bob", 1002));

    // Menampilkan daftar buku dan anggota
    perpustakaan.tampilkanDaftarBuku();
    perpustakaan.tampilkanDaftarAnggota();

    // Meminjam buku
    Anggota* alice = perpustakaan.cariAnggota(1001);
    Buku* harryPotter = perpustakaan.cariBuku("Harry Potter");
    if (alice && harryPotter) {
        alice->pinjamBuku(harryPotter);
    }

    // Menampilkan daftar buku yang dipinjam oleh Alice
    alice->tampilkanInfo();

    // Mengembalikan buku
    if (alice && harryPotter) {
        alice->kembalikanBuku(harryPotter);
    }

    // Menampilkan daftar buku yang dipinjam oleh Alice setelah pengembalian
    alice->tampilkanInfo();

    return 0;
}
