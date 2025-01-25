#include "classes.h"
#include <iostream>
#include <string>
using namespace std;

const int MAX_KONTAK = 8; // Maksimal kontak yang bisa disimpen di PhoneBook
int idPhoneBook = 0; // id PhoneBook, di auto-increment

// Class Kontak
class Kontak {
    public:
        // Atribut
        string nama;
        string nomor;
        string alamat;
        string power;

        // Konstruktor
        Kontak() : nama(""), nomor(""), alamat(""), power("") {}
    
        Kontak(string nama, string nomor, string alamat, string power) :
            nama(nama),
            nomor(nomor),
            alamat(alamat),
            power(power)
        {}

        // Metode
        void printKontak() const {
            cout << "Nama: " << nama << "\n"
                << "Nomor: " << nomor << "\n"
                << "Alamat: " << alamat << "\n"
                << "Power: " << power << endl;
        }

        // Operator
        bool operator==(const Kontak& kontak) const {
            return this->nama == kontak.nama && this->nomor == kontak.nomor;
        }
};

const Kontak MARK("", "", "", ""); // Buat nandain kontak kosong


// Class PhoneBook
class PhoneBook {
        // Atribut
        unsigned int id; // id PhoneBook
        Kontak kontaks[MAX_KONTAK]; // Array of Kontak buat nyimpen seluruh kontak, disimpan terurut dari kontak terlama. Rata kiri.
        int countKontak; // Jumlah kontak yang disimpan di PhoneBook
        
    public:
        // Konstruktor
        PhoneBook() :
            id(idPhoneBook++),
            countKontak(0) {
                for (int i = 0; i < MAX_KONTAK; i++) kontaks[i] = MARK;
            }
        

        // Metode
        bool isKontakEmpty() const {
            return (countKontak == 0);
        }
        bool isKontakFull() const {
            return (countKontak == MAX_KONTAK);
        }

        void tambahKontak(const Kontak& kontak){
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
        void printSemuaKontak() const {
            for (int i = 0; i < countKontak; i++) {
                kontaks[i].printKontak();
            }
        }
        
        void printSemuaNama() const {
            for (int i = 0; i < countKontak; i++) {
                cout << kontaks[i].nama << endl;
            }
        }

        void printKontakByNama(string nama) const {
            for (int i = 0; i < countKontak; i++) {
                if (kontaks[i].nama == nama) {
                    kontaks[i].printKontak();
                    return;
                }
            }
            cout << "Kontak yang namanya " << nama << " nggak ada, Cik!" << endl;
        }
        void setKontak(string nama, Kontak kontak) {
            for (int i = 0; i < countKontak; i++) {
                if (kontaks[i].nama == nama) {
                    kontaks[i] = kontak;
                }
            }
        }
        void hapusKontak(string nama) {
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
        void hapusSemuaKontak() {
            for (int i = 0; i < MAX_KONTAK; i++) {
                kontaks[i] = MARK;
            }
            countKontak = 0;
            cout << "Semua kontak berhasil dihapus, Cik!" << endl;
        }
        int getIdxKontakByNama(string nama) const {
            for (int i = 0; i < countKontak; i++) {
                if (this->kontaks[i].nama == nama) {
                    return i;
                }
            }
            return -1;
        }
    };

// Notes
// PhoneBook dikasi ID buat implementasi kedepannya kalo memungkinkan lebih dari 1 PhoneBook
// Kontak yang disimpan di PhoneBook disimpan terurut dari kontak terlama. Rata kiri.
