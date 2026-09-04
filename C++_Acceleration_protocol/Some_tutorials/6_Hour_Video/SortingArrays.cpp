#include <iostream>

// We will utilize the bubble sort algorithm to sort an array of integers in ascending order. 
//The bubble sort algorithm repeatedly steps through the list,
// compares adjacent elements and swaps them if they are in the wrong order.
// The pass through the list is repeated until the list is sorted.
// Using a temporary variable to swap the values of two elements in the array.


int main(){
    
    //-----We can also do this with a foreach loop in C++11 and later versions----
    //foreach loop = loop that eases the traversal over an iterable data structure

    int array [] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(array)/sizeof(array[0]); // Calculate the size of the array

    for (int el: array){
        std::cout << el << " "; // Print the original array
    }
    sort(array, size); // Call the sort function to sort the array
}

void sort(int array[], int size){
    int temp; // Temporary variable to hold the value during swapping
    for (int i = 0; i < size -1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (array[j] > array[j + 1]){ // Compare adjacent elements
                temp = array[j]; // Swap the elements if they are in the wrong order
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// This is asceinding order and still not fully efficient.
// We can use the std::sort function from the <algorithm> library to sort the array in a more efficient way.