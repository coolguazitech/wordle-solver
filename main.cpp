#include "solver.cpp"
#include "wordList.cpp"

using namespace std;

int main(){

    int wordLength, chances;
    cout << "What is the length of the word you want to guess: ";
    cin >> wordLength;
    cout << "How many chances do you have to guess: ";
    cin >> chances;

    Solver solver = Solver(wordLength);
    solver.start(chances);

    system("pause");
}