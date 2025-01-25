#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <iostream>

const int MAX_KONTAK = 8;
extern int idPhoneBook; // Counter buat id PhoneBook

class Kontak {
public:
    std::string nama;
    std::string nomor;
    std::string alamat;
    std::string power;

    // Constructors
    Kontak();
    Kontak(std::string nama, std::string nomor, std::string alamat, std::string power);

    // Methods
    void printKontak() const;
    bool operator==(const Kontak& other) const;
};

extern const Kontak MARK;  // Declaration of marker

class PhoneBook {
    unsigned int id;
    Kontak kontaks[MAX_KONTAK];
    int countKontak;

public:
    // Konstruktor
    PhoneBook();
    
    // Validator
    bool isKontakEmpty() const;
    bool isKontakFull() const;
    
    // Methods buat CRUD
    // Create
    void tambahKontak(const Kontak& kontak);
    
    // Read
    void printSemuaKontak() const;
    void printSemuaNama() const;
    void printKontakByNama(std::string nama) const;
    
    // Update
    void setKontak(std::string nama, Kontak kontak);
    
    // Delete
    void hapusKontak(std::string nama);
    void hapusSemuaKontak();
    
    // Getter
    int getIdxKontakByNama(std::string nama) const;
    Kontak getKontakByNama(std::string nama) const;
};

#endif