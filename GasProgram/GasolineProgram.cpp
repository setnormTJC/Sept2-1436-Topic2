// GasProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your car's fuel efficiency (in mpg (or kpl))\n";

    int fuelEfficiency;// = 0;// = 57.7; //the 0.7 gets "truncated" (silly inclusion for demonstration)
    //initiliazing ALL variables when you declare them is a good idea

    //std::string a; 
    //std::getline(std::cin, a);

    std::cin >> fuelEfficiency;

    //std::cout << "You entered fuel efficiency = " << fuelEfficiency << " miles per gallon\n";

    //remember the term BREAKPOINT ->  EXTREMELY useful for debugging

    int tankCapacity = 13;//  gallons

    int travelRange = fuelEfficiency * tankCapacity;
    //  -> NOTE: parentheses DO NOT mean multiply in C++ don't do this -> 5(4) = 20
    //also don't do this 5 x 4 

    std::cout << "YOu can go this many miles on a full tank: "
        << travelRange << "\n";

}

