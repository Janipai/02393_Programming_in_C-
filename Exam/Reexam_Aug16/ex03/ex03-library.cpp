#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "ex03-library.h"

using namespace std;

// Exercise 3(b)
// Check and correct if necessary
void Dictionary::insert_words(string u, string v){
    english2danish[u] = v;
    danish2english[v] = u;
}

// Exercise 3(b)
// Check and correct if necessary
string Dictionary::get_word(string lang, string u){
    if (lang == "english")
        return english2danish[u];
    else if (lang == "danish")
        return danish2english[u];
    else
        return "#unknown#";
}

// Exercise 3(c)
void Dictionary::insert_synonym(string lang, string u, string v){
    // Put your code here
    if (lang == "danish")
        danish_synonyms[u].insert({u,v});
    else if (lang == "english")
        english_synonyms[u].insert({u,v});
    else 
        return;
}

// Exercise 3(d)
set<string> Dictionary::get_synonyms(string lang, string u){
    // Put your code here
    if (lang == "danish")
        return danish_synonyms[u];
    else if (lang == "english")
        return english_synonyms[u];
    else 
        return;
}

// Exercise 3(e)
set<string> Dictionary::translate(string lang, string u){
    // Put your code here
    if (lang == "danish"){
        for(auto d: danish_synonyms)
            if (d.first == u)
                return d.second;            
    }
    else if (lang == "english")
       for(auto e: english_synonyms)
            if (e.first == u)
                return e.second; 
    else 
        return;
}

