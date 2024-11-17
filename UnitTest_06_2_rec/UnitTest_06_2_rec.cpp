#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_2_rec/Lab_06_2_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest062rec
{
	TEST_CLASS(UnitTest062rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 8;
			int a[n] = { -12, 2, 5, -3, 7 };
			int expectation = CalculateAverageOfEvenIndices(a, 0, n, 0, 0);
			int actual = 3;
			Assert::AreEqual(expectation, actual);
		}
	};
}
