#include <iostream>

using namespace std;

int main(){
    float n,toSum, result;
    cin >> n;
    result = 0;
    while (n>0)
    {
       cin >> toSum;
       result = result + toSum;
       n = n - 1;
    }

    cout << result << endl;
}