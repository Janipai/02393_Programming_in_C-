#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    vector<int> a;
    vector<int> b;

    char set;
    int value, result, longestArray;

    cin >> set;
    cin >> value;

    if (set == 'a')
        a.push_back(value);
    else
        b.push_back(value);

    while (!cin.fail())
    {
        cin >> set;
        cin >> value;

        if (set == 'a')
            a.push_back(value);
        else if (set == 'b')
            b.push_back(value);
        
        set = ' ';
        value = 0;
    }

    result = 0;
    longestArray = 0;

    if (a.size() > b.size())
        longestArray = a.size();
    else
        longestArray = b.size();

    for (int i = 0; i < longestArray; i++)
    {
        if (i >= a.size())
            result += 0 * b.at(i);

        else if (i >= b.size())
            result += a.at(i) * 0;

        else
            result += a.at(i) * b.at(i);
    }

    cout << result;
}