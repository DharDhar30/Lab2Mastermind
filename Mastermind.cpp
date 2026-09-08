//
// Created by Dharshini Senthil Nathan on 9/8/26.
//

#include "Mastermind.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Mastermind::Mastermind() {
    debug = false;
    makeSecretCode();
}
Mastermind::Mastermind(bool de_bug) {
    debug = de_bug;
    makeSecretCode();
}
void Mastermind::makeSecretCode() {
    for (int i = 0; i < code_len; i++) {
        secretCode[i] = rand()% 10;
    }
    if (debug) {
        cout << "Secret Code: ";
        for (int i = 0; i < code_len; i++) {
            cout << secretCode[i];
        }
        cout << endl;
    }
}