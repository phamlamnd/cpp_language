#include <iostream>
#include <fstream>
#include <string>

#define _swap_(a,b)	\
{					\
	char t = a;		\
	a = b;			\
	b = t;			\
}					\

void sort(std::string s)
{
	for (int i = 0; i < 8; i += 2)
	{
		for (int j = 2; j < 10; j += 2)
		{
			if (s[i] <= '9' && s[j] <= '9')
			{
				if (s[i] > s[j])
				{
					_swap_(s[i], s[j]);
				}
			}
			else if (s[i] <= '9' && s[j] >= 'A')
			{
				if (s[i] > s[j])
				{
					_swap_(s[i], s[j]);
				}
			}
		}
	}
}

bool checkRoyalFlush(std::string Player1, std::string Player2)
{
	return true;
}

int main()
{
	std::ifstream fileIn("p054_poker.txt");
	std::string oneLine;
	
	//while (!fileIn.eof())
	{
		std::getline(fileIn, oneLine);
		int length = oneLine.length();
		for (int i = 0; i < length; i++)
		{
			if (' ' == oneLine[i])
			{
				oneLine.erase(oneLine.begin() + i);
				i--;
				length--;
			}
		}
		std::string Player1(&oneLine[0], 10);
		std::string Player2(&oneLine[10], 10);
		sort(Player1);
		sort(Player2);
		std::cout << Player1 << std::endl;
		std::cout << Player2 << std::endl;
		std::string s("Lam");
		s.
	}

	system("pause");
	return 0;
}