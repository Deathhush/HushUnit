#include "..\UnitTestFramework\UnitTest.h"

#include "..\Common\String.h"
#include "..\Common\Exception.h"

#include <iostream>
using namespace std;

using namespace Hush;
using namespace Hush::UnitTest;

TESTCLASS(UnitTestTests)
{
    TESTMETHOD(TestException)
    EXPECTEXCEPTION(int)
    {
        throw 1;            
    }

    TESTMETHOD(TestException1)
    EXPECTEXCEPTION(int)
    {
        throw 2;
    }

    TESTMETHOD(TestException3)
    EXPECTEXCEPTION(Exception)
    {
        throw Exception(L"test");
    }
};
