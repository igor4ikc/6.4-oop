#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4/vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector <int> a(3);
			Assert::AreEqual(a.ext("max"), 0);
		}
	};
}
