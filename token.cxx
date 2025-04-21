#include "token.hxx"

std::string Token::to_string() const
{
    return '[' + token_type_to_string(type) + ',' + lexeme + ',' + std::to_string(line) + ']';
}