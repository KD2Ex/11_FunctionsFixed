#include <iostream>
#include <string>
using namespace std;

string parse(string str) {
    int len = 0;
    string number;
    for (int i = 0; i < str.length() && str[i] != '.'; i++) {
        len++;
        number += str[i];
    }
    return number;
}

bool numberValid(string str) {

    if (str.length() > 3 || str.length() == 0) {
        return false;
    }
    for (int i = 0; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9' || (str[i] == '0' && str.length() != 1 && i == 0)) {
            return false;
        }
    }
    if (stoi(str) >  255 || stoi(str) < 0) {
        return false;
    }
    return true;
}

void ipValidation(string str) {
    bool flag = true;
    for (int i = 0; i < 4; i++) {
        string number = parse(str);
        if (!numberValid(number)) {
            flag = false;
            break;
        } else {
            str.erase(0, number.length() + 1);
        }
    }
    if (flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

int main() {
    string str;
    cin >> str;
        ipValidation(str);

}