#include "stdafx.h"
#include "StringStack.h"

using namespace std;

void CStringStack::Push(std::string const & data)
{
	CNode * newNode = new CNode(data);

	if (m_first == nullptr)
	{
		m_first = newNode;
		return;
	}

	CNode * current = m_first;
	while (current->m_next != nullptr)
	{
		current = current->m_next;
	}
	current->m_next = newNode;
}

std::string CStringStack::Pop()
{
	if (m_first == nullptr)
	{
		throw length_error("Stack is empty");
	}

	CNode * current = m_first;
	CNode * previous = nullptr;

	while (current->m_next != nullptr)
	{
		previous = current;
		current = current->m_next;
	}
	
	string data = current->m_data;
	delete current;

	if (previous == nullptr)
	{
		m_first = nullptr;
	}
	else
	{
		previous->m_next = nullptr;
	}

	return move(data);
}

bool CStringStack::IsEmpty() const
{
	return m_first == nullptr;
}

void CStringStack::Delete(CNode * node)
{
	if (node == nullptr)
	{
		return;
	}

	if (node->m_next != nullptr)
	{
		Delete(node->m_next);
	}
	delete node;
}


CStringStack::CStringStack(CStringStack const & stack)
try
{
	CNode * current = stack.m_first;
	while (current != nullptr)
	{
		Push(current->m_data);
		current = current->m_next;
	}
}
catch (...)
{
	Delete(m_first);
	throw;
}

CStringStack::~CStringStack()
{
	Delete(m_first);
}