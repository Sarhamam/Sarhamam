#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <numeric>

#define EXIT "EXIT"
#define XOR "XOR"
#define AND "AND"
#define NOT "NOT"
#define OR "OR"
#define ADD "ADD"
#define D2B "D2B"
#define D2H "D2H"


#define EXIT_ENUM 0
#define XOR_ENUM 1
#define AND_ENUM 2
#define NOT_ENUM 3
#define OR_ENUM 4

#define ADD_ENUM 5
#define D2B_ENUM 6
#define D2H_ENUM 7

std::map<std::string, int> operationsEnumeration = {
 {EXIT, EXIT_ENUM},
 {XOR, XOR_ENUM},
 {AND, AND_ENUM},
 {NOT, NOT_ENUM},
 {OR, OR_ENUM},
 {ADD, ADD_ENUM},
 {D2B, D2B_ENUM},
 {D2H, D2H_ENUM}
};
typedef std::string (*operationFunction)(std::vector<int>);
struct ParsedExpression {
    int operation;
    std::vector<int> arguments;
};
std::string _exit(std::vector<int> arguments);
std::string _add(std::vector<int>);
std::string _xor(std::vector<int>);
std::string _not(std::vector<int>);
std::string _and(std::vector<int>);
std::string _or(std::vector<int>);
std::string _dec2bin(std::vector<int>);
std::string _dec2hex(std::vector<int>);
std::string evaluateExpression(ParsedExpression parsedExpression);
std::string parseAndEvaluateExpression(std::string);
int main() {
    std::string expression;
    std::string answer;
    while (expression != EXIT) {
        std::cout << "Evaluate: (Input - decimal, usage: <operation> arg1 [arg2], EXIT to leave)" << std::endl;
        std::getline(std::cin, expression);
        answer = parseAndEvaluateExpression(expression);
        if (answer!=EXIT) {
            std::cout << answer << std::endl;
        }
    }
    return 0;
}

ParsedExpression parseExpression(std::string unparsedExpression) {
    std::string operationString;
    std::vector<int> arguments;
    int argument;
    std::stringstream expressionStream(unparsedExpression);
    expressionStream >> operationString;
    while (expressionStream >> argument) {
        arguments.push_back(argument);
    }
    
    ParsedExpression parsedExpression = {operationsEnumeration[operationString], arguments};
    return parsedExpression;
}

std::string evaluateExpression(ParsedExpression parsedExpression) {
    std::string answer;
    switch (parsedExpression.operation) {
        case EXIT_ENUM:
            answer = EXIT;
            break;
        case ADD_ENUM:
            answer = _add(parsedExpression.arguments);
            break;
        case XOR_ENUM:
            answer = _xor(parsedExpression.arguments);
            break;
        case OR_ENUM:
            answer = _or(parsedExpression.arguments);
            break;
        case NOT_ENUM:
            answer = _not(parsedExpression.arguments);
            break;
        case AND_ENUM:
            answer = _and(parsedExpression.arguments);
            break;
        case D2B_ENUM:
            answer = _dec2bin(parsedExpression.arguments);
            break;
        case D2H_ENUM:
            answer = _dec2hex(parsedExpression.arguments);
            break;
        default:
            answer = "Wrong commmand";
            break;
    }
    return answer;
}

std::string evaluateExpressionNoSwitch(ParsedExpression parsedExpression) {
    std::string answer;
    operationFunction handlers[8] = { &_exit,&_xor, &_and, &_not, &_or, &_add, &_dec2bin, &_dec2hex };
    if (parsedExpression.operation >= 0 && parsedExpression.operation <=7) {
        answer =  handlers[parsedExpression.operation](parsedExpression.arguments);
    }
    return answer;
}
std::string _exit(std::vector<int> arguments) {
    return "EXIT";
}
std::string _add(std::vector<int> arguments) {
    int answer = 0;
    for (const auto& arg : arguments ) {
        answer += arg;
    }
    return std::to_string(answer);
}
std::string _xor(std::vector<int> arguments) {
    int answer = 0;
    for (const auto& arg : arguments ) {
        answer ^= arg;
    }
    return std::to_string(answer); 
}
std::string _not(std::vector<int> arguments) {
    std::vector<std::string> answers;
    for (const auto& arg : arguments ) {
        answers.push_back(std::to_string(~arg));
    }
    std::string answer = "";
    for (const auto& ans : answers) {
        answer += ans + " ";
    }
    return answer;
}
std::string _and(std::vector<int> arguments) {
    int answer = 0;
    for (const auto& arg : arguments ) {
        answer &= arg;
    }
    return std::to_string(answer); 
}
std::string _or(std::vector<int> arguments) {
    int answer = 0;
    for (const auto& arg : arguments ) {
        answer |= arg;
    }
    return std::to_string(answer); 
}
std::string _dec2bin(std::vector<int> arguments) {
    std::vector<std::string> answers;
    for (const auto& arg : arguments ) {
        std::bitset<sizeof(int)*8> answer(arg);
         answers.push_back(answer.to_string());
    }
    std::string answer = "";
    for (const auto& ans : answers) {
        answer += ans + " ";
    }
    return answer;
}
std::string _dec2hex(std::vector<int> arguments) { // check
    std::stringstream stream;
    for (const auto& arg : arguments ) {
        stream << " "<< std::hex << arg;
    }
    return stream.str();
}

std::string parseAndEvaluateExpression(std::string unparsedExpression) {
    ParsedExpression parsedExpression = parseExpression(unparsedExpression); 
    return evaluateExpressionNoSwitch(parsedExpression);
}