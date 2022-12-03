#include <iostream>
#include <string>

using namespace std;

int main(){
    int x, y;

    cin >> x;
    cin >> y;

    if (x>y)
        cout << x << " is bigger than " << y<< endl;
    else if (x<y)
        cout << x << " is smaller than " << y<< endl;
    else
        cout << x << " is equal to " << y<< endl;
}