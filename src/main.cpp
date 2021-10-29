#include <iostream>
#include "mat.h"

int main(int argc, char *argv[])
{
    std::cout << "\nHello let's solve some matrices together \\(* v *)/" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "please enter a matrix \t \t need help? type \"help\"" << std::endl;
    std::string userInput;
    std::cin >> userInput;

    //TODO: implement input verification

    if (!userInput.compare("help"))
    {
        std::cout << "enter your n X m Matrix in the following format: \n\n"
                     "[[X11, X21, ..., Xn1],[X12, X22, ..., Xn2], ..., [X1m, X2m, ..., Xnm]] \n\n"
                     "and press Enter"
                  << std::endl;
    }

    //Testcode to test the Matrix class
    mat::Matrix coeffMatrix(10,10);

    mat::Matrix solMatrix(10,1);
    
    for(uint16_t i = 0; i < coeffMatrix.getRows(); i++)
    {
        for(uint16_t j = 0; j < coeffMatrix.getCols();j++)
        {
            *coeffMatrix(i,j) = rand() % 10;
        }
        *solMatrix(i,0) = rand() % 10;
    }

    coeffMatrix.display();
    solMatrix.display();

    solMatrix = mat::gaussElm(&coeffMatrix,&solMatrix);
    
    solMatrix.display();
}
