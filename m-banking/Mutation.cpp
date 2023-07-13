#include <iostream>
#include <string>
#include <ctime>
#include <stack>

#include "Mutation.h"
#include "Helper.h"

using namespace std;

Mutation::Mutation(
	time_t timeMoneyMove,
	string type,
	double moneyIn,
	double moneyOut,
	string sender,
	string destination,
	string information
) {	
	this->moneyIn = moneyIn;
	this->moneyOut = moneyOut;
	this->type = type;
	this->timeMoneyMove = timeMoneyMove;
	this->destination = destination;
	this->sender = sender;
	this->information = information;
};

Mutation Mutation::addMutation(	
	string type,
	double moneyIn = 0,
	double moneyOut = 0,
	string sender = "",
	string destination = "",
	string information = ""
) {
	time_t now = time(0);

	return Mutation(now, type, moneyIn, moneyOut, sender, destination, information);
}

void Mutation::showMutation(stack<Mutation> mutations) {
	cout << "BANK AMIKOM" << endl;
	cout << "===========" << endl;

	cout << "Mutasi Rekening" << endl;	
	cout << "--" << endl;
	cout << "Pilih layanan sorting mutasi " << endl;
	cout << "1. Berdasarkan Uang Masuk" << endl;
	cout << "2. Berdasarkan Uang Keluar" << endl;
	cout << "3. Berdasarkan Uang Masuk dan Keluar" << endl;
	cout << "4. Berdasarkan Waktu" << endl;

	int userChoosen;
	cout << "Pilihan: ";
	cin >> userChoosen;

	if (userChoosen == 1) {
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| No | Pengirim\t\t| Penerima\t\t| Jenis\t\t\t| Nominal\t\t| Waktu\t\t\t|" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		
		int i = 1;
		while (!mutations.empty()) {
			if (mutations.top().type == "moneyin") {
				cout <<
					"| " << i << " |" <<
					" " << mutations.top().sender << "\t|" <<
					" " << mutations.top().destination << "\t\t|" <<
					" " << mutations.top().information << "\t\t|" <<
					" +" << Helper::convertToRupiah(
						mutations.top().moneyIn) << "\t|" <<
					" " << Helper::timeIndonesian(
						mutations.top().timeMoneyMove) << "\t\t|" << endl;
				i++;
			}
			mutations.pop();
		}		
	} else if (userChoosen == 2) {
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| No | Pengirim\t\t| Penerima\t\t| Jenis\t\t\t| Nominal\t\t| Waktu\t\t\t|" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

		int i = 1;
		while (!mutations.empty()) {
			if (mutations.top().type == "moneyout") {
				cout <<
					"| " << i << " |" <<
					" " << mutations.top().sender << "\t|" <<
					" " << mutations.top().destination << "\t\t\t|" <<
					" " << mutations.top().information << "\t\t|" <<
					" -" << Helper::convertToRupiah(mutations.top().moneyOut) << "\t|" <<
					" " << Helper::timeIndonesian(mutations.top().timeMoneyMove) << "\t\t|" << endl;
				i++;
			}
			mutations.pop();
		}
		
	}
	else if (userChoosen == 3) {
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| No | Pengirim\t\t| Penerima\t\t| Jenis\t\t\t| Nominal\t\t| Waktu\t\t\t|" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

		int i = 1;
		while (!mutations.empty()) {
			double money = (mutations.top().moneyIn == 0) ? mutations.top().moneyOut : mutations.top().moneyIn;

			cout <<
				"| " << i << " |" <<
				" " << mutations.top().sender << "\t|" <<
				" " << mutations.top().destination << "\t|" <<
				" " << mutations.top().information << "\t\t|" <<
				(((mutations.top().moneyIn == 0) ? " -" : " +") + Helper::convertToRupiah(money)) << "\t|" <<
				" " << Helper::timeIndonesian(mutations.top().timeMoneyMove) << "\t\t|" << endl;		

			mutations.pop();
			i++;
		}
		
	}
	else if (userChoosen == 4) {
		string fromDate, toDate;

		cout << endl << "Masukkan Rentang Tanggal" << endl;
		cout << "Dari tanggal (DD-MM-YYYY)\t: ";
		cin.ignore();
		getline(cin, fromDate);
		cout << "Sampai tanggal (DD-MM-YYYY)\t: ";
		getline(cin, toDate);
		
		int userChoosen;
		cout << endl << "Pilih pengurutan mutasi:" << endl;
		cout << "1. Terbaru" << endl;
		cout << "2. Terlama" << endl;
		cout << "Pilihan: ";
		cin >> userChoosen;

		if (userChoosen == 1) {
			Helper::bubbleSortDescending(mutations);
		}
		else {
			Helper::bubbleSortAscending(mutations);
		}
		
		time_t startDate = Helper::convertStringToTimeT(fromDate);
		time_t endDate = Helper::convertStringToTimeT(toDate);	
		
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| No | Pengirim\t\t| Penerima\t\t| Jenis\t\t\t| Nominal\t\t| Waktu\t\t\t|" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

		int i = 1;
		while (!mutations.empty()) {
			if (mutations.top().timeMoneyMove >= startDate && mutations.top().timeMoneyMove <= endDate) {
				double money = (mutations.top().moneyIn == 0) ? mutations.top().moneyOut : mutations.top().moneyIn;

				cout <<
					"| " << i << " |" <<
					" " << mutations.top().sender << "\t|" <<
					" " << mutations.top().destination << "\t|" <<
					" " << mutations.top().information << "\t\t|" <<
					(((mutations.top().moneyIn == 0) ? " -" : " +") + Helper::convertToRupiah(money)) << "\t|" <<
					" " << Helper::timeIndonesian(mutations.top().timeMoneyMove) << "\t\t|" << endl;
				i++;
			}
			mutations.pop();
		}		
	}
	else {

	}		
}