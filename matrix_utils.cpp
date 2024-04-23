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

    std::vector<std::vector<int>> add(std::vector<std::vector<int>> matrix_A, std::vector<std::vector<int>> matrix_B)
    {
        

        int row = matrix_A.size();
        int column = matrix_A.size();

        std::vector<std::vector<int>> result(row, std::vector<int>(column));

        for(int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                result[i][j] = matrix_A[i][j] + matrix_B[i][j];
            }
        }

        return result;

    }
}
