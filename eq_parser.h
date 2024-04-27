#ifndef EQ_PARSER_H
#define EQ_PARSER_H

#include "common.h"

class Equation
{
    public:
        static int equation_count;

        std::string equation;
        std::vector<std::string> parsed;
        std::unordered_map<char, std::string> string_values;
        std::unordered_map<char, double> values;

        Equation(std::string equation);

        ~Equation();

        void transform_equation();

        static void print_list(){}

        template<typename T, typename... list>
        static void print_list(T eq, list... equations)
        {
            std::cout << eq.equation << std::endl;
            print_list(equations...);
        }
        

};


#endif