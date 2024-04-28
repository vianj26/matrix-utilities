#ifndef EQ_PARSER_H
#define EQ_PARSER_H

#include "common.h"

class Equation
{
    public:

        std::string equation;
        std::vector<std::string> parsed;
        std::unordered_map<std::string, std::string> string_values;
        std::unordered_map<std::string, double> values;

        Equation(std::string equation);

        void transform_equation();
        void print();
        
        

};


#endif