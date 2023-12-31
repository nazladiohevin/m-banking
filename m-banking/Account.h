#pragma once
#include <string>
#include <vector>
#include <stack>

#include "Mutation.h"

using namespace std;

class Account {	
	public:
		string name, password, username, idAccount, pin, email;
		double money;
		stack<Mutation> mutation;
		Account(string name, string username, string email, string password, string pin, string idAccount, double money); // Constructor
		static Account* login(string username, string password, vector<Account>& accounts);		
		static Account registerAccount(string name, string username, string email, string password, string pin, double money);		
		static void showProfile(Account& account);		
};