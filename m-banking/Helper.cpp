#include "Helper.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <regex>

// #include "curl/curl.h"

using namespace std;

string Helper::inputBullet() {
    string password;

    char ch;
    while ((ch = _getch()) != '\r') {  // Menggunakan _getch() untuk membaca karakter tanpa menampilkan di layar
        if (ch == '\b') {  // Jika karakter adalah backspace, hapus karakter sebelumnya
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";  // Menghapus karakter di layar
            }
        }
        else {
            password.push_back(ch);
            cout << '*';  // Menampilkan karakter "*" sebagai tanda bahwa input merupakan password
        }
    }

    cout << endl;

    return password;
}

// BELUM FIX, MASIH ADA BUG
bool Helper::isSequence(string& input) {
    for (int i = 0; i < input.length() - 2; i++) {
        int currentDigit = input[i] - '0';
        int nextDigit = input[i + 1] - '0';
        int nextNextDigit = input[i + 2] - '0';

        if (currentDigit + 1 == nextDigit && nextDigit + 1 == nextNextDigit) {
            return false;
        }
    }

    return true;
}

bool Helper::validateEmail(string& email) {
    regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return regex_match(email, emailRegex);
}

//void Helper::sendEmail(string to, string from, string subject, string content) {
//    // Inisialisasi libcurl
//    curl_global_init(CURL_GLOBAL_DEFAULT);
//    string recipient = "To: " + to;
//    string sender = "From: " + from;
//    string title = "Subject: " + subject;
//
//    // Inisialisasi CURL
//    CURL* curl = curl_easy_init();
//    if (curl) {
//        // Atur alamat server SMTP
//        curl_easy_setopt(curl, CURLOPT_URL, "smtps://smtp.gmail.com:465"); // Ganti dengan alamat server SMTP yang sesuai
//
//        // Atur opsi SSL
//        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
//
//        // Atur informasi otentikasi
//        curl_easy_setopt(curl, CURLOPT_USERNAME, from);  // Ganti dengan alamat email Anda
//        curl_easy_setopt(curl, CURLOPT_PASSWORD, "05072003oke");         // Ganti dengan kata sandi email Anda
//
//        // Atur informasi email
//        struct curl_slist* recipients = NULL;
//        recipients = curl_slist_append(recipients, recipient.c_str());
//        recipients = curl_slist_append(recipients, sender.c_str());
//        recipients = curl_slist_append(recipients, title.c_str());
//        recipients = curl_slist_append(recipients, "Content-Type: text/plain");
//        recipients = curl_slist_append(recipients, "X-Mailer: curl");
//
//        // Atur penerima email
//        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
//
//        // Atur isi email
//        curl_easy_setopt(curl, CURLOPT_READFUNCTION, readCallback);
//        curl_easy_setopt(curl, CURLOPT_READDATA, &content);
//
//        // Kirim email
//        CURLcode res = curl_easy_perform(curl);
//
//        // Periksa hasil pengiriman email
//        if (res == CURLE_OK) {
//            cout << "Email terkirim." << endl;
//        }
//        else {
//            cout << "Gagal mengirim email: " << curl_easy_strerror(res) << endl;
//        }
//
//        // Bersihkan
//        curl_slist_free_all(recipients);
//        curl_easy_cleanup(curl);
//    }
//
//    // Cleanup libcurl
//    curl_global_cleanup();
//}

//static size_t readCallback(void* ptr, size_t size, size_t nmemb, void* userdata) {
//    std::string* content = static_cast<std::string*>(userdata);
//    size_t len = size * nmemb;
//    if (!content || len == 0)
//        return 0;
//
//    size_t actualLen = std::min(content->length(), len);
//    memcpy(ptr, content->c_str(), actualLen);
//    *content = content->substr(actualLen);
//
//    return actualLen;
//}