#ifndef EQ_PARSER_H
#define EQ_PARSER_H

#include "common.h"

class Equation
{
    std::string equation;
    std::vector<std::string> parsed;
    std::unordered_map<char, std::string> string_values;
    std::unordered_map<char, double> values;

    public:
        Equation(std::string equation);

};


#endif