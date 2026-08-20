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

    //=========================================================================
    // =================== Useful Math functions ===========================
    double x = 3;
    double y = 4;
    double z;
    z = std::max(x,y); // Compares the two values and finds the greater one... here 4 
    z = pow(2,4); // Two raised to the 4 
    z = sqrt(9); // Square root function
    z = abs(-3); // Absolute value 
    z = round(3.14); // Gives the rounded value...3
    z = ceil(3.14) // Rounds up to 4 
    z = floor(3.14) // Rounds down to 3...

    //=========================================================================
    // =================== If and else statements ===========================

    int age;
    std::cout << "Enter age for instance: "
    std::cin >> age;
    if(age >= 18)
    {
        std::cout << "Welcome";
    }
    else if(age < 0 )
    { // This is checked of course after an if statement as en elif statement...
        std::cout << " You haven't been born yet bro";
    }
    else if(age >= 100)
    {
        std::cout << "You are waaay to old";
    }
    else
    {
        std::cout << "You are not old enough to enter"
    }

    //=========================================================================
    // =================== Switches  ===========================
    // An alternative way to use many "else if" statements 
    // Compare one value against matching cases
    int month;
    std::cout << "Enter the month (weekday)";
    std::cin >> month;
    switch(weekDay) // More efficient for several if statements, more efficient and easier to read!
    {
        case 1:
            std::cout << "It is Monday";
            break;
        default:
            std::cout << "Please enter correct number"; 

    }
    //--------------------------------------------------------------------
    switch(Grade)
    {
        case 'A':
            std::cout << "Congratulations";
            break;
        case 'F':
            std::cout << "You have to lock in a bit...";
            break;
        default:
            std::cout << "Not a valid grade letter";

    }
    //==========================================================================
    // =================== Ternary operator ?:  ===========================
    // A replacement to using if and else statements
    // Condition ? expression1 : expression2;
    int grade;
    std::cout "What grade did you get?";
    std::cin >> grade;
    //--------------------------------------------------------------------
    grade >= 60 ? std::cout << " You pass" : std::cout << "You failed";
    number % 2 == 1 ? std::cout << "Odd" : std::cout << "True";
    
    bool hungry = true;
    hungry ? std::cout << "You are Hungry" : std::cout << "You are full";
    std::cout << (hungry ? "You are Hungry" : "You are full");

    //=========================================================================
    // =================== Logical Operators: &&, ||, ! =====================
    // && = check if two conditions are true
    // || = check if at least one of the two conditions is true
    // ! = reverse the logical state of its operand

    int temp;
    std::cout << "Temperature: "
    std::cin >> temp;

    if (temp > 0 && temp < 30) // Both must be true to execute the code. Check several conditions
    { 
        std::cout << "The temperature is good!";
    }
    else
    {
        std::cout << "The temperator is bad !";
    }
    //--------------------------------------------------------------------
    if (temp <= 0 || temp >= 30)
    {
        std::cout << "The temperature is bad!";
    }
    else 
    {
        std::cout << "The temperature is good!"; 
    }
    //--------------------------------------------------------------------
    int temp;
    bool sunny = false;
    if(!sunny){ // Checking to see if it is NOT sunny outside
        std::cout << "It is cloudy outside"; 
    }
    else {
        std::cout << "It is sunny outside"
    }
    //=========================================================================
    // =================== Useful String Methods =====================
    std::string name;
    std::getline(std::cin, name); // Here we get a name and imediately assign it to the variable

    if (name.length() > 12){
        // In this methode we directly get the length of the string with .length
    }

    if (name.empty()){
        // Returns if a string is empty or not...check if someone actually inserts user inputs!
        std::cout << "You did not enter your name:"
    };

    name.clear(); // This methode simply clears something
    name.append(); // Add a string to the end of another string
    std::cout << name.at(1); // Character at the index 1 

    name.insert(0, "@"); // Inserts a character at the index 
    std::cout << name.find();
    name.erase(0,3) // Eliminates the first three characters

    if(name.empty() // Simpy checks if the name is empty or not)
    while(name.empty()){
        std::cout << "Enter jour name"
        std::getline(std::cin, name);
    } // Same for the code


    
    //=========================================================================
    // =================== For and While loops =====================
    do{
        std::cout <<"Enter a poisitig number"
        std::cin >number;
        // do some code first,
        // Then Repeat agin if conditions are true
    }while(name < 0);

    
    return 0;
}