#include <iostream>

using namespace std;

int main()
{
    int input, n;
    cin >> input;
    n=2;

    //input not 0
    while (input != 1){
        if (input%n==0){
            cout << n;
            input = input/n;
            if (input!=1)
                cout<< " * ";
        }else
            n++;
        
    }  
}