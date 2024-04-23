#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H


namespace matrix
{
    void print_matrix(std::vector<std::vector<int>> matrix);

    std::vector<std::vector<int>> add(std::vector<std::vector<int>> matrix_A, std::vector<std::vector<int>> matrix_B);

    std::vector<std::vector<int>> subtract(std::vector<std::vector<int>> matrix_A, std::vector<std::vector<int>> matrix_B);


}


#endif