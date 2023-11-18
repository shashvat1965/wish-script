#include <iostream>
#include "lexer.cpp"

using namespace std;

int main() {
    cout << "Hello, Wish Script" << endl;
    string input;
    cin >> input;
    Lexer lexer = Lexer(input);
    lexer.tokenize();
    for(auto & token : lexer.tokens){
        cout << token.value << " " << token.type << '\n';
    }
    return 0;
}
