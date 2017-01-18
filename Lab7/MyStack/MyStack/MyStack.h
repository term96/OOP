#pragma once

#include <string>

template <typename T>
class CMyStack
{
public:
	void Push(T const & data);
	T Pop();
	T GetTop() const;
	bool IsEmpty() const;
	size_t GetSize() const;
	void Clear();

	CMyStack() = default;
	CMyStack(CMyStack const & stack);
	CMyStack(CMyStack && stack);
	~CMyStack();

	CMyStack & operator=(CMyStack const & stack);
	CMyStack & operator=(CMyStack && stack);
private:
	struct Node
	{
		Node(T const & data, Node * prev = nullptr)
			:m_data(data)
			,m_prev(prev)
		{
		}

		T m_data;
		Node * m_prev;
	};

	Node * m_top = nullptr;
	size_t m_size = 0;
};

template<typename T>
inline void CMyStack<T>::Push(T const & data)
{
	Node * newNode = new Node(data, m_top);

	m_top = newNode;
	++m_size;
}

template<typename T>
inline T CMyStack<T>::Pop()
{
	if (m_top == nullptr)
	{
		throw length_error("Stack is empty");
	}

	T data = m_top->m_data;
	Node * prev = m_top->m_prev;

	delete m_top;
	m_top = prev;
	--m_size;

	return move(data);
}

template<typename T>
inline T CMyStack<T>::GetTop() const
{
	return m_top->m_data;
}

template<typename T>
inline bool CMyStack<T>::IsEmpty() const
{
	return m_size == 0;
}

template<typename T>
inline size_t CMyStack<T>::GetSize() const
{
	return m_size;
}

template<typename T>
inline void CMyStack<T>::Clear()
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

template<typename T>
inline CMyStack<T>::CMyStack(CMyStack const & stack)
{
	if (!stack.IsEmpty())
	{
		Node * current = stack.m_top;
		Node * back = nullptr;

		try 
		{
			while (current != nullptr)
			{
				if (back != nullptr)
				{
					back->m_prev = new Node(current->m_data);
					back = back->m_prev;
				}
				else
				{
					m_top = new Node(current->m_data);
					back = m_top;
				}
				current = current->m_prev;
			}
			m_size = stack.m_size;
		}
		catch (...)
		{
			Clear();
			throw;
		}
	}
}

template<typename T>
inline CMyStack<T>::CMyStack(CMyStack && stack)
{
	*this = move(stack);
}

template<typename T>
inline CMyStack<T> & CMyStack<T>::operator=(CMyStack<T> const & stack)
{
	if (m_top == stack.m_top)
	{
		return *this;
	}
	CMyStack<T> newStack(stack);
	Clear();
	*this = move(newStack);
	return *this;
}

template<typename T>
inline CMyStack<T> & CMyStack<T>::operator=(CMyStack<T> && stack)
{
	if (m_top == stack.m_top)
	{
		return *this;
	}
	Clear();
	m_top = stack.m_top;
	m_size = stack.m_size;
	stack.m_top = nullptr;
	stack.m_size = 0;
	return *this;
}

template<typename T>
inline CMyStack<T>::~CMyStack()
{
	Clear();
}