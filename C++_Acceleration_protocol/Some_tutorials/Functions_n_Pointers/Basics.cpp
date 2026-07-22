#include <iostream>
#include <vector>

int main(){

    // The function makes a copy of our vector, so having a vector with 10 million particles
    // The function will just double the RAM usage and waste time copying

    // So we pass by Reference. So the function gets the ADdress of our vector. Works on the original 

    // 1. BAD (Slow): Copies the whole vector 
    double calculation_energy_bad(std::vector<double> state){
        return state[0];
    }

    // 2. Good (Fast): Uses '&' to reference original 
    // 'const' means: "I promise not to change our vector, just read it "
    double calculate_energy_good(const std::vector<double>& state){
        return state[0];
    }

    // 3. MODIFIER: Uses '&' but no 'const'. Changes the original. 
    void flip_spin(std::vector<int>& state, int index ){
        state[index] = -state[index]; // Actually changes the vector in main()
    }

    // Writing the If statement, more 

    //============================== Mini exercise==========================================

    //Creates a vector of doubles (Energies).

    // Passes it by Reference to a function called apply_field.

    // Inside the function, loop through and add +0.5 to every energy.

    // Print the result in main.











    return 0;
}