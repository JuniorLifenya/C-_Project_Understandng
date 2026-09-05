#include <iostream>
#include <string>

int main(){
    // Dynamic Memory Allocation in C++
    // Dynamic memory allocation allows us to allocate memory at runtime using the new operator.
    // Memory is allocated after the program is already compiled & running. 
    // Use the "new operator to allocate memory in the heap rather than the stack


    // Useful when we don't know how much memory we will need. 
    // Makes our programs more flexible, especially when accepting user input.

    int *pnum = NULL; // Pointer variable that stores a null value, indicating that it does not point to any valid memory address
    pNum = new int; // Allocates memory for an integer and returns a pointer to it

    *pNum = 10; // Assigns a value to the allocated memory


    std::cout << "adress: " << pNum << "\n"; // Prints the address of the allocated memory
    std::cout << "value: " << *pNum << "\n"; // Prints the value of the allocated memory

    delete pNum; // Deallocates the memory allocated for the integer. No memory leaks.
    // Always deallocate memory when done using it.

    char *pGrades = NULL;
    int size;

    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    pGrades = new char[size]; // Allocates memory for an array of 'size' characters and returns a pointer to it

    for (int i = 0; i < size; ++i) {
        std::cout << "Enter grade " << i + 1 << ": ";
        std::cin >> pGrades[i]; // Assigns values to the allocated array
    }

    for (int i = 0; i < size; ++i) {
        std::cout << "Grade " << i + 1 << ": " << pGrades[i] << "\n"; // Prints the values of the allocated array
    }

    delete[] pGrades; // Deallocates the memory allocated for the array. No memory leaks.

    return 0; // Return 0 to indicate successful execution

}