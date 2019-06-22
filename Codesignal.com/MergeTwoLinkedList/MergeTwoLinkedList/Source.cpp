// Definition for singly-linked list:
 template<typename T>
 struct ListNode {
   ListNode(const T &v) : value(v), next(nullptr) {}
   T value;
   ListNode *next;
 };

ListNode<int> * mergeTwoLinkLists(ListNode<int> *l1, ListNode<int> *l2)
{
	ListNode<int> *pHead = nullptr;
	ListNode<int> *pTail = nullptr;
	ListNode<int> *newNode = nullptr;
	while (l1 != nullptr || l2 != nullptr)
	{
		if (l1 != nullptr && l2 != nullptr)
		{
			if (l1->value <= l2->value)
			{
				newNode = new ListNode<int>(l1->value);
				l1 = l1->next;
			}
			else // if (l1->value > l2->value)
			{
				newNode = new ListNode<int>(l2->value);
				l2 = l2->next;
			}
		}
		else if (l1 != nullptr && l2 == nullptr)
		{
			newNode = new ListNode<int>(l1->value);
			l1 = l1->next;
		}
		else if ((l1 == nullptr && l2 != nullptr))
		{
			newNode = new ListNode<int>(l2->value);
			l2 = l2->next;
		}

		//add to linked list
		if (pHead == nullptr)
		{
			pHead = pTail = newNode;
		}
		else
		{
			pTail->next = newNode;
			pTail = newNode;
		}
	}
	return pHead;
}

int main() 
{
	return 0;
}