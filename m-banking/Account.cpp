#include "Account.h"
#include "Helper.h"

#include <iostream>
#include <string>
#include <random>
#include <vector>

using namespace std;

Account::Account(string name, string username, string email, string password, string pin, string idAccount, double money) {
	this->name = name;
	this->username = username;
	this->email = email;
	this->password = password;
	this->pin = pin;
	this->idAccount = idAccount;
	this->money = money;
}

Account* Account::login(string username, string password, vector<Account>& accounts) {
	bool isFound = false;
	Account* loggedAccount = nullptr;

	for (int i = 0; i < accounts.size(); i++) {
		if (accounts.at(i).username == username 
			&& accounts.at(i).password == password) {
			loggedAccount = &accounts.at(i);
			isFound = true;
			break;
		}
	}

	if (isFound) {
		cout << endl << "Berhasil login." << endl;
		cout << "Mohon tunggu sebentar..." << endl;
		return loggedAccount;
	} else {
		cout << "Akun tidak ditemukan, Mohon cek username atau password yang diinputkan!" << endl;
		return nullptr;
	}
}

Account Account::registerAccount(string name, string username, string email, string password, string pin, double money) {
	string idAccount;
	
	// Buat angka random
	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<int> randomNumber(10000, 99999);

	idAccount = "623000" + to_string(randomNumber(generator));

	cout << "No Rekening (Dibuat otomatis) : " << idAccount << endl;
	
	return Account(name, username, email, password, pin, idAccount, money);	
}

void Account::showProfile(Account& account) {
	cout << "BANK AMIKOM" << endl;
	cout << "===========" << endl;

	cout << "Profile" << endl;
	cout << "--" << endl;	
	cout << "\nNama\t : " << account.name;
	cout << "\nUsername : " << account.username;
	cout << "\nEmail\t : " << account.email;
	cout << "\nRekening : " << account.idAccount;
	cout << "\nSaldo\t : " << Helper::convertToRupiah(account.money);
	
	cout << "\n\n";
}