#include "eq_parser.h"

int Equation::equation_count = 0;

Equation::Equation(std::string equation)
{
    //TODO: check proper equation format : ax + by + ... = c
    
    for(char& c : equation)
    {
        if( c == 'c') throw std::invalid_argument("Use other variable other than c.");
    }

    //remove spaces in the linear equation;
    for(char& c: equation)
    {
        if(c != ' ') this->equation = this->equation + c;
    }

    //check and transform if the equation have negative constant value to avoid "=-" in the equation
    if((this->equation).find("=-") != std::string::npos)
    {
        transform_equation();
    }
    
    //break string into approprieate equation member(ax, by, ... =c)
    std::string temp;
    int length = (this->equation).size();
    int position=0;

    //condition when the first number of the equation is negative
    if((this->equation)[0] == '-')
    {
        position = 1;
        temp = '-';
    } 

    if(this->equation[0] == '+')
    {
        position = 1;
        temp = "";
    }

    for(int i = position; i < length; i++)
    {

        if((this->equation)[i] == '+' || (this->equation)[i] == '=' || (this->equation)[i] == '-') 
        {
            (this->parsed).push_back(temp);
            temp = (this->equation)[i];
        }
        else
        {   
            temp +=(this->equation)[i];
        }
    }

    //add the last temp value to the vector
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

    equation_count++;

}

Equation::~Equation()
{
    equation_count--;
}


void Equation::transform_equation()
{
    int position = (this->equation).find("=-");
    int length = (this->equation).length();

    (this->equation).replace(position, 2, "=");

    for(int i = 0; i < length; i++)
    {
        if((this->equation)[i] == '-')
         {this->equation[i] = '+';}
        else if(this->equation[i] == '+')
         {this->equation[i] = '-';}
    }
}
