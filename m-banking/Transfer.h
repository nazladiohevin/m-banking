#ifndef TRANSFER_H
#define TRANSFER_H

#include "Account.h"
#include "Helper.h"

class Transfer {
public:
    static void transferMenu(Account& sender, std::vector<Account>& accounts) {
        std::string targetAccount;
        double transferAmount;

        std::cout << "TRANSFER" << std::endl;
        std::cout << "========" << std::endl;

        std::cout << "Masukkan nomor rekening tujuan : ";
        std::cin.ignore();
        std::getline(std::cin, targetAccount);

        std::cout << "Masukkan jumlah transfer : ";
        std::cin >> transferAmount;

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
                std::cout << "Transfer berhasil!" << std::endl;
                std::cout << "Saldo Anda: " << Helper::convertToRupiah(sender.money) << std::endl;
            }
            else {
                std::cout << "Saldo Anda tidak mencukupi!" << std::endl;
            }
        }
        else {
            std::cout << "Nomor rekening tujuan tidak ditemukan!" << std::endl;
        }
    }
};

#endif // TRANSFER_H
