//
// Created by samuel on 10/26/19.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

class TextInput {
public:

    string output;

    TextInput() {
        ifstream myFile ("text3.txt");
        string str((std::istreambuf_iterator<char>(myFile)), std::istreambuf_iterator<char>());
        cout << str << endl;
        cout << "Text po odstraneni vsetkych medzier a specialnych znakov" << endl;
        for (int i = 0; i < str.length(); ++i) {
            str[i] = toupper(str[i]);
            if (str[i] < 'A' || str[i] > 'Z')
                str[i] = ' ';
        }
        str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end()); //erase all whitespace from string
        output = str;
    }

    string getStr() {
        return output;
    }
};

