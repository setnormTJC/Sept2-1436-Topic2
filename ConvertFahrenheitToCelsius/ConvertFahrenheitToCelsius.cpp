// ConvertFahrenheitToCelsius.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


//using namespace std; 

int main()
{
	//int degreesF = 212; 
	//int degreesC = (5.0 / 9)*(degreesF - 32);

	//std::cout << degreesF << " degrees F is equivalent to: " << degreesC << " degrees C\n";



	//std::cout << "\n\nstatic_cast on 7.9 yields: " << static_cast<int> (7.9) << "\n";


	//how to "increment" a variable's value:

	int numberOfLikes = 123; 

	std::cout << "Initial number of likes: " << numberOfLikes << "\n";

	numberOfLikes = numberOfLikes + 1; 

	//x = x + 1? is there any x for which this equation can be solved? (like in algebra) 

	std::cout << "After INCREMEMENTING by 1: " << numberOfLikes << "\n";

	numberOfLikes += 1; 


	std::cout << "After INCREMEMENTING by 1: " << numberOfLikes << "\n";


	numberOfLikes++; 

	std::cout << "After INCREMEMENTING by 1: " << numberOfLikes << "\n";


	char letterGrade = 'B+';
	
	//int age = “31 years”; //this is related to en-dash versus em-dash


	std::cout << "\n\n\nLetter grade is: " << letterGrade << "\n";
}

