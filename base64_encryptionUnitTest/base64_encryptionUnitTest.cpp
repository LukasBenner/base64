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
		
		TEST_METHOD(TestEncode1)
		{
			char* in = "Hallo";
			std::string out = "SGFsbG8=";
			Assert::IsTrue(out == encode(in));
		}

		TEST_METHOD(TestDecode1)
		{
			char* in = "RGllcyBpc3QgZWluIFRlc3QgZGVyIERlY29kZXIgc29sbCBnZXRlc3RldCB3ZXJkZW4u";
			std::string out = "Dies ist ein Test der Decoder soll getestet werden.";
			Assert::IsTrue(out == decode(in));
		}

		TEST_METHOD(TestConvert_to_vector)
		{
			std::string in = "Hallo Welt";
			std::vector<std::string> out = { "Hal", "lo ", "Wel", "t\0\0" };
			
		}
	};
}
