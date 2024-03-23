#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <sstream>
#include "../Project1/Source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectTests
{
    TEST_CLASS(NoteManagementTests)
    {
    public:

        TEST_METHOD(InputNotesTest)
        {
            const int N = 2;
            Note notes[N];
            std::istringstream input("John\nDoe\n1234567890\n1 1 1990\nJane\nSmith\n0987654321\n2 2 2000\n");
            std::streambuf* oldcin = std::cin.rdbuf(input.rdbuf());
            inputNotes(notes, N);
            std::cin.rdbuf(oldcin);

            Assert::AreEqual(std::string("John"), notes[0].firstName);
            Assert::AreEqual(std::string("Doe"), notes[0].lastName);
            Assert::AreEqual(std::string("1234567890"), notes[0].phoneNumber);
            Assert::AreEqual(1, notes[0].birthDate[0]);
            Assert::AreEqual(1, notes[0].birthDate[1]);
            Assert::AreEqual(1990, notes[0].birthDate[2]);

            Assert::AreEqual(std::string("Jane"), notes[1].firstName);
            Assert::AreEqual(std::string("Smith"), notes[1].lastName);
            Assert::AreEqual(std::string("0987654321"), notes[1].phoneNumber);
            Assert::AreEqual(2, notes[1].birthDate[0]);
            Assert::AreEqual(2, notes[1].birthDate[1]);
            Assert::AreEqual(2000, notes[1].birthDate[2]);
        }

        TEST_METHOD(SortByPhoneNumberTest)
        {
            const int N = 3;
            Note notes[N] = { {"John", "Doe", "1234567890", {1, 1, 1990}},
                              {"Jane", "Smith", "0987654321", {2, 2, 2000}},
                              {"David", "Johnson", "5555555555", {3, 3, 1980}} };
            sortByPhoneNumber(notes, N);

            Assert::AreEqual(std::string("0987654321"), notes[0].phoneNumber);
            Assert::AreEqual(std::string("1234567890"), notes[1].phoneNumber);
            Assert::AreEqual(std::string("5555555555"), notes[2].phoneNumber);
        }

        TEST_METHOD(PrintNoteInfoTest)
        {
            const int N = 2;
            Note notes[N] = { {"John", "Doe", "1234567890", {1, 1, 1990}},
                              {"Jane", "Smith", "0987654321", {2, 2, 2000}} };
            std::ostringstream output;
            std::streambuf* oldcout = std::cout.rdbuf(output.rdbuf());
            printNoteInfo(notes, N, "Smith");
            std::cout.rdbuf(oldcout);

            Assert::IsTrue(output.str().find("Information about person \"Smith, Jane\":") != std::string::npos);
            Assert::IsTrue(output.str().find("Phone number: 0987654321") != std::string::npos);
            Assert::IsTrue(output.str().find("Birth date: 2/2/2000") != std::string::npos);
        }
    };
}
