#include "matrix_utils.h"
#include "eq_parser.h"
#include "eq_solver.h"

void matrix_sample();

int main()
{
    Equation eq1("2x+3y-1z=5");
    Equation eq2("1x+2y+1z=8");
    Equation eq3("3x-1y+4z=10");


    Solver::solve({eq1, eq2, eq3});


    return 0;

}
