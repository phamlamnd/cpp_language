// Definition for singly-linked list:
 template<typename T>
 struct ListNode {
   ListNode(const T &v) : value(v), next(nullptr) {}
   T value;
   ListNode *next;
 };

ListNode<int> * removeValueFromList(ListNode<int> *l, int k)
{
	ListNode<int> *pPrev = l; //prev->curr->next
	ListNode<int> *pNext = l;
	ListNode<int> *pCurr = l;
	while (pCurr != nullptr)
	{
		if (pCurr->value == k)
		{
			pNext = pCurr->next;
			if (l == pCurr)
			{
				l = pNext;
			}
			else
			{
				pPrev->next = pNext;
			}
			delete pCurr;
			pCurr = pNext;
		}
		else
		{
			pPrev = pCurr;
			pCurr = pCurr->next;
		}
	}
	return l;
}
