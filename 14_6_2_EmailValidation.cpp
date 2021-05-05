#include <iostream>
#include <string>
using namespace std;

bool firstPart(string str) {
    int length = 0;
    string dictionary = "0123456789!#$%&'*+-/=?^_`{|}~-.";
    bool dot = false;
    for (int i = 0; str[i] != '@'; i++) {
        if ((dictionary.find(str[i], 0) == string::npos
        && !(str[i] >= 65 && str[i] <= 90) && !(str[i] >= 97 && str[i] <= 122))
        || (str[i] == '.' && dot) || (i == 0 && str[i] == '.')) {
            return false;
        } else if (str[i] == '.') {
            dot = true;
        } else {
            dot = false;
        }
        length++;
    }
    if (length < 1 || length > 64 || str[length - 1] == '.' || str.length() == length || length == -1) {
        return false;
    } else {
        return true;
    }
}

bool secondPart(string str) {
    int length = 0;
    bool dot = false;
    int start = str.find('@',0) + 1;
    for (int i = start; i < str.length(); i++) {
        if ((!(str[i] >= 65 && str[i] <= 90) && !(str[i] >= 97 && str[i] <= 122) && !(str[i] >= 48 && str[i] <= 57)
        && str[i] != 45 && str[i] != 46) || (str[i] == '.' && dot) ||  (str[i] == '@')) {
            return false;
        } else if (str[i] == '.') {
            dot = true;
        } else {
            dot = false;
        }
        length++;
    }
    if (length < 1 || length > 63 || str[start] == '.') {
        return false;
    }
    return true;
}

void emailValidation(string str) {
    if (firstPart(str) && (secondPart(str))) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

int main() {
    string str;
    cin >> str;
    emailValidation(str);
}

