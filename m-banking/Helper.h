#pragma once
#include <string>
using namespace std;

class Helper
{
public:
	static string inputBullet();
	static bool isSequence(string& input);
	static bool validateEmail(string& email);
	static void sendEmail(string to, string from, string subject, string content);
};

