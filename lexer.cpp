#include <string>
#include <iostream>
#include <vector>
#include "tokens.cpp"

using namespace std;

class Lexer {
    inline const static string digits = "1234567890";
    inline const static string letters = "abcdefghijklmnopqrstuvwxyz";
    inline const static string operations = "+-/*=";
    inline const static string stopword = " ";
    inline const static string keywords[2] = {"please","what"};

public:
    string text;
    int index = 0;
    vector<Token> tokens;
    string character = string(1,text[index]);

    explicit Lexer(const string &enteredText) {
        text = enteredText;
        index = 0;
        character = string(1,text[index]);
    };

    void move() {
        index++;
        if (index < text.length()) {
            character = string(1,text[index]);
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
            }
            if (isSubstring(digits)) {
                extractNumber();
            }
            if (isSubstring(letters)) {
                extractWord();
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

    void extractWord(){

        // lambda function to check if the character belongs to any string set
        auto isSubstring = [&](const string& stringSet) {
            return stringSet.find(character) != string::npos;
        };

        string keyword;
        while(isSubstring(letters) && (index < text.length())){
            keyword += character;
            move();
        }

         //code to check if keyword belongs in keywords
        for (const auto &keyword1 : keywords) {
            if (keyword == keyword1) {
                tokens.push_back(Keyword(keyword));
                return;
            }
        }

    }

    void extractOperation(){
        tokens.push_back(Operation(character));
        move();
    }

};