#include "stdafx.h"
#include "../StringStack/StringStack.h"
#include <sstream>

using namespace std;

BOOST_AUTO_TEST_SUITE(String_stack)
	BOOST_AUTO_TEST_CASE(Destructor_doesnt_throw_any_exceptions)
	{
		CStringStack * stack = new CStringStack;
		stack->Push("one");
		stack->Push("two");
		stack->Push("three");
		BOOST_CHECK_NO_THROW(delete stack);

		CStringStack * emptyStack = new CStringStack;
		BOOST_CHECK_NO_THROW(delete emptyStack);
	}
	BOOST_AUTO_TEST_CASE(Push_and_pop)
	{
		string test1 = "test1";
		string test2 = "test2";

		CStringStack stack;
		BOOST_CHECK(stack.IsEmpty());

		stack.Push(test1);
		stack.Push(test2);
		BOOST_CHECK(!stack.IsEmpty());

		BOOST_CHECK_EQUAL(test2, stack.Pop());
		BOOST_CHECK_EQUAL(test1, stack.Pop());
		BOOST_CHECK(stack.IsEmpty());
	}
	BOOST_AUTO_TEST_CASE(Pop_from_empty_stack)
	{
		CStringStack stack;
		BOOST_CHECK_THROW(stack.Pop(), length_error);
	}
	BOOST_AUTO_TEST_CASE(Copy_constructor)
	{
		CStringStack s1;
		s1.Push("1");
		s1.Push("2");

		CStringStack s2(s1);
		BOOST_CHECK(s2.Pop().compare("2") == 0);
		BOOST_CHECK(s2.Pop().compare("1") == 0);
	}
BOOST_AUTO_TEST_SUITE_END()