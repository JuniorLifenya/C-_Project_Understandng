#include <iostream>
#include <string>
using namespace std;

// C++ is backwards compatible with C !

void PrintString(string* str) // Here it is a type of string pointer becaus of *
{
    cout << *str; // Here it dereferences an object or a pointer 
};


void PrintString2(string& str) 
// Now it is passed as a reference! Type of string reference now
// Cleaner syntax 
{
    cout << str;
};

class ClassB
{
Public:
    ClassB(int whoa) // Requires an integer passed to it
    // Now way to instatiate a classB with some other default initializer
    {

    }
}

class ClassA
{
private:
    int& _myfield;
    ClassB _otherObject;


    int& _number; // Not referencing ANYTHING really! Problematic
    // Because the first thing that happens is the initialization
    // Firstly the fields are Initialized then constructors get invoked
    // Initialization sets them to their default values...Giving A PARADOX
    // One cannot initialize a reference to a default value
    // Because references per definition do not have default values!!!
    // They Always Points Towards something Valid !!!

public: // Even the constructor logic here does not work!
    ClassA(int& number) : _number(number), _otherObject(10) // Overrides really C++ Initialization
    //Preceeds the Constructor before execution!!!
    // We can instead assign values to it 
    // This code here changes what gets invoked BEFORE the CONSTRUCTOR !!!
    // Goes to Costume Initialization and then execution jumps to CONSTRUCTORS
    // Initialization lists are required for constant values to be set !
        {
            _number = number;
        }
};




int main(){

    // What are references...similar to pointers
    // References do not replace pointers...
    // They are like pointer but with limitations
    // They cannot be changed!
    // The code can look like they might be able to change 
    // If you cannot get away with using references...use Pointers
    // References HAS NO DEFAULT VALUE
    int numbers;
    int* numperPointer = &number; // Can here point to something random...ANYTHING!!!

    cout << *numerPointer;

    string blegh = "Hey"; // String has defaut constructors 

    PrintString(&blegh); // Here this & is to retrieve the adress of it
    PrintString2(blegh);

    //Test code here
    int number1 = 10;
    int number2 = 20;

    int& numberRef = number1; // Pointing to number1, Initialization...cannot change
    numberRef = number2; 
    // This is an assignment 
    // Now taking the value of number1 goes to number2 

    cout << number1 << "\n" << number2 << "\n" << numberRef; // Prints out number 2 

    cin.get(); // Error I think because now number2 is pointing towards number 1 and IS the int& numberRef


    int number =10;
    ClassA clsl(number);







    
    return 0 ;

}

// IN C++ memory allocation is deterministic 