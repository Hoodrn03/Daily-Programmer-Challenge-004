#pragma once

#include <iostream>
#include <vector>

class StringSeparator
{

#pragma region Data Members

#pragma endregion

#pragma region Member Functions

public:

	/*! \function This will be used to seperate a list of numbers in a string into a vector of different strings, a spacing identifier 
	*				is required to determine where to break the numbers apart. 
	*Param One: String - The full list of numbers which require seperating. 
	*Param Two: Char - The spacing identifier which will be used to determine the break between numbers, for example a space: ' '. 
	*/
	std::vector<std::string> m_NumberSeperator(std::string stringToSeperate, char spacingIdentifier);

#pragma endregion

};