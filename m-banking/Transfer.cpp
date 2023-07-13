#include "Transfer.h"
#include "Helper.h"
#include "Mutation.h"

#include <iostream>


void Transfer::transferMenu(Account& sender, vector<Account>& accounts) {
    string targetAccount;
    double transferAmount;

    cout << "TRANSFER" << endl;
    cout << "========" << endl;

    cout << "Masukkan nomor rekening tujuan : ";
    cin.ignore();
    getline(cin, targetAccount);

    cout << "Masukkan jumlah transfer : ";
    cin >> transferAmount;

    Account* target = nullptr;
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].idAccount == targetAccount) {
            target = &accounts[i];
            break;
        }
    }

    if (target != nullptr) {
        if (sender.money >= transferAmount) {
            sender.money -= transferAmount;
            target->money += transferAmount;
            cout << "Transfer berhasil!" << endl;
            cout << "Saldo Anda: " << Helper::convertToRupiah(sender.money) << endl;

            sender.mutation.push(Mutation::addMutation(
                "moneyout",
                0,
                transferAmount,
                sender.name.substr(0, 15),
                target->name.substr(0, 15),
                "Men-Transfer"
            ));

            target->mutation.push(Mutation::addMutation(
                "moneyin",
                transferAmount,
                0,
                sender.name.substr(0, 15),
                target->name.substr(0, 15),
                "Men-Transfer"
            ));
        }
        else {
            cout << "Saldo Anda tidak mencukupi!" << endl;
        }
    }
    else {
        cout << "Nomor rekening tujuan tidak ditemukan!" << endl;
    }

}