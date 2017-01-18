#include "stdafx.h"
#include "StringStack.h"

#include <iostream>

using namespace std;

void CStringStack::Push(std::string const & data)
{
	Node * newNode = new Node(data);

	newNode->m_prev = m_top;
	m_top = newNode;
	++m_size;
}

std::string CStringStack::Pop()
{
	if (m_top == nullptr)
	{
		throw length_error("Stack is empty");
	}

	string data = move(m_top->m_data);
	Node * prev = m_top->m_prev;

	delete m_top;
	m_top = prev;
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

void CStringStack::Clear()
{
	Node * prev;
	while (m_top != nullptr)
	{
		prev = m_top->m_prev;
		delete m_top;
		m_top = prev;
	}
	m_size = 0;
}

CStringStack::CStringStack(CStringStack const & stack)
{
	try
	{
		if (!stack.IsEmpty())
		{
			Node * current = stack.m_top;
			m_top = new Node(current->m_data);
			current = current->m_prev;

			Node * bottom = m_top;
			while (current != nullptr)
			{
				bottom->m_prev = new Node(current->m_data);
				bottom = bottom->m_prev;
				current = current->m_prev;
			}
		}
		m_size = stack.m_size;
	}
	catch (...)
	{
		Clear();
		throw;
	}
}

CStringStack::CStringStack(CStringStack && stack)
{
	*this = move(stack);
}

void CStringStack::operator=(CStringStack const & stack)
{
	CStringStack * newStack = new CStringStack(stack);
	*this = move(*newStack);
	delete newStack;
}

void CStringStack::operator=(CStringStack && stack)
{
	m_top = stack.m_top;
	m_size = stack.m_size;
	stack.m_top = nullptr;
	stack.m_size = 0;
}

CStringStack::~CStringStack()
{
	Clear();
}