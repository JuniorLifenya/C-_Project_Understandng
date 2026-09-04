#include <iostream>


int main(){
    std::string foods[5]; // Limited sizes...static arrays have a fixed size.
    // We can use dynamic arrays or vectors for more flexibility....later
    int size = sizeof(foods)/sizeof(foods[0]); // Calculate the size of the array
    std::string temp;


    for(int i = 0; i < size; ++i){
        std::cout << "Enter food item " << (i + 1) << ": ";
        std::getline(std::cin, temp);
        if(temp== "q"){
            break; // Exit the loop if the user enters "q"
        }
        else{
            foods[i] = temp; // Store the input in the array
        }
    }
    for(int i = 0; !foods[i].empty(); ++i){
        std::cout << "Food item " << (i + 1) << ": " << foods[i] << std::endl;
    }
}



