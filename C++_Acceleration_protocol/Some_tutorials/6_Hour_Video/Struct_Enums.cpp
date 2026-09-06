
#include <iostream>



template <typename T, typename U> // Template for a function that can work with different data types
auto max(T a, U b) { // Function that returns the maximum of two values
    return (a > b) ? a : b; // Ternary operator that returns a if a is greater than b, otherwise returns b
}

struct student {
        std::string name;
        double gpa;
        bool enrolled;
}

enum Day{sunday= 0, monday= 1, tuesday = 2}

int main(){
    //---------------------- Struct  --------------------------------

         // A structure that groups related variables under one name, it can contain many different data types.
         // Store multiple values of different datatypes.
         // (String, variables in a struct are known as "members")
         // Members can be accessesed with . "Class Member Access Operator" 

         student Student1;
         Student1.name = "Bro1";
         Student1.gpa = 3,7;
         Student1.enrolled = true;

         student Student2;
         Student2.name = "Bro1";
         Student2.gpa = .4;
         Student2.enrolled = false;

         std::cout << Student1.name << Student1.enrolled <<Student1.gpa;
         std::cout << Student2.name << Student2.enrolled <<Student2.gpa;
         // Functions take in a copy of the struct actually and does so by values !

    //---------------------- enums  --------------------------------

         // enums = a user-defined data type that consists of paired named-integer constants.
         // GREAT if you have a set of potential potions
         Day today = "day1";

         switch (today)
         {
         case "sunday": std::cout << "It is day1";
            break;
         case "Monday": std::cout << "It is day2";
            break;
         default:
            break;
         }

         return 0;


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

