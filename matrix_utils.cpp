#include <iostream>
#include <vector>
#include "matrix_utils.h"


namespace matrix
{
    void print_matrix(std::vector<std::vector<double>> matrix)
    {
        int row = matrix.size();
        int column= (matrix[0]).size();

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                std::cout << matrix[i][j] << "\t";
            }

            std::cout <<"\b\n";
        }
        
    }

    std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> matrix)
    {
        int row = matrix.size();
        int column = (matrix[0]).size();

        std::vector<std::vector<double>> result(column, std::vector<double>(row));

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
    std::vector<std::vector<double>> add(std::vector<std::vector<double>> matrix_A, std::vector<std::vector<double>> matrix_B)
    {
        

        int row = matrix_A.size();
        int column = matrix_A.size();

        std::vector<std::vector<double>> result(row, std::vector<double>(column));

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
    std::vector<std::vector<double>> subtract(std::vector<std::vector<double>> matrix_A, std::vector<std::vector<double>> matrix_B)
    {
        

        int row = matrix_A.size();
        int column = matrix_A.size();

        std::vector<std::vector<double>> result(row, std::vector<double>(column));

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
    std::vector<std::vector<double>> multiply(std::vector<std::vector<double>> matrix_A, std::vector<std::vector<double>> matrix_B)
    {
        int row_A = matrix_A.size();
        int column_A = (matrix_A[0]).size();
        int row_B = matrix_B.size();
        int column_B = (matrix_B[0]).size();

        if(row_A != column_B)
        {
            std::cout << "Matrix incompatible with multiplication." << std::endl;
            throw std::invalid_argument("Matrix imcompatible with multiplication.");
        }

        std::vector<std::vector<double>> matrix_B_T = transpose(matrix_B);

        std::vector<std::vector<double>> result(row_A, std::vector<double>(column_B));
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
    std::vector<std::vector<double>> horizontal_flip(std::vector<std::vector<double>> matrix)
    {
        int row = matrix.size();

        std::vector<std::vector<double>> result;

        for(int i = row - 1; i >= 0; i--)
        {
            result.push_back(matrix[i]);
        }

        return result;

    }

    std::vector<std::vector<double>> vertical_flip(std::vector<std::vector<double>> matrix)
    {
        int row = matrix.size();
        int column = (matrix[0]).size();

        std::vector<std::vector<double>> result;
        std::vector<double> temp;

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


    double determinant(std::vector<std::vector<double>> matrix)
    {
        int row = matrix.size();
        int column = (matrix[0]).size();
        
        if (row != column) 
        {
            std::cout << "Only square matrix(same row and column) can have determinant." << std::endl;
            throw std::invalid_argument("Only square matrix(same row and column) can have determinant.");
        }
        
        int column_position;
        double product = 1, result = 0;

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

        std::vector<std::vector<double>> matrix_T = horizontal_flip(matrix);

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