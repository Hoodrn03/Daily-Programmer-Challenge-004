#include "StringSeparator.h"

/*! \function This will be used to seperate a list of numbers in a string into a vector of different strings, a spacing identifier
*				is required to determine where to break the numbers apart.
*Param One: String - The full list of numbers which require seperating.
*Param Two: Char - The spacing identifier which will be used to determine the break between numbers, for example a space: ' '.
*/
std::vector<std::string> StringSeparator::m_NumberSeperator(std::string stringToSeperate, char spacingIdentifier)
{
	// Local Variables 

	/*! \var This will be the current element to be added into the list. */
	std::string l_sCurrentElementToAdd = "";

	/*! \var This is the return value from the function, this will contain all of the seperated characters. */
	std::vector<std::string> l_ReturnValue;

	// Processing

	for (unsigned int i = 0; i < stringToSeperate.size(); i++)
	{
		if (stringToSeperate.at(i) == spacingIdentifier)
		{
			l_ReturnValue.push_back(l_sCurrentElementToAdd);

			l_sCurrentElementToAdd = "";
		}
		else
		{
			l_sCurrentElementToAdd.push_back(stringToSeperate.at(i));
		}
	}

	// Debugging

	/*

	for (unsigned int j = 0; j <= l_ReturnValue.size(); j++)
	{
		std::cout << l_ReturnValue[j] << std::endl;
	}

	*/

	return l_ReturnValue;

}
