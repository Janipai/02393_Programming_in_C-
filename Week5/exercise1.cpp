#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    vector<int> a;
    vector<int> b;

    char set;
    int value;

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
        else if(set == 'b')
            b.push_back(value);
        set = ' ';
        value = 0;
    }

    sort(a.begin(), a.end());
    for (auto x : a)
        cout << x << " ";

    sort(b.begin(), b.end());
    for (auto x : b)
        cout << x << " ";

    return 0;
}