#include <string>
#include <vector>
#include "tokens.cpp"

using namespace std;
class Lexer {
    const string digits = "1234567890";
    const string letters = "abcdefghijklmnopqrstuvwxyz";
    const string operations = "+-/*";
    const vector<string> stopwords = {" "};

public:
    string text;
    int index = 0;
    vector<Token> tokens;
    Token* selectedToken = nullptr;
    char character = text[index];

    explicit Lexer(const string& enteredText){
       text = enteredText;
       index = 0;
    }

};