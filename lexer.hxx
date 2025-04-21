#pragma once

#include <unordered_map>
#include "token.hxx"

// 词法分析器类
// 负责将源代码字符串转换为一系列的词法单元（tokens）
class Lexer
{
public:
    // 构造函数：传入源代码字符串
    template <std::convertible_to<std::string> T>
    explicit Lexer(T&& source):
        source_(std::forward<T>(source))
    {}

    // 返回下一个词法单元
    Token next_token();

private:
    static constexpr std::string_view                                   alphabet_ = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 \t\n\r,;(){}:+-*/=!<>|&";    // 合法字符集
    const static std::unordered_map<int, std::unordered_map<char, int>> DFAtran_;                                                                                                // DFA 状态转移表

    int         status_ = 0;                                                                                                                                                     // 当前状态
    std::string source_;                                                                                                                                                         // 完整的源代码
    size_t      lexeme_begin_ = 0;                                                                                                                                               // 当前 lexeme 的起始位置
    size_t      lexeme_end_   = 0;                                                                                                                                               // 当前 lexeme 的结束位置
    int         line_         = 1;                                                                                                                                               // 当前所在行号

    // 获取下一个字符
    char next_char();

    // 将 lexeme_end_ 前移一位
    void prev_position();

    // 获取当前 lexeme 的字符串
    [[nodiscard]]
    std::string get_lexeme() const;

    // 判断字符是否在合法的字符集内
    [[nodiscard]]
    static bool is_valid_char(char c);

    // 判断是否到达文件末尾
    [[nodiscard]]
    bool at_eof() const;

    // 判断是否是终止状态
    [[nodiscard]]
    bool is_final_state() const;

    // 判断是否是空白状态
    [[nodiscard]]
    bool is_ws_state() const;

    // 获取当前状态对应的 TokenType
    [[nodiscard]]
    TokenType get_token_type() const;

    // 重置 DFA 状态
    void reset();
};