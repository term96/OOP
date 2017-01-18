#pragma once

#include <string>

class CStringStack
{
public:
	void Push(std::string const & data);
	std::string Pop();
	bool IsEmpty() const;
	size_t GetSize() const;
	void Clear();

	CStringStack() = default;
	CStringStack(CStringStack const & stack);
	CStringStack(CStringStack && stack);
	~CStringStack();

	CStringStack & operator=(CStringStack const & stack);
	CStringStack & operator=(CStringStack && stack);
private:
	struct Node
	{
		Node(std::string data)
			:m_data(move(data))
		{
		}

		std::string m_data;
		Node * m_prev = nullptr;
	};
	
	Node * m_top = nullptr;
	size_t m_size = 0;
};

