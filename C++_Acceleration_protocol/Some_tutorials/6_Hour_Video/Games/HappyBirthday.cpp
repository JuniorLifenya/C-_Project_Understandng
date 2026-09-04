#include <ctime>
#include <iostream>
#include <cstdlib>
#include <string>

// Functions are blocks of re-usable codes
// Especially if you think some code with purpose is gonna be re-used

void happyBirthday(std::string name);// No return types HappyBirthday() calls it 
// A lot of people like to declare it first,
// then have it after the main int function
// Void has to be changed to match the datatype the function returns 

void bakePizza();
void bakePizza(std::string topping1);
void bakePizza(std::string topping1, std::string topping2);

int myNum = 3; // Open to the outside world for anyone to use...
void PrintNum() // Declaration of a global print function


int main()
{

    // Psudo-random = NOT truly random (but close)

    srand(time(NULL));

    int num1 = (rand() % 6) + 1; // Random number between one and 6 
    int num2 = (rand() % 100) + 1; // Random number between one and 100 

    // =================== Random Even Generator =================
    srand(time(0)); // Random Seed
    int randNum = rand() % 5 +1;

    switch(randNum){
        case 1:
            std::cout << "You win Sticker \n";
            break;
        case 2:
            std::cout << "You win Free Lunch \n";
            break;
        case 3:
            std::cout << "You win TicTac toe \n";
            break;
        case 4:
            std::cout << "You win a Concert Ticket";
    }


    // =================== Random Guesser Game =================
    // int num;
    // int guess;
    // int tries = 0;

    // srand(time(NULL)); // Again create a random seed
    // num = (rand() % 100) +1;

    // std::cout << "########## Number Game Started ######### \n";

    // do{
    //     std::cout << "Enter a guess between (1-100) \n";
    //     std::cin >>guess;
    //     tries++;

    //     if(guess > num){
    //         std::cout << "Too high \n";
    //     }
    //     else if(guess < num){
    //         std::cout << "Too low\n";
    //     }
    //     else{
    //         std::cout << "CORECT" << tries << "\n";

    //     }
    // }while (guess !=num);   
    
    // std::cout << "#### WINNER WINNER !!! ####";
    // std::cout << "########## Number Game ENDED #########";

    //==================== Function Calling ==================
    std::string name = "Bro";
    happyBirthday(name);
    // Shared function...all of these map to that one function 
    std::string firstName = "Bro";
    std::string lastName = "Code";
    std::string fullName = concatStrings(firstName, lastName);

    std::cout << "Hello" << fullName;

    // The inverse is also possible...for a given datatype or object here 
    // We can have different functions outside 
    // Over loaded functions
    bakePizza("peperoni","mushroom");

    // =================== Global and Local Scopes ===========
    int myNum = 1;
    printNum();
    std::cout << ::myNUm << "\n "; // The Scope-res operator targets the global version 
    return 0;
}

// Function definition
void happyBirthday(std::string name)
{
    std::cout << "Happy Birthday to " << name << "\n";
    std::cout << "Happy Birthday to " << name << "\n";
    std::cout << "Happy Birthday to " << name << "\n";
    std::cout << "Happy Birthday Dear " << name << "\n";
    std::cout << "Happy Birthday to " << name << "\n\n";
}

// Share functions 
std::string concatStrings(std::string string1, std::string string2)
{
    return string1 + " " + string2;
}

// Overloaded function function name + paramaters = function signature
void bakePizza(){
    std::cout << "Here is your Pizza! \n";
}
void bakePizza(std::string topping1){
    std::cout << "Here is your " << topping1 << "pizza! \n";
}
void bakePizza(std::string topping1, std::string topping2){
    std::cout << "Here is your " << topping1 << "and" <<toping2 << "Pizza";
}

void printNum(){
    int myNum = 2;
    std::cout << myNum;
}