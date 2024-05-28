#include <iostream>
using namespace std;

// deklarasi double linked list
struct DataUser{
  string nama, username, email, password;
  DataUser *sebelumnya;
  DataUser *selanjutnya;
};

DataUser *kepala, *ekor, *saat_ini, *nodeBaru, *hapus, *setelahNode;

// Buat Double Linked List
void buatDoubleLinkedList( string data[4] ){
  kepala = new DataUser();
  kepala->nama = data[0];
  kepala->username = data[1];
  kepala->email = data[2];
  kepala->password = data[3];
  kepala->sebelumnya = NULL;
  kepala->selanjutnya = NULL;
  ekor = kepala;
}

// hitung Double Linked List
int hitungDoubleLinkedList()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    saat_ini = kepala;
    int jumlah = 0;
    while( saat_ini != NULL ){
      jumlah++;      
      // pindah
      saat_ini = saat_ini->selanjutnya;
    }
    return jumlah;
  }
}

// Tambah Awal
void tambahAwal( string data[4] ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    nodeBaru = new DataUser();
    nodeBaru->nama = data[0];
    nodeBaru->username = data[1];
    nodeBaru->email = data[2];
    nodeBaru->password = data[3];
    nodeBaru->sebelumnya = NULL;
    nodeBaru->selanjutnya = kepala;
    kepala->sebelumnya = nodeBaru;
    kepala = nodeBaru;
  }
}

// Tambah Akhir
void tambahAkhir( string data[4] ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    nodeBaru = new DataUser();
    nodeBaru->nama = data[0];
    nodeBaru->username = data[1];
    nodeBaru->email = data[2];
    nodeBaru->password = data[3];
    nodeBaru->sebelumnya = ekor;
    nodeBaru->selanjutnya = NULL;
    ekor->selanjutnya = nodeBaru;
    ekor = nodeBaru;
  }
}


// hapus Awal
void hapusAwal()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    hapus = kepala;
    kepala = kepala->selanjutnya;
    kepala->sebelumnya = NULL;
    delete hapus;
  }
}

// hapus Akhir
void hapusAkhir()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    hapus = ekor;
    ekor = ekor->sebelumnya;
    ekor->selanjutnya = NULL;
    delete hapus;
  }
}

// Cetak Double Linked List
void cetakDoubleLinkedList()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cout << "Jumlah Data : " << hitungDoubleLinkedList() << endl;
    cout << "Isi Data : " << endl;
    saat_ini = kepala;
    while( saat_ini != NULL ){
      // cetak
      cout << "Nama User : " << saat_ini->nama << endl;
      cout << "Username User : " << saat_ini->username << endl;
      cout << "Email User : " << saat_ini->email << endl;
      cout << "Password User : " << saat_ini->password << "\n" << endl;
      // pindah
      saat_ini = saat_ini->selanjutnya;
    }
  }
}

int main(){

string newData[4] = {"Irma Fatimatuz Zahro", "jimet", "irmakayang@gmail.com", "tahu_uap"};
  buatDoubleLinkedList(newData);

  cetakDoubleLinkedList();

  string data2[4] = {"Muhammad Diluc", "dilucxx", "dilukgemsing@gmail.com", "dilucgantenglovvv"};

  tambahAwal( data2 );

  cetakDoubleLinkedList();

  string data3[4] = {"Pace Mace", "pacmac", "sayapapua@gmail.com", "yppa"};

  tambahAkhir( data3 );

  cetakDoubleLinkedList();

  cetakDoubleLinkedList();


}