#include <iostream>
#include <string>
using namespace std;

string encrypt_caesar(string str, int parameter) {
    for (int i = 0; i < str.length(); i++) {
        parameter %= 26;
        int newSymbolCode = (int)str[i] + parameter;
        if ((str[i] >= 97  && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90)) {
            if (str[i] >= 97) {
                if (newSymbolCode > 122) {
                    newSymbolCode = newSymbolCode % 122 + 96;
                } else if (newSymbolCode < 97) {
                    newSymbolCode += 26;
                }
            } else if (str[i] <= 90) {
                if (newSymbolCode > 90) {
                    newSymbolCode = newSymbolCode % 90 + 64;
                } else if (newSymbolCode < 65) {
                    newSymbolCode += 26;
                }
            }
            str[i] = (char)newSymbolCode;
        }
    }
    return str;
}

string decrypt_caesar(string str, int parameter) {
    return encrypt_caesar(str, -parameter);
}

int main() {
    int parameter;
    string str;
    getline(cin, str);
    cin >> parameter;
    string encryptedMessage = encrypt_caesar(str, parameter);
    cout << encryptedMessage << endl;
    cout << decrypt_caesar(encryptedMessage, parameter);
}
