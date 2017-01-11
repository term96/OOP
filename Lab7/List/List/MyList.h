#pragma once
#include <iterator>

template <typename T>

class CMyList
{
private:
	struct Node
	{
		Node(T const & arg)
		{
			data = arg;
		}
		T data;
		Node * prev;
		Node * next;
	};

	size_t m_size;
	typename CMyList::Node * m_front;
	typename CMyList::Node * m_back;
public:
	class CIterator
		: public std::iterator<std::input_iterator_tag, T>
	{
	public:
		friend CMyList;
		CIterator(Node * current)
		{
			m_current = current;
		}
		CIterator(CIterator const & iter)
		{
			m_current = iter.m_current;
		}
		bool operator!=(CIterator & iter)
		{
			return m_current != iter.m_current;
		}
		CIterator & operator++()
		{
			m_current = m_current->next;
			return *this;
		}
		CIterator & operator++(int)
		{
			m_current = m_current->next;
			return *this;
		}
		T& operator*()
		{
			return m_current->data;
		}

	private:
		Node * m_current;
	};

	class CReverseIterator
		: public std::iterator<std::input_iterator_tag, T>
	{
	public:
		friend CMyList;
		CReverseIterator(Node * current)
		{
			m_current = current;
		}
		CReverseIterator(CReverseIterator const & iter)
		{
			m_current = iter.m_current;
		}
		bool operator!=(CReverseIterator & iter)
		{
			return m_current != iter.m_current;
		}
		CReverseIterator & operator++()
		{
			m_current = m_current->prev;
			return *this;
		}
		CReverseIterator & operator++(int)
		{
			m_current = m_current->prev;
			return *this;
		}
		T& operator*()
		{
			return m_current->data;
		}

	private:
		Node * m_current;
	};

	CMyList();
	~CMyList();

	void PushFront(T const & data);
	void PushBack(T const & data);
	void Delete(typename CMyList::CIterator const & iterator);
	void Delete(typename CMyList::CReverseIterator const & iterator);
	size_t GetSize() const;

	typename CMyList::CIterator begin();
	typename CMyList::CIterator end();
	typename CMyList::CReverseIterator rbegin();
	typename CMyList::CReverseIterator rend();
};

template<typename T>
CMyList<T>::CMyList()
{
	m_size = 0;
	m_front = nullptr;
	m_back = nullptr;
}

template<typename T>
CMyList<T>::~CMyList()
{
	// TO DO
}

template<typename T>
void CMyList<T>::PushFront(T const & data)
{
	Node * newNode = new Node(data);
	newNode->next = m_front;
	
	if (m_front != nullptr)
	{
		m_front->prev = newNode;
	}
	m_front = newNode;

	++m_size;
}

template<typename T>
void CMyList<T>::PushBack(T const & data)
{
	Node * newNode = new Node(data);
	newNode->next = nullptr;
	
	newNode->prev = m_back;

	if (m_back != nullptr)
	{
		m_back->next = newNode;
	}
	m_back = newNode;

	if (m_front == nullptr)
	{
		m_front = newNode;
	}

	++m_size;
}

template<typename T>
void CMyList<T>::Delete(typename CMyList::CIterator const & iterator)
{
	if (current == nullptr)
	{
		throw std::length_error("Position is out of range");
	}

	// TO DO
}

template<typename T>
void CMyList<T>::Delete(typename CMyList::CReverseIterator const & iterator)
{
}

template<typename T>
size_t CMyList<T>::GetSize() const
{
	return m_size;
}

template<typename T>
typename CMyList<T>::CIterator CMyList<T>::begin()
{
	return CIterator(m_front);
}

template<typename T>
typename CMyList<T>::CIterator CMyList<T>::end()
{
	return CIterator(nullptr);
}

template<typename T>
typename CMyList<T>::CReverseIterator CMyList<T>::rbegin()
{
	return CReverseIterator(m_back);
}

template<typename T>
typename CMyList<T>::CReverseIterator CMyList<T>::rend()
{
	return CReverseIterator(nullptr);
}