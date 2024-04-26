#include "eq_parser.h"

Equation::Equation(std::string equation)
{
    for(char& c : equation)
    {
        if( c = 'c') throw std::invalid_argument("Use other variable other than c.");
    }

    //remove spaces in the linear equation;
    for(char& c: equation)
    {
        if(c != ' ') this->equation = this->equation + c;
    }

    std::cout << this->equation << std::endl;

    
    //break string into approprieate equation member(ax, by, ... =c)
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

    
    //TODO: assign respective values in variables
    for(std::string member : (this->parsed))
    {
        //filters the constant value
        if( member[0] == '=')
        {
            int length = member.size();
            std::string string_value = member.substr(1, length -1);

            string_values['c'] = string_value;
            continue;
        }

        //assign values to variable with string of double using hashmap
        int length = member.size();
        char variable = member[length - 1];
        std::string string_value = member.substr(0, length - 1);

        try
        {
            string_values[variable] = string_value;
        }
        catch(const std::invalid_argument e)
        {
            std::cout << e.what() << std::endl;
        }
        catch (const std::out_of_range e)
        {
            std::cout << e.what() << std::endl;
        }
        

    }

    //make a copy of string_values hashmap where in string_values are converted to double type
    for(auto& pair : this->string_values)
    {
        double value = std::stod(pair.second);

        values[pair.first] = value;

    }

    for(auto& pair : this-> values)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

}

