#include "pch.h"
#include "CppUnitTest.h"
#include "../base64_encryption/decoder.h"
#include "../base64_encryption/encoder.h"
#include "../base64_encryption/helperFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace base64encryptionUnitTest
{
	TEST_CLASS(base64encryptionUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char* in = "Hallo";
			std::string out = "SGFsbG8=";
			Assert::IsTrue(out.compare(encode(in)) == 0);
		}
	};
}
