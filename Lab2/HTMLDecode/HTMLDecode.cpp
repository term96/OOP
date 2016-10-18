// HTMLDecode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

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
	map<string, string>::iterator it;

	for (it = htmlChars.begin(); it != htmlChars.end(); ++it)
	{
		int pos = text.find(it->first);
		while (pos != string::npos)
		{
			text.replace(pos, it->first.length(), it->second);
			pos = text.find(it->first);
		}
	}

	return move(text);
}

int _tmain(int argc, _TCHAR* argv[])
{
	string line;
	while (!cin.eof())
	{
		getline(cin, line);
		cout << HtmlDecode(line) << '\n';
	}
	return 0;
}