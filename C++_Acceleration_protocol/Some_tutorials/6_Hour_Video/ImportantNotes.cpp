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
double getTotal(double prices[],int size); // Function prototype for passing an array to a function


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

    if(name.empty()) // Simpy checks if the name is empty or not)
    while(name.empty()){
        std::cout << "Enter jour name"
        std::getline(std::cin, name);
    } // Same for the code


    
    //=========================================================================
    // =================== For and While loops =====================
    int number;

    while (number < 0){
        std::cout << "Enter Positive number";
        std::cin >> counter;
    }

    do{  // Allows use to do some code once, THEN repeat IT again if some condition is true
        std::cout <<"Enter a poisitig number"
        std::cin >number;
        // do some code first,
        // Then Repeat agin if conditions are true
    }while(name < 0);
        // --------------------------------------------------------------------------
        // A loop that executes code a specified amount of time 

    for (int i = 1; i <= 3; ++i) // We can Increment i+=3 for instance and so on with decrementation
    {
        std::cout << "Happy New Year";
    }
        // -------------------- Break for switches...--------------------------------
        // -------------------- Continue skips the current iteration---

        switch(player){

        case "R":
            if(computer == 'R'){
                std::cout << "It's a tie!\n";
            } else if(computer == 'P'){
                std::cout << "Computer wins!\n";
            } else {
                std::cout << "You win!\n";
            }
            break;
        case "P":
            if(computer == 'R'){
                std::cout << "You win!\n";
            } else if(computer == 'P'){
                std::cout << "It's a tie!\n";
            } else {
                std::cout << "Computer wins!\n";
            }
            break;
        case "S":
            if(computer == 'R'){
                std::cout << "Computer wins!\n";
            } else if(computer == 'P'){
                std::cout << "You win!\n";
            } else {
                std::cout << "It's a tie!\n";
            }
            break;
        default:
            std::cout << "Invalid choice\n";
        }   

        //=========================================================================
        // =================== Arrays and Sizes =====================

        // -------------------- Array --------------------------------
        // A data structure that  can hold multiple values
        // Values are accessed by an index number
        // Kind of like a variable that holds multiple values
        std::string car[] = {"  Volvo", "BMW", "Ford", "Mazda"};

        // Can Also insert values into an array like this:
        std::string car[4];
        // Assigning values later demands the size of the array to be specified
        std::string car2[3] = {"Volvo", "BMW", "Ford"}; 
        // Here we can specify the size of the array and insert values at the same time
        car2[0] = "Volvo";
        car2[1] = "BMW";
        car2[2] = "Ford";
        // car2[3] = "Mazda"; // This would be out of bounds

        std::cout << car[0]; // Prints Volvo
        std::cout << car[1]; // Prints BMW


         // -------------------- Sizeof operator --------------------------------
         // sizeof() = determines the size in bytes of a:
         // variable, data type, or object

        double x = 5.0;
        std::cout << sizeof(x); // Prints 8 bytes

        std::string name = "Bro";// Prints 32 bytes

        char grade = 'A'; // Prints 1 byte
        bool isMale = true; // Prints 1 byte
        char grades[] = {'A', 'B', 'C', 'D', 'E'};
        std::string names[] = {"Bro", "Bro2", "Bro3", "Bro4", "Bro5"};

        std::cout << sizeof(grades); // Prints 5 bytes
        std::cout << sizeof(grades/sizeof(char)) <<"Elements in the array \n"; 
        // Calculates the number of elements in the array
        // Calculates the number of elements in the array
        std::cout << sizeof(names); // Prints 160 bytes
        std::cout << sizeof(names)/sizeof(std::string) <<"Elements in the array \n";

        //--------------------- Loops through arrays --------------------------------
        std::string students[] = {"Bro", "Bro2", "Bro3", "Bro4", "Bro5"};
        char grades2[] = {'A', 'B', 'C', 'D', 'E'};
        
        for (int i = 0; i < sizeof(students)/sizeof(std::string); ++i)
        {
            std::cout << students[i] << "\n"; // Calculate size and prints out all the elements in the array
        }

        for(int i = 0; i < sizeof(grades2)/sizeof(char); ++i)
        {
            std::cout << grades2[i] << "\n"; // Calculate size and prints out all the elements in the array
        }

        //-----We can also do this with a foreach loop in C++11 and later versions----
        //foreach loop = loop that eases the traversal over an iterable data structure
    
        int grades[] = {90, 85, 78, 92, 88};
        for (int grade: grades ){
            std::cout << grade << "\n"; // Prints all the elements in the array
        }
         

        //---------------- Pass array to a function --------------------------------
        // We can pass an array to a function by passing the name of the array
            double prices[] = {10.99, 5.99, 3.99, 6.59};
            int size = sizeof(prices)/sizeof(double);
            double total = getTotal(prices, size);
            // Passing an array to a function is done by name

        //---------------- Search in an array --------------------------------
            



    return 0;
}

double getTotal(double prices[], int size) { // Function receiving an array decays into a pointer and forgets the size of it 
    // So we pass it as an additional parameter to the function. 
    // The size of the array is not known to the function, so we must pass it as an additional parameter.
    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        total += prices[i];
    }
    return total;
}