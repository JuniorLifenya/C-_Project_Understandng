

// Object = A collection of attributes and methods.
// They can have characteristics and could perform actions.
// Can be used to mimic real world items.
// Created from a class which acts as a "blue-print"

#include <iostream>

class Cars{
    public:
        std::string make; // Attributes....characteristics
        std::string model;
        int year; 
        std::string color;


        void accelerate(){ // Methods...Functions the object can perform
            std::cout << "You step on the gas ! \n";
        }
        void breake(){
            std::cout << "You step on the brakes\n";
        }
};

class Car_Constructor{
    public:
        std::string make;
        std::string model;
        std::string color;
        int year;
    car( std::string make,  std::string model,  std::string color, int year ){
        this->make = make;
        this->model = model;
        this->color = color;
        this->year = year;
    }
}

int main(){

    Car car1;
    car1.make = "Ford";
    car1.model = "Mustang";
    car1.color = "Silver";
    car1.year = "Purple";

    std::cout << car1.make << "\n";
    std::cout << car1.model << "\n";
    std::cout << car1.color << "\n";
    std::cout << car1.year << "\n";

    car1.accelerate();
    car1.brake();

    // ------------- Same for another Car 2 for instance ----------------

    //====================== Constructor =================================
    // A special method that is autmatically called when an object is instantiated
    //  Useful to assign values to attributes as arguments 
    
    Car_Constructor Car_constr1 ("Chevy", "Corvette", 2022, "blue");
    std::cout << Car_constr1.make << "\n";

    //====================== Overload Constructors =================================
    // Multiple constructors w/ name but different parameters
    // Allos for varying arguments when instantiating an object 



    return 0;



}
