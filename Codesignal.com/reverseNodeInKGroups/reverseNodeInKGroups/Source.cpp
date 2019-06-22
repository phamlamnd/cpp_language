// Definition for singly-linked list:
 template<typename T>
 struct ListNode {
   ListNode(const T &v) : value(v), next(nullptr) {}
   T value;
   ListNode *next;
 };

ListNode<int> * reverseNodeInKGroups(ListNode<int> * l, int k)
{
	if (k == 1) /* if k == 1 */
	{
		return l;
	}
	ListNode<int> *pFront = l;				/* front node in group */
	ListNode<int> *pBack = l;				/* back node in group */
	ListNode<int> *pPrev = nullptr;			/* prev node */
	ListNode<int> *pCurr = nullptr;			/* current node */
	ListNode<int> *pNext = nullptr;			/* next node */
	ListNode<int> *pNextGroup = nullptr;	/* next group node */
	ListNode<int> *pPrevGroup = nullptr;	/* prev group node */
	int loop = k;
	while (pFront != nullptr && pBack != nullptr)
	{
		loop = k;
		while (loop > 1 && pBack->next != nullptr)
		{
			loop--;
			pBack = pBack->next;		/* find back node */
		}

		if (loop > 1)					/*if group not enough element -> break */
		{
			break;
		}
		else if (loop == 1)				/* if enough element */
		{
			if (l == pFront)			/* if group is first */
			{
				l = pBack;				/* update list l */
			}
			pNextGroup = pBack->next;	/* save next group*/
			pPrev = pNextGroup;         /* prev = next group*/
			pCurr = pFront;             /* current = front node*/
			while (pCurr != pNextGroup) /* pPrev->pCurr->pNext */
			{
				pNext = pCurr->next;    /* save next node */
				pCurr->next = pPrev;    /* connect current node to prev node */
				pPrev = pCurr;		    /* prev node = current node */
				pCurr = pNext;		    /* current node = next node */
			}
			if (pPrevGroup != nullptr)	/* if prev group exist*/
			{
				pPrevGroup->next = pBack; /* connect prev group to current group*/
			}
			pPrevGroup = pFront;		/* save prev group node */
			pFront = pNextGroup;		/* init new group for pFront */
			pBack = pNextGroup;			/* init new group for pBack */
		}
	}
	//return ListNode
	return l;
}