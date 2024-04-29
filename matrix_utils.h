#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#include "common.h"




namespace matrix
{
    void print_matrix(std::vector<std::vector<double>> matrix);

    std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> matrix);

    std::vector<std::vector<double>> add(std::vector<std::vector<double>> matrix_A, std::vector<std::vector<double>> matrix_B);

    std::vector<std::vector<double>> subtract(std::vector<std::vector<double>> matrix_A, std::vector<std::vector<double>> matrix_B);

    std::vector<std::vector<double>> multiply(std::vector<std::vector<double>> matrix_A, std::vector<std::vector<double>> matrix_B);

    std::vector<std::vector<double>> horizontal_flip(std::vector<std::vector<double>> matrix);

    std::vector<std::vector<double>> vertical_flip(std::vector<std::vector<double>> matrix);

    double determinant(std::vector<std::vector<double>> matrix);

}


#endif