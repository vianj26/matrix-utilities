#include <iostream>
#include <vector>
#include "matrix_utils.h"


namespace matrix
{
    void print_matrix(std::vector<std::vector<int>> matrix)
    {
        int row = matrix.size();
        int column= (matrix[0]).size();

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                std::cout << matrix[i][j] << "\t";
            }

            std::cout << "\b\n";
        }

        
    }
}
