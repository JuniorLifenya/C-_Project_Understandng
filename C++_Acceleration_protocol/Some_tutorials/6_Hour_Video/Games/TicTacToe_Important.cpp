#include <iostream>
#include <ctime>

void drawBroad(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
void checkWinner(char *spaces, char player, char computer);
void checkTie(char *spaces);


int main(){


    char spaces[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
    char player = "X";
    char computer = "O";

    bool running = true;

    while(running){
        playerMove(spaces, player);
        drawBroad(spaces);  // Recall arrays to a func decays to a pointer...
        if(checkWinner(spaces,player,computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }

        computerMove(spaces,computer);
        drawBroad(spaces);
        if(checkWinner(spaces,player,computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }
    }



    std::cout << "Thanks for playing! \n";

    return 0;

}

void drawBroad(char *spaces){


    return 0;
}

void playerMove(char *spaces, char player){
    int number; 

    do{

        std::cout << " Enter a spot to place marker (1-9)";
        std::cin >> number;
        number--;
        if(spaces[number] == " "){
            spaces[number] = player;
            break;
        }

    }while(!number > 0 || !number <8);
}

void computerMove(char *spaces, char computer){

     int number;
     srand(time(0));

     while(true){
        number = rand() % 9;
        if(spaces[number] == " "){
            spaces[number] = computer;
            break;
        }
     }


}

void checkWinner(char *spaces, char player, char computer){

    if((spaces[0] != " ") && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player ? std::cout << " You win\n" : std::cout << "You loose\n";

    }
    else if((spaces[3] != " ") && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player ? std::cout << " You win\n" : std::cout << "You loose\n";

    }
    else if((spaces[6] != " ") && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player ? std::cout << " You win\n" : std::cout << "You loose\n";

    }
    else if((spaces[0] != " ") && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player ? std::cout << " You win\n" : std::cout << "You loose\n";

    }
    else if((spaces[1] != " ") && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player ? std::cout << " You win\n" : std::cout << "You loose\n";

    }
    else if((spaces[2] != " ") && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player ? std::cout << " You win\n" : std::cout << "You loose\n";

    }
    else if((spaces[0] != " ") && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player ? std::cout << " You win\n" : std::cout << "You loose\n";

    }
    else if((spaces[2] != " ") && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player ? std::cout << " You win\n" : std::cout << "You loose\n";

    }
    else{
        return false;
    }
    return 0;
}

void checkTie(char *spaces){
    for(int i = 0; i<9; ++i){
        if(spaces[i] == " "){
            return false;
        }
    }
    std::cout << "It is a TIE! \n";
    return true;
}


