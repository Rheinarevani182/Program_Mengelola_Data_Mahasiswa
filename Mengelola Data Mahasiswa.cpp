#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nim;
    string nama;
    float ipk;
    string jurusan;  // Menambahkan jurusan
};

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "\n=============================\n";
    cout << "   Program Data Mahasiswa\n";
    cout << "=============================\n";
    cout << "1. Tambah Data Mahasiswa\n";
    cout << "2. Tampilkan Data Mahasiswa\n";
    cout << "3. Hapus Data Mahasiswa\n";
    cout << "4. Keluar\n";
    cout << "Pilih menu: ";
}

// Fungsi untuk menambahkan data mahasiswa
void tambahMahasiswa(vector<Mahasiswa>& data) {
    Mahasiswa mhs;
    cout << "Masukkan NIM  : ";
    cin >> mhs.nim;
    cin.ignore(); // 
    cout << "Masukkan Nama : ";
    getline(cin, mhs.nama);
    cout << "Masukkan IPK  : ";
    cin >> mhs.ipk;
    cin.ignore(); // 
    cout << "Masukkan Jurusan: ";
    getline(cin, mhs.jurusan);  

    // Validasi IPK
    if (mhs.ipk < 0.0 || mhs.ipk > 4.0) {
        cout << "IPK harus antara 0.0 hingga 4.0. Data tidak ditambahkan.\n";
        return;
    }

    data.push_back(mhs);
    cout << "Data mahasiswa berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanMahasiswa(const vector<Mahasiswa>& data) {
    if (data.empty()) {
        cout << "Tidak ada data mahasiswa.\n";
        return;
    }

    cout << "\n=============================\n";
    cout << "     Data Mahasiswa\n";
    cout << "=============================\n";
    for (size_t i = 0; i < data.size(); ++i) {
        cout << "Mahasiswa " << i + 1 << ":\n";
        cout << "NIM      : " << data[i].nim << "\n";
        cout << "Nama     : " << data[i].nama << "\n";
        cout << "IPK      : " << data[i].ipk << "\n";
        cout << "Jurusan  : " << data[i].jurusan << "\n";  
        cout << "-----------------------------\n";
    }
}

// Fungsi untuk menghapus data mahasiswa berdasarkan NIM
void hapusMahasiswa(vector<Mahasiswa>& data) {
    if (data.empty()) {
        cout << "Tidak ada data mahasiswa untuk dihapus.\n";
        return;
    }

    string nim;
    cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
    cin >> nim;

    for (vector<Mahasiswa>::iterator it = data.begin(); it != data.end(); ++it) {
        if (it->nim == nim) {
            data.erase(it); // Menghapus data mahasiswa berdasarkan NIM
            cout << "Data mahasiswa dengan NIM " << nim << " berhasil dihapus!\n";
            return; // Keluar setelah data dihapus
        }
    }

    cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
}

// Fungsi utama
int main() {
    vector<Mahasiswa> dataMahasiswa;
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahMahasiswa(dataMahasiswa);
                break;
            case 2:
                tampilkanMahasiswa(dataMahasiswa);
                break;
            case 3:
                hapusMahasiswa(dataMahasiswa);
                break;
            case 4:
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 4);

    return 0;
}

