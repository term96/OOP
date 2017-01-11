#pragma once

#include "Node.h"
#include <string>

class CStringStack
{
public:
	void Push(std::string const & data);
	std::string Pop();
	bool IsEmpty() const;

	~CStringStack();
private:
	void Delete(CNode * node);
	CNode * m_first = nullptr;
};

