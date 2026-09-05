#include <iostream>

int main(){
    // Pointer = variable that stores the memory of another variable.
    // & = "address of" operator, returns the memory address of a variable.
    // * = "dereference" operator, returns the value of the variable located at the address specified by the pointer.

    std::string food = "Pizza";
    std::string freePizzas[5] = {"Pizza", "Pizza", "Pizza", "Pizza", "Pizza"};
    int age = 21;

    std::string *pName = &food; // Pointer variable that stores the address of the food variable
    int *pAge = &age; // Pointer variable that stores the address of the age variable
    std::string *pFreePizzas = freePizzas; // Pointer variable that stores the address of the first element of the freePizzas array

    std::cout << "Food: " << food << "\n"; // Prints the value of the food variable
    std::cout << "Address of food: " << &food << "\n"; // Prints the address of the food variable
    std::cout << "Pointer to food: " << pName << "\n"; // Prints the address of the food variable stored in the pointer variable pName
    std::cout << "Dereferenced pointer to food: " << *pName << "\n"; // Prints the value of the food variable by dereferencing the pointer variable pName


    // --------------------------Nulll value -------------------------------------------------------
    // Null value = a special value that means something has no value or is not valid. In C++, the null value is represented by the nullptr keyword.
    // nullptr = keyword that represents a null pointer, which is a pointer that does not point to any valid memory address.
    // It is used to indicate that a pointer variable is not initialized or does not point to any valid memory address.

    // nullptrs are helpful when determining if an adress was sucessfully assigned to a pointer variable. 
    // If the pointer variable is null, it means that it does not point to any valid memory address.

    // When using pointers, be careful that your code isn't dereferencing a null pointer or pointing to free memory,
    // as it will lead to undefined behavior. Always check if a pointer is null before dereferencing it.

    

    int *ptr = nullptr; // Pointer variable that stores a null value, indicating that it does not point to any valid memory address
    int x = 123;

    int *pointer = &x; // Pointer variable that stores the address of the x variable

    if (pointer == nullptr) { // Checks if the pointer variable is null
        std::cout << "Pointer is null\n"; // Prints a message indicating that the pointer variable is null
    } else {
        std::cout << "Pointer is not null\n"; // Prints a message indicating that the pointer variable is not null
    }

    // So we can use the pointer variable to access the value of the x variable by dereferencing it.
    std::cout << "Value of x: " << *pointer << "\n"; // Prints the value of the x variable by dereferencing the pointer variable pointer
    // Not safe to dereference a null pointer, as it will lead to undefined behavior.
    // Always check if a pointer is null before dereferencing it.


    return 0; // Return 0 to indicate successful execution

}


#include <iostream>
#include <string>


void swap(std::string &x, std::string &y);

int main2(){
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