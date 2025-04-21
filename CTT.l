# 词法分析
# 使用正则文法定义

      DELIM -> ' ' | \t | \r | \n
         WS -> (DELIM)+
      DIGIT -> [0-9]
     DIGITS -> (digit)+
     LETTER -> [A-Za-z]
         ID -> letter(letter|digit)*
INT_LITERAL -> digits
       FUNC -> func
        VAR -> var
         IF -> if
       GOTO -> goto
     RETURN -> return
       TYPE -> int | bool
      COMMA -> ,
  SEMICOLON -> ;
     LPAREN -> (
     RPAREN -> )
     LBRACE -> {
     RBRACE -> }
      COLON -> :
         OP -> + | - | * | / | == | != | < | > | <= | >= | || | && | ! | =