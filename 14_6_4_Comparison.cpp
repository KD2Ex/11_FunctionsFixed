#include <iostream>
#include <string>
using namespace std;

bool IsNumberCorrect(string n) {
    bool atLeastOneDigit = false;
    bool dot = false;
    int index;
    for (int i = 0; i < n.length() && !dot; i++){
        if (n[i] == '.'){
            index = i;
            dot = true;
        } else if (n[i] < '0' || n[i] > '9') {
            if (!(i == 0 && n[i] == '-')){
                return false;
            }
        } else {
            atLeastOneDigit = true;
        }
    }
    for (int i = index + 1; i < n.length(); i++){
        if (n[i] < '0' || n[i] > '9'){
            return false;
        }
    }
    return atLeastOneDigit;
}

string parse(string str) {
    int len = 0;
    bool minus = str[0] == '-';
    string number;
    if (minus) {
        str.erase(0, 1);
    }

    if (str[0] == '0') {
        int index;
        for (index = 0; str[index] == '0'; index++) {

        }
        str.erase(0, index);
    }
    for (int i = 0; i < str.length() && str[i] != '.'; i++) {
        len++;
        number += str[i];
    }
    return number;
}

string wholeNumbersComparison(string number1, string number2) {

    if (number1.length() > number2.length() || (number2[0] == '-' && number1[0] != '-')) {
        return "More";
    } else if (number1.length() < number2.length() || (number1[0] == '-' && number2[0] != '-')) {
        return "Less";
    } else if (number1[0] != '-' && number2[0] != '-'){
        for (int i = 0; i < number1.length(); i++) {
            if (number1[i] > number2[i]) {
                return "More";
            } else if (number1[i] < number2[i]) {
                return "Less";
            }
        }
        return "Equal";
    } else {
        for (int i = 0; i < number1.length(); i++) {
            if (number1[i] > number2[i]) {
                return "Less";
            } else if (number1[i] < number2[i]) {
                return "More";
            }
        }
        return "Equal";
    }
}

string floatNumberComparison(string number1, string number2) {
    int i;
    for (i = 0; i < number1.length() && i < number2.length(); i++) {
        if (number1[i] > number2[i]) {
            return "More";
        } else if (number1[i] < number2[i]) {
            return "Less";
        }
    }
    number1.erase(0, i);
    number2.erase(0, i);
    if (number1.length() > number2.length()) {
        for (int j = 0; j < number1.length(); j++) {
            if (number1[j] != '0') {
                return  "More";
            }
        }
        return "Equal";
    } else if (number1.length() < number2.length()) {
        for (int k = 0; k< number2.length(); k++) {
            if (number2[k] != '0') {
                return  "Less";
            }
        }
        return "Equal";
    } else {
        return "Equal";
    }
}

void longNumbersComparison(string number1, string number2) {
    string firstNumber = parse(number1);
    string secondNumber = parse(number2);
    if (wholeNumbersComparison(firstNumber, secondNumber) == "Equal") {

        number1.erase(0, firstNumber.length()+1);
        number2.erase(0, secondNumber.length()+1);

        cout << floatNumberComparison(number1, number2);
    } else {
        cout << wholeNumbersComparison(firstNumber, secondNumber);
    }
}

int main() {
    string n1,n2;
    cin >> n1 >> n2;
    if (IsNumberCorrect(n1) && IsNumberCorrect(n2)){
        longNumbersComparison(n1,n2);
    } else {
        cout << "Invalid input";
    }
}