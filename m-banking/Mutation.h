#pragma once
#include <ctime>
#include <string>
#include <stack>
using namespace std;

class Mutation {
	public:
		double moneyIn, moneyOut;
		string type, destination, sender, information;
		time_t timeMoneyMove;
		Mutation(			
			time_t timeMoneyMove,
			string type,
			double moneyIn,
			double moneyOut,
			string sender,
			string destination,
			string information
		);
		static Mutation addMutation(	
			string type,
			double moneyIn, 
			double moneyOut, 			
			string sender,
			string destination,
			string information
		);
		static void showMutation(stack<Mutation> mutations);		
};

