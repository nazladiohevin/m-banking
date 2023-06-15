#pragma once
#include <string>
#include <vector>
using namespace std;

class Account {	
	public:
		Account(string name, string username, string email, string password, string pin, string idAccount); // Constructor
		static void login(string username, string password, vector<Account> accounts);		
		static Account registerAccount(string name, string username, string email, string password, string pin);

	protected: 
		string name, password, username, idAccount, pin, email;	
};