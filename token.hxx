#pragma once

#include <string>

// 词法单元类型
enum class TokenType
{
    FUNC,           // func
    VAR,            // var
    IF,             // if
    GOTO,           // goto
    RETURN,         // return
    INT,            // int
    BOOL,           // bool
    ID,             // 标识符
    INT_LITERAL,    // INT型字面量
    ADD,            // +
    SUB,            // -
    MUL,            // *
    DIV,            // /
    EQ,             // ==
    NEQ,            // !=
    LT,             // <
    GT,             // >
    LE,             // <=
    GE,             // >=
    AND,            // &&
    OR,             // ||
    NOT,            // !
    BITWISE_AND,    // &
    BITWISE_OR,     // |
    BITWISE_NOT,    // ~
    ASSIGN,         // =
    COMMA,          // ,
    SEMICOLON,      // ;
    LPAREN,         // (
    RPAREN,         // )
    LBRACE,         // {
    RBRACE,         // }
    COLON,          // :
    END_OF_FILE,    // EOF
    ERROR           // ERROR
};

inline std::string token_type_to_string(TokenType type)
{
    switch (type)
    {
        case TokenType::FUNC        : return "FUNC";
        case TokenType::VAR         : return "VAR";
        case TokenType::IF          : return "IF";
        case TokenType::GOTO        : return "GOTO";
        case TokenType::RETURN      : return "RETURN";
        case TokenType::INT         : return "INT";
        case TokenType::BOOL        : return "BOOL";
        case TokenType::ID          : return "ID";
        case TokenType::INT_LITERAL : return "INT_LITERAL";
        case TokenType::ADD         : return "ADD";
        case TokenType::SUB         : return "SUB";
        case TokenType::MUL         : return "MUL";
        case TokenType::DIV         : return "DIV";
        case TokenType::EQ          : return "EQ";
        case TokenType::NEQ         : return "NEQ";
        case TokenType::LT          : return "LT";
        case TokenType::GT          : return "GT";
        case TokenType::LE          : return "LE";
        case TokenType::GE          : return "GE";
        case TokenType::AND         : return "AND";
        case TokenType::OR          : return "OR";
        case TokenType::NOT         : return "NOT";
        case TokenType::BITWISE_AND : return "BITWISE_AND";
        case TokenType::BITWISE_OR  : return "BITWISE_OR";
        case TokenType::BITWISE_NOT : return "BITWISE_NOT";
        case TokenType::ASSIGN      : return "ASSIGN";
        case TokenType::COMMA       : return "COMMA";
        case TokenType::SEMICOLON   : return "SEMICOLON";
        case TokenType::LPAREN      : return "LPAREN";
        case TokenType::RPAREN      : return "RPAREN";
        case TokenType::LBRACE      : return "LBRACE";
        case TokenType::RBRACE      : return "RBRACE";
        case TokenType::COLON       : return "COLON";
        case TokenType::END_OF_FILE : return "END_OF_FILE";
        case TokenType::ERROR       : return "ERROR";
    }
    return "UNKNOWN";
}

// 词法单元结构
class Token
{
public:
    TokenType   type;      // 词法单元类型
    std::string lexeme;    // 原始字符串
    uint        line;      // 所在行号

    template <std::convertible_to<std::string> T>
    explicit Token(TokenType type, T&& lexeme, uint line):
        type(type), lexeme(std::forward<T>(lexeme)), line(line)
    {}

    [[nodiscard]]
    std::string to_string() const;
};