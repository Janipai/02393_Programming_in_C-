#include <iostream>
#include <math.h>

using namespace std;

double pi(int n)
{
    double result = 0.0;

    for (int i = 0; i < n; i++)
    {
            result += pow(-1,i) / (2.0 * i + 1);
    }

    cout << result *4 << endl;
    return 0;
}

int main()
{
    int n;
    cin >> n;

    pi(n);
}