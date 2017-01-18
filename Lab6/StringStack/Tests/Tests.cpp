#include "stdafx.h"
#include "../StringStack/StringStack.h"
#include <sstream>

using namespace std;

BOOST_AUTO_TEST_SUITE(String_stack)
	BOOST_AUTO_TEST_CASE(Destructor_doesnt_throw_exceptions)
	{
		CStringStack * stack = new CStringStack;
		stack->Push("one");
		stack->Push("two");
		stack->Push("three");
		BOOST_CHECK_NO_THROW(delete stack);

		CStringStack * emptyStack = new CStringStack;
		BOOST_CHECK_NO_THROW(delete emptyStack);
	}
	BOOST_AUTO_TEST_CASE(Push_and_pop_functions_work_correctly)
	{
		string test1 = "test1";
		string test2 = "test2";

		CStringStack stack;
		BOOST_CHECK(stack.IsEmpty());

		stack.Push(test1);
		stack.Push(test2);
		BOOST_CHECK(stack.GetSize() == 2);

		BOOST_CHECK_EQUAL(test2, stack.Pop());
		BOOST_CHECK_EQUAL(test1, stack.Pop());
		BOOST_CHECK(stack.IsEmpty());
	}
	BOOST_AUTO_TEST_CASE(Pop_from_empty_stack_throws_exception)
	{
		CStringStack stack;
		BOOST_CHECK(stack.IsEmpty());
		BOOST_CHECK_THROW(stack.Pop(), length_error);
	}
	BOOST_AUTO_TEST_CASE(Stack_can_be_cleared)
	{
		CStringStack stack;
		stack.Push("1");
		stack.Push("2");
		BOOST_CHECK(!stack.IsEmpty());
		stack.Clear();
		BOOST_CHECK(stack.IsEmpty());
	}
	BOOST_AUTO_TEST_CASE(Copy_constructor_works_correctly)
	{
		CStringStack s1;
		s1.Push("1");
		s1.Push("2");

		CStringStack s2(s1);
		BOOST_CHECK_EQUAL(s1.GetSize(), s2.GetSize());
		BOOST_CHECK_EQUAL(s2.Pop(), "2");
		BOOST_CHECK_EQUAL(s2.Pop(), "1");
	}
	BOOST_AUTO_TEST_CASE(Move_constructor_works_correctly)
	{
		CStringStack s1;
		s1.Push("1");
		s1.Push("2");

		CStringStack s2(move(s1));
		BOOST_CHECK_EQUAL(s2.Pop(), "2");
		BOOST_CHECK_EQUAL(s2.Pop(), "1");
		BOOST_CHECK(s1.IsEmpty());
	}
	BOOST_AUTO_TEST_CASE(Assignment_operator_works_correctly)
	{
		CStringStack s1;
		s1.Push("1");
		s1.Push("2");

		CStringStack s2;
		s2 = s1;

		BOOST_CHECK_EQUAL(s1.GetSize(), s2.GetSize());
		BOOST_CHECK_EQUAL(s2.Pop(), "2");
		BOOST_CHECK_EQUAL(s2.Pop(), "1");
	}
	BOOST_AUTO_TEST_CASE(Move_assignment_operator_works_correctly)
	{
		CStringStack s1;
		s1.Push("1");
		s1.Push("2");

		CStringStack s2;
		s2 = move(s1);

		BOOST_CHECK_EQUAL(s2.Pop(), "2");
		BOOST_CHECK_EQUAL(s2.Pop(), "1");
		BOOST_CHECK(s1.IsEmpty());
	}
BOOST_AUTO_TEST_SUITE_END()