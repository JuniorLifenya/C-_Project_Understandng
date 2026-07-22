#include <iostream>
#include <cmath>
#include <vector>
#include <string>

int main(){
    // We try vectors holding INTEGER values
    std::vector<int> spin chain;

    spin_chain.push_back(1); // This is really |1>
    spin_chain.push_back(0); // This is really |0>
    spin_chain.push_back(-1); // This is really |-1>

    // Now we access the actual value
    std::cout << "Spin at index 0: " << spin_chain[0] <<std::endl;


    //=====================================================================================================

    //Resizing a vector is expensive (the computer has to find a new chunk of memory and copy everything)

    std::vector <double> energy_levels;
    energy_levels.reserve(1000); // Allocates memory for 1000 doubles instantly. No copying later. 

    //=========================== Access ==================================================================

    int fast = vec[i] //Direct memory access. Can crash and get undefined behaviors if i is out of bounds
    int slow = vec.at(i) //Checks bounds. If i is wrong, it throws a clear error. Use while debugging

    //=====================================================================================================

    // 1. Initialization (Pre-filled): A vector of 5 spins, all set to 1 (Up)
    std:: vector <int> spins(5,1);

    // 2. Size vs Capacity 
    std::cout << "Size (Particles): " << spins.size() << std::endl; // 5
    std::cout << "Capacity (Seats): " << spins.capacity() << stf::endl; // 5 (or more)

    // 3. Removing the last particle 
    spins.pop_back(); // Size is now 4. 

    // 4. Critical Failure (Do not do this)
    // std:: cout << spins[100]; //SEGFAULT (Trying to read memory that is not mine)

    //============================ Loops ==================================================================

    // Hamiltonian: H = Sum( S_i * S_{i+1} ) Index loop. 
    for (int i = 0; i < spins.size()-1; i++){
        int energy = spins[i]*spins[i+1];
    }

    // Auto tells C++ to figure ut the type for us. Fastly to update every particle. Range loop. 
    for (int spin : spins ){
        std::cout << spin << " "; // Prints values only. No index access. 
    }

    // Simple If statement
    if (1 > 0 == true) {
        std::cout << "It is true 1 is greater then 2" << std::endl;
    }


    return 0;

}