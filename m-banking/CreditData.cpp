#include "CreditData.h"
#include "Helper.h"
#include "Mutation.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void CreditData::process(Account& account) {
    int jm = 0;
    double total = 0;
    int i, kembali;
    char noperator[10];
    char nohp[15];
    char nominal[10];
    string nama;
    char lagi;
    int bayar[10] = { 0 };

    system("cls");
    cout << "======== AMIKOM CELL ========" << endl;
    cout << "Melayani Pembelian Pulsa & Data" << endl;
    cout << "=============================" << endl << endl;
    cout << "Nama Konsumen : ";
    cin.ignore();
    getline(cin, nama);
    cout << "Jumlah isi    : ";
    cin >> jm;
    cout << endl;
    system("cls");

    for (i = 1; i <= jm; i++)
    {
        cout << "Pembelian Ke-" << i << endl << endl;

        cout << "Three | Indosat | Telkomsel | XL | AXIS" << endl << endl;
        cout << "Masukan Nama Operator     : ";
        cin >> noperator;
        cout << "Masukan Nomor HP          : ";

        cin >> nohp;
        cout << "\n";
        cout << "==============================" << endl;
        cout << "    NOMINAL     KODE NOMINAL  " << endl;
        cout << "==============================" << endl;
        cout << "  Rp 5000             A       " << endl;
        cout << "  Rp 10000            B       " << endl;
        cout << "  Rp 25000            C       " << endl;
        cout << "  Rp 50000            D       " << endl;
        cout << "  Rp 100000           E       " << endl;
        cout << "  1GB Data            F       " << endl;
        cout << "  3GB Data            G       " << endl;
        cout << "  10GB Data           H       " << endl;
        cout << "  50GB Data           I       " << endl;
        cout << "  100GB Data          J       " << endl;
        cout << "==============================" << endl;
        cout << endl;
        cout << "Masukan Kode Nominal : ";
        cin >> nominal[i];
        cout << endl;
        system("cls");

        if (nominal[i] == 'A' || nominal[i] == 'a')
        {
            bayar[i] = 6000;
        }
        else if (nominal[i] == 'B' || nominal[i] == 'b')
        {
            bayar[i] = 11000;
        }
        else if (nominal[i] == 'C' || nominal[i] == 'c')
        {
            bayar[i] = 26000;
        }
        else if (nominal[i] == 'D' || nominal[i] == 'd')
        {
            bayar[i] = 49000;
        }
        else if (nominal[i] == 'E' || nominal[i] == 'e')
        {
            bayar[i] = 99000;
        }
        else if (nominal[i] == 'F' || nominal[i] == 'f')
        {
            bayar[i] = 10000;
        }
        else if (nominal[i] == 'G' || nominal[i] == 'g')
        {
            bayar[i] = 25000;
        }
        else if (nominal[i] == 'H' || nominal[i] == 'h')
        {
            bayar[i] = 50000;
        }
        else if (nominal[i] == 'I' || nominal[i] == 'i')
        {
            bayar[i] = 100000;
        }
        else if (nominal[i] == 'J' || nominal[i] == 'j')
        {
            bayar[i] = 500000;
        }
    }

    cout << "======== AMIKOM CELL ========" << endl;
    cout << "Melayani Pembelian Pulsa & Data" << endl;
    cout << "=============================" << endl << endl;
    cout << "Nama : " << nama << endl
        << endl;
    cout << "========================\n";
    cout << "  NO   NOMINAL   BAYAR \n";
    cout << "========================\n";
    for (i = 1; i <= jm; i++)
    {
        cout << " " << left << setw(4) << i;
        cout << "  " << setw(9) << nominal[i];
        cout << " " << setw(6) << Helper::convertToRupiah(bayar[i]);
        cout << setw(7) << " ";
        cout << "\n";
    }
    cout << "========================\n";

    for (int i = 1; i <= jm; i++)
    {
        total = total + bayar[i];
    }
    cout << "  Total\t" << left << setw(6) << Helper::convertToRupiah(total);
    cout << " " << endl;
    cout << "========================\n";
    cout << endl;

    char option;
    cout << "Bersedia membayar (y/n)? ";
    cin >> option;

    if (option == 'y') {
        account.money -= total;
        cout << "Terimakasih telah menggunakan layanan kami" << endl;
        account.mutation.push(
            Mutation::addMutation(
                "moneyout",
                0,
                total,
                nama.substr(0, 15),
                "-              ",
                "Beli Pulsa"
            )
        );
    }
    else {
        cout << "Mohon maaf, bila layanan kami tidak memuaskan" << endl;
    }

    cout << endl;

}