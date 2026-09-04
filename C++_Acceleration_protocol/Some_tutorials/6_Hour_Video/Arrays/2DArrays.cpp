#include <iostream>
#include <string>



int main (){
    // First Rows and Second Columns
    std::string cars[][3] = {{"Volvo", "BMW", "Ford"},
                            {"Corvette", "Equinox", "Silverado"},
                            {"Challenger", "Durango", "Ram 1500"}}; 
    // Each row is a manufacturer and each column is a model of that manufacturer.
    std::cout << cars[0][0] << "\n"; // Prints Volvo
    std::cout << cars[1][2] << "\n"; // Prints Silverado
    std::cout << cars[2][1] << "\n"; // Prints Durango

}