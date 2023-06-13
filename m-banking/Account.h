#pragma once
#include <string>
using namespace std;

class Account
{	
	public:
		Account(); // Constructor
		bool login();
		void registerAccount();

	protected: 
		string name, password, username;
		int pin, idAccount;
		
};