#include "pch.h"
#include "CppUnitTest.h"
#include "DummyServiceLib/DummyService.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DummyServiceLibTests
{
	TEST_CLASS(DummyServiceLibTests)
	{
	public:
		TEST_METHOD(DummyService_Run_ReturnsTrue)
		{
			dummyservice::DummyService service;
			Assert::IsTrue(service.Run());
		}
	};
}
