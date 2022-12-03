#include <iostream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int main(){

    string operation;
    int value = 0;
    multiset<int> n;

    cin >> operation;
    cin >> value;

    string add ("add");
    string del ("del");
    string qry ("qry");
    string quit ("quit");

    while (operation != "quit")
    {
        if (operation.find(add) == 0)
        {
            n.insert(value);
        }
        else if (operation.find(del) == 0)
        {
            auto i = std::find(n.begin(), n.end(), value);
            n.erase(i);
            //n.erase(value);
        }
        else if (operation.find(qry) == 0)
        {
            if (n.count(value) != 0)
            {
                cout << "T";
            }else{
                cout << "F";
            }   
        }
        cin >> operation;
        if(operation != "quit")
            cin >> value;
    }

    return 0;
}