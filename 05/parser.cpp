#ifndef PARSER
#define PARSER
#include <iostream>
#include <cstring>
#include "./stack.cpp"

#define MAX_STRING_LEN 512


namespace saod
{


class Parser {

    private: 
        char * expr;
        size_t expr_len;

        void toPostfixNotation();
        int prec(char c);
        bool is_digit(char c) { return c >= '0' && c <= '9'; }
        bool is_operator(char c) { return c == '*' || c == '/' || c == '+' || c == '-' || c == '^'; }


    public:
        Parser() {};
        bool parse(std::string expression);


};


void Parser::toPostfixNotation()
{
    saod::Stack op_stack; // temporary stack for operations 
    char output[MAX_STRING_LEN] = {}; // expression in postfix notation
    size_t out_i = 0;
    char ch, tmp;

    for (size_t i = 0; expr[i] != 0; i++)
    {
        ch = expr[i];

        if (is_digit(ch))
        {
            output[out_i++] = ch;
        }
        else if (is_operator(ch)) 
        {
            while (op_stack.notEmpty() && prec(ch) <= prec(op_stack.top()))
                output[out_i++] = op_stack.pop();

            op_stack.push(ch);
        }
        else if (ch == '(')
        {
            op_stack.push(ch);
        }
        else if (ch == ')')
        {
            while (op_stack.notEmpty() && op_stack.top() != '(')
                output[out_i++] = op_stack.pop();

            if (op_stack.top() == '(')
                op_stack.pop();
        }
    }

    while (op_stack.notEmpty())
        output[out_i++] = op_stack.pop();

    memcpy(expr, output, out_i + 1);
}


bool Parser::parse(std::string expression)
{
    expr = (char *) expression.c_str();
    expr_len = expression.size();

    toPostfixNotation();

    std::cout << expr << std::endl;

}



int Parser::prec(char c) 
{ 
    if(c == '^') 
        return 3; 
    else if(c == '*' || c == '/') 
        return 2; 
    else if(c == '+' || c == '-') 
        return 1; 
    else
        return -1; 
}







} // namespace saod

#endif // PARSER