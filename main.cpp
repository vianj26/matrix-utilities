#include <iostream>
#include "eq_solver.h"
#include "eq_parser.h"
#include "matrix_utils.h"




int main()
{
    Equation eq1("5x + 4y = 9");
    Equation eq2("2x + 5y = 4");
    Equation eq3("8x + 10y = -14");

    eq3.print();

    return 0;
}
