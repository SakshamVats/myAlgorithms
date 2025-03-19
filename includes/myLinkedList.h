#pragma once

#include <iostream>

struct IntNode
{
	int data{0};
	IntNode* next{ nullptr };
};

class IntLinkedList
{
private:
	IntNode* m_head{};
	int m_size{0};

public:
	~IntLinkedList()
	{
		while (m_head)
		{
			IntNode* temp = m_head;
			m_head = m_head->next;
			delete temp;
		}
	}

	int size() const
	{
		return m_size;
	}

	void insertAtHead(int data)
	{
		IntNode* head{ new IntNode{data} };

		head->next = m_head;
		m_head = head;

		++m_size;
	}

	void insertAtTail(int data)
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

	void deleteIndex(int delIndex)
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

	int search(int element)
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

	void print() const
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

	IntNode* getHead() const
	{
		return m_head;
	}
};

struct WeightedIntNode
{
	int vertex{ 0 };
	int weight{ 1 };
	WeightedIntNode* next{ nullptr };
};

class WeightedIntLinkedList
{
private:
	WeightedIntNode* m_head{};
	int m_size{ 0 };

public:
	~WeightedIntLinkedList()
	{
		while (m_head)
		{
			WeightedIntNode* temp{ m_head };
			m_head = m_head->next;
			delete temp;
		}
	}

	void insertAtHead(int vertex, int weight)
	{
		WeightedIntNode* newNode{ new WeightedIntNode{vertex, weight} };

		newNode->next = m_head;
		m_head = newNode;

		++m_size;
	}

	void insertAtTail(int vertex, int weight)
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

	void print() const
	{
		WeightedIntNode* curr{ m_head };

		while (curr)
		{
			std::cout << "(" << curr->vertex << ", " << curr->weight << ") -> ";
			curr = curr->next;
		}

		std::cout << "null\n";
	}

	WeightedIntNode* getHead() const
	{
		return m_head;
	}

	int size() const
	{
		return m_size;
	}
};