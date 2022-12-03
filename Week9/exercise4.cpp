#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int substring;

int levenshtein(string u, string w)
{
    if(u.size() == 0){ return w.size();}
    if(w.size() == 0){ return u.size();}

    string u1 = u.substr(1,u.size()-1);
    string w1 = w.substr(1,w.size()-1);
    
    return min(min(levenshtein(u1,w) + 1, levenshtein(u,w1)+1),levenshtein(u1,w1) + ((u[0]== w[0]) ? 0 : 1));
}


int main()
{
    string u, w;

    cin >> u;
    cin >> w;

    cout << levenshtein(u, w);
}