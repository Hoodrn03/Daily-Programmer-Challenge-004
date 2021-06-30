#include "StringSeparator.h"

std::vector<std::string> StringSeparator::m_NumberSeperator(std::string stringToSeperate, char spacingIdentifier)
{
	// Local Variables 

	std::string l_sCurrentElementToAdd = "";

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
