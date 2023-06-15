#include "Helper.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

string Helper::inputBullet() {
    string password;

    char ch;
    while ((ch = _getch()) != '\r') {  // Menggunakan _getch() untuk membaca karakter tanpa menampilkan di layar
        if (ch == '\b') {  // Jika karakter adalah backspace, hapus karakter sebelumnya
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";  // Menghapus karakter di layar
            }
        }
        else {
            password.push_back(ch);
            cout << '*';  // Menampilkan karakter "*" sebagai tanda bahwa input merupakan password
        }
    }

    cout << endl;

    return password;
}

// BELUM FIX, MASIH ADA BUG
bool Helper::isSequence(string& input) {
    for (int i = 0; i < input.length() - 2; i++) {
        int currentDigit = input[i] - '0';
        int nextDigit = input[i + 1] - '0';
        int nextNextDigit = input[i + 2] - '0';

        if (currentDigit + 1 == nextDigit && nextDigit + 1 == nextNextDigit) {
            return false;
        }
    }

    return true;
}