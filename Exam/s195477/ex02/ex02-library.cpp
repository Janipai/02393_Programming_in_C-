#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
void displayTeams(TournamentNode *t) {
    // Write your code here
    if (t == nullptr)
        return;
    cout << t->name << endl;
    displayTeams(t->left);
    displayTeams(t->right);
}

// Task 2(b).  Implement this function
unsigned int matches(TournamentNode *t) {
    // Replace the following with your code
    if (t == nullptr || t->nodeType == team)
        return 0;

    unsigned int counter = 1;
    counter = counter + matches(t->left);
    counter = counter + matches(t->right);
    return counter;
}

// Task 2(c).  Implement this function
string winner(TournamentNode *t) {
    // Replace the following with your code
    if (t == nullptr)
        return "";
    
    if (t->result == none)
        return t->name;
    if (t->result == leftWin){
        winner(t->left);
    }else if (t->result == rightWin){
        winner(t->right);
    }        
}

// Task 2(d). Implement this function
bool wonAnyMatch(TournamentNode *t, string teamName) {
    // Replace the following with your code
    if (t == nullptr || t->nodeType == team)
        return false;

    if (t->nodeType == match)
    {
        if (t->result == leftWin)
        {
            if(t->left->name == teamName)
                return true;
            else  
                wonAnyMatch(t->left, teamName);
        }else{
            if(t->right->name == teamName)
                return true;
            else
                wonAnyMatch(t->right, teamName);

        }
    }
}