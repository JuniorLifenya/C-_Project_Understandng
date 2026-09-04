#include <iostream>
#include <cmath>


int searchArray(int array[], int size, int element); // Function prototype for searching an array

int mian(){

            //---------------- Pass array to a function --------------------------------
        // We can pass an array to a function by passing the name of the array
            double prices[] = {10.99, 5.99, 3.99, 6.59};
            int size = sizeof(prices)/sizeof(double);
            double total = getTotal(prices, size);
            // Passing an array to a function is done by name

        //---------------- Search in an array --------------------------------
            int numbers[] = {1, 2, 3, 4, 5};
            int size = sizeof(numbers)/sizeof(numbers[0]);
            int index;
            int myNum;

            std::cout << "Enter a number to search for: " << "\n";
            std::cin >> myNum;

            index = searchArray(numbers, size, myNum);
            if (index != -1) {
                std::cout << "Found at index: " << index << "\n";
            } else {
                std::cout << "Not found" << "\n";
            }
            
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



int searchArray(int array[], int size, int element){
    for(int i = 0; i < size; i++){ // Linear search technically
        if (array[i] == element){
            return i; // Return the index of the element if found
        }
        return -1; // Return -1 if the element is not found. Sentinal value to indicate not found

    }
}