#include <iostream>
#include <sstream>

#include "StringSeparator.h"

#pragma region Cannibal Number Calculator

/*! \Function This will use the inputted string of numbers loop through them and if the current number is higher than the one being 
*				checked than it will be consumed, making the current number one (+ 1) higher and removing it from the list. 
*Param One: Vector<String> - The list of numbers to be checked and consumed. 
*Param Two: Int - The max number each cannibal can reach. 
*/
void l_CannibalNumbers(std::vector<std::string> numbers, int maxNumber)
{
	/*! \var This is the current number in the list being checked. */
	unsigned int l_uiCurrentNumberPos = 0; 

	/*! \var This will determine weather the loop should continue. */
	bool l_bLoop = true;

	/*! \var This is the running counter for the current loop, ensuring that an infinate loop doesn't occur. */
	int l_iLoopCounter = 0;

	do
	{
		/*! \var This will be used to convert between strings and integer types. */
		std::stringstream l_ssIntConverter;

		/*! \var This will be the current number of focus doing the consuming. */
		int l_iCurrentNumber;

		// Convert string from list into a local int value. 

		l_ssIntConverter << numbers[l_uiCurrentNumberPos];

		l_ssIntConverter >> l_iCurrentNumber;

		l_iLoopCounter++; 

		for (unsigned int i = 0; i < numbers.size(); i++)
		{
			if (i != l_uiCurrentNumberPos && i < numbers.size())
			{
				/*! \var This will be used to convert between string to int, allowing for this value to be consumed. */
				std::stringstream l_ssConsumerConverter; 

				/*! \var Local storage for the number to be consumed. */
				int l_iNumberToConsume;

				// Convert string to local int. 

				l_ssConsumerConverter << numbers[i];
				l_ssConsumerConverter >> l_iNumberToConsume; 

				// If the number is > (less than) the current number of focus it will be consumed and removed from the list. 

				if (l_iCurrentNumber > l_iNumberToConsume && l_iCurrentNumber < maxNumber)
				{
					// Debugging output to console. 

					std::cout << "Number " + std::to_string(l_iCurrentNumber) + " is consuming number " + std::to_string(l_iNumberToConsume) + " becoming " + std::to_string(l_iCurrentNumber + 1) << std::endl;

					// Increase number of focus's value. 

					l_iCurrentNumber++; 

					// Re-add it into the list at its origional position. 

					numbers[l_uiCurrentNumberPos] = std::to_string(l_iCurrentNumber); 

					// Remove the consumed number from the list and clear empty spaces. 

					numbers.erase(numbers.begin() + i); 

					numbers.shrink_to_fit(); 

					// Step back one number so none are missed after the resize. 

					i--;
				}
				else if (l_iCurrentNumber >= maxNumber)
				{
					break;
				}
			}
		}

		// If either the loop counter reaches a defined number or the number of focus hits the user defined maximum move onto 
		// the next number in the list. 

		if (l_iCurrentNumber >= maxNumber || l_iLoopCounter >= 5)
		{
			l_uiCurrentNumberPos++;

			l_iLoopCounter = 0; 
		}

		// If the current number of focus is greater than the size of the list the final number has been checked and thus the 
		// processing is complete and the loop should end. 

		if (l_uiCurrentNumberPos == numbers.size())
		{
			l_bLoop = false; 
		}

	} while (l_bLoop);

	// Debugging output the remaining numbers into the console. 

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
	/*! \var This will be the inputted list of numbers by the user upon startup. */
	std::string l_sInputTextListOfNumbers;

	/*! \var This is the max defined number each cannibal can reach. */
	std::string l_sInputTextMaxNumber;

    // Entry Point 

	std::cout << "Welcome to the cannibal number calulator. \n"; 
	std::cout << "Enter a set of numbers and a maximum value each canibal can reach. \n";
	std::cout << "Type your numbers in sequence seperated with a space. \n"; 

	// User Input 

	std::getline(std::cin, l_sInputTextListOfNumbers);

	/*! \var Class used to seperate string components. */
	StringSeparator l_StringTool; 

	/*! \var List used to hold the seperated numbers. */
	std::vector<std::string> l_ManipulatedString = l_StringTool.m_NumberSeperator(l_sInputTextListOfNumbers, ' ');

	std::cout << "\nNext We need to determie the max power each cannibal can reach. \n";
	std::cout << "Every Time a number consumes another it will increase in value by 1 but they may only eat numbers of lower value than themselves. \n"; 

	// User Input 

	std::cin >> l_sInputTextMaxNumber; 

	/*! \var This is the max number for passing into the calculation script. */
	int l_iMaxNumber; 

	/*! \var Used to convert between a string to an int. */
	std::stringstream l_ssIntConverter; 

	// String to Int conversion. 

	l_ssIntConverter << l_sInputTextMaxNumber;
	l_ssIntConverter >> l_iMaxNumber; 

	// Calculations made. 

	l_CannibalNumbers(l_ManipulatedString, l_iMaxNumber); 

}

