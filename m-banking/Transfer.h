#pragma once

#include "Account.h"

#include <vector>

using namespace std;

class Transfer {
public:
    static void transferMenu(Account& sender, vector<Account>& accounts);
};

