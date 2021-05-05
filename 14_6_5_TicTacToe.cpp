#include <iostream>
#include <string>
using namespace std;

bool correctInput(string str) {
    for (int i = 0; i < 3; i++) {
        if (str[i] != '.' && str[i] != 'O' && str[i] != 'X') {
            return false;
        }
    }
    return true;
}


int checkingRows(string str[], char mark) {
    bool win = false;
    int winCounter = 0;
    for (int i = 0; i < 3; i++) {
        win = true;
        for (int j = 0; j < 3; j++) {
            if (str[i][j] != mark) {
                win = false;
                break;
            }
        }
        if (win) {
            winCounter++;
        }
    }

    return winCounter;
}

int checkingCols(string str[], char mark) {
    bool win = true;
    int winCounter = 0;
    for (int i = 0; i < 3; i++) {
        win = true;
        for (int j = 0; j < 3; j++) {
            if (str[j][i] != mark) {
                win = false;
                break;
            }
        }
        if (win) {
            winCounter++;
        }
    }
    return winCounter;
}

int checkingDiagonals(string str[], char mark) {
    bool win = true;
    int winCounter = 0;


    if (str[1][1] == mark) {

        if (str[0][0] == mark && str[2][2] == mark) {
            winCounter++;
        }
        if (str[0][2] == mark && str[2][0] == mark) {
            winCounter++;
        }
    }
    return winCounter;
}

bool gameWon(string str[], char mark) {
    return checkingRows(str, mark) == 1 || checkingCols(str, mark) == 1 || checkingDiagonals(str, mark) == 1;
}

string gameResult(string str[]) {
    int x = 0, y = 0;
    int circle = 0, cross = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (str[i][j] == 'X') cross++;
            else if (str[i][j] == 'O') circle++;
        }
    }
    if ( (gameWon(str, 'O') && gameWon(str, 'X'))
    || (gameWon(str, 'O') && (cross > circle || circle > cross)) || (gameWon(str, 'X')
    && (circle >= cross || cross - circle >=  2)) || (gameWon(str, 'O') > 1)
    || (gameWon(str, 'X') > 1) ) {
        return "Incorrect";
    } else if (gameWon(str, 'O')) {
        return "Vanya won";
    } else if (gameWon(str, 'X')) {
        return "Petya won";
    } else {
        return "Nobody";
    }
}


int main() {
    string row[3];
    string str;
    for (int i = 0; i < 3; i++) {
        cin >> str;
        if (!correctInput(str)) {
            cout << "Invalid input";
            return 0;
        }
        row[i] = str;
    }
    cout << gameResult(row);
}