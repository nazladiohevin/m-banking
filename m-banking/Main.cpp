#include <iostream>
#include <string> // Buat tipe data string dan manipulasi string

#include <chrono> // Untuk menggunakan tipe data waktu
#include <thread> // untuk menggunakan fungsi sleep_for()

#include <random>

#include <vector>
#include <conio.h>

// IMPORT CLASS
#include "Account.h"
#include "Helper.h"


using namespace std;

int main() {
    int userChoosen;

    vector<Account> accounts = {
        Account::Account("Farrel Rashendriya", "farrelakbar", "farrelakbar@gmail.com", "20041234", "123456", "62300097645"),
        Account::Account("Reza Kecap", "kecapmanis", "rezamanis@gmail.com", "20035678", "987654", "62300076587"),
    };

    do {
        cout << "Selamat datang di Bank Amikom" << endl;
        cout << "=============================" << endl;
        cout << "Silahkan pilih aksi berikut :" << endl << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Lupa Username/Password" << endl;
        cout << "0. Exit" << endl;

        // User choose
        cout << "Pilih: ";
        cin >> userChoosen;

        system("cls");

        if (userChoosen == 0) {
            break;
        } else if (userChoosen == 1) {
            string username, password;
            cout << "BANK AMIKOM" << endl;
            cout << "===========" << endl;

            cout << "Login" << endl;
            cout << "--" << endl;
            cout << "Masukkan input berikut" << endl;

            cout << "Username : ";
            cin.ignore();
            getline(cin, username);

            cout << "Password : ";
            password = Helper::inputBullet();

            Account::login(username, password, accounts);
        } else if (userChoosen == 2) {
            string name, username, pin, password, email;                       
            bool isOk;
            
            do {
                isOk = true;

                cout << "BANK AMIKOM" << endl;
                cout << "===========" << endl;

                cout << "Register" << endl;
                cout << "--" << endl;
                cout << "Masukkan input berikut" << endl;

                cout << "Nama\t\t: ";
                cin.ignore();
                getline(cin, name);

                cout << "Username\t: ";
                getline(cin, username);

                cout << "Email\t: ";
                getline(cin, email);

                cout << "Password\t: ";
                password = Helper::inputBullet();

                cout << "Pin\t\t: ";
                getline(cin, pin);
                if (pin.length() != 6) {
                    cout << "Pin harus 6 digit!" << endl;
                    cout << "Akun belum terdaftar, Silahkan input ulang" << endl;
                    isOk = false;                    
                }

                    /*if (!Helper::isSequence(password)) {
                        cout << "Pin tak boleh berurutan" << endl;
                        cout << "Akun belum terdaftar, Silahkan input ulang" << endl;
                        isOk = false;
                    }*/
                
                if (!isOk) {
                    this_thread::sleep_for(chrono::milliseconds(3000));
                    system("cls");
                }              

            } while (!isOk);            

            
            accounts.push_back(Account::registerAccount(name, username, email, password, pin)); 

            cout << endl << "Berhasil membuat akun" << endl;
            cout << "Mohon tunggu sebentar...";
        } else if (userChoosen == 3) {

        } else {

        }
        
        // Refresh CMD with delay 3000 miliseconds
        this_thread::sleep_for(chrono::milliseconds(3000));
        system("cls");
    } while (userChoosen != 0);

    cout << endl  << "Terimakasih telah berkunjung" << endl;
    
}