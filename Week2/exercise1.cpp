#include <iostream>

using namespace std;

int main()
{
    int n, result;
    cin >> n;
    result = 0;
    while (n > 0)
    {
        result += n;
        n = n - 1;
    }

    cout << result << endl;
}