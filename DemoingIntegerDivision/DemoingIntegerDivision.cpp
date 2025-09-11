// DemoingIntegerDivision.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int totalInches = 69; 

    constexpr int INCHES_PER_FEET = 12; //SCREAMING_SNAKE_CASE (snake_case)
    //INCHES_PER_FEET = 8498494; //illegal!


    std::cout << "The number of FEET in " << totalInches << " inches is "
        << totalInches/INCHES_PER_FEET << "\n";

    //find the number of remaining inches with the mod operator 
}
