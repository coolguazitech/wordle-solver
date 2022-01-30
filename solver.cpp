#include "solver.h"

Solver::Solver(){
    wordLength = 5;
    wordList = WordList(wordLength);
}

Solver::Solver(int length): wordLength(length){
    wordList = WordList(wordLength);
}

string Solver::makeGuess(WordList wordList){
    return wordList.getList().front();
}

void Solver::loadHistory(string & guess, string & judgement){
    pair<string, string> trial (guess, judgement);
    guessesAndJudgements.push_back(trial);
}

string Solver::judge(string & word, string & target){
    vector<char> alphabetsWord;
    vector<char> alphabetsTarget;
    int wordLength = word.length();
    string judgement = "";

    for(int i = 0; i < wordLength; i++){
        alphabetsWord.push_back(word[i]);
        alphabetsTarget.push_back(target[i]);
    }

    for(int i = 0; i < wordLength; i++){
        if(alphabetsWord[i] == alphabetsTarget[i]){
            judgement += 'A';
            continue;
        }
        for(int j = 0; j < wordLength; j++){
            if(alphabetsWord[i] == alphabetsTarget[j]){
                judgement += 'B';
                break;
            }
        }
        if(judgement.length() != i + 1){
            judgement += 'X';
        }
    }

    return judgement;
}

void Solver::remove(WordList & wordList, string & word, string & judgment){
    for(auto it = wordList.getList().begin(); it != wordList.getList().end();){
        if(judge(word, *it) != judgment){
            it = wordList.getList().erase(it);
            continue;
        }
        ++it;
    }
}

void Solver::start(int chances){
    cout << "Game started!" << endl;

    string guess;
    string judgement;

    string winningJudgement = "";
    for(int i = 0; i < wordLength; i++){
        winningJudgement += 'A';
    }
    string notInWordBank = "null";

    while(--chances >= 0 && !wordList.getList().empty()){
        guess = makeGuess(wordList);
        cout << "I guess that word is \"" << guess << "\" ( " << chances << " guesses left )\n";
        cout << "Please input the judgement: ";
        cin >> judgement;

        if(judgement == notInWordBank){
            cout << "Hmm... let me try again" << endl;
            chances ++;
            wordList.getList().remove(guess);
            continue;
        }

        loadHistory(guess, judgement);
        remove(wordList, guess, judgement);

        if(judgement == winningJudgement){
            cout << "You won!" << endl;
            return;
        }
    }
    cout << "You lost!" << endl;
}