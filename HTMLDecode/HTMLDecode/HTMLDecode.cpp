// HTMLDecode.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void FindAndReplace(string &text, string const& oldText, string const& newText)
{
	int pos = text.find(oldText);
	while (pos != string::npos)
	{
		text.replace(pos, oldText.length(), newText);
		pos = text.find(oldText);
	}
}

string HtmlDecode(string const& html)
{
	static map<string, string> htmlChars = 
	{ 
		{ "&quot;", "\"" }, 
		{ "&apos;", "\'" }, 
		{ "&lt;", "<" },
		{ "&gt;", ">" },
		{ "&amp;", "&" }
	};

	string text(html);
	
	for (pair<string, string> pair : htmlChars)
	{
		FindAndReplace(text, pair.first, pair.second);
	}

	return move(text);
}

bool ReadStream(istream &stream, string &line)
{
	if (stream >> line)
	{
		return true;
	}
	return false;
	/*{
		return true;
	}
	return false;*/
}