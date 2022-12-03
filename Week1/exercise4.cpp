#include <iostream>

using namespace std;

int main(){

    float x, y, z, result;
    int n = 3;

    while (n>0)
    {
       if(n=3)
        cin >> x;
       if(n=2)
        cin >> y;
       if(n=1)
        cin >> z;
    
       n = n - 1;
    }
    
    result = (x + y) - z;

    cout << result << endl;
}