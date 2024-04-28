#include "eq_solver.h"

std::unordered_map<std::string, std::vector<double>> Solver::columns{};


/*
void Solver::solve(std::vector<Equation>& list)
{
    for(auto& equation : list)
    {
        std::cout << equation.equation << std::endl;
        for(auto& member : equation.values)
        {

            (columns[member.first]).push_back(member.second);
        }
    }
}
*/
