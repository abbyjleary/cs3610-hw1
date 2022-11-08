#include <iostream>
#include <string>
#include "dictionary.h"
#include "node.h"

using namespace std;

int main()
{
    Dictionary d;

    d.put("Name", "Bob");
    d.put("email", "bob@gmail.com");
    d.put("address", "12 Main St.");
    d.put("raNk", "Captain");
    d.put("rank2", "Captain");
    d.put("email2", "Captain");

    d.removeValues("Captain");
    vector<string> k = d.keys();
    cout << k[0] << endl;
    cout << k[1] << endl;
    cout << k[2] << endl;
    cout << k.size() << endl;

    if ("email2" > "email"){
        cout << "yes";
    }
}