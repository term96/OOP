#include "stdafx.h"
#include "Car.h"
#include "VirtualCar.h"

#include <iostream>
#include "Windows.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	CVirtualCar virtualCar;
	virtualCar.HandleUserCommands(cin, cout);
    return 0;
}

