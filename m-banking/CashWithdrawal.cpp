#include "CashWithdrawal.h"
#include "Account.h"
#include "Helper.h"
#include "Mutation.h"

#include <iostream>
#include <vector>
using namespace std;

void CashWithdrawal::process(Account& account) {
	double takeMoney = 0;
	bool isFinished;

	do {
		vector<string> messages;
		isFinished = true;

		cout << "BANK AMIKOM" << endl;
		cout << "===========" << endl;

		cout << "Tarik Tunai" << endl;
		cout << "Uang anda: " << Helper::convertToRupiah(account.money) << endl;
		cout << "--" << endl;
		cout << "Jumlah uang : ";
		cin >> takeMoney;

		if (takeMoney > account.money) {
			messages.push_back("Tidak boleh melebihi sisa saldo anda");
			isFinished = false;
		}

		if (takeMoney < 100000) {
			messages.push_back("Minimal tarik tunai adalah Rp 100.000");
			isFinished = false;
		}


		if (messages.size() != 0) {
			cout << "\nPerhatian: " << endl;
			for (int i = 0; i < messages.size(); i++) {
				cout << "- " + messages.at(i) << endl;
			}

			cout << "\nTerdapat pesan kesalahan, mohon input ulang!" << endl;
		} 

		cout << endl;
		
		// Program utama
		if (isFinished) {
			account.money = account.money - takeMoney;
			
			account.mutation.push(Mutation::addMutation(
				"moneyout",
				0,
				takeMoney,
				account.name.substr(0, 15),
				"-              ",
				"Tarik Tunai"
			));
		}
		else {
			system("pause");
			system("cls");
		}


	} while (!isFinished);	
}