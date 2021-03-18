#include "pch.h"
#include "CppUnitTest.h"
#include <string>
using namespace std::string_literals;
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
			std::string in  = "Hallo";
			std::string out = "SGFsbG8=";
			//Assert::IsTrue(out == encode(in));
			Assert::AreEqual(out, encode(in));
		}

		TEST_METHOD(TestDecode1)
		{
			std::string in = "RGllcyBpc3QgZWluIFRlc3QgZGVyIERlY29kZXIgc29sbCBnZXRlc3RldCB3ZXJkZW4u";
			std::string out = "Dies ist ein Test der Decoder soll getestet werden.";
			//Assert::IsTrue(out == decode(in));
			Assert::AreEqual(out, decode(in));
		}

		TEST_METHOD(TestConvert_to_vector)
		{
			std::string in = "Hallo Welt";
			std::vector<std::string> expected = { "Hal", "lo ", "Wel", "t\0\0"s};
			auto output = convert_to_byte_wise(in, 3);
			for(int i = 0; i< output.size(); i++)
			{
				Assert::AreEqual(expected[i], output[i]);
			}
			
		}

		TEST_METHOD(TestConvert_to_vector_leftover_bug)
		{
			std::string in = "Hallo";
			std::vector<std::string> expected = { "Hal", "lo\0"s};
			auto actual = convert_to_byte_wise(in, 3);

			for (int i = 0; i < actual.size(); i++)
			{
				Assert::AreEqual(expected[i], actual[i]);
			}
		}
	};
}
