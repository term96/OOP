#pragma once

#include <string>

class CNode
{
public:
	CNode(std::string const & data);
	std::string m_data;
	CNode * m_next = nullptr;
};

