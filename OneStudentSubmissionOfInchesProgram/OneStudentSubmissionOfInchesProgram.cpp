#include <iostream>
using namespace std;

int main() {

	while (true)
	{

		//こんにちは世界
		int choice;

		cout << "=== Unit Converter ===" << endl;
		cout << "Choose an option:" << endl;
		cout << "1. Convert Inches to Feet & Inches" << endl;
		cout << "2. Convert Feet & Inches to Inches" << endl;
		cout << "Enter 1 or 2: ";
		cin >> choice;

		if (choice == 1) {
			// Inches to Feet & Inches
			int totalInches;
			cout << "Enter total inches: ";
			cin >> totalInches;

			if (totalInches < 0) {
				cout << "Norman is trying to measure backwards through time. Not allowed!" << endl;
			}
			else {
				int feet = totalInches / 12;
				int inches = totalInches % 12;

				cout << totalInches << " inches = "
					<< feet << " feet and " << inches << " inches." << endl;
			}

		}
		else if (choice == 2) {
			// Feet & Inches to Total Inches
			int feet, inches;
			cout << "Enter feet: ";
			cin >> feet;
			cout << "Enter inches: ";
			cin >> inches;

			if (feet < 0 || inches < 0) {
				cout << "Gabe thinks negative height is a thing. Nice try, time traveler!" << endl;
			}
			else if (inches >= 12) {
				cout << "Norman! Inches should be less than 12. Put that tape measure down and think." << endl;
			}
			else {
				int totalInches = (feet * 12) + inches;
				cout << feet << " feet and " << inches << " inches = "
					<< totalInches << " inches." << endl;
			}

		}
		else {
			cout << "\nGabe tried to enter option " << choice << ". That's not even a thing!" << endl;
			cout << "Norman is confused. Again. 🤦‍♂️" << endl;
			cout << "Please run the program and choose either 1 or 2, not your shoe size." << endl;
		}

	}
	return 0;
}