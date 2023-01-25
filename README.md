Optimization

# optimization_uni-muenster_bidesh
Running the code:  
src-> contains the main source code.  
test-> contains the input file to run the case.  
  
The goal function implemented in this code is 'a*x*x + b*y*y + a*x + b*y' in src/munsterCode.c, where a and b are the coefficients. The user may change it to any function of their choice with the coefficients. Then user need to compile the code with './compile.sh'. 

The minima of any given function is found by gradient descent algorithm given by 'gradient_descent' function described in src/munsterCode.c.  
'munsterCode.py' calls 'munsterCode.c' which is linked with test/input.txt file where inputs are provided. Running the code can be done with './runFile.sh'. 

Contact: bideshsengupta.08@gmail.com
