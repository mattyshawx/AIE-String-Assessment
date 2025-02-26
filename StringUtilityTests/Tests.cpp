#include <format>
#include <iostream>

#include "TestManager.h"

#include <aie/String.h>

#define TITLE(text) "\x1B[36m" << text << "\x1B[39m\n"
#define STRING(text) "\"" << text << "\""
#define TEST_TITLE(text) TITLE("TEST: " << text)

using aie::String;
using aie::TestManager;

using std::cout;


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


//Create strings to be used for testing
String string1 = "G'day mate!";
String string2 = "Okay bye...";
const String stringConstant = "I am the constant";

//Start up function
DEFINE_TEST_INIT_FUNCTION(Initialise)
{
	//Print out the two strings
	cout << TITLE("There are three strings for testing:")
		<< " 1: " << STRING(string1)
		<< "\n 2: " << STRING(string2)
		<< "\n 3: " << STRING(stringConstant) << " <-- This is a constant variable"
		<< "\n\n";
}

//Demonstrates printing a whole string
DEFINE_TEST_FUNCTION(Print)
{
	cout << TEST_TITLE("Streaming to console");

	//Print it to the console
	cout << string1;
	
	//Check whether it failed or not
	if (cout.fail())
	{
		return false;
	}

	return true;
}

//Demonstrates indexing, looping over the whole string
/*DEFINE_TEST_FUNCTION(Index)
{


	return true;
}*/

//Same as above but for a constant variable