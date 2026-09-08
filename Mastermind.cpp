#include "Mastermind.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Mastermind::Mastermind() {
    code_len = 5;
    max_num_attempts = 10;
    numCols = 7;
    debug = true;

    cout << "Welcome to MasterMind!" << endl;
    cout << "Can you guess the " << code_len << "-digit secret code? (Digits do not repeat)" << endl;

    playGame();
}

Mastermind::Mastermind(bool de_bug) {
    code_len = 5;
    max_num_attempts = 10;
    numCols = 7;
    debug = de_bug;

    cout << "Welcome to MasterMind!" << endl;
    cout << "Can you guess the " << code_len << "digit secret code? (Digits do not repeat)" << endl;

    playGame();
}

void Mastermind::makeSecretCode() {

    bool used[10] = {false};

    for (int i = 0; i < code_len; i++) {
        int num = rand() % 10;
        while (used[num] == true) {
            num = rand() % 10;
        }
        secretCode[i] = num;
        used[num] = true;
    }
}

void Mastermind::calculateFeedback(int *RR, int *RW, int currGuess[]) {

    *RR = 0;
    *RW = 0;

    bool usedSecret[5] = {false};
    bool usedGuess[5] = {false};

    for (int i = 0; i < code_len; i++) {

        if (currGuess[i] == secretCode[i]) {
            *RR = *RR + 1;
            usedSecret[i] = true;
            usedGuess[i] = true;
        }
    }

    for (int i = 0; i < code_len; i++) {

        if (usedGuess[i] == false) {

            for (int j = 0; j < code_len; j++) {

                if (usedSecret[j] == false && usedGuess[i] == false && currGuess[i] == secretCode[j]) {
                    *RW = *RW + 1;
                    usedSecret[j] = true;
                    usedGuess[i] = true;
                }
            }
        }
    }
}

void Mastermind::updateMatrix(int turn, const int currGuess[], int RR, int RW) {

    for (int i = 0; i < code_len; i++) {
        codeMatrix[turn][i] = currGuess[i];
    }

    codeMatrix[turn][5] = RR;
    codeMatrix[turn][6] = RW;
}

void Mastermind::printMatrix(int turn) {

    cout << endl;
    cout << "Guess Matrix:" << endl;

    for (int i = 0; i < turn; i++) {

        for (int j = 0; j < numCols; j++) {
            cout << codeMatrix[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
}

void Mastermind::getUserGuess(int currGuess[]) {

    string input;
    bool getInput = true;

    while (getInput) {

        getInput = true;

        cout << "Enter your " << code_len << "-digit guess (e.g., 12345): ";
        cin >> input;

        if (input.length() != code_len) {
            cout << "The input is the wrong length. Please try again with "
                 << code_len << " digits." << endl;

            getInput = false;
        }
        bool validDigits = true;

        for (int i = 0; i < code_len; i++) {

            if (input[i] >= '0' && input[i] <= '9') {
                currGuess[i] = input[i] - '0';
            }
            else {
                validDigits = false;
            }
        }

        cout << endl;

        if (validDigits == false) {
            cout << "Invalid input. Please only use numbers 0-9." << endl;
            getInput = true;
        }
        else {
            getInput = false;
        }
    }
}

void Mastermind::playGame() {

    int currGuess[code_len];
    int RR;
    int RW;
    bool won = false;
    int turn = 0;

    makeSecretCode();

    while (won == false && turn < max_num_attempts) {

        cout << "Turn " << turn + 1 << " out of " << max_num_attempts << endl;
        cout << "-------------------------" << endl;

        RR = 0;
        RW = 0;

        getUserGuess(currGuess);

        if (debug) {

            cout << "In debug: user's guess is ";

            for (int i = 0; i < code_len; i++) {
                cout << currGuess[i] << " ";
            }

            cout << endl;

            cout << "Still in debug: secret code is ";

            for (int i = 0; i < code_len; i++) {
                cout << secretCode[i] << " ";
            }
            cout << endl;
        }
        calculateFeedback(&RR, &RW, currGuess);

        if (debug) {
            cout << "Debug in playGame: ";
            cout << "RR: " << RR << ", ";
            cout << "RW: " << RW << endl;
        }

        updateMatrix(turn, currGuess, RR, RW);

        printMatrix(turn + 1);

        if (RR == code_len) {

            cout << "You cracked the code in "
                 << turn+1 << " turns!!!!" << endl;

            won = true;
        }
        turn++;
    }

    if (won == false) {

        cout << "Game Over! You ran out of turns. The secret code was: ";

        for (int i = 0; i < code_len; i++) {
            cout << secretCode[i];
        }

        cout << endl;
    }
}