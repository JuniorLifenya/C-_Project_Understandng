#include <iostream>
#include <string>


void swap(std::string &x, std::string &y);

int main(){
    std::string x = "Cola";
    std::string y = "Pepsi";

    swap(x, y); // Pass by reference. The function parameters are references to the original variables.
    std::cout << "x: " << x << "\n"; // Prints Pepsi
    std::cout << "y: " << y << "\n"; // Prints Cola

    return 0;
}

// Function that swaps two strings. 
// The parameters are passed by value, so the original values of x and y are not changed. By DEFAULT,
// C++ passes parameters by value.

void swap(std::string &x, std::string &y){
    std::string temp = x;
    x = y;
    y = temp;
    std::cout << "Inside swap function: \n";
    std::cout << "x: " << x << "\n"; // Prints Pepsi
    std::cout << "y: " << y << "\n"; // Prints Cola
}