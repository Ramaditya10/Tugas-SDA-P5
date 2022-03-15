#include <iostream>                                    //Nama   : Ramaditya Firdaus
#include <string>                                      //NIM    : 2103800
using namespace std;                                   //Kelas  : RPL 3B

struct Barang
{
    string kodeBarang;
    string namaBarang;
    int jumlahBarang;
};

void TambahBarang(Barang *barang);
void TampilkanBarang(Barang *barang);
int totalBarang = 0;

int main(){
    int pilihMenu;
    char lanjutkan;
    Barang *listBrg = new Barang[100];               //Array Pointer Dinamis

    MenuUtama:                                       //Label
    system("cls");                                   //Membersihkan Konsol

    cout << "Menu Pilihan" << endl;
    cout << "1. Tambah / Masukan Barang" << endl;
    cout << "2. Tampilkan Barang" << endl;
    cout << "3. Keluar" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Pilih Menu Program : ";
    cin >> pilihMenu;

      while(pilihMenu != 3){                        //Seleksi Kondisi
        switch(pilihMenu){
        case 1:
            TambahBarang(listBrg);                  //Memanggil prosedure (void TambahaBarang())
            break;
        case 2:
            TampilkanBarang(listBrg);
            break;
        default:
            cout << "Pilihan Tidak Ada" << endl;
            goto MenuUtama;                         //pergi ke label MenuUtama
            break;
        }

        cout << endl;
        menu_lanjutkan:
        cout << "Lanjutkan?(Y/N): " ; cin >> lanjutkan;
        if( (lanjutkan == 'Y') | (lanjutkan == 'y') ){
            goto MenuUtama;
        } else if((lanjutkan == 'N') | (lanjutkan == 'n')){
            break;
        }else {
            goto menu_lanjutkan;
        }
    }
}

void TambahBarang(Barang *barang){
    string nama;
    string kode;
    int jumlah;
    int nTambah;

    cout << endl;
    cout << "Input Jumlah Barang : " ;
    cin >> nTambah;

    for(int i=0; i<nTambah; i++){                           //Looping sesuai keinginan Users
        cout << "Data Barang Ke-" << totalBarang+1 << endl;
        cout << "Kode Barang   : ";
        cin >> kode;
        cout << "Nama Barang   : ";
        cin >> nama;
        cout << "Jumlah Barang : ";
        cin >> jumlah;

        barang[totalBarang].kodeBarang = kode;              //Diinputkan kedalam struct
        barang[totalBarang].namaBarang = nama;
        barang[totalBarang].jumlahBarang = jumlah;
        totalBarang++;
        cout << endl;
    }
}

void TampilkanBarang(Barang *barang){
    cout << "No\t" << "Kode Barang\t" << "Nama Barang\t" << "Jumlah Barang\t" << endl;
    for(int i=0; i < totalBarang; i++){
        cout << i + 1 << "\t" << barang[i].kodeBarang << "\t\t" << barang[i].namaBarang << "\t\t" << barang[i].jumlahBarang << endl;
    }
}
