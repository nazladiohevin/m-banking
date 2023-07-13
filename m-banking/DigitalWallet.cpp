#include "DigitalWallet.h"
#include <iostream>

using namespace std;


DigitalWallet::DigitalWallet()
{
    topUpAmount = 0.0;
    nomorMerchant = 0.0;
}

void DigitalWallet::topUpMenu()
{

    // Dompet Digital
    double topUpAmount;
    double nomormerchant;
    int userChoosen;
   
        cout << "DOMPET DIGITAL" << endl;
        cout << "===============" << endl;

        cout << "Silahkan pilih merchant :" << endl;
        cout << "1. Ovo" << endl;
        cout << "2. Gopay" << endl;
        cout << "3. Dana" << endl;
        cout << "4. ShopeePay" << endl;
        cout << "5. LinkAja" << endl;
        cout << "0. Exit" << endl;

        cout << "Pilih : ";
        cin >> userChoosen;

        if (userChoosen == 0) {
            cout << "Proses Logout..." << endl;
        }
        else if (userChoosen == 1) {
            cout << "- TOP UP OVO -" << endl;
            cout << "Masukkan nomor OVO : ";
            cin >> nomorMerchant;
            cout << "Masukkan jumlah top up : ";
            cin >> topUpAmount;
        }
        else if (userChoosen == 2) {
            cout << "- TOP UP GOPAY -" << endl;
            cout << "Masukkan nomor GOPAY : ";
            cin >> nomorMerchant;
            cout << "Masukkan jumlah top up : ";
            cin >> topUpAmount;
        }
        else if (userChoosen == 3) {
            cout << "- TOP UP DANA -" << endl;
            cout << "Masukkan nomor DANA : ";
            cin >> nomorMerchant;
            cout << "Masukkan jumlah top up : ";
            cin >> topUpAmount;
        }
        else if (userChoosen == 4) {
            cout << "- TOP UP SHOPEEPAY -" << endl;
            cout << "Masukkan nomor SHOPEEPAY : ";
            cin >> nomorMerchant;
            cout << "Masukkan jumlah top up : ";
            cin >> topUpAmount;
        }
        else if (userChoosen == 5) {
            cout << "- TOP UP LINKAJA -" << endl;
            cout << "Masukkan nomor LINKAJA : ";
            cin >> nomorMerchant;
            cout << "Masukkan jumlah top up : ";
            cin >> topUpAmount;
        }
    }


double DigitalWallet::getTopUpAmount() const
{
    return topUpAmount;
}
