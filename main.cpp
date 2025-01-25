#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "classes.h"
using namespace std;

void clearScreen() {
    cout << "\033c\033[H"; // Ini pake ANSI Escape code
}

void printHelp() {
    cout << "Berikut aksi-aksi yang bisa Pak Bell pilih:" << endl;
    cout << "(ADD) Tambah Kontak" << endl;
    cout << "(PRINT) Cetak Semua Kontak" << endl;
    cout << "(SEARCH) Cari Kontak" << endl;
    cout << "(EDIT) Sunting Kontak" << endl;
    cout << "(DELETE) Hapus Kontak" << endl;
    cout << "(EXIT) Keluar dari Program" << endl;
    cout << "Silakan pilih aksi yang diinginkan dengan mengetikkan kode aksi (yang diapit tanda kurung) di atas:" << endl;
}

int main() {
    PhoneBook phoneBook;
    
    cout << "Halo, Pak Bell! Selamat datang di program PhoneBook!" << endl;
    printHelp();
    cout << ">> ";

    string aksi;
    cin >> aksi;

    while (aksi != "EXIT") {
        clearScreen();
        // ADD
        if (aksi == "ADD") {
            string nama, nomor, alamat, power;

            // INPUT
            //// Nama
            cout << "Masukkan nama kontak:" << endl;
            cin >> nama;
            if (nama == "") {
                cout << "Nama kontak nggak boleh kosong, Pak Bell!" << endl;
                cout << "Silakan coba lagi!" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                continue;
            }
            if (phoneBook.getIdxKontakByNama(nama) != -1) {
                cout << "Kontak dengan nama " << nama << " sudah ada, Pak Bell!" << endl;
                cout << "Silakan coba lagi!" << endl;
                
                nama = "";
                this_thread::sleep_for(chrono::seconds(1));
                continue;
            }

            //// Nomor
            cout << "Masukkan nomornya si " << nama << ": " << endl;
            cin >> nomor;
            if (nomor == "") {
                cout << "Nomor telepon nggak boleh kosong, Pak Bell! Gimana mau nelpon deh kalo kosong?" << endl;
                cout << "Silakan coba lagi!" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                continue;
            }

            //// Alamat
            cout << "Masukkan alamatnya si " << nama << ": " << endl;
            cin >> alamat;
            if (alamat == "") {
                cout << "Alamat nggak boleh kosong, Pak Bell!" << endl;
                cout << "Silakan coba lagi!" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                continue;
            }

            //// Power
            cout << "Masukkan power-nya si " << nama << ": " << endl;
            cin >> power;

            // CREATE
            Kontak kontak(nama, nomor, alamat, power);
            phoneBook.tambahKontak(kontak);

            // OUTPUT
            cout << "Kontaknya si " << nama << " berhasil ditambahkan, Pak Bell!" << endl;
        }

        // PRINT
        else if (aksi == "PRINT") {
            phoneBook.printSemuaKontak();
        }

        // SEARCH
        else if (aksi == "SEARCH") {
            string nama;
            
            phoneBook.printSemuaNama();
            cout << "Masukkan nama kontak yang ingin dicari:" << endl;
            cin >> nama;
            phoneBook.printKontakByNama(nama);
        }

        // EDIT
        else if (aksi == "EDIT") {
            string nama, nomor, alamat, power;

            phoneBook.printSemuaNama();
            cout << "Masukkan nama kontak yang ingin disunting:" << endl;
            cin >> nama;
            
            // Periksa apakah kontak dengan nama yang dimasukkan ada
            int idx = phoneBook.getIdxKontakByNama(nama);
            if (idx == -1) {
                cout << "Kontak dengan nama " << nama << " nggak ada, Pak Bell!" << endl;
                cout << "Silakan coba lagi!" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                continue;
            }

            Kontak kontak = phoneBook.getKontakByNama(nama);
            cout << "Kontak yang ingin disunting:" << endl;

            // INPUT
            cout << "Masukkan nomor baru untuk kontak " << nama << "(kosongkan kalau tidak berubah):" << endl;
            cin >> nomor;
            cout << "Masukkan alamat baru untuk kontak " << nama << "(kosongkan kalau tidak berubah):" << endl;
            cin >> alamat;
            cout << "Masukkan power baru untuk kontak " << nama << "(kosongkan kalau tidak berubah):" << endl;
            cin >> power;

            // UPDATE
            if (nomor != "") {
                kontak.nomor = nomor;
            }
            if (alamat != "") {
                kontak.alamat = alamat;
            }
            if (power != "") {
                kontak.power = power;
            }
            phoneBook.setKontak(nama, kontak);

            // OUTPUT
            cout << "Kontak " << nama << " berhasil disunting, Pak Bell!" << endl;
        }

        // DELETE
        else if (aksi == "DELETE") {
            string nama;

            phoneBook.printSemuaNama();
            cout << "Masukkan nama kontak yang ingin dihapus:" << endl;
            cin >> nama;

            // Periksa apakah kontak dengan nama yang dimasukkan ada
            int idx = phoneBook.getIdxKontakByNama(nama);
            if (idx == -1) {
                cout << "Kontak dengan nama " << nama << " nggak ada, Pak Bell!" << endl;
                cout << "Silakan coba lagi!" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                continue;
            }

            phoneBook.hapusKontak(nama);
            cout << "Kontak " << nama << " berhasil dihapus, Pak Bell!" << endl;
        }

        // EXIT
        else if (aksi == "EXIT") {
            cout << "Terima kasih, Pak Bell! Sampai jumpa lagi!" << endl;
            phoneBook.hapusSemuaKontak();
            break;
        }

        // INVALID
        else {
            cout << "Maaf, Pakcik! Saya nggak tau itu aksi apaan!" << endl;
        }
        
        // Delay 3 detik lalu tampilkan menu lagi
        this_thread::sleep_for(chrono::milliseconds(1500));
        cout << "Tekan Enter untuk kembali ke laman utama...";
        cin.ignore();
        cin.get();

        clearScreen();
        printHelp();

        // Input aksi lagi
        aksi = "";
        cin >> aksi;
    }

    phoneBook.hapusSemuaKontak();
    return 0;
}
