#include "stdafx.h"
#include "../Dictionary/Dictionary.h"

#include <sstream>
#include <Windows.h>

using namespace std;

BOOST_AUTO_TEST_SUITE(dictionary)
	void InitDictionary(Dictionary &dictionary)
	{
		pair<string, string> firstPair("cat", "кот, кошка");
		pair<string, string> secondPair("ball", "м€ч");
		dictionary.insert(firstPair);
		dictionary.insert(secondPair);
	}

	BOOST_AUTO_TEST_CASE(Saving_and_reading)
	{
		Dictionary dictionary;
		InitDictionary(dictionary);

		ofstream out("dictionary.txt");
		SaveChanges(dictionary, out);
		out.close();

		dictionary.clear();

		ifstream in("dictionary.txt");
		ReadFromFile(dictionary, in);
		
		auto firstWord = dictionary.find("cat");
		auto secondWord = dictionary.find("ball");

		BOOST_CHECK(firstWord != dictionary.end());
		BOOST_CHECK(secondWord != dictionary.end());
		BOOST_CHECK(firstWord->second.compare("кот, кошка") == 0);
		BOOST_CHECK(secondWord->second.compare("м€ч") == 0);
	}
	BOOST_AUTO_TEST_CASE(User_input_handling)
	{
		Dictionary dictionary;
		bool dictionaryChanged = false;

		stringstream stream;
		stream << "кот, кошка";

		HandleUserInput("cat", dictionary, dictionaryChanged, stream);
		auto catWord = dictionary.find("cat");
		BOOST_CHECK(dictionaryChanged);
		BOOST_CHECK(dictionary.size() == 1);
		BOOST_CHECK(catWord != dictionary.end());
		BOOST_CHECK(catWord->second.compare("кот, кошка") == 0);
	}
	BOOST_AUTO_TEST_CASE(Interaction_loop)
	{
		Dictionary dictionary;
		bool dictionaryChanged = false;

		stringstream stream;
		stream << "cat\n" << "кот, кошка\n" << "ball\n" << "м€ч\n" << "...\n" << "Y";

		dictionaryChanged = InteractionLoop(dictionary, stream);

		auto catWord = dictionary.find("cat");
		auto ballWord = dictionary.find("ball");
		BOOST_CHECK(dictionaryChanged);
		BOOST_CHECK(dictionary.size() == 2);
		BOOST_CHECK(catWord != dictionary.end());
		BOOST_CHECK(ballWord != dictionary.end());
		BOOST_CHECK(catWord->second.compare("кот, кошка") == 0);
		BOOST_CHECK(ballWord->second.compare("м€ч") == 0);
	}
BOOST_AUTO_TEST_SUITE_END()