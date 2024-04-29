#include "eq_solver.h"


void Solver::convert_to_matrix()
{
    //TODO: need correct arrangement inside the matrix
    for(auto& column : columns)
    {
        std::string variable = column.first;
        std::vector <double> temp_list;
        std::vector<std::vector<double>> temp_matrix;
        
        for(auto& candidate : columns)
        {
            if(candidate.first == "c")
            {
                continue;
            }
            else if(candidate.first == column.first)
            {
                temp_list = columns["c"];
            }
            else
            {
                temp_list = candidate.second;
            }
            temp_matrix.push_back(temp_list);
            temp_list.clear();
        }
        matrix_list[variable] = matrix::transpose(temp_matrix);
        temp_matrix.clear();
    }


    //display matrix
    for(auto& pair : matrix_list)
    {
        std::cout << pair.first << ": " << std::endl;
        for(auto& list : pair.second)
        {
            for(auto& value : list)
            {
                std::cout << value << "\t";
            }
            std::cout << std::endl;
        }
    }
    
    for(auto& pair : matrix_list)
    {
        double determinant = matrix::determinant(pair.second);
        determinant_list[pair.first] = determinant;
    }

    std::cout << "Matrix: " << std::endl;





    //determinant
    for(auto& pair : determinant_list)
    {
        if(pair.first != "c")
        {
            std::cout << pair.first << ": " << determinant_list["c"] << "/" << (pair.second) << std::endl;
            variable_values[pair.first] = (pair.second)/determinant_list["c"];
        }
    }

    //display determinant list
    std::cout << "Determinant: " << determinant_list.size() << std::endl;
    for(auto& pair : determinant_list)
    {
        std::cout << pair.first << ": " << pair.second << std:: endl;
    }

    //display values
    std::cout << "Values : " << std::endl;

    for(auto& pair : variable_values)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    
}

void Solver::print_columns()
{
    std::cout << "Columns: " << std::endl;

    for(auto& pair : columns)
    {
        std::cout << "\t" << pair.first << ": " << "[";
        for(auto& value : pair.second)
        {
            std::cout << value << ",";
        }
        std::cout << "\b]" << std::endl;

    }
}