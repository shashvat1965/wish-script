#include <string>

using namespace std;

class Token {
public:
    string type;
    string value;

    explicit Token(const string &type, const string &value) {
        this->type = type;
        this->value = value;
    }
};

class Integer : public Token {
public:
    explicit Integer(const string& value) : Token("INT", value) {}
};

class Float : public Token {
public:
    explicit Float(const string& value) : Token("FLOAT", value) {}
};