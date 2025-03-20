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
	int m_size{ 0 };

public:
	~IntLinkedList();
	int size() const;
	void insertAtHead(int data);
	void insertAtTail(int data);
	void deleteIndex(int delIndex);
	int search(int element);
	void print() const;
	IntNode* getHead() const;
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
	~WeightedIntLinkedList();
	void insertAtHead(int vertex, int weight);
	void insertAtTail(int vertex, int weight);
	void remove(int vertex);
	int search(int vertex);
	void print() const;
	WeightedIntNode* getHead() const;
	int size() const;
};