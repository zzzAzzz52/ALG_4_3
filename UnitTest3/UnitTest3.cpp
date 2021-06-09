#include "pch.h"
#include "CppUnitTest.h"
#include "../ALGSTRD3/Func.h"
#include "../ALGSTRD3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest43
{
	TEST_CLASS(UnitTest43)
	{
	public:
		TEST_METHOD(data_set)
		{
			string a = "";
			string expected = "Could not open file";
			ifstream in;
			if (!in.is_open()) a = "Could not open file";
			Assert::AreEqual(expected, a);
		}

		TEST_METHOD(dataprice)
		{
			int msg = 0; string a, b;
			int expected = 50;
			ifstream in;
			Flights T;
			msg = T.start3(a, b, msg);
			Assert::AreEqual(expected, msg);
		}
		TEST_METHOD(datadep)
		{
			string a;
			string expected = "MOSCOW";
			Flights T;
			a = T.start2(a);
			Assert::AreEqual(expected, a);
		}
	};
}
