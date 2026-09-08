

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

    //====================== Overload Constructors =================================
    // Multiple constructors w/ name but different parameters
    // Allos for varying arguments when instantiating an object 



class Pizza_OverLoadedConstr{
    public:
        std::string topping1;
        std::string topping2;
    Pizza(){ // No topping

    }
    Pizza(std::string topping1){
        this->topping1 = topping1;
    }
    Pizza(std::string topping1, std::string topping2){
        this->topping1 = topping1;
        this->topping2 = topping2;
    }
};



class Stove{

    private:
        int temperature = 0;
    public:

    int getTemperature(){
        return temperature;
    }

    void setTemperature (int temperature){

        if (temperature < 0 ){
            this->temperature = 0 ;
        }
        else if(temperature >=10){
            this->temperature = 10;
        }
        else{
        this->temperature = temperature;
        }
    }
};


class Animal{
    public:
        bool alive= true;

    void eat(){
        std::cout << "This animal is eating \n"; // CAN JUST MAKE CHANGES HERE IN ONE PLACE FOR ALL OTHER INHERITANCES!
    }
};

class Dog : public Animal{

    public:

    void bark(){
        std::cout << "The dog goes woof\n";
    }

};


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

    // Abstraction = hiding unnecessary data from outside a class 
    // getter = func that makes a private attribute READABLE
    // setter = func that makes a private attribute WRITEABLE! 

    Stove stove;

    stove.setTemperature(-5);

    std::cout << "The temp setting is: " <<stove.getTemperature;


    //====================== Inheritance ==================================
    // A class that recieves attributes and methods from another class
    // The children class inherits the Parent class 
    // Helps to reuse similar code found within multiple classes

    Dog dog;

    std::cout << dog.alive << "\n";
    dog.eat();
    dog.bark();


    return 0;



}
