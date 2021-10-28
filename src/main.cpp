#include <iostream>
#include "mat.h"

int main(int argc, char *argv[])
{
    std::cout << "\nHello let's solve some matrices together \\(* v *)/" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "please enter a matrix \t \t need help? type \"help\"" << std::endl;
    std::string userInput;
    std::cin >> userInput;

    if (!userInput.compare("help"))
    {
        std::cout << "enter your n X m Matrix in the following format: \n\n"
                     "[[X11, X21, ..., Xn1],[X12, X22, ..., Xn2], ..., [X1m, X2m, ..., Xnm]] \n\n"
                     "and press Enter"
                  << std::endl;
    }

    //Testcode to test the Matrix class
    mat::Matrix MyMatrix(10,10);
    
    for(uint16_t i = 0; i < MyMatrix.getRows(); i++)
    {
        for(uint16_t j = 0; j < MyMatrix.getCols();j++)
        {
            if(j == 0)
            {
                *MyMatrix(i,j) = 0;
            }
            else
            {
                *MyMatrix(i,j) = rand() % 10;
            }
        }
    }

    MyMatrix.display();
    MyMatrix = mat::gaussElm(&MyMatrix);
    MyMatrix.display();



}
