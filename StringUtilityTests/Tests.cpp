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

using std::istream;
using std::ostream;

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

	//Read the input
	char input;
	cin >> std::setw(1) >> input;

	//Check the output
	return input == 'y';
}


//------------------------------------------------------------------------
//					Initialisation
//------------------------------------------------------------------------

//Create strings to be used for testing
String string1 = "Hello world!";
String string2 = "Okay bye...";
const String stringConstant = "I am the constant";
const String stringEmpty;

//Start up function
DEFINE_TEST_INIT_FUNCTION(Initialise)
{
	cout << SECTION("Initialisation");

	//Print out the strings
	cout << TITLE("There are four strings for testing:")
		<< " 1: " << STRING(string1)
		<< "\n 2: " << STRING(string2)
		<< "\n 3: " << STRING(stringConstant) << " <-- A constant string"
		<< "\n 3: " << STRING(stringEmpty) << " <-- An empty string"
		<< "\n\n";
}


//------------------------------------------------------------------------
//					Streaming
//------------------------------------------------------------------------

//Demonstrates streaming in a whole string
DEFINE_TEST_FUNCTION(StreamOut)
{
	cout << SECTION("Streaming out");

	cout << TEST_TITLE("Streaming out a string");

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

//Demonstrates streaming a string in
/*
DEFINE_TEST_FUNCTION(StreamIn)
{
	cout << SECTION("Streaming into a string");

	cout << TEST_TITLE("Streaming in from the console");

	//Ask the user for input
	istream inputStream();

	cout << "Input a string:\n > ";

	std::getline(cin, inputStream);


	cout << testString;

	return true;
}
*/

//------------------------------------------------------------------------
//					String functions
//------------------------------------------------------------------------
//Demonstrates streaming in from the console


//Demonstrates streaming to the console


//------------------------------------------------------------------------
//					Operators
//------------------------------------------------------------------------

//Demonstrates the indexing in bounds
DEFINE_TEST_FUNCTION(Index)
{
	cout << SECTION("Operators");

	cout << TEST_TITLE("Indexing in bounds");

	//Check an index in bounds
	char resultingCharacter = string1[6];

	if (resultingCharacter != 'w') //Make sure it got the right character
	{
		reason = format("Expected 'w', got '{}'", resultingCharacter);

		return false;
	}
	
	return true;
}