#include <string>

/***************************************************************************
**Name: alphabeticShiftOne
**Func: Given a string, replace each its character by the next one
**Input: string
**Return: string
****************************************************************************/
std::string alphabeticShiftOne(std::string sInputString)
{
	int iLength = sInputString.length();
	for (int i = 0; i < iLength; i++)
	{
		if (sInputString[i] == 'z')
		{
			sInputString[i] = 'a';
		}
		else
		{
			sInputString[i] += 1;
		}
	}
	return sInputString;
}
