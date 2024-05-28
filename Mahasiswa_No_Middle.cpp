#include <iostream>
using namespace std;

// deklarasi double linked list
struct DataUser {
  string nama, jurusan, NIM;
  DataUser *sebelumnya;
  DataUser *selanjutnya;
};

DataUser *kepala, *ekor, *saat_ini, *nodeBaru, *hapus, *setelahNode;

// Buat Double Linked List
void buatDoubleLinkedList(string data[3]) {
  kepala = new DataUser();
  kepala->nama = data[0];
  kepala->jurusan = data[1];
  kepala->NIM = data[2];
  kepala->sebelumnya = NULL;
  kepala->selanjutnya = NULL;
  ekor = kepala;
}

// hitung Double Linked List
int hitungDoubleLinkedList() {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!";
  } else {
    saat_ini = kepala;
    int jumlah = 0;
    while (saat_ini != NULL) {
      jumlah++;
      // pindah
      saat_ini = saat_ini->selanjutnya;
    }
    return jumlah;
  }
  return 0;
}

// Tambah Awal
void tambahAwal(string data[3]) {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!";
  } else {
    nodeBaru = new DataUser();
    nodeBaru->nama = data[0];
    nodeBaru->jurusan = data[1];
    nodeBaru->NIM = data[2];
    nodeBaru->sebelumnya = NULL;
    nodeBaru->selanjutnya = kepala;
    kepala->sebelumnya = nodeBaru;
    kepala = nodeBaru;
  }
}

// Tambah Akhir
void tambahAkhir(string data[3]) {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!";
  } else {
    nodeBaru = new DataUser();
    nodeBaru->nama = data[0];
    nodeBaru->jurusan = data[1];
    nodeBaru->NIM = data[2];
    nodeBaru->sebelumnya = ekor;
    nodeBaru->selanjutnya = NULL;
    ekor->selanjutnya = nodeBaru;
    ekor = nodeBaru;
  }
}

// hapus Awal
void hapusAwal() {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!";
  } else {
    hapus = kepala;
    kepala = kepala->selanjutnya;
    kepala->sebelumnya = NULL;
    delete hapus;
  }
}

// hapus Akhir
void hapusAkhir() {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!";
  } else {
    hapus = ekor;
    ekor = ekor->sebelumnya;
    ekor->selanjutnya = NULL;
    delete hapus;
  }
}

// Ubah Data di Posisi Pertama
void changeFirst(string data[3]) {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    kepala->nama = data[0];
    kepala->jurusan = data[1];
    kepala->NIM = data[2];
  }
}


// Ubah Data di Posisi Terakhir
void changeLast(string data[3]) {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    ekor->nama = data[0];
    ekor->jurusan = data[1];
    ekor->NIM = data[2];
  }
}

// Cetak Double Linked List
void cetakDoubleLinkedList() {
  if (kepala == NULL) {
    cout << "Double Linked List belum dibuat!!!" << endl;
  } else {
    cout << "Jumlah Data : " << hitungDoubleLinkedList() << endl;
    cout << "Isi Data : " << endl;
    saat_ini = kepala;
    while (saat_ini != NULL) {
      // cetak
      cout << "Nama User : " << saat_ini->nama << endl;
      cout << "Jurusan User : " << saat_ini->jurusan << endl;
      cout << "NIM User : " << saat_ini->NIM << "\n" << endl;
      // pindah
      saat_ini = saat_ini->selanjutnya;
    }
  }
}

int main() {
  string newData[3] = {"Irma Fatimatuz Zahro", "informatika", "1111"};
  buatDoubleLinkedList(newData);

  cetakDoubleLinkedList();

  string data2[3] = {"Muhammad Diluc", "elektro", "2222"};
  tambahAwal(data2);
  cetakDoubleLinkedList();

  string data3[3] = {"Pace Mace", "manajemen", "3333"};
  tambahAkhir(data3);
  cetakDoubleLinkedList();

  string changeData[3] = {"pacar cina", "DKV", "9999"};
  changeFirst(changeData);
  cetakDoubleLinkedList();

  string changeDataLast[3] = {"Kurnia Agatha", "Sastra Jawa", "7777"};
  changeLast(changeDataLast);
  cetakDoubleLinkedList();


}
