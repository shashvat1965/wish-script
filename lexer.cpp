#include <string>
#include <iostream>
#include <vector>
#include "tokens.cpp"

using namespace std;

class Lexer {
    inline const static string digits = "1234567890";
    inline const static string letters = "abcdefghijklmnopqrstuvwxyz";
    inline const static string operations = "+-/*";
    inline const static string stopword = " ";

public:
    string text;
    int index = 0;
    vector<Token> tokens;
    Token *selectedToken = nullptr;
    string character = string(1,text[index]);

    explicit Lexer(const string &enteredText) {
        text = enteredText;
        index = 0;
        character = string(1,text[index]);;
    };

    void move() {
        index++;
        if (index < text.length()) {
            character = string(1,text[index]);
        } else {

        }
    }

    vector<Token> tokenize() {
        while (index < text.length()) {

            // lambda function to check if the character belongs to any string set
             auto isSubstring = [&](const string& stringSet) {
                return stringSet.find(character) != string::npos;
            };

            if (isSubstring(stopword)) {
                move();
                continue;
            }
            if (isSubstring(digits)) {
                extractNumber();
            }
            if (isSubstring(operations)) {
                extractOperation();
            }
        }
        return tokens;
    }

    void extractNumber(){

        // lambda function to check if the character belongs to any string set
        auto isSubstring = [&](const string& stringSet) {
            return stringSet.find(character) != string::npos;
        };

        string number;
        while(isSubstring(digits) && (index < text.length())){
            number += character;
            move();
        }
        tokens.push_back(Integer(number));

    }

    void extractOperation(){
        tokens.push_back(Operation(character));
        move();
    }

};