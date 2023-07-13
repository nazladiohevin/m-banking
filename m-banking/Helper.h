#pragma once
#include <string>
#include <ctime>

#include "Mutation.h"

using namespace std;

class Helper
{
public:
	static string inputBullet();	
	static bool validateEmail(string& email);	
	static string convertToRupiah(double amount);
	static string timeIndonesian(time_t timeMoneyMove);
	static string convertTimeTToString(time_t period);
	static time_t convertStringToTimeT(const string& dateString);
	static void bubbleSortAscending(stack<Mutation>& mutations);
	static void bubbleSortDescending(stack<Mutation>& mutations);
};

