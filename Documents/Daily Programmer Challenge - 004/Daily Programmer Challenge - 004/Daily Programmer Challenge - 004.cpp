#include <iostream>
#include <sstream>

#include "StringSeparator.h"

#pragma region Cannibal Number Calculator

void l_CannibalNumbers(std::vector<std::string> numbers, int MaxNumber)
{

}

#pragma endregion

int main()
{
	std::string l_sInputTextListOfNumbers;

	std::string l_sInputTextMaxNumber;

    // Entry Point 

	std::cout << "Welcome to the cannibal number calulator. \n"; 
	std::cout << "Enter a set of numbers and a maximum value each canibal can reach. \n";
	std::cout << "Type your numbers in sequence seperated with a space. \n"; 

	std::getline(std::cin, l_sInputTextListOfNumbers);

	StringSeparator l_StringTool; 

	std::vector<std::string> l_ManipulatedString = l_StringTool.m_NumberSeperator(l_sInputTextListOfNumbers, ' ');

	std::cout << "\nNext We need to determie the max power each cannibal can reach. \n";
	std::cout << "Every Time a number consumes another it will increase in value by 1 but they may only eat numbers of lower value than themselves. \n"; 

	std::cin >> l_sInputTextMaxNumber; 

}

