//
// Created by Dharshini Senthil Nathan on 9/8/26.
//

#ifndef MASTERMINDPROJ_MASTERMIND_H
#define MASTERMINDPROJ_MASTERMIND_H


class Mastermind {
    int code_len = 5; // for the length of the code we're trying to crack
    int max_num_attempts = 10; // for the number of guesses the user gets
    // Matrix dimensions: max_num_attempts rows for turns.
    // Columns: 5 for the guessed digits
    // 1 for RR count
    // 1 for RW count = 7 columns.
    int numCols = 7;
    int secretCode[5]; //computer-generated secret code the user is trying to figure out
    // this is ugly code. I know that.There's a better way that we will see shortly
    int codeMatrix[10][7]; // the matrix with the guesses and the feedback
    bool debug;
public:
    Mastermind();
    Mastermind(bool de_bug); // in this case I included a flag that if I make
    // it true will print out the secret code and
    // other info that might help me debug while I am
    // programming
    void makeSecretCode();
    void getUserGuess(int currGuess[]);
    void updateMatrix(int turn, const int currGuess[],int RR, int RW);
    void printMatrix(int turn);
    void calculateFeedback(int *RR, int *RW, int currGuess[]);
    void playGame();
};


#endif //MASTERMINDPROJ_MASTERMIND_H
