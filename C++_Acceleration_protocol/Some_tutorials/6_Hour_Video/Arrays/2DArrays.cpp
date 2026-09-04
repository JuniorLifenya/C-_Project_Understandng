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

    int rows = sizeof(cars)/sizeof(cars[0]); // Calculate the number of rows in the 2D array
    int columns = sizeof(cars[0])/sizeof(cars[0][0]); // Calculate the number of columns in the 2D array

    for (int i = 0; i < rows; ++i){ // One loop gives only the memory address of the first element in each row.
        // We need a nested loop to access each element in the 2D array
        for (int j = 0; j < columns; ++j){
            std::cout << cars[i][j] << " "; // Print each element in the 2D array as rows and columns. 
            // The first loop iterates through the rows and the second loop iterates through the columns.
        }
        std::cout << "\n"; // New line after each row
    }

}