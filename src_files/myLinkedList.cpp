#include "../includes/myLinkedList.h"

IntLinkedList::~IntLinkedList()
{
	while (m_head)
	{
		IntNode* temp = m_head;
		m_head = m_head->next;
		delete temp;
	}
}

int IntLinkedList::size() const
{
	return m_size;
}

void IntLinkedList::insertAtHead(int data)
{
	IntNode* head{ new IntNode{data} };

	head->next = m_head;
	m_head = head;

	++m_size;
}

void IntLinkedList::insertAtTail(int data)
{
	IntNode* tail{ new IntNode{data} };

	if (!m_size)
	{
		m_head = tail;
		++m_size;
		return;
	}

	IntNode* curr{ m_head };

	for (int index{ 0 }; index < m_size - 1; ++index)
	{
		curr = curr->next;
	}

	curr->next = tail;
	++m_size;
}

void IntLinkedList::deleteIndex(int delIndex)
{
	if (delIndex < 0)
	{
		std::cout << "Delete index must be non-negative!\n";
		return;
	}

	if (delIndex == 0)
	{
		m_head = m_head->next;
		--m_size;
		return;
	}

	if (delIndex >= m_size)
	{
		std::cout << "Delete index is more than linked list size!\n";
		return;
	}

	IntNode* curr{ m_head };

	for (int index{ 0 }; index < delIndex - 1; ++index)
	{
		curr = curr->next;
	}

	curr->next = curr->next->next;
	--m_size;
}

int IntLinkedList::search(int element)
{
	IntNode* curr = m_head;

	for (int index{ 0 }; index < m_size; ++index)
	{
		if (curr->data == element)
			return index;

		curr = curr->next;
	}

	return -1;
}

void IntLinkedList::print() const
{
	if (!m_size)
	{
		std::cout << "Linked List is empty!\n";
		return;
	}

	IntNode* curr{ m_head };

	for (int index{ 0 }; index < m_size; ++index)
	{
		std::cout << curr->data << "->";
		curr = curr->next;
	}

	std::cout << "null\n";
}

IntNode* IntLinkedList::getHead() const
{
	return m_head;
}

WeightedIntLinkedList::~WeightedIntLinkedList()
{
	while (m_head)
	{
		WeightedIntNode* temp{ m_head };
		m_head = m_head->next;
		delete temp;
	}
}

void WeightedIntLinkedList::insertAtHead(int vertex, int weight)
{
	WeightedIntNode* newNode{ new WeightedIntNode{vertex, weight} };

	newNode->next = m_head;
	m_head = newNode;

	++m_size;
}

void WeightedIntLinkedList::insertAtTail(int vertex, int weight)
{
	WeightedIntNode* newNode{ new WeightedIntNode{vertex, weight} };

	if (!m_head)
	{
		m_head = newNode;
		++m_size;
		return;
	}

	WeightedIntNode* curr{ m_head };

	while (curr->next)
	{
		curr = curr->next;
	}

	curr->next = newNode;
	++m_size;
}

void WeightedIntLinkedList::remove(int vertex)
{
	WeightedIntNode* curr{ m_head };
	WeightedIntNode* prev{ nullptr };

	while (curr)
	{
		if (curr->vertex == vertex)
		{
			if (prev)
				prev->next = curr->next;

			else
				m_head = curr->next;

			delete curr;
			--m_size;

			return;
		}

		prev = curr;
		curr = curr->next;
	}
}

int WeightedIntLinkedList::search(int vertex)
{
	WeightedIntNode* curr{ m_head };
	while (curr)
	{
		if (curr->vertex == vertex)
			return curr->weight;

		curr = curr->next;
	}

	return -1;
}

void WeightedIntLinkedList::print() const
{
	WeightedIntNode* curr{ m_head };

	while (curr)
	{
		std::cout << "(" << curr->vertex << ", " << curr->weight << ") -> ";
		curr = curr->next;
	}

	std::cout << "null\n";
}

WeightedIntNode* WeightedIntLinkedList::getHead() const
{
	return m_head;
}

int WeightedIntLinkedList::size() const
{
	return m_size;
}
