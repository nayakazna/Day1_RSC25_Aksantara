#include "classes.h"
using namespace std;

int idPhoneBook = 0; // id PhoneBook, di auto-increment
const Kontak MARK("", "", "", ""); // Buat nandain kontak kosong

// Implementasi Metode dari Kelas Kontak
Kontak::Kontak() : nama(""), nomor(""), alamat(""), power("") {}

Kontak::Kontak(string nama, string nomor, string alamat, string power) :
    nama(nama),
    nomor(nomor),
    alamat(alamat),
    power(power) {}

void Kontak::printKontak() const {
    cout << "Nama: " << nama << "\n"
         << "Nomor: " << nomor << "\n"
         << "Alamat: " << alamat << "\n"
         << "Power: " << power << endl;
}

bool Kontak::operator==(const Kontak& kontak) const {
    return this->nama == kontak.nama && this->nomor == kontak.nomor;
}

// Implementasi Metode dari Kelas PhoneBook
PhoneBook::PhoneBook() :
    id(idPhoneBook++),
    countKontak(0) {
        for (int i = 0; i < MAX_KONTAK; i++) kontaks[i] = MARK;
    }

bool PhoneBook::isKontakEmpty() const {
    return (countKontak == 0);
}

bool PhoneBook::isKontakFull() const {
    return (countKontak == MAX_KONTAK);
}

void PhoneBook::tambahKontak(const Kontak& kontak) {
    // Cuma tambah kalo kontak belum ada di PhoneBook
    if (getIdxKontakByNama(kontak.nama) != -1) {
        cout << "Kontak yang namanya " << kontak.nama << " udah ada, Cik!" << endl;
        return;
    }
    if (isKontakFull()) {
        // Geser kiri semua kontak
        for (int i = 0; i < MAX_KONTAK-1; i++) {
            kontaks[i] = kontaks[i+1];
        }
        kontaks[MAX_KONTAK-1] = kontak;
    }
    else {
        kontaks[countKontak++] = kontak;
    }
}

void PhoneBook::printSemuaKontak() const {
    if (isKontakEmpty()) {
        cout << "Kontak kosong, Cik!" << endl;
    }
    else {
        for (int i = 0; i < countKontak; i++) {
            cout << "Kontak ke-" << i+1 << ": " << endl;
            kontaks[i].printKontak();
        }
    }
}

void PhoneBook::printSemuaNama() const {
    if (isKontakEmpty()) {
        cout << "Kontak kosong, Cik!" << endl;
    }
    else {
        for (int i = 0; i < countKontak; i++) {
            cout << "Kontak ke-" << i+1 << ": " << kontaks[i].nama << endl;
        }
    }
}

void PhoneBook::printKontakByNama(string nama) const {
    for (int i = 0; i < countKontak; i++) {
        if (kontaks[i].nama == nama) {
            kontaks[i].printKontak();
            return;
        }
    }
    cout << "Kontak yang namanya " << nama << " nggak ada, Cik!" << endl;
}

void PhoneBook::setKontak(string nama, Kontak kontak) {
    for (int i = 0; i < countKontak; i++) {
        if (kontaks[i].nama == nama) {
            kontaks[i] = kontak;
        }
    }
}

void PhoneBook::hapusKontak(string nama) {
    for (int i = 0; i < countKontak; i++) {
        if (kontaks[i].nama == nama) {
            for (int j = i; j < MAX_KONTAK-1; j++) {
                kontaks[j] = kontaks[j+1];
            }
            kontaks[MAX_KONTAK-1] = MARK;
            countKontak--;
            break;
        }
    }
}

void PhoneBook::hapusSemuaKontak() {
    for (int i = 0; i < MAX_KONTAK; i++) {
        kontaks[i] = MARK;
    }
    countKontak = 0;
    cout << "Semua kontak berhasil dihapus, Cik!" << endl;
}

int PhoneBook::getIdxKontakByNama(string nama) const {
    for (int i = 0; i < countKontak; i++) {
        if (this->kontaks[i].nama == nama) {
            return i;
        }
    }
    return -1;
}

Kontak PhoneBook::getKontakByNama(string nama) const {
    for (int i = 0; i < countKontak; i++) {
        if (this->kontaks[i].nama == nama) {
            return this->kontaks[i];
        }
    }
    return MARK;
}

// Notes
// PhoneBook dikasi ID buat implementasi kedepannya kalo memungkinkan lebih dari 1 PhoneBook
// Kontak yang disimpan di PhoneBook disimpan terurut dari kontak terlama. Rata kiri.