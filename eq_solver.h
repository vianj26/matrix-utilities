#ifndef EQ_SOLVER_H
#define EQ_SOLVER_H

#include "common.h"
#include "eq_parser.h"
#include "matrix_utils.h"


class Solver
{
    public:
        std::map<std::string, std::vector<double>> columns; //{x:{1,2,3}}
        std::map<std::string, std::vector<std::vector<double>>> matrix_list{}; //{x:{{1,2,3},{4,5,6},{7,8,9}}}
        std::map<std::string, double> determinant_list{}; //{x:{1}}
        std::map<std::string, double> variable_values{};  //{x:{1}}
        int equation_count = 0;

        template<typename T, typename... list>
        Solver(T& equation, list&... equations)
        {
            std::cout << "Equations: " << std::endl;
            std::cout << equation.equation << std::endl;
            for(auto& member : equation.values)
            {

                (columns[member.first]).push_back(member.second);
            }

            equation_count++;

            solve(equations...);
        }

        void solve()
        {
            if(this->columns.size() != (equation_count + 1)) throw std::invalid_argument("Invalid to solve.");
            convert_to_matrix();
        }

        template<typename T, typename... list>
        void solve(T& equation, list&... equations)
        {
            std::cout << equation.equation << std::endl;
            for(auto& member : equation.values)
            {

                (columns[member.first]).push_back(member.second);
            }

            equation_count++;

            solve(equations...);
        }

        void print_columns();

        void convert_to_matrix();

};

#endif