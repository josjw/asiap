#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <iomanip>
#define MAX 11

using namespace std;

struct pasien
{
    string nik, nama, jk;
    int umur, index;
};

struct queue
{
    pasien psn[MAX];
    int awal, akhir;
}antrean;

struct node
{
    string nik, nama;
    int jasa, obat, total;
    node *next;
};

node *head = NULL;
node *posisi;
int no_urut = 1, antri = 0;
string user, pass;

bool full()
{
    if(antrean.akhir == MAX-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool empty()
{
    if(antrean.akhir==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void init()
{
    antrean.awal = 0;
    antrean.akhir = 0;
}

void tampilData(bool a)
{
    int i;
    if(a == true)
    {
        cout << "\n Nomor Sekarang = " << antri << endl << endl;
        cout << " =============================================================\n";
        cout << " | NO |        NIK        |         NAMA         | JK | UMUR |\n";
        cout << " =============================================================\n";
    }
    else
    {
        cout << "\n Nomor Sekarang = " << antri << endl << endl;
        cout << " =============================\n";
        cout << " | NO |         NAMA         |\n";
        cout << " =============================\n";
    }
    if(!empty())
    {
        for(i=antrean.awal; i<antrean.akhir; i++)
        {
            if(a == true)
            {
                cout << " | " << setw(2) << antrean.psn[i].index;
                cout << " | " << setiosflags(ios::left) << setw(17) << antrean.psn[i].nik;
                cout << " | " << setiosflags(ios::left) << setw(20) << antrean.psn[i].nama;
                cout << " | " << setiosflags(ios::left) << setw(2) << antrean.psn[i].jk;
                cout << " |  " << setiosflags(ios::left) << setw(3) << antrean.psn[i].umur << " |" << endl;
            }
            else
            {
                cout << " | " << setw(2) << antrean.psn[i].index;
                cout << " | " << setiosflags(ios::left) << setw(20) << antrean.psn[i].nama << " |" << endl;
            }
        }
    }
    else
    {
        if(a == true)
        {
            cout << " |                      ANTREAN KOSONG                       |\n";
        }
        else
        {
            cout << " |      ANTREAN  KOSONG      |\n";
        }
    }
    if(a == true)
    {
        cout << " =============================================================\n";
    }
    else
    {
        cout << " =============================\n";
    }
}

void sort_asc(bool x, bool y)
{
    string temp, temp0, temp1;
    int temp2, temp3;
    int u = antrean.akhir-1, nmax;
    for(int k = antrean.awal; k < antrean.akhir; k++)
    {
		nmax = 0;
		for(int j=0; j<=u; j++)
		{
		    if(y == true)
            {
                if(antrean.psn[nmax].nama<antrean.psn[j].nama)
                {
                    nmax=j;
                }
            }
            else if(y == false)
            {
                if(antrean.psn[nmax].nama>antrean.psn[j].nama)
                {
                    nmax=j;
                }
            }

		}
        temp = antrean.psn[u].nik;
        antrean.psn[u].nik = antrean.psn[nmax].nik;
        antrean.psn[nmax].nik = temp;
        temp0 = antrean.psn[u].nama;
        antrean.psn[u].nama = antrean.psn[nmax].nama;
        antrean.psn[nmax].nama = temp0;
        temp1 = antrean.psn[u].jk;
        antrean.psn[u].jk = antrean.psn[nmax].jk;
        antrean.psn[nmax].jk = temp1;
        temp2 = antrean.psn[u].umur;
        antrean.psn[u].umur = antrean.psn[nmax].umur;
        antrean.psn[nmax].umur = temp2;
        temp3 = antrean.psn[u].index;
        antrean.psn[u].index = antrean.psn[nmax].index;
        antrean.psn[nmax].index = temp3;
        u--;
	}
	if(x == true)
    {
        tampilData(false);
    }
}

void queue_def()
{
    string temp, temp0, temp1;
    int temp2,temp3;
    int u = antrean.akhir-1, nmax;
    for(int k = antrean.awal; k < antrean.akhir; k++)
    {
		nmax = 0;
		for(int j=0; j<=u; j++)
		{
            if(antrean.psn[nmax].index<antrean.psn[j].index)
            {
                nmax=j;
            }
		}
        temp = antrean.psn[u].nik;
        antrean.psn[u].nik = antrean.psn[nmax].nik;
        antrean.psn[nmax].nik = temp;
        temp0 = antrean.psn[u].nama;
        antrean.psn[u].nama = antrean.psn[nmax].nama;
        antrean.psn[nmax].nama = temp0;
        temp1 = antrean.psn[u].jk;
        antrean.psn[u].jk = antrean.psn[nmax].jk;
        antrean.psn[nmax].jk = temp1;
        temp2 = antrean.psn[u].umur;
        antrean.psn[u].umur = antrean.psn[nmax].umur;
        antrean.psn[nmax].umur = temp2;
        temp3 = antrean.psn[u].index;
        antrean.psn[u].index = antrean.psn[nmax].index;
        antrean.psn[nmax].index = temp3;
        u--;
	}
}

void cari()
{
    string nik;
    sort_asc(false, true);
    cin.ignore(1, '\n');
    cout << "\n Masukkan NIK yang dicari : ";
    getline(cin,nik);
    int kiri = antrean.awal;
    int kanan = antrean.akhir-1;
    int tengah = 0;
    while(kiri<=kanan)
    {
        tengah = (kiri + kanan)/2;
        if(nik > antrean.psn[tengah].nik)
        {
            kiri = tengah + 1;
        }
        else if(nik < antrean.psn[tengah].nik)
        {
            kanan = tengah - 1;
        }
        else
        {
            kiri = kanan + 1;
        }
    }
    cout << "\n Nomor Sekarang = " << antri << endl;
    cout << " =============================================================\n";
    cout << " | NO |        NIK        |         NAMA         | JK | UMUR |\n";
    cout << " =============================================================\n";
    if(nik == antrean.psn[tengah].nik)
    {
        cout << " | " << setw(2) << antrean.psn[tengah].index;
        cout << " | " << setiosflags(ios::left) << setw(17) << antrean.psn[tengah].nik;
        cout << " | " << setiosflags(ios::left) << setw(20) << antrean.psn[tengah].nama;
        cout << " | " << setiosflags(ios::left) << setw(2) << antrean.psn[tengah].jk;
        cout << " |  " << setiosflags(ios::left) << setw(3) << antrean.psn[tengah].umur << " |" << endl;
    }
    else
    {
        cout << " |                   DATA TIDAK DITEMUKAN                    |\n";
    }
        cout << " =============================================================\n";

    queue_def();
}

void inQueue()
{
    tampilData(false);
    string elemen, elemen0, elemen1;
    int elemen2;
    bool kon;

    if(!full())
    {
        cin.ignore(1, '\n');
        cout << "\n Masukkan Data Pasien : " << endl;
        cout << "\n NIK                : ";
        getline(cin,elemen);
        cout << " Nama               : ";
        getline(cin, elemen0);
        do
        {
            cout << " Jenis Kelamin(L/P) : ";
            getline(cin, elemen1);
            if(elemen1 == "l" || elemen1 == "L")
            {
                elemen1 = "L";
                kon = true;
            }
            else if(elemen1 == "p" || elemen1 == "P")
            {
                elemen1 = "P";
                kon = true;
            }
            else
            {
                cout << "\n Salah, Masukkan huruf L atau P saja!!!\n\n";
                kon = false;
            }
        }
        while(kon == false);
        cout << " Umur               : ";
        cin >> elemen2;
        cout << "\n Data berhasil ditambahkan\n\n";
        antrean.psn[antrean.akhir].nik = elemen;
        antrean.psn[antrean.akhir].nama = elemen0;
        antrean.psn[antrean.akhir].jk = elemen1;
        antrean.psn[antrean.akhir].umur = elemen2;
        antrean.psn[antrean.akhir].index = no_urut;
        antrean.akhir++;
        no_urut++;
    }
    else
    {
        cout << " Queue penuh\n";
    }
}

void deQueue()
{
    int i, a=50000, menu, harga=0, sub=0;
    char konfirmasi, pil;
    bool ulang = false;
    node *temp, *temp2;
    temp = new node;
    if(!empty())
    {
        cout << "\n Memanggil... \n\n";
        cout << " =============================================================\n";
        cout << " | NO |        NIK        |         NAMA         | JK | UMUR |\n";
        cout << " =============================================================\n";
        cout << " | " << setw(2) << antrean.psn[antrean.awal].index;
        cout << " | " << setiosflags(ios::left) << setw(17) << antrean.psn[antrean.awal].nik;
        cout << " | " << setiosflags(ios::left) << setw(20) << antrean.psn[antrean.awal].nama;
        cout << " | " << setiosflags(ios::left) << setw(2) << antrean.psn[antrean.awal].jk;
        cout << " |  " << setiosflags(ios::left) << setw(3) << antrean.psn[antrean.awal].umur << " |" << endl;
        cout << " =============================================================\n";
        antri = antrean.psn[antrean.awal].index;
        temp->nik = antrean.psn[antrean.awal].nik;
        temp->nama = antrean.psn[antrean.awal].nama;
        cout << "\n Pasien masih ada?(Y/N)";
        cin >> konfirmasi;
        if(konfirmasi == 'Y' || konfirmasi == 'y')
        {
            temp->jasa = a;
            while(ulang != true)
            {
                system("cls");
                cout << "\n Pilihan menu :\n";
                cout << "\n 1. Scalling\n";
                cout << " 2. Bleaching\n";
                cout << " 3. Behel Gigi\n";
                cout << " 4. Tambal Gigi\n";
                cout << " 5. Cabut Gigi\n";
                cout << " 6. Pasang Gigi\n";
                cout << " 7. Lain-lain\n";
                cout << "\n Masukkan Menu : ";
                cin >> menu;
                switch(menu)
                {
                case 1 :
                    harga = 50000;
                    break;
                case 2 :
                    harga = 75000;
                    break;
                case 3 :
                    harga = 250000;
                    break;
                case 4 :
                    harga = 60000;
                    break;
                case 5 :
                    harga = 40000;
                    break;
                case 6 :
                    harga = 100000;
                    break;
                case 7 :
                    cout << " Masukkan Harga = ";
                    cin >> harga;
                    break;
                default :
                    cout << " Menu yang anda inputkan salah!!!\n";
                    break;
                }
                sub += harga;
                cout << "\n Lagi?(Y/N)";
                cin >> pil;
                if(pil == 'N' || pil == 'n')
                {
                    ulang = true;
                }
            }
            temp->obat = sub;
        }
        else
        {
            a = 0;
            sub = 0;
            temp->jasa = a;
            temp->obat = sub;
        }

        temp->total = a + sub;
        temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        posisi = head;
    }
    else
    {
        temp2 = head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
        for(i=antrean.awal; i<antrean.akhir; i++)
        {
            antrean.psn[i].nik = antrean.psn[i+1].nik;
            antrean.psn[i].nama = antrean.psn[i+1].nama;
            antrean.psn[i].jk = antrean.psn[i+1].jk;
            antrean.psn[i].umur = antrean.psn[i+1].umur;
            antrean.psn[i].index = antrean.psn[i+1].index;
        }
        antrean.akhir--;
    }
    else
    {
        cout << "\n Antrean kosong\n";
    }
}

void tampil()
{
    int no=1;
    node *temp;
    temp = head;
    cout << endl;
    cout << " ==============================================================================\n";
    cout << " | NO |       NIK        |       NAMA        |   JASA   |  BIAYA   |  JUMLAH  |\n";
    cout << " ==============================================================================\n";
    if (temp == NULL)
    {
        cout << " |                                DATA KOSONG                                 |\n" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << " | " << setw(2) << no;
            cout << " | " << setiosflags(ios::left) << setw(16) << temp->nik;
            cout << " | " << setiosflags(ios::left) << setw(17) << temp->nama;
            cout << " | " << setiosflags(ios::right) << setw(8) << temp->jasa;
            cout << " | " << setw(8) << temp->obat;
            cout << " | " << setw(8) << temp->total << " |\n";
            temp = temp->next;
            no++;
        }
    }
    cout << " ==============================================================================\n";
}

void carilink(string x)
{
    int no = 1;
    bool ketemu = false;
    node *temp;
    temp = head;
    cout << endl;
    if (temp == NULL)
    {
        cout << " List kosong!" << endl;
    }
    else
    {
        cout << " ==============================================================================\n";
        cout << " | NO |       NIK        |       NAMA        |   JASA   |  BIAYA   |  JUMLAH  |\n";
        cout << " ==============================================================================\n";
        while (temp != NULL)
        {
            if(x == temp->nik)
            {
                cout << " | " << setw(2) << no;
                cout << " | " << setiosflags(ios::left) << setw(16) << temp->nik;
                cout << " | " << setiosflags(ios::left) << setw(17) << temp->nama;
                cout << " | " << setiosflags(ios::right) << setw(8) << temp->jasa;
                cout << " | " << setw(8) << temp->obat;
                cout << " | " << setw(8) << temp->total << " |\n";
                ketemu = true;
                break;
            }
            temp = temp->next;
            no++;
        }
        if(ketemu == false)
        {
            cout << " |                            DATA TIDAK DITEMUKAN                            |\n";
        }
        cout << " ==============================================================================\n";
    }
}

void hapus_awal()
{
    node *temp;
    temp = head;
    head = head->next;
    delete temp;
    cout << "\n Data Berhasil Dihapus!\n";
}

void hapus_tengah()
{
  int banyakdata,posisi_hapus,poshapus;
  node *hapus, *bantu;
  if(head != NULL)
  {
    cout<<"\n Hapus data ke : ";
    cin>>posisi_hapus;
    banyakdata=1;
    bantu=head;
    while(bantu->next != NULL)
    {
      bantu=bantu->next;
      banyakdata++;
    }
    if((posisi_hapus<1)||(posisi_hapus>banyakdata))
    {
      cout<<" Belum ada data !! masukkan Data dula aja...\n";
    }
    else
    {
      bantu=head;
      poshapus=1;
      while(poshapus<(posisi_hapus-1))
      {
        bantu=bantu->next;
        poshapus++;
      }
      hapus=bantu->next;
      bantu->next=hapus->next;
      delete hapus;
      cout << "\n Data Berhasil Dihapus!\n";
    }
 }
 else
    cout<<" Data Masih kosong, tidak bisa hapus data dari tengah! ";
}

void hapus_akhir()
{
    node *temp1, *temp2;
    if (head == NULL)
    cout << " List kosong!" << endl;
    else
    {
        temp1 = head;
        if (temp1->next == NULL)
        {
            delete temp1;
            head = NULL;
        }
        else
        {
            while (temp1->next != NULL)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
        delete temp1;
        temp2->next = NULL;
        }
        cout << "\n Data Berhasil Dihapus!\n";
    }
}

void login()
{
    char c;
    string password;
    cout << "\n User     : ";
    cin >> user;
    cout << " Password : ";
    while(c != '\r')
    {
        c = getch();
        if(c == '0')
        {
            switch(getch())
            {
                default:
                    break;
            };
        }
        else if(c == '\b')
        {
            if(password.size() != 0)
            {
                cout << "\b \b";
                password.erase(password.size() -1, 1);
            }
            continue;
        }
        else if((c <= '9' && c >= '0') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            password += c;
            cout << "*";
        }
        else
        {
            continue;
        }
    }
    pass = password;
}

int main()
{
    head = NULL;
    int pilihan, pil, pilsort, hapus;
    string carinik;
    init();
    do
    {
        system("cls");
        cout << "\n =========================================\n";
        cout << "  APLIKASI SISTEM ANTRIAN PASIEN  (ASIAP) \n";
        cout << "                DOKTER GIGI               \n";
        cout << " =========================================\n";
        cout << " [1] Pendaftaran \n";
        cout << " [2] Tampilkan Antrean \n";
        cout << " [3] Urutkan Antrean\n";
        cout << " [4] Cari Antrean\n";
        cout << " [5] Menu Admin \n";
        cout << " [6] Keluar\n";
        cout << " =========================================\n";
        cout << "\n Masukkan pilihan : ";
        cin >> pilihan;
        cout << "\n =========================================\n";
        switch(pilihan)
        {
            case 1 : inQueue(); break;
            case 2 :
                tampilData(false);
                break;
            case 3 :
                cout << "\n 1. Ascending\n";
                cout << " 2. Descending\n";
                cout << "\n Masukkan Pilihan : ";
                cin >> pilsort;
                cout << "\n =========================================\n";
                if (pilsort == 1)
                {
                    sort_asc(true, true);
                    queue_def();
                }
                else if (pilsort == 2)
                {
                    sort_asc(true, false);
                    queue_def();
                }
                else
                {
                    cout << "\n Pilihan Salah!!!\n";
                }
                break;
            case 4 :
                cari();
                break;
            case 5 :
                login();
                if(user == "admin" && pass == "admin123")
                {
                    do
                    {
                        system("cls");
                        cout << "\n =========================================\n";
                        cout << "  APLIKASI SISTEM ANTRIAN PASIEN  (ASIAP) \n";
                        cout << "                DOKTER GIGI               \n";
                        cout << " =========================================\n";
                        cout << " [1] Tampilkan Antrean \n";
                        cout << " [2] Panggil Antrean \n";
                        cout << " [3] Tampilkan Laporan \n";
                        cout << " [4] Cari Laporan \n";
                        cout << " [5] Delete Laporan\n";
                        cout << " [6] LogOut\n";
                        cout << " =========================================\n";
                        cout << "\n Masukkan pilihan : ";
                        cin >> pil;
                        cout << "\n =========================================\n";
                        switch(pil)
                        {
                            case 1 : tampilData(true); break;
                            case 2 : deQueue(); break;
                            case 3 : tampil(); break;
                            case 4 :
                                cin.ignore(1, '\n');
                                cout << "\n Masukkan NIK yang dicari : ";
                                getline(cin,carinik);
                                carilink(carinik);
                                break;
                            case 5 :
                                tampil();
                                cout << "\n =========================================\n";
                                cout << "\n 1. Hapus Awal\n";
                                cout << " 2. Hapus Tengah\n";
                                cout << " 3. Hapus Akhir\n";
                                cout << " Masukkan Pilihan : ";
                                cin >> hapus;
                                cout << endl;
                                switch(hapus)
                                {
                                    case 1 : hapus_awal(); break;
                                    case 2 : hapus_tengah(); break;
                                    case 3 : hapus_akhir(); break;
                                    default : cout << "\n Pilihan Salah!!!\n"; break;
                                }
                                break;
                            case 6 : break;
                            default : cout << "\n Pilihan Salah!!!\n"; break;
                        }
                        cout << "\n (Tekan Enter Untuk Melanjutkan!!!)\n";
                        getch();
                    }
                    while(pil!=6);
                }
                else
                {
                    cout << "\n\n Username atau Password Salah!!!\n";
                }
                break;
            case 6 : break;
            default : cout << " Pilihan Salah!!!\n"; break;
        }
        cout << "\n (Tekan Enter Untuk Melanjutkan!!!)";
        getch();
    }
    while(pilihan!=6);
    return 0;
}
