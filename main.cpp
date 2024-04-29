#include <iostream>
#include "eq_solver.h"
#include "eq_parser.h"
#include "matrix_utils.h"

void problem1()
{
    Equation eq1("3x+1y-6z=-3");
    Equation eq2("2x+6y+3z=0");
    Equation eq3("3x+2y-3z=-6");

    Solver solve1(eq1, eq2, eq3);
}

int main()
{
    problem1();

    return 0;
}
