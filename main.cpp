#include <iostream>
#include <vector>
#include "matrix_utils.h"

int main()
{
    std::vector<std::vector<int>> matrix = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int row, column;
    
    matrix::print_matrix(matrix);

    return 0;
}