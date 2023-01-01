#include "ex03-library.h"
#include <iostream>

//Do not modify
WordsList::WordsList(){
	allWords.push_back("121");
	wordsToPalindromeDistance["121"]=0;
	allWords.push_back("122");
	wordsToPalindromeDistance["122"]=1;
}

//Exercise 3 (a) implement this method
void WordsList::print(){
	//put your code here
	cout << allWords.size() << " words: ";

	for(auto it: this->wordsToPalindromeDistance){
		cout << it.first << " (" << it.second << ") ";
	}
}

//Exercise 3 (b) implement this method
int WordsList::distancePalindrome(string s){
	//put your code here
	int dist = 0;
	int n = s.length() - 1;

	for (int i = 0; i < s.length()/2; i++)
	{
		if (s[i] != s[n])
			dist ++;
		n--;
	}
	return dist;
}

//Exercise 3 (c) implement this method
void WordsList::addWord(string word){
	//put your code here
	allWords.push_back(word);
	int dist = distancePalindrome(word);
	this->wordsToPalindromeDistance[allWords.at(allWords.size() - 1)] = dist;
}

//Exercise 3 (d) implement this method
int WordsList::palindromeWords(){
	//put your code here
	int counter = 0;
	for (int i = 0; i < allWords.size(); i++){
		if (wordsToPalindromeDistance[allWords.at(i)] == 0)
			counter++;
	}
	return counter;	
}