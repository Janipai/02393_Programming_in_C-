// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <set>

// using namespace std;

// vector< string > arr;
// set<int> bag;


// void validateOption(vector< string > arr){

//     for (int i = 0; i < arr.size(); i++)
//     {
//         cout << arr.at(i) << endl;
//     }

//     for (int i = 0; i < arr.size()-2; i++)
//     {
//         if (arr.at(i) == "quit")
//             exit(0);
//         else if (arr.at(i) == "add")
//             bag.insert(stoi(arr.at(i+1)));
//         else if (arr.at(i) == "del"){
//             bag.erase(std::find(bag.begin(), bag.end(), stoi(arr.at(i+1))));
//         else if(arr.at(i) == "qry"){
//             if (std::find(bag.begin(), bag.end(), arr.at(i+1)) != bag.end())
//                 cout << "T";
//             else
//                 cout << "F";
//         }
//         i++;

//     } 
// }

// void split(string str){
//     // declaring temp string to store the curr "word" upto del
//       string temp = "";
   
//     for(int i=0; i<(int)str.size(); i++){
//         // If cur char is not del, then append it to the cur "word", otherwise
//           // you have completed the word, print it, and start a new word.
//         if(str[i] != ' '){
//             temp += str[i];
//         }
//         else{
//             arr.push_back(temp);
//             temp = "";
//         }
//     }
//     validateOption(arr);    
// } 

// int main()
// {
//     string input;
//     getline(cin, input);

//     // Takes only space separated C++ strings.
//     split(input); 
//     return 0;        
// }


#include <iostream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int main(){

    string operation;
    int value = 0;
    set<int> n;

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
            n.erase(value);
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