#include <string>
#include <iostream>
#include "lexer.hxx"

int main()
{
    //     std::string code = R"(
    //     func main(int a, int b)
    //     {
    //         var ans1 int;
    //         var ans2 bool;
    //     A:
    //         ans1 = a + b;
    //         ans1 = a - b;
    //         ans1 = a * b;
    //         ans1 = a / b;
    //         ans2 = a == b;
    //         ans2 = a != b;
    //         ans2 = a < b;
    //         ans2 = a > b;
    //         ans2 = a <= b;
    //         ans2 = a >= b;
    //         ans2 = a && b;
    //         ans2 = a || b;
    //         ans2 = !a;
    //         ans1 = a & b;
    //         ans1 = a | b;
    //         ans1 = ~a;
    //
    //         if ( ans1 == 123456789)
    //         {
    //             goto A;
    //         }
    //
    //         return ans1
    //     }
    // )";

    std::string code  = R"(?intmain(var a int){})";
    Lexer       lexer = Lexer(code);

    while (true)
    {
        Token token = lexer.next_token();
        std::cout << token.to_string() << std::endl;
        if (token.type == TokenType::END_OF_FILE)
            break;
    }

    return 0;
}