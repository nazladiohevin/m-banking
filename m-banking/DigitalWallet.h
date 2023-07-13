#pragma once

#include "Account.h"

class DigitalWallet {
    public:
        DigitalWallet();
        void topUpMenu(Account& login);
        double getTopUpAmount() const;

    private:
        double topUpAmount;
        double nomorMerchant;
};

