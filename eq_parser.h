#ifndef EQ_PARSER_H
#define EQ_PARSER_H

#include "common.h"

class Equation
{
    std::string equation;
    std::vector<std::string> parsed;

    public:
        Equation(std::string equation);

};


#endif