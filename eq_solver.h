#ifndef EQ_SOLVER_H
#define EQ_SOLVER_H

#include "common.h"
#include "eq_parser.h"


class Solver
{
    public:
        std::unordered_map<std::string, std::vector<double>> columns;
        int equation_count = 0;

        template<typename T, typename... list>
        Solver(T& equation, list&... equations)
        {
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
        };

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

};

#endif