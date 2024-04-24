#include <iostream>
#include <vector>
#include "matrix_utils.h"

int main()
{
    std::vector<std::vector<int>> matrix_A = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    std::vector<std::vector<int>> matrix_B = 
    {
        {1,3,3},
        {4,5,6},
        {7,8,9}
    };

    std::vector<std::vector<int>> matrix_C = 
    {
        {1,2,3},
        {4,5,6}
    };

    std::vector<std::vector<int>> matrix_D =
    {
        {1, 2},
        {2, 3},
        {3, 4}
    };

    matrix::print_matrix(matrix_B);

    int result= matrix::determinant(matrix_B);

    std::cout << result << std::endl;

    return 0;

}