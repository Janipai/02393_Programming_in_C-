#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = -1;
    int amount;
    vector< int > arr;
    amount = -1;

    while (n != 0)
    {
        cin >> n;
        if (n==0)
        {
            exit(0);
        }
        
        arr.push_back(n);

        for (int i = 0; i < arr.size(); i++)
        {
            if(arr.at(i)==n){
                amount++;
            } else if (arr.at(i)==n && amount == 0)
            {
                cout << 0 << endl;
            }
            
        }
        cout << amount << endl;
        amount = -1;
    }
}