#include <iostream>
#include <ctime>

char getUserChoice();
char getComputerChoice();
void showChoice(char,choice);
void chooseWinner(char player,char computer)


int main(){

    char player;
    char computer;

    player = getUserChoice();
    std::out << "You chose: ";
    showChoice(player);

    computer = getComputerChoice();
    std::cout << "Computer chose: ";
    showChoice(computer);

    chooseWinner(player, computer);
    return 0;

}

char getUserChoice (){

    char player;
    std::cout << "Rock-Paper-Scissors Game! \n";

    do{
        std::cout << "Enter your choice (R, P, S): ";
        std::cout << "===================================" << std::endl;
        std::cout << "R = Rock \n";
        std::cout << "P = Paper \n";
        std::cout << "S = Scissors \n";
        std::cin >> player;
        std::cout << std::endl;
    } while (player != 'R' && player != 'P' && player != 'S'); // Only accept R, P, or S as valid input

    return player;

}
char getComputerChoice (){
    
    srand(time(0)); // Seed the random number generator
    int num = rand() % 3; // Generate a random number between 0 and 2

    switch(num){
        case 0:
            computer = 'R';
            break;
        case 1:
            computer = 'P';
            break;
        case 2:
            computer = 'S';
            break;
    }
    return computer;
}
void showChoice(char choice){
    
    switch (choice) {
        case 'R':
            std::cout << "Rock\n";
            break;
        case 'P':
            std::cout << "Paper\n";
            break;
        case 'S':
            std::cout << "Scissors\n";
            break;
        default:
            std::cout << "Invalid choice\n";
    }
}
void chooseWinner(char player, char computer) {
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
    }
}