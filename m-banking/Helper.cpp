#include <iostream>
#include <string>
#include <conio.h>
#include <regex>
#include <sstream>
#include <iomanip>

#include "Helper.h"
#include "Mutation.h"

using namespace std;

string Helper::inputBullet() {
    string password;

    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else {
            password.push_back(ch);
            cout << '*';
        }
    }

    cout << endl;

    return password;
}

bool Helper::validateEmail(string& email) {
    regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return regex_match(email, emailRegex);
}

string Helper::convertToRupiah(double amount) {
    ostringstream oss;
    oss.imbue(locale(""));

    oss << "Rp " << fixed << setprecision(2) << showpoint << amount;

    return oss.str();
}

string Helper::timeIndonesian(time_t timeMoneyMove) {   
    struct tm* t = localtime(&timeMoneyMove);
    
    int day = t->tm_mday;
    int month = t->tm_mon + 1;
    int year = t->tm_year + 1900;
    
    int hour = t->tm_hour;
    int minute = t->tm_min;
    int second = t->tm_sec;

    string dayStr = (day < 10) ? "0" + to_string(day) : to_string(day);
    string monthStr = (month < 10) ? "0" + to_string(month) : to_string(month);
    string yearStr = to_string(year);
    string hourStr = (hour < 10) ? "0" + to_string(hour) : to_string(hour);
    string minuteStr = (minute < 10) ? "0" + to_string(minute) : to_string(minute);
    string secondStr = (second < 10) ? "0" + to_string(second) : to_string(second);
    
    return dayStr + "-" + monthStr + "-" + yearStr + "  " + hourStr + ":" + minuteStr + ":" + secondStr;
}

string Helper::convertTimeTToString(time_t period) {
    struct tm* t = localtime(&period);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", t);
    return string(buffer);
}
time_t Helper::convertStringToTimeT(const string& dateString) {
    struct tm timeInfo = { 0 };
    
    istringstream dateStream(dateString);
    string token;
    getline(dateStream, token, '-');
    timeInfo.tm_mday = stoi(token);
    getline(dateStream, token, '-');
    timeInfo.tm_mon = stoi(token) - 1;
    getline(dateStream, token);
    timeInfo.tm_year = stoi(token) - 1900;

    timeInfo.tm_hour = 0;
    timeInfo.tm_min = 0;
    timeInfo.tm_sec = 0;

    time_t convertedTime = mktime(&timeInfo);

    return convertedTime;
}

void Helper::bubbleSortAscending(stack<Mutation>& mutations) {
    vector<Mutation> tempVector;
    
    while (!mutations.empty()) {
        tempVector.push_back(mutations.top());
        mutations.pop();
    }
    
    int n = tempVector.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tempVector[j].timeMoneyMove > tempVector[j + 1].timeMoneyMove) {
                swap(tempVector[j], tempVector[j + 1]);
            }
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        mutations.push(tempVector[i]);
    }
}

void Helper::bubbleSortDescending(stack<Mutation>& mutations) {
    vector<Mutation> tempVector;

    while (!mutations.empty()) {
        tempVector.push_back(mutations.top());
        mutations.pop();
    }
    
    int n = tempVector.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tempVector[j].timeMoneyMove < tempVector[j + 1].timeMoneyMove) {
                swap(tempVector[j], tempVector[j + 1]);
            }
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        mutations.push(tempVector[i]);
    }
}