#pragma once
#include <string>
#include <vector>
using namespace std;

class Account {	
	public:
		string name, password, username, idAccount, pin, email;
		Account(string name, string username, string email, string password, string pin, string idAccount); // Constructor
		static Account* login(string username, string password, vector<Account>& accounts);		
		static Account registerAccount(string name, string username, string email, string password, string pin);		
};