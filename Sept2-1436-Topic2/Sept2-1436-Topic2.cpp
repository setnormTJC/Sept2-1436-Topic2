// Sept2-1436-Topic2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<cctype>
#include <iostream>
#include<string>


void demoingSomeThings()
{
	//asdfasdfa

/*These are "keywords" (AKA:  reserved words)*/
//int char bool //these are "data types" 

//return case if while for  //PURPLE syntax highlighjting for these keywords 

/*
* asdfasdf
* asdf
* asdfasdf
* asdf
*
Here is a multi - line
	comment
This is a comment, comments are useful for "documentation" (among other things)
*/

//an example of a unary operator 
	int age = 12;

	if (!(age > 18)) //! (the "logical NOT" operator is "unary" 
	{
		std::cout << "You are not old enough to vote\n";
	}

	std::cout << 5 + 2; //arithmetic expression 
	//5 is an "operand" 
	// + is an "operator" (and it is a "binary" operator)


	//return 0;  //optional 
}

int main()
{
	/*code "snippets"*/

	/*some random (hopefully instructive) variable initializations*/
	const float PI = 3.14; //the decimal point can "float" 
	
	auto someNumber = 12;  //the SINGLE equals sign is called the "assignment operator" 

	auto someLetter = 'z'; //zed

	std::cout << "Enter your username:\n";
	//std::string userName; //this is called a variable DECLARATION 
	std::string userName = ""; //this is called the "empty string" 


	//std::cin >> userName;  //this means get character input
	//cin >> is ONE way to get user input from keyboard whilst program is running

	std::getline(std::cin, userName); 
	//std::getline(filename, userName); //this gets input from a file 


	std::cout << "You entered: " << userName << "\n";

	//int number1; 
	//int number2;
	//int number3 = number1 +number2;

	std::cout << "Art thou happy with this?\n"; 
	std::string happyResponse; 
	std::getline(std::cin, happyResponse);

	if (happyResponse == "no") //NOTE the double = sign! (this is the "equality" operator
	{
		std::cout << "RE-enter username\n";
		//overwrite the contents of the variable username: 
		std::getline(std::cin, userName);

		std::cout << "UPDATED user name to: " << userName << "\n";
	}


}

