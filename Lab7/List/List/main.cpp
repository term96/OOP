#include "stdafx.h"
#include "MyList.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	CMyList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	
	cout << "Size: " << list.GetSize() << "\n";
	for (auto iter = list.begin(); iter != list.end(); ++iter)
	{
		cout << *iter << " ";
	}

	cout << "\n";

	for (auto iter = list.rbegin(); iter != list.rend(); ++iter)
	{
		cout << *iter << " ";
	}
    return 0;
}

