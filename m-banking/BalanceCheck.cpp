// Main class
#include "BalanceCheck.h"
// side class
#include "Account.h"
#include "Helper.h"

// Library
#include <iostream>
using namespace std;

void BalanceCheck::print(Account account) {
	cout << "BANK AMIKOM" << endl;
	cout << "===========" << endl;

	cout << "Cek Saldo" << endl;
	cout << "--" << endl;
	cout << "Saldo anda: " << Helper::convertToRupiah(account.money) << "\n\n";
}
