#include "stdafx.h"
#include "HTMLDecode.h"

#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string line;
	while (ReadStream(cin, line))
	{
		cout << HtmlDecode(line) << '\n';
	}
	return 0;
}