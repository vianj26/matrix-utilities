#ifndef EQ_SOLVER_H
#define EQ_SOLVER_H

#include "common.h"
#include "eq_parser.h"


class Solver
{
    public:
        static std::unordered_map<std::string, std::vector<double>> columns;

        static void solve(){};

        template<typename T, typename... list>
        static void solve(T& equation, list&... equations)
        {
            std::cout << equation.equation << std::endl;
            for(auto& member : equation.values)
            {

                (columns[member.first]).push_back(member.second);
            }

            solve(equations...);
        }

        static bool is_valid()
        {
            return (Solver::columns).size() + 1 == Equation::equation_count;
        }

};

#endif