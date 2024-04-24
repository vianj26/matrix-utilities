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

    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> matrix)
    {
        int row = matrix.size();
        int column = (matrix[0]).size();

        std::vector<std::vector<int>> result(column, std::vector<int>(row));

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                result[j][i] = matrix[i][j];
            }
        }

        return result;

    }
    
    //Add Matrix A and Matrix B
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

    //Subtract Matrix B from Matrix
    std::vector<std::vector<int>> subtract(std::vector<std::vector<int>> matrix_A, std::vector<std::vector<int>> matrix_B)
    {
        

        int row = matrix_A.size();
        int column = matrix_A.size();

        std::vector<std::vector<int>> result(row, std::vector<int>(column));

        for(int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                result[i][j] = matrix_A[i][j] - matrix_B[i][j];
            }
        }

        return result;

    }

    //Multiply Matrix A and Matrix B
    std::vector<std::vector<int>> multiply(std::vector<std::vector<int>> matrix_A, std::vector<std::vector<int>> matrix_B)
    {
        int row_A = matrix_A.size();
        int column_A = (matrix_A[0]).size();
        int row_B = matrix_B.size();
        int column_B = (matrix_B[0]).size();

        //TODO: row_A == column_B

        std::vector<std::vector<int>> matrix_B_T = transpose(matrix_B);

        std::vector<std::vector<int>> result(row_A, std::vector<int>(column_B));
        int count = 0;
        int sum = 0;

        for(int i = 0; i < row_A; i++)
        {
            for(int j = 0; j < column_B; j++)
            {

                for(int k = 0; k < row_B; k++)
                {
                    sum = sum + matrix_A[i][k] * matrix_B_T[j][k];
                }

                result[i][j] = sum;
                sum = 0;
            }
        }

        return result;
        
    }
    
    //flips matrix on horizontal axis
    std::vector<std::vector<int>> horizontal_flip(std::vector<std::vector<int>> matrix)
    {
        int row = matrix.size();

        std::vector<std::vector<int>> result;

        for(int i = row - 1; i >= 0; i--)
        {
            result.push_back(matrix[i]);
        }

        return result;

    }

    std::vector<std::vector<int>> vertical_flip(std::vector<std::vector<int>> matrix)
    {
        int row = matrix.size();
        int column = (matrix[0]).size();

        std::vector<std::vector<int>> result;
        std::vector<int> temp;

        for(int i = 0; i < row; i++)
        {
            for(int k = column - 1; k >= 0; k--)
            {
                temp.push_back(matrix[i][k]);
            }

            result.push_back(temp);
            temp.clear();
        }

        return result;

    }

    int determinant(std::vector<std::vector<int>> matrix)
    {
        int row = matrix.size();
        int column = (matrix[0]).size();

        
        if (row != column) 
        {
            std::cout << "Only square matrix(same row and column) can have determinant." << std::endl;
            throw std::invalid_argument("Only square matrix(same row and column) can have determinant.");
        }
        
        int column_position;
        int product = 1, result = 0;

        for(int i = 0; i < column; i++)
        {
            for(int j = 0; j < row; j++)
            {
                column_position = i + j;
                if(column_position > column - 1) column_position -= column;
                product *= matrix[j][column_position];
            }

            result += product;
            product = 1;
        }

        std::vector<std::vector<int>> matrix_T = vertical_flip(matrix);

        for(int i = 0; i < column; i++)
        {
            for(int j = 0; j < row; j++)
            {
                column_position = i + j; //3
                if(column_position > column - 1) column_position -= column;
                product *= matrix_T[j][column_position];
            }

            result -= product;
            product = 1;
            
        }

        return result;
    }
    
}