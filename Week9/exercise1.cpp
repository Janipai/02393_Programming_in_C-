#include <iostream>

using namespace std;

int main()
{
    int n, i;
    int *arr = new int[10];

    i = 0;
    cin >> n;
    while (!cin.fail())
    {
        arr[i] = n;
        cin >> n;

        i += 1;
    }

    for (int j = i; j >= 0; j--)
    {
        if (j == i)
        {
            continue;
        }else{
            cout << arr[j] << " ";
        }
        
    }

    delete [] arr;
    
}