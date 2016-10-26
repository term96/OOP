#include "stdafx.h"
#include "../Dictionary/Dictionary.h"

#include <sstream>

using namespace std;

BOOST_AUTO_TEST_SUITE(dictionary)
	Dictionary dictionary;
	BOOST_AUTO_TEST_CASE(Reading_from_stream)
	{
		ofstream out("dictionary.txt");
		out << "cat\n" << "кот, кошка\n" << "ball\n" << "м€ч\n";
		out.close();
		ifstream in("dictionary.txt");
		ReadFromFile(dictionary, in);
		auto firstWord = dictionary.find("cat");
		auto secondWord = dictionary.find("ball");

		cout << "1: " << dictionary.at()

		BOOST_CHECK(firstWord != dictionary.end());
		BOOST_CHECK(secondWord != dictionary.end());
		BOOST_CHECK(firstWord->second.compare("кот, кошка") == 0);
		BOOST_CHECK(secondWord->second.compare("м€ч") == 0);
	}
	BOOST_AUTO_TEST_CASE(Saving_changes)
	{
		ofstream out("dictionary.txt");
		SaveChanges(dictionary, out);
		out.close();

		/*ifstream in("dictionary.txt");
		string line;
		getline(in, line);
		cout << ":" << line << ":\n";
		BOOST_CHECK(line.compare("cat") == 0);*/
	}
BOOST_AUTO_TEST_SUITE_END()