// ModOperatorDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int currentZuluHour{};

	std::cout << "Current UTC time in 24 hour format is: " << currentZuluHour << "\n";
	
	
	while (true) //infinite loop for testing easily 
	{
		std::cout << "Enter a NEW hour in 24 hour format (so that we can test how the % operator works): \n";
		std::cin >> currentZuluHour;
		std::cout << "You entered this: " << currentZuluHour << "\n";


		std::cout << "Using the TWELVE hour clock, that time is: " << currentZuluHour % 12;
		if (currentZuluHour >= 12)
		{
			std::cout << "PM\n";
		}

		else
		{
			std::cout << "AM\n";
		}
		//we read the % symbol as "mod" (not like NexusMods) 



	}

}
