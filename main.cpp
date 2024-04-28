#include <iostream>
#include "eq_solver.h"
#include "eq_parser.h"
#include "matrix_utils.h"





int main()
{
    Equation eq1("5x + 4y = 9");
    Equation eq2("2x + 5y = 4");
    Equation eq3("8x + 10y = -14");
    Equation eq4("8x + 10y = 14");

    Solver::solve(eq1, eq2);

    for(auto member : Solver::columns)
    {
        std::cout << member.first << ": " << std::endl << "[";
        for(auto value : member.second)
        {
            std::cout << value << ",";
        }
        std::cout << "\b]" << std::endl;
    }


    std::cout << std::boolalpha << Solver::is_valid() << std::endl;

    return 0;
}
