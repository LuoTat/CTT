#include <string>
#include <iostream>
#include "lexer.hxx"

int main()
{
    std::string code = R"(
    func main(int a, int b)
    {
        var ans1 int;
        var ans2 int;
        var ans3 int;
        var ans4 int;
        var ans5 bool;
    A:

        ans1 = a + b;
        ans2 = a - b;
        ans3 = a * b;
        ans4 = a / b;

        ans5 = ans1 == ans2;
        ans5 = ans1 != ans2;
        ans5 = ans1 < ans2;
        ans5 = ans1 > ans2;
        ans5 = ans1 <= ans2;
        ans5 = ans1 >= ans2;
        ans5 = ans1 && ans2;
        ans5 = ans1 || ans2;
        ans5 = ans1 && !ans2;

        if ( ans1 == 123456789)
        {
            goto A;
        }

        return ans1
    }
    )";

    // std::string code  = R"(a=1|2)";
    Lexer lexer = Lexer(code);

    while (true)
    {
        Token token = lexer.next_token();
        std::cout << token.to_string() << std::endl;
        if (token.type == TokenType::END_OF_FILE)
            break;
    }

    return 0;
}