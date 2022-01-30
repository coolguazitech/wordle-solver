#include "wordList.h"

WordList::WordList(){
    wordLength = 5;
    wordList = generateWordlist(wordLength);
}

WordList::WordList(int Length): wordLength(Length){
    wordList = generateWordlist(wordLength);
}

list<string> WordList::expandWordLengths(list<string> & oldList){
    list<string> newList;
    for(auto & oldWord: oldList){
        for(int i = 0; i < 26 ; i++){
            string newWord = oldWord;
            newWord += i + 97;
            newList.push_back(newWord);
        }
    }
    return newList;
}

list<string> WordList::generateAllWords(int wordLength){
    list<string> allWords (1, "");
    for(int i = 0; i < wordLength; i++){
        allWords = expandWordLengths(allWords);
    }
    return allWords;
}

list<string> WordList::generateCommonWords(int wordLength){
    list<string> commonWords;

    fstream file;
    file.open("commonWords.txt", ios::in);

    if(file.is_open()){
        string word;
        while(getline(file, word)){
            if(word.length() == wordLength){
                commonWords.push_back(word);
            }
        }
        file.close();
        return commonWords;
    }else{
        cerr << "Error: word list could not be opened" << endl;
        exit(-1);
    }
}

list<string> & WordList::concatenate(list<string> & foreList, list<string> & hindList){
    foreList.splice(foreList.end(), hindList);
    return foreList;
}   

list<string> WordList::generateWordlist(int wordLength){
    list<string> allWords = generateAllWords(wordLength);
    list<string> commonWords = generateCommonWords(wordLength);
    return concatenate(commonWords, allWords);
}

list<string> & WordList::getList(){
    return wordList;
}