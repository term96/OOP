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
		string test = "test";
		CStringStack stack;
		BOOST_CHECK(stack.IsEmpty());

		stack.Push(test);
		BOOST_CHECK(!stack.IsEmpty());

		BOOST_CHECK_EQUAL(test, stack.Pop());
		BOOST_CHECK(stack.IsEmpty());
	}
	BOOST_AUTO_TEST_CASE(Pop_from_empty_stack)
	{
		CStringStack stack;
		BOOST_CHECK_THROW(stack.Pop(), out_of_range);
	}
BOOST_AUTO_TEST_SUITE_END()