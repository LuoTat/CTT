#include <string>
#include <iostream>
#include <fstream>
#include "lexer.hxx"

int main()
{
    std::ifstream   file("../main.ctt", std::ios::ate);
    std::streamsize size = file.tellg();    // 获取大小
    file.seekg(0, std::ios::beg);           // 定位到文件开头
    std::string code(size, '\0');
    file.read(&code[0], size);
    Lexer lexer = Lexer(code);

    while (true)
    {
        Token token = lexer.next_token();
        std::cout << token.to_string() << std::endl;
        if (token.type == TokenType::END_OF_FILE)
            break;
    }
}