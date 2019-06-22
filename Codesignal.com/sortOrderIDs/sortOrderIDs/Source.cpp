#include <iostream>
#include <string>
#include <vector>

/***************************************************************************
**Name: compare
**Func: Compare two string
**Input: std::string sA, std::string sB
**Return: true or false
****************************************************************************/
bool compare(std::string sA, std::string sB)
{
	//if two string have first character is letter
	if (sA[0] >= 'a' && sB[0] >= 'a')
	{
		return sA > sB;
	}
	//if one string have first character is letter, one string is digit
	else if (sA[0] >= 'a' && sB[0] <= '9')
	{
		return false;
	}
	//if two string have first character is digit
	else if (sA[0] <= '9' && sB[0] <= '9')
	{
		//if first digit is same
		if (sA[0] == sB[0])
		{
			return sA > sB;
		}
		//if first digit is difference
		return sA < sB;
	}
	//if one string have first character is digit, one string is letter
	else if (sA[0] <= '9' && sB[0] >= 'a')
	{
		return true;
	}
}


/***************************************************************************
**Name: sort
**Func: Sort vector function, element is string
**Input: std::vector<std::string> &docIDs
**Return: void
****************************************************************************/
void sort(std::vector<std::string> &docIDs)
{
	int nSize = docIDs.size();
	for (int i = 0; i < nSize - 1; i++)
	{
		for (int j = i + 1; j < nSize; j++)
		{
			if (compare(docIDs[i], docIDs[j]))
			{
				//swap element
				std::string tmp = docIDs[i];
				docIDs[i] = docIDs[j];
				docIDs[j] = tmp;
			}
		}
	}
}

/***************************************************************************
**Name: sortOrderIDs
**Func: Sort Order ID
**Input: std::vector<std::string> docIDs
**Return: std::vector<std::string>
****************************************************************************/
std::vector<std::string> sortOrderIDs(std::vector<std::string> docIDs)
{
	std::vector<std::string>::iterator docIdsIterrator = docIDs.begin();

	for (; docIdsIterrator != docIDs.end();)
	{
		int nLength = (*docIdsIterrator).length();
		//if "abXc" and "X123" invalid will remove element
		if ((('X' == (*docIdsIterrator)[0] && 'X' != (*docIdsIterrator)[nLength - 1]))
			|| ('X' != (*docIdsIterrator)[0] && 'X' == (*docIdsIterrator)[nLength - 1]))
		{
			//remove element
			docIdsIterrator = docIDs.erase(docIdsIterrator);
			continue;
		}
		//if "XabcX" erase X and check 
		else if ('X' == (*docIdsIterrator)[0] && 'X' == (*docIdsIterrator)[nLength - 1])
		{
			//if length >= 2
			if (nLength >= 2)
			{
				//remove end X
				(*docIdsIterrator).erase((*docIdsIterrator).begin() + nLength - 1);
			}
			//remove begin X
			(*docIdsIterrator).erase((*docIdsIterrator).begin());

			//update string length
			nLength = (*docIdsIterrator).length();

			//check inside string have number
			for (int i = 0; i < nLength; i++)
			{
				if ((*docIdsIterrator)[i] >= '1' && (*docIdsIterrator)[i] <= '9')
				{
					//erase all numbers in string
					(*docIdsIterrator).erase((*docIdsIterrator).begin() + i);
					nLength--;
				}
			}

			//if ID is empty or include X inside (ex: aXa)
			if ("" == (*docIdsIterrator) || ((*docIdsIterrator).find('X') != std::string::npos))
			{
				//remove element
				docIdsIterrator = docIDs.erase(docIdsIterrator);
				continue;
			}
		}

		//if include X inside (ex: aXa)
		else if ((*docIdsIterrator).find('X') != std::string::npos)
		{
			//remove element
			docIdsIterrator = docIDs.erase(docIdsIterrator);
			continue;
		}
		//next element
		docIdsIterrator++;
	}
	//sort function
	sort(docIDs);
	return docIDs;
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		std::string *s = new std::string("A");
	}
	system("pause");
	return 0;
}