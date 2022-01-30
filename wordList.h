#ifndef _WORDLIST_H_
#define _WORDLIST_H_

#include <list>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;



class WordList{
private:
    int wordLength;
    list<string> wordList;
    list<string> expandWordLengths(list<string> &);
    list<string> generateAllWords(int);
    list<string> generateCommonWords(int);
    list<string> & concatenate(list<string> &, list<string> &);
    list<string> generateWordlist(int);
public:
    WordList();
    WordList(int);
    list<string> & getList();
};

#endif