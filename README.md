# PhoneBook Tuan Bell 📞

Sistem manajemen kontak sederhana dalam C++ dengan antarmuka CLI yang dibuat untuk mengelola kontak Pak Bell setelah kehilangan buku kontaknya akibat kedzaliman Fatui Harbinger.

## Fitur ✨
- **Operasi CRUD**:
  - Buat, cetak, perbarui, dan hapus kontak
  - Hapus semua kontak sekaligus ketika keluar dari program dengan perintah `EXIT`
- **Pencarian**:
  - Cari berdasarkan nama
  - Tampilkan semua nama kontak
- **Penyimpanan Data**:
  - Penyimpanan array statik (maks 8 kontak)
  - Penggantian FIFO saat penuh
- **Detail Kontak**:
  - Nama
  - Nomor Telepon
  - Alamat
  - Kekuatan Super

## Instalasi
### Dependensi
- Kompiler C++ (direkomendasikan GCC)
- C++11 atau lebih baru
- Terminal Linux/macOS atau Windows PowerShell/Command Prompt

### Kompilasi
Silakan *compile* program dengan menjalankan perintah berikut di *command line*:
```bash
g++ -o phonebook main.cpp classes.cpp -std=c++11 
```

Selanjutnya, jalankan program dengan
```bash
./phonebook
```