#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#ifndef NULL
#define NULL 0
#endif

template <class T>
class LinkedList
{
private:
	class Node;

public:
	LinkedList();
	~LinkedList();
	class Iterator;
	Iterator begin();
	Iterator end();
	void push_back(T data);
	void pop_back();

	class Iterator
	{
	public:
		Iterator();
		Iterator(const Node *pNode);
		Iterator& operator=(const Iterator& iterator);
		Iterator& operator++();
		Iterator operator++(int);
		bool operator==(const Iterator& iterator);
		bool operator!=(const Iterator& iterator);
		T operator*();
	private:
		const Node *m_pCurrentNode;
	};

private:
	class Node
	{
	private:
		T data;
		Node *pNext;
		friend class LinkedList<T>;
	};

	Node* createNode(T data);
	bool _Greater(T &lhs, T &rhs);
	bool _Less(T &lhs, T &rhs);

	Node *m_spRoot;
};

template <class T>
LinkedList<T>::LinkedList() : m_spRoot(NULL)
{
}

template <class T>
LinkedList<T>::~LinkedList()
{
	Node *pCurrentNode = m_spRoot;
	Node *pTemp = NULL;
	while (pCurrentNode)
	{
		pTemp = pCurrentNode->pNext;
		delete pCurrentNode;
		pCurrentNode = pTemp;
	}
	m_spRoot = NULL;
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::begin()
{
	return m_spRoot;
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::end()
{
	return NULL;
}

template <class T>
void LinkedList<T>::push_back(T data)
{
	Node *pNode = createNode(data);
	if (!m_spRoot)
	{
		m_spRoot = pNode;
	}
	else
	{
		Node *pTail = m_spRoot;
		while (pTail->pNext)
		{
			pTail = pTail->pNext;
		}
		pTail->pNext = pNode;
	}
}

template <class T>
void LinkedList<T>::pop_back()
{
	if (!m_spRoot)
	{
		return;
	}
	Node *pTail = m_spRoot;
	Node *pPreTail = m_spRoot;
	while (pTail->pNext)
	{
		pPreTail = pTail;
		pTail = pTail->pNext;
	}
	delete pTail;
	pPreTail->pNext = NULL;
}

template <class T>
LinkedList<T>::Iterator::Iterator() : m_pCurrentNode(NULL)
{
}

template <class T>
LinkedList<T>::Iterator::Iterator(const Node *pNode) : m_pCurrentNode(pNode)
{
}

template <class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
	this->m_pCurrentNode = iterator->m_pCurrentNode;
	return *this;
}

template <class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++()
{
	if (m_pCurrentNode)
	{
		m_pCurrentNode = m_pCurrentNode->pNext;
	}
	return *this;
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int)
{
	Iterator iterator = *this;
	++(*this);
	return iterator;
}

template <class T>
bool LinkedList<T>::Iterator::operator==(const LinkedList<T>::Iterator& iterator)
{
	return (this->m_pCurrentNode == iterator.m_pCurrentNode);
}

template <class T>
bool LinkedList<T>::Iterator::operator!=(const LinkedList<T>::Iterator& iterator)
{
	return !(this->m_pCurrentNode == iterator.m_pCurrentNode);
}

template <class T>
T LinkedList<T>::Iterator::operator*()
{
	return m_pCurrentNode->data;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::createNode(T data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->pNext = NULL;
	return newNode;
}

template <class T>
bool LinkedList<T>::_Greater(T &lhs, T &rhs)
{
	return (lhs > rhs);
}

template <class T>
bool LinkedList<T>::_Less(T &lhs, T &rhs)
{
	return (lhs < rhs);
}

#endif /*_LINKED_LIST_H_*/