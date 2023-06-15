﻿#include "Account.h"
#include "Helper.h"

#include <iostream>
#include <string>
#include <random>
#include <vector>

using namespace std;

Account::Account(string name, string username, string email, string password, string pin, string idAccount) {
	this->name = name;
	this->username = username;
	this->email = email;
	this->password = password;
	this->pin = pin;
	this->idAccount = idAccount;
}

void Account::login(string username, string password, vector<Account> accounts) {
	bool isFinded = false;

	for (int i = 0; i < accounts.size(); i++) {
		if (accounts.at(i).username == username 
			&& accounts.at(i).password == password) {			
			isFinded = true;
			break;
		}
	}

	if (isFinded) {
		cout << endl << "Berhasil login." << endl;
		cout << "Mohon tunggu sebentar..." << endl;
	} else {
		cout << "Akun tidak ditemukan, Mohon cek username atau password yang diinputkan!" << endl;
	}
}

Account Account::registerAccount(string name, string username, string email, string password, string pin) {
	string idAccount;
	
	// Buat angka random
	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<int> randomNumber(10000, 99999);

	idAccount = "623000" + to_string(randomNumber(generator));

	cout << "No Rekening (Dibuat otomatis) : " << idAccount << endl;
	
	return Account(name, username, email, password, pin, idAccount);	
}