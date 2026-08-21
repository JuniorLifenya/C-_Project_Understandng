#include <ctime>
#include <iostream>

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
    int num;
    int guess;
    int tries = 0;

    srand(time(NULL)); // Again create a random seed
    num = (rand() % 100) +1;

    std::cout << "########## Number Game Started ######### \n";

     do{
        std::cout << "Enter a guess between (1-100) \n";
        std::cin >>guess;
        tries++;

        if(guess > num){
            std::cout << "Too high \n";
        }
        else if(guess < num){
            std::cout << "Too low\n";
        }
        else{
            std::cout << "CORECT" << tries << "\n";

        }
        }while (guess !=num);
        std::cout << "#### WINNER WINNER !!! ####";
    std::cout << "########## Number Game ENDED #########";

     return 0;
}