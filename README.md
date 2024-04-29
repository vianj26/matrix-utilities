# Matrix Utility and Linear Equation Solver

Initially, this project aimed to create utility files for processing matrices, including operations like addition, subtraction, multiplication, and calculating determinants. It has since expanded to include solving systems of linear equations with n variables.

## Updates
- April 29, 2024: Added functionality to solve n-variable linear equations.

## How to Use
1. **Matrix Operations**: Use the provided utility functions to perform matrix operations. See `main.cpp` for sample usage.
2. **Linear Equation Solver**:
   - Format equations in standard linear equation format (`ax + by = c`).
   - Avoid using "c" as a variable.
   - Use single-character variables.
   - Input 0 if there is no value for a variable (e.g., `3x + 0y = 10`).
   - Input 1 if a variable has no coefficient (e.g., `x + y = 10` becomes `1x + 1y = 10`).
   - Future updates will handle additional edge cases, such as variables with coefficients of 0 or 1.

## License

You may use this project for your own projects. Please give credit to the author (vianj26) and consider starring the repository. Thank you!