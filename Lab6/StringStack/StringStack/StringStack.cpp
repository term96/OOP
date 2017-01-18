#include "stdafx.h"
#include "StringStack.h"

#include <iostream>

using namespace std;

void CStringStack::Push(std::string const & data)
{
	Node * newNode = new Node(data);

	newNode->m_prev = m_back;
	m_back = newNode;
	++m_size;
}

std::string CStringStack::Pop()
{
	if (m_back == nullptr)
	{
		throw length_error("Stack is empty");
	}

	string data = move(m_back->m_data);
	Node * prev = m_back->m_prev;

	delete(m_back);
	m_back = prev;
	--m_size;

	return move(data);
}

bool CStringStack::IsEmpty() const
{
	return m_size == 0;
}

size_t CStringStack::GetSize() const
{
	return m_size;
}

void CStringStack::Delete(Node * node)
{
	Node * current = node;
	Node * prev;

	while (current != nullptr)
	{
		prev = current->m_prev;
		delete current;
		current = prev;
	}
}

CStringStack::CStringStack(CStringStack const & stack)
{
	try
	{
		Node * current = stack.m_back;
		m_back = new Node(current->m_data);
		current = current->m_prev;

		Node * first = m_back;
		while (current != nullptr)
		{
			first->m_prev = new Node(current->m_data);
			first = first->m_prev;
			current = current->m_prev;
		}
		m_size = stack.m_size;
	}
	catch (...)
	{
		Delete(m_back);
	}
}

CStringStack::CStringStack(CStringStack && stack)
{
	*this = move(stack);
}

void CStringStack::operator=(CStringStack const & stack)
{
	CStringStack * newStack = new CStringStack(stack);
	m_back = newStack->m_back;
	m_size = newStack->m_size;
	newStack->m_back = nullptr;
	delete newStack;
}

void CStringStack::operator=(CStringStack && stack)
{
	m_back = stack.m_back;
	m_size = stack.m_size;
	stack.m_back = nullptr;
	stack.m_size = 0;
}

CStringStack::~CStringStack()
{
	Delete(m_back);
}