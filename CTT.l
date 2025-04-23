# 词法分析

/* 正则定义 */

delim             [ \t\r\n]
ws                {delim}+
digit             [0-9]
letter            [A-Za-z]
id                {letter}({letter}|{digit})*
int_literal       {digit}+

%%
"func"            {return FUNC}
"var"             {return VAR}
"if"              {return IF}
"goto"            {return GOTO}
"return"          {return RETURN}
"int"             {return INT}
"bool"            {return BOOL}
{id}              {return ID}
{int_literal}     {return INT_LITERAL}
"+"               {return ADD}
"-"               {return SUB}
"*"               {return MUL}
"/"               {return DIV}
"=="              {return EQ}
"!="              {return NEQ}
"<"               {return LT}
">"               {return GT}
"<="              {return LE}
">="              {return GE}
"&&"              {return AND}
"||"              {return OR}
"!"               {return NOT}
"&"               {return BITWISE_AND}
"|"               {return BITWISE_OR}
"~"               {return BITWISE_NOT}
"="               {return ASSIGN}
","               {return COMMA}
";"               {return SEMICOLON}
"("               {return LPAREN}
")"               {return RPAREN}
"{"               {return LBRACE}
"}"               {return RBRACE}
":"               {return COLON}
<<EOF>>           {return END_OF_FILE}
.                 {return ERROR}