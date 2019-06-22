#include <vector>
#include <string>

std::vector<int> findBottomNode(std::string tree)
{
	std::vector<int> _stack;
	std::vector<int> result;
	int nMaxDepth = 0;		/* init nMaxDepth */
	int nCountDepth = 0;	/* init nCountDepth */
	int nLength = tree.length();
	for (int i = 0; i < nLength; i++)
	{
		// if '('
		if (tree[i] == '(')
		{
			std::string sNumber = "";
			while (tree[i + 1] >= '0' && tree[i + 1] <= '9')
			{
				sNumber += tree[i + 1];
				i++;
			}
			if (sNumber != "")
			{
				int x = std::stoi(sNumber);		/* change string to integer */
				nCountDepth++;					/* count depth */
				// if nCountDepth > nMaxDepth
				if (nCountDepth > nMaxDepth)	
				{
					nMaxDepth = nCountDepth;	/* update nMaxDepth */
					result.clear();				/* clear result */
				}
				_stack.push_back(x);			/* push to stack */
			}
		}
		// if ')'
		else if (tree[i] == ')' && tree[i - 1] != '(')
		{
			// if nCountDepth == nMaxDepth
			if (nCountDepth == nMaxDepth)
			{
				result.push_back(_stack[_stack.size() - 1]);	/* push top of stack to result*/
			}
			nCountDepth--;		/* decrease nCountDepth */
			_stack.pop_back();	/* remove top of stack */
		}
	}
	return result;
}

int main()
{
	std::string tree{ "(1 () (2 () (3 () (5 () (8 () (13 () (21 () (34 () ()))))))))" };
	std::vector<int> re = findBottomNode(tree);
	system("pause");
	return 0;
}