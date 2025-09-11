#include <iostream>

int main() {



	int zuluHour = 0;

	std::cout << "Current UTC time in 24-hour format is: " << zuluHour << "\n";

	while (true)
	{

		std::cout << "Enter a new hour in 24-hour format: \n";

		std::cin >> zuluHour;

		std::cout << "You entered: " << zuluHour << "\n";

		std::cout << "Using the twelve-hour clock: ";

		/*if (zuluHour == 12 && zuluHour == 24)
		{
			std::cout << "12";
		}

		else
		{

			std::cout << zuluHour % 12;

		}

		*/

		std::cout << zuluHour % 12;

		if (zuluHour >= 12)
		{
			std::cout << "PM\n";
		}

		else
		{
			std::cout << "AM\n";
		}

	}


	return 0;
}