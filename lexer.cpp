#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Lexer {
    string digits = "1234567890";
    string letters = "abcdefghijklmnopqrstuvwxyz";
    string operations = "+-/*";
    vector<string> stopwords = {" "};

public:
    Lexer(){
        cout << "hello lexer!" << endl;
    }

};