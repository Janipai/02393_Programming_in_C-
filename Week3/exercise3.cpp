#include <iostream>
#include <string>
#include <map>

using namespace std;

struct addressBook
{
    string first_name;
    string middel_name;
    string last_name;
    int phone_number;
    string street_addr;
    int house_number;
    int zip;
    string region;
};

void add(string temp_addr_book[], addressBook addr[], bool page_is_empty[])
{

    int page = stoi(temp_addr_book[1]);
    if (page_is_empty[page] == false)
        return;
    else if ((0 < page) && (page < 51))
    {

        addr[page].first_name = temp_addr_book[2];
        addr[page].middel_name = temp_addr_book[3];
        addr[page].last_name = temp_addr_book[4];
        addr[page].phone_number = stoi(temp_addr_book[5]);
        addr[page].street_addr = temp_addr_book[6];
        addr[page].house_number = stoi(temp_addr_book[7]);
        addr[page].zip = stoi(temp_addr_book[8]);
        addr[page].region = temp_addr_book[9];

        page_is_empty[page] = false;
    }
}

void qry(string temp_addr_book[], addressBook addr[], bool page_is_empty[])
{
    int page;
    cin >> page;

    if ((0 < page) && (page < 51))
    {

        if (page_is_empty[page] == false)
        {

            cout << addr[page].first_name << ","
                 << addr[page].middel_name << ","
                 << addr[page].last_name << ","
                 << addr[page].phone_number << ","
                 << addr[page].street_addr << ","
                 << addr[page].house_number << ","
                 << addr[page].zip << ","
                 << addr[page].region << endl;
        }
    }
}

void clr(string temp_addr_book[], addressBook addr[], bool page_is_empty[])
{
    int page;
    cin >> page;

    page_is_empty[page] = true;
}

int main()
{
    addressBook addr[50];
    bool page_is_empty[50];

    for (int i = 0; i < 50; i++)
    {
        page_is_empty[i] = true;
    }

    string input;
    cin >> input;

    int i = 0;

    string temp_addr_book[12];
    temp_addr_book[i] = input;

    while (input != "quit")
    {
        i++;
        cin >> input;

        if (input == "qry")
        {
            qry(temp_addr_book, addr, page_is_empty);
            i = -1;
        }
        else if (input == "clr")
        {
            temp_addr_book[i] = input;
            clr(temp_addr_book, addr, page_is_empty);
            i = -1;
        }
        else if (i != 10)
        {
            temp_addr_book[i] = input;
            if (i == 9)
            {
                add(temp_addr_book, addr, page_is_empty);
                i = -1;
            }
        }
        else
            exit(0);
    }

    exit(0);
}