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
        {1,2,3},
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
    
    std::vector<std::vector<int>> result = matrix::multiply(matrix_A, matrix_B);

    matrix::print_matrix(result);

    return 0;

}