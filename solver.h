#include <iostream>
#include <vector>
#include "wordList.h"

using namespace std;

typedef vector<pair<string, string>> history;

class Solver{
private:
    int wordLength; 
    WordList wordList;
    history guessesAndJudgements;
    string makeGuess(WordList);
    void loadHistory(string &, string &);
    string judge(string &, string &);
    void remove(WordList &, string &, string &);

public:
    Solver();
    Solver(int);
    void start(int);
};
