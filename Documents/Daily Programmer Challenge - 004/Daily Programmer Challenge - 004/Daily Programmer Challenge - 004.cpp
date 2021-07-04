#include <iostream>
#include <sstream>

#include "StringSeparator.h"

#pragma region Cannibal Number Calculator

void l_CannibalNumbers(std::vector<std::string> numbers, int maxNumber)
{

	unsigned int l_uiCurrentNumberPos = 0; 

	bool l_bLoop = true;

	int l_iLoopCounter = 0;

	do
	{
		std::stringstream l_ssIntConverter;

		int l_iCurrentNumber;

		l_ssIntConverter << numbers[l_uiCurrentNumberPos];

		l_ssIntConverter >> l_iCurrentNumber;

		l_iLoopCounter++; 

		for (unsigned int i = 0; i < numbers.size(); i++)
		{
			if (i != l_uiCurrentNumberPos)
			{
				std::stringstream l_ssConsumerConverter; 

				int l_iNumberToConsume;

				l_ssConsumerConverter << numbers[i];
				l_ssConsumerConverter >> l_iNumberToConsume; 

				if (l_iCurrentNumber > l_iNumberToConsume && l_iCurrentNumber < maxNumber)
				{
					std::cout << "Number " + std::to_string(l_iCurrentNumber) + " is consuming number " + std::to_string(l_iNumberToConsume) + " becoming " + std::to_string(l_iCurrentNumber + 1) << std::endl;

					l_iCurrentNumber++; 

					numbers[l_uiCurrentNumberPos] = std::to_string(l_iCurrentNumber); 

					numbers.erase(numbers.begin() + i); 

					numbers.shrink_to_fit(); 
				}
			}
		}

		if (l_iCurrentNumber >= maxNumber || l_iLoopCounter >= 5)
		{
			l_uiCurrentNumberPos++;

			l_iLoopCounter = 0; 
		}

		if (l_uiCurrentNumberPos > numbers.size())
		{
			l_bLoop = false; 
		}

	} while (l_bLoop);


	std::cout << "The Remaning numbers are : "; 

	for (int j = 0; j < numbers.size(); j++)
	{
		std::cout << numbers[j] + " "; 
	}

	std::cout << std::endl;

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

	int l_iMaxNumber; 
	std::stringstream l_ssIntConverter; 

	l_ssIntConverter << l_sInputTextMaxNumber;
	l_ssIntConverter >> l_iMaxNumber; 

	l_CannibalNumbers(l_ManipulatedString, l_iMaxNumber); 

}

