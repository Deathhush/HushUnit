#include "..\UnitTestFramework\UnitTest.h"

#include "..\Common\String.h"

#include <iostream>
using namespace std;

using namespace Hush;
using namespace Hush::UnitTest;


TESTCLASS(StringTests)
{
public:
	TESTMETHOD(BasicRefCountTest)
	{
		String s1(L"Test");

		Assert::AreEqual(1l, s1.data.use_count());
		String s2(s1);
		Assert::AreEqual(2l, s1.data.use_count());
		s1=L"Test2";
		Assert::AreEqual(1l, s2.data.use_count());
	}

	TESTMETHOD(ExternalStringTest)
	{
		// Should not throw exception
		const Char* name = L"Justin";
		String s = String::WrapToString(name);
		String s1(name, true);		

		// Assert data has not been copied
		Assert::IsTrue(s.data->data == name, L"s data has been copied");
		Assert::IsTrue(s1.data->data == name, L"s1 data has been copied");
	}

	TESTMETHOD(TestEmptyString)
	{
		Assert::IsTrue(String::Empty.data == Null);

		String s = String::Empty;
		Assert::IsTrue(s.data == Null);
	}
};