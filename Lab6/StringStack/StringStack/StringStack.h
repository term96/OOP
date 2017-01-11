#pragma once

#include "Node.h"
#include <string>

class CStringStack
{
public:
	void Push(std::string const & data);
	std::string Pop();
	bool IsEmpty() const;

	CStringStack() = default;
	CStringStack(CStringStack const & stack);
	~CStringStack();

	void operator=(CStringStack const &) = delete;
private:
	void Delete(CNode * node);
	CNode * m_first = nullptr;
};

