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

struct ActionUser
{
    int userChoosen;
};

struct UserData {
    string name, username, pin, password, email;
    double money;   
};

int main() {
    ActionUser user;

    vector<Account> accounts = {
        Account::Account("Farrel Rashendriya", "farrelakbar", "farrelakbar@gmail.com", "20041234", "123456", "62300097645", 200000),
        Account::Account("Reza Kecap", "kecapmanis", "rezamanis@gmail.com", "20035678", "987654", "62300076587", 300000),
    };

    do {
        cout << "Selamat datang di Bank Amikom" << endl;
        cout << "=============================" << endl;
        cout << "Silahkan pilih aksi berikut :" << endl << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        // cout << "3. Lupa Username/Password" << endl; Pending dulu ini wkwkwk
        cout << "0. Exit" << endl;

        // User choose
        cout << "Pilih: ";
        cin >> user.userChoosen;

        system("cls");

        if (user.userChoosen == 0) {
            break;
        } else if (user.userChoosen == 1) {
            string username, password;
            cout << "BANK AMIKOM" << endl;
            cout << "===========" << endl;

            cout << "Login" << endl;
            cout << "--" << endl;
            cout << "Masukkan input berikut:" << endl;

            cout << "Username : ";
            cin.ignore();
            getline(cin, username);

            cout << "Password : ";
            password = Helper::inputBullet();

            // Variabel login ini buat memproses data tiap akun yang berhasil login
            // Kalian bisa nambahin variabel-variabel baru di class Account sesuai kebutuhan
            // dan menerapkannya di class lain
            // Good Luck friends
            Account* login = Account::login(username, password, accounts);

            if (login != nullptr) {
                // LOGIN SUCCESS               
                system("cls");
                bool isExit = false;
                
                do {
                    // Type Code Here after login success
                    ActionUser loggedUser;

                    cout << "BANK AMIKOM" << endl;                    
                    cout << "===========" << endl;
                    cout << "User: " << login->name << endl;
                    cout << "---------------" << endl;

                    cout << "Silahkan pilih aksi berikut :" << endl << endl;
                    cout << "1. Tarik Tunai" << endl;
                    cout << "2. Transfer" << endl;
                    cout << "3. Dompet Digital" << endl;
                    cout << "4. Pulsa/Data" << endl;          
                    cout << "5. PLN" << endl;
                    cout << "6. Mutasi Rekening" << endl;
                    cout << "7. Cek Saldo" << endl;
                    cout << "8. Profile" << endl;
                    cout << "0. Exit" << endl;

                    cout << "Pilih : ";
                    cin >> loggedUser.userChoosen;

                    cout << "\nTunggu sebentar...";
                    this_thread::sleep_for(chrono::milliseconds(2000));                                        
                    system("cls");

                    if (loggedUser.userChoosen == 0) {
                        isExit = false;
                        cout << "Proses Logout..." << endl;
                    }
                    else if (loggedUser.userChoosen == 1) {
                        // Type here for Tarik Tunai
                    }
                    else if (loggedUser.userChoosen == 2) {
                        // Type here for Transfer
                    }
                    else if (loggedUser.userChoosen == 3) {
                        // Type here for Dompet Digital
                    }
                    else if (loggedUser.userChoosen == 4) {
                        // Type here for Pulsa/Data
                    }
                    else if (loggedUser.userChoosen == 5) {
                        // Type here for PLN
                    }
                    else if (loggedUser.userChoosen == 6) {
                        // Type here for Mutasi Rekening
                    }
                    else if (loggedUser.userChoosen == 7) {
                        // Type here for Cek Saldo
                    }
                    else if (loggedUser.userChoosen == 8) {
                        // Type here for Profile
                        Account::showProfile(*login);
                    }
                    else {
                        cout << "\nPilih menu yang telah disediakan!" << endl;
                    }
                                       
                    system("pause");                    
                } while (isExit);
            }
            else {
                // LOGIN FAILED
                cout << "Gagal Login";
            }
        } else if (user.userChoosen == 2) {
            UserData user;
            vector<string> messages;
            bool isOk;
            
            do {
                isOk = true;

                cout << "BANK AMIKOM" << endl;
                cout << "===========" << endl;

                cout << "Register" << endl;
                cout << "--" << endl;
                cout << "Masukkan input berikut:" << endl;

                cout << "Nama\t\t\t\t: ";
                cin.ignore();
                getline(cin, user.name);

                cout << "Username\t\t\t: ";
                getline(cin, user.username);               

                cout << "Email\t\t\t\t: ";
                getline(cin, user.email);

                cout << "Password\t\t\t: ";
                user.password = Helper::inputBullet();

                cout << "Pin\t\t\t\t: ";
                getline(cin, user.pin);

                cout << "Setoran awal (Min: Rp 500.000)\t: ";
                cin >> user.money;


                // VALIDASI
                // Nama
                if (user.name.length() < 3) {
                    messages.push_back("Nama setidaknya 3 karakter");                    
                    isOk = false;
                }

                // Username
                if (user.username.length() < 3) {
                    messages.push_back("Username setidaknya 3 karakter");                    
                    isOk = false;
                }
                for (int i = 0;i < accounts.size(); i++) {
                    if (user.username == accounts.at(i).username) {
                        messages.push_back("Username \"" + user.username + "\" sudah dipakai");
                        isOk = false;
                        break;
                    }
                }

                // Email
                if (!Helper::validateEmail(user.email)) {
                    messages.push_back("Format email salah");                    
                    isOk = false;
                }

                // Password
                if (user.password.length() < 8) {
                    messages.push_back("Password setidaknya harus 8 karakter");                    
                    isOk = false;
                }

                // Pin
                if (user.pin.length() != 6) {
                    messages.push_back("Pin harus 6 digit");                                        
                    isOk = false;                    
                }

                if (user.money < 500000) {
                    messages.push_back("Setoran minimal Rp 500.000");
                }
                /*if (!Helper::isSequence(password)) {
                     cout << "Pin tak boleh berurutan" << endl;
                     cout << "Akun belum terdaftar, Silahkan input ulang" << endl;
                     isOk = false;
                 }*/

                // munculkan message error jika ada
                if (messages.size() != 0) {
                    cout << "\nPerhatian: " << endl;
                    for (int i = 0;i < messages.size(); i++) {
                        cout << "- " + messages.at(i) << endl;
                    }

                    cout << "\nAkun belum terdaftar, Silahkan input ulang" << endl;
                }
                
                
                if (!isOk) {
                    cout << endl;
                    system("pause");
                    system("cls");
                }              

            } while (!isOk);            

            
            accounts.push_back(Account::registerAccount(user.name, user.username, user.email,
                user.password, user.pin, user.money)); 

            cout << endl << "Berhasil membuat akun" << endl;
            cout << "Mohon tunggu sebentar...";
        } else if (user.userChoosen == 3) {
           
        } else {
            cout << "Pilih menu yang disediakan!" << endl;
        }
        
        // Refresh CMD with delay 3000 miliseconds
        this_thread::sleep_for(chrono::milliseconds(3000));
        system("cls");
    } while (user.userChoosen != 0);

    cout << endl  << "Terimakasih telah berkunjung" << endl;
    
}