// GasProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iomanip> //input output manipulation
#include <iostream>
#include <string>

int main()
{

    //what is 6/5? 
    //std::cout << "6/5 = " << (6 / 5) << "\n";

    //std::system("pause");

    
    std::cout << "Enter your car's fuel efficiency (in mpg (or kpl))\n";

    int fuelEfficiency{};// = 0;// = 57.7; //the 0.7 gets "truncated" (silly inclusion for demonstration)
    //initializing ALL variables when you declare them is a good idea
    //the {} after the variable name is called "brace initializer syntax" 

    std::cin >> fuelEfficiency;

    //std::cout << "You entered fuel efficiency = " << fuelEfficiency << " miles per gallon\n";

    int tankCapacity = 13;//  gallons

    int number_of_miles_you_can_go = fuelEfficiency * tankCapacity;
    //  -> NOTE: parentheses DO NOT mean multiply in C++ don't do this -> 5(4) = 20
    //also don't do this 5 x 4 

    std::cout << "YOu can go this many miles on a full tank: "
        << number_of_miles_you_can_go << "\n";

    double costPerGallon{}; //DEFINITELY be a float (AKA: double) 
    //the braces {} that I just typed are an alternative method of INITIALIZING the double to 0.0

    std::cout << "Enter how much gas costs per gallon: \n";
    std::cin >> costPerGallon;
    
    //echo user input to confirm correct read: 
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "You entered: " << costPerGallon << "\n";

    //SUPPOSE user enters 2.70 (as of 9:18 am, this program echos 2.7! -> bad) 


    float costOfFullTank = costPerGallon * tankCapacity;
    //why a float -> so we can gain experience with std::setprecision() (in my Topic THREE slides) 

    std::cout << "The total cost for a full tank is: $" << costOfFullTank << "\n";

    
}

