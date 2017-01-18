#include "stdafx.h"
#include "../MyStack/MyStack.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(MyStack)
	BOOST_AUTO_TEST_SUITE(String_stack)
		BOOST_AUTO_TEST_CASE(Destructor_doesnt_throw_exceptions)
		{
			CMyStack<string> * stack = new CMyStack<string>;
			stack->Push("one");
			stack->Push("two");
			stack->Push("three");
			BOOST_CHECK_NO_THROW(delete stack);

			CMyStack<string> * emptyStack = new CMyStack<string>;
			BOOST_CHECK_NO_THROW(delete emptyStack);
		}
		BOOST_AUTO_TEST_CASE(Push_and_pop_functions_work_correctly)
		{
			string test1 = "test1";
			string test2 = "test2";

			CMyStack<string> stack;
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
			CMyStack<string> stack;
			BOOST_CHECK(stack.IsEmpty());
			BOOST_CHECK_THROW(stack.Pop(), length_error);
		}
		BOOST_AUTO_TEST_CASE(GetTop_function_works_correctly)
		{
			CMyStack<string> stack;
			stack.Push("1");
			stack.Push("2");
			size_t initialSize = stack.GetSize();
			BOOST_CHECK_EQUAL(stack.GetTop(), "2");
			BOOST_CHECK_EQUAL(initialSize, stack.GetSize());
		}
		BOOST_AUTO_TEST_CASE(Stack_can_be_cleared)
		{
			CMyStack<string> stack;
			stack.Push("1");
			stack.Push("2");
			BOOST_CHECK(!stack.IsEmpty());
			stack.Clear();
			BOOST_CHECK(stack.IsEmpty());
		}
		BOOST_AUTO_TEST_CASE(Copy_constructor_works_correctly)
		{
			CMyStack<string> s1;
			s1.Push("1");
			s1.Push("2");

			CMyStack<string> s2(s1);
			BOOST_CHECK_EQUAL(s1.GetSize(), s2.GetSize());
			BOOST_CHECK_EQUAL(s2.Pop(), "2");
			BOOST_CHECK_EQUAL(s2.Pop(), "1");
		}
		BOOST_AUTO_TEST_CASE(Move_constructor_works_correctly)
		{
			CMyStack<string> s1;
			s1.Push("1");
			s1.Push("2");

			CMyStack<string> s2(move(s1));
			BOOST_CHECK_EQUAL(s2.Pop(), "2");
			BOOST_CHECK_EQUAL(s2.Pop(), "1");
			BOOST_CHECK(s1.IsEmpty());
		}
		BOOST_AUTO_TEST_CASE(Assignment_operator_works_correctly)
		{
			CMyStack<string> s1;
			s1.Push("1");
			s1.Push("2");

			CMyStack<string> s2;
			s2 = s1;

			BOOST_CHECK_EQUAL(s1.GetSize(), s2.GetSize());
			BOOST_CHECK_EQUAL(s2.Pop(), "2");
			BOOST_CHECK_EQUAL(s2.Pop(), "1");
		}
		BOOST_AUTO_TEST_CASE(Move_assignment_operator_works_correctly)
		{
			CMyStack<string> s1;
			s1.Push("1");
			s1.Push("2");

			CMyStack<string> s2;
			s2 = move(s1);

			BOOST_CHECK_EQUAL(s2.Pop(), "2");
			BOOST_CHECK_EQUAL(s2.Pop(), "1");
			BOOST_CHECK(s1.IsEmpty());
		}
	BOOST_AUTO_TEST_SUITE_END() // String stack

	BOOST_AUTO_TEST_SUITE(Int_stack)
		BOOST_AUTO_TEST_CASE(Destructor_doesnt_throw_exceptions)
		{
			CMyStack<int> * stack = new CMyStack<int>;
			stack->Push(1);
			stack->Push(2);
			stack->Push(3);
			BOOST_CHECK_NO_THROW(delete stack);

			CMyStack<int> * emptyStack = new CMyStack<int>;
			BOOST_CHECK_NO_THROW(delete emptyStack);
		}
		BOOST_AUTO_TEST_CASE(Push_and_pop_functions_work_correctly)
		{
			CMyStack<int> stack;
			BOOST_CHECK(stack.IsEmpty());

			stack.Push(1);
			stack.Push(2);
			BOOST_CHECK(stack.GetSize() == 2);

			BOOST_CHECK_EQUAL(2, stack.Pop());
			BOOST_CHECK_EQUAL(1, stack.Pop());
			BOOST_CHECK(stack.IsEmpty());
		}
		BOOST_AUTO_TEST_CASE(Pop_from_empty_stack_throws_exception)
		{
			CMyStack<int> stack;
			BOOST_CHECK(stack.IsEmpty());
			BOOST_CHECK_THROW(stack.Pop(), length_error);
		}
		BOOST_AUTO_TEST_CASE(GetTop_function_works_correctly)
		{
			CMyStack<int> stack;
			stack.Push(1);
			stack.Push(2);
			size_t initialSize = stack.GetSize();
			BOOST_CHECK_EQUAL(stack.GetTop(), 2);
			BOOST_CHECK_EQUAL(initialSize, stack.GetSize());
		}
		BOOST_AUTO_TEST_CASE(Stack_can_be_cleared)
		{
			CMyStack<int> stack;
			stack.Push(1);
			stack.Push(2);
			BOOST_CHECK(!stack.IsEmpty());
			stack.Clear();
			BOOST_CHECK(stack.IsEmpty());
		}
		BOOST_AUTO_TEST_CASE(Copy_constructor_works_correctly)
		{
			CMyStack<int> s1;
			s1.Push(1);
			s1.Push(2);

			CMyStack<int> s2(s1);
			BOOST_CHECK_EQUAL(s1.GetSize(), s2.GetSize());
			BOOST_CHECK_EQUAL(s2.Pop(), 2);
			BOOST_CHECK_EQUAL(s2.Pop(), 1);
		}
		BOOST_AUTO_TEST_CASE(Move_constructor_works_correctly)
		{
			CMyStack<int> s1;
			s1.Push(1);
			s1.Push(2);

			CMyStack<int> s2(move(s1));
			BOOST_CHECK_EQUAL(s2.Pop(), 2);
			BOOST_CHECK_EQUAL(s2.Pop(), 1);
			BOOST_CHECK(s1.IsEmpty());
		}
		BOOST_AUTO_TEST_CASE(Assignment_operator_works_correctly)
		{
			CMyStack<int> s1;
			s1.Push(1);
			s1.Push(2);

			CMyStack<int> s2;
			s2 = s1;

			BOOST_CHECK_EQUAL(s1.GetSize(), s2.GetSize());
			BOOST_CHECK_EQUAL(s2.Pop(), 2);
			BOOST_CHECK_EQUAL(s2.Pop(), 1);
		}
		BOOST_AUTO_TEST_CASE(Move_assignment_operator_works_correctly)
		{
			CMyStack<int> s1;
			s1.Push(1);
			s1.Push(2);

			CMyStack<int> s2;
			s2 = move(s1);

			BOOST_CHECK_EQUAL(s2.Pop(), 2);
			BOOST_CHECK_EQUAL(s2.Pop(), 1);
			BOOST_CHECK(s1.IsEmpty());
		}
	BOOST_AUTO_TEST_SUITE_END() // Int stack
BOOST_AUTO_TEST_SUITE_END() // MyStack