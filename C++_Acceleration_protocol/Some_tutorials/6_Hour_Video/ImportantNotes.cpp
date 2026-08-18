#include <iostream>


// A namespace allows for identically named entities 
namespace first 
{
    int x = 0; 
}

// Works better with using keyword. Defines an alias for another data type simply. 
typedef int number_t;
typedef std::string text_; 
using text_t = std::string; 
using number_t = int; // More suitable for templates


int main()
{

    bool forSale = true; // Remember bolian values in C++ 
    char Grade1 = 'A'; // Only one character input not AB for instance..must use '' and not ""
    std::string name = "Bro"; // Here we can hold multiple characters at the same time
    const double PI = 3.14159; // Here we use Big letter to change the double to a CONST

    int x = 1; // Different version of the variables...local version 
    std::cout << first::x; // Two colons are the scope resolution operators. Referign to x in first namespace

    text_ firstname = "Eplekake";
    std::cout << firstname << std::endl;

    // Type conversions
    int correct = 8;
    int questions = 10;
    double score = correct/(double)questions * 100; // Converts a value of one type to another
    // Implicit = automatic, Explicit = Precede value with new data type (int)

    return 0;
}