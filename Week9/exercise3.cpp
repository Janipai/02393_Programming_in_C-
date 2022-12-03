#include <iostream>
#include <vector>

using namespace std;

int pali(vector<int> &arr, int begin, int end)
{
    // base case
    if (begin >= end)
    {
        cout << "yes";
        return 1;
    }
    if (arr[begin] == arr[end])
    {
        return pali(arr, begin + 1, end - 1);
    }
    else
    {
        cout << "no";
        return 0;
    }
}

int main()
{
    int n;
    vector<int> arr;
    cin >> n;

    while (!cin.fail())
    {
        arr.push_back(n);
        cin >> n;
    }
    pali(arr, 0, arr.size() - 1);
}