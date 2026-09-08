#include "Mastermind.h"
#include <iostream>
#include <ctime>
using namespace std;
int main() {
    cout << "Hello, World!" << endl;
    srand(time(NULL)); // Seed the random number generator
    Mastermind game(true);
    //Mastermind game(false); When you get the game working properly, turn debug off and try playing!!!
    return 0;
}