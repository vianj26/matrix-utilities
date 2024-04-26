#include "eq_parser.h"

Equation::Equation(std::string equation)
{

    for(char c: equation)
    {
        if(c != ' ') this->equation = this->equation + c;
    }

    std::cout << this->equation << std::endl;

    //TODO:break string between operators and constant values

    
    std::string temp;
    int length = (this->equation).size();
    int count = 0;

    for(int i = 0; i < length; i++)
    {
        if((this->equation)[i] == '+' || (this->equation)[i] == '=') 
        {
            (this->parsed).push_back(temp);
            temp = (this->equation)[i];
        }
        else
        {
            temp +=(this->equation)[i];
        }
    }

    (this->parsed).push_back(temp);

    for(std::string member : (this->parsed))
    {
        std::cout << member << std::endl;
    }

    //for(char c: (this->equation)){}
    //TODO: assign respective values in variables
}

