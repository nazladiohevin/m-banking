#pragma once

#include "Electricity.h"
#include "Account.h"
#include "Helper.h"

#include <iostream>
#include <chrono> 
#include <thread>

using namespace std;

void Electricity::print(Account& account) {
	int userchose;
	cout << "BANK AMIKOM" << endl;
	cout << "===========" << endl;
	cout << " " << endl;
	cout << "Silahkan Pilih Aksi Anda" << endl;
	cout << "1. Pembayaran Meteran Listrik" << endl;
	cout << "2. Pembelian Pulsa Listrik" << endl;

	cout << "Pilih : ";
	cin >> userchose;

	cout << "\nTunggu sebentar...";
	this_thread::sleep_for(chrono::milliseconds(1000));
	system("cls");
	
	if (userchose == 1) {
		string nama, rumah;

		cout << "Pembayaran Meteran Listrik" << endl;
		cout << "Masukan Nama pemilik meteran : ";
		cin.ignore();
		getline(cin, nama);
		cout << "Masukan Alamat Rumah : ";
		getline(cin, rumah);

		cout << "\nTunggu sebentar...";
		this_thread::sleep_for(chrono::milliseconds(1000));
		system("cls");

		srand(time(0));
		int token = rand() % 9000 + 1000;
		int kwh = token * 100;

		cout << "Anda mengunakan listrik sebesar " << token << " kwh" << endl;
		cout << "Tagihan Anda adalah : " << Helper::convertToRupiah(kwh) << endl;
		cout << "Lanjutkan membayar ? (y/n)";
		char chose;
		cin >> chose;

		if (chose == 'y') {
			account.money -= kwh;

			account.mutation.push(Mutation::addMutation(
				"moneyout",
				0,
				kwh,
				account.name.substr(0, 15),
				nama,
				"Bayar Meter Listrik"
			));

			cout << "\nTunggu sebentar...";
			this_thread::sleep_for(chrono::milliseconds(1000));
			system("cls");

			cout << "transaksi berhasil" << endl;
		}
		else {
			cout << "Anda membatalkan Transaksi" << endl;
		}
	}
	else if (userchose == 2) {
		string number;
		char chose;
		int tokenChose;

		cout << "Pembelian Pulsa Listrik" << endl;
		cout << "Masukan Nomor Listrik Pintar : ";
		cin.ignore();
		getline(cin, number);

		cout << "\nTunggu sebentar...";
		this_thread::sleep_for(chrono::milliseconds(1000));
		system("cls");

		cout << "Nomor Listrik Pintar: " << number << endl;
		cout << "Silahkan Pilih Aksi Anda" << endl;
		cout << "====================" << endl;
		cout << "1. 50.000" << endl;
		cout << "2. 100.000" << endl;
		cout << "3. 200.000" << endl;
		cout << "4. Lainnya" << endl;		
		cout << "Pilih: ";
		
		cin >> tokenChose;
		system("cls");

		if (tokenChose == 1) {
			cout << "Anda memilih pulsa sebesar 50.000" << endl;
			cout << "Apakah anda ingin melanjutkan transaksi (y/n)? ";			
			cin >> chose;

			if (chose == 'y') {
				cout << number << endl;
				cout << "melakukan pembelian sebesar 50.000" << endl;
				account.money -= 50000;
				
				account.mutation.push(Mutation::addMutation(
					"moneyout",
					0,
					50000,
					account.name.substr(0, 15),
					number + "    ",
					"Beli Pulsa Listrik"
				));

				cout << "\nTunggu sebentar...";
				this_thread::sleep_for(chrono::milliseconds(1000));
				system("cls");

				cout << "Transaksi berhasil" << endl;
			}
			else cout << "Transaksi di batalkan" << endl;		
		}
		else if (tokenChose == 2) {
			cout << "Anda memilih pulsa sebesar 100.000" << endl;
			cout << "Apakah anda ingin melanjutkan transaksi (y/n)?";
			cin >> chose;

			if (chose == 'y') {
				cout << number << endl;
				cout << "melakukan pembelian sebesar 100.000" << endl;
				account.money -= 100000;

				account.mutation.push(Mutation::addMutation(
					"moneyout",
					0,
					100000,
					account.name.substr(0, 15),
					number + "    ",
					"Beli Pulsa Listrik"
				));

				cout << "\nTunggu sebentar...";
				this_thread::sleep_for(chrono::milliseconds(1000));
				system("cls");

				cout << "Transaksi berhasil" << endl;
			}
			else cout << "Transaksi di batalkan" << endl;		
		}
		else if (tokenChose == 3) {
			cout << "Anda memilih pulsa sebesar 200.000" << endl;
			cout << "Apakah anda ingin melanjutkan transaksi (y/n)? ";
			cin >> chose;

			if (chose == 'y') {
				cout << number << endl;
				cout << "melakukan pembelian sebesar 200.000" << endl;
				account.money -= 200000;

				account.mutation.push(Mutation::addMutation(
					"moneyout",
					0,
					200000,
					account.name.substr(0, 15),
					number + "    ",
					"Beli Pulsa Listrik"
				));

				cout << "\nTunggu sebentar...";
				this_thread::sleep_for(chrono::milliseconds(1000));
				system("cls");

				cout << "Transaksi berhasil" << endl;
			}
			else cout << "Transaksi di batalkan" << endl;			
		}
		else if (tokenChose == 4) {
			int inputPulsa;

			cout << "Masukan Jumlah pulsa yang ingin anda beli :";
			cin >> inputPulsa;
			cout << "melakukan pembelian sebesar " << inputPulsa << endl;
			cout << "Apakah anda ingin melanjutkan transaksi (y/n)? ";
			cin >> chose;

			if (chose == 'y') {	
				cout << number << endl;
				cout << "melakukan pembelian sebesar " << inputPulsa << endl;
				account.money -= inputPulsa;

				account.mutation.push(Mutation::addMutation(
					"moneyout",
					0,
					inputPulsa,
					account.name.substr(0, 15),
					number + "    ",
					"Beli Pulsa Listrik"
				));

				cout << "\nTunggu sebentar...";
				this_thread::sleep_for(chrono::milliseconds(1000));
				system("cls");

				cout << "Transaksi berhasil" << endl;
			}
			else {
				cout << "Transaksi di batalkan" << endl;
			}
		}
	}
}
