#include <format>
#include <iostream>
#include <iomanip>

#include "TestManager.h"

#include <aie/String.h>

#define SECTION(text) TITLE("------------------------------------") << "\t" << text << TITLE("\n------------------------------------\n")

#define TITLE(text) "\x1B[36m" << text << "\x1B[39m\n"
#define TEST_TITLE(text) TITLE("TEST: " << text)

#define STRING(text) "\"" << text << "\""

using aie::String;
using aie::TestManager;

using std::cout;
using std::cin;

using std::format;


#pragma region Example Functions

/*DEFINE_TEST_INIT_FUNCTION(ExampleInit)
{
	std::cout << "I am called before all functions are run\n\n";
}

DEFINE_TEST_SHUTDOWN_FUNCTION(ExampleShutdown)
{
	std::cout << "\nI am called after all tests are run\n";
}

DEFINE_TEST_FUNCTION(Example)
{
	reason = "I am an example error message";

	return false;
}

DEFINE_TEST_FUNCTION(Example2)
{
	reason = std::format("I am another example message with formatting: {}", 2);

	return true;
}*/

#pragma endregion


bool VerifyOutput(std::string question)
{
	//Question the user
	cout << question << " (y/n):\n > ";

	//Read the input (using my string class hah)
	String input;
	input.ReadLine();

	//Check the output
	return input[0] == 'y';
}


//------------------------------------------------------------------------
//					Initialisation
//------------------------------------------------------------------------

//Create strings to be used for testing
String string1 = "Hello world!";
String string2 = "Okay bye...";
const String stringConstant = "I am the constant";
const String stringEmpty;
String string1Copy = string1;

//Start up function
DEFINE_TEST_INIT_FUNCTION(Initialise)
{
	//Print hello world for compliance
	String compliantString = "Hello, World!";
	cout << compliantString << "\n\n\n";


	cout << SECTION("Initialisation");

	//Print out the strings
	cout << TITLE("There are five strings for testing:")
		<< " 1: " << STRING(string1)
		<< "\n 2: " << STRING(string2)
		<< "\n 3: " << STRING(stringConstant) << " <-- A constant string"
		<< "\n 4: " << STRING(stringEmpty) << " <-- An empty string"
		<< "\n 5: " << STRING(string1Copy) << " <-- A copy of string 1"
		<< "\n\n";
}


//------------------------------------------------------------------------
//					Streaming
//------------------------------------------------------------------------

//Demonstrates streaming in a whole string
DEFINE_TEST_FUNCTION(StreamOut)
{
	cout << SECTION("Streaming");

	cout << TEST_TITLE("Streaming out");

	//Stream out the string
	cout << string1 << "\n\n";

	//Verify with the user whether it failed or not
	if (!VerifyOutput("Is the string above \"Hello world!\"?"))
	{
		reason = "The string streamed out was deemed incorrect";

		return false;
	}

	return true;
}

//Demonstrates reading the console
DEFINE_TEST_FUNCTION(ReadLine)
{
	cout << TEST_TITLE("Reading line");

	//Ask the user for input
	cout << "Input a string:\n > ";
	
	String testString;
	testString.ReadLine();
	
	//Check with the user that the string is correct
	cout << "\n Did you input \"" << testString;

	if (!VerifyOutput("\"?"))
	{
		reason = "The string streamed in was deemed incorrect";

		return false;
	}

	return true;
}

//------------------------------------------------------------------------
//					String functions
//------------------------------------------------------------------------




//------------------------------------------------------------------------
//					Operators
//------------------------------------------------------------------------

//Demonstrates the indexing in bounds
DEFINE_TEST_FUNCTION(IndexInBounds)
{
	cout << SECTION("Operators");

	cout << TEST_TITLE("Indexing in bounds");

	//Check an index in bounds
	char resultingCharacter = string1[6];

	cout << STRING(string1) << "[6]: " << resultingCharacter;

	//Make sure it got the right character
	if (resultingCharacter != 'w')
	{
		reason = format("Expected 'w', got '{}'", resultingCharacter);

		return false;
	}
	
	return true;
}

//Demonstrates indexing out of bounds
DEFINE_TEST_FUNCTION(IndexOutOfBounds)
{
	cout << TEST_TITLE("Indexing out of bounds");

	//Check an index in bounds
	char resultingCharacter = string1[25];

	cout << STRING(string1) << "[25]: " << resultingCharacter;

	//Make sure it got the right character
	if (resultingCharacter != '\0')
	{
		reason = format("Expected '\\0' (null terminator), got '{}'", resultingCharacter);

		return false;
	}

	return true;
}

//Demonstrates the equality operator
DEFINE_TEST_FUNCTION(Equality)
{
	cout << TEST_TITLE("Checking equality of 2 strings");

	cout << " String 1: " << STRING(string1);
	cout << "\n String 2: " << STRING(string1Copy);

	if (string1 != string1Copy)
	{
		reason = "Expected two strings to be equal, but they were deemed different";

		return false;
	}

	return true;
}

//Demonstrates the NOT equality operator
DEFINE_TEST_FUNCTION(Inequality)
{
	cout << TEST_TITLE("Checking inequality of 2 strings");

	cout << " String 1: " << STRING(string1);
	cout << "\n String 2: " << STRING(string2);

	if (string1 == string2)
	{
		reason = "Expected two strings to be different, but they were deemed the same";

		return false;
	}

	return true;
}