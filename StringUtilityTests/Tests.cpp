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

	//Read the input
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
String stringCopy = string1;

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
		<< "\n 5: " << STRING(string1) << " <-- A copy of string1"
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
	//testString.ReadLine(); ended up getting streaming in working, but still keeping read line as it could be of use in a real application
	cin >> testString;
	
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

//Demonstrates the append function
DEFINE_TEST_FUNCTION(Append)
{
	cout << SECTION("Functions");

	cout << TEST_TITLE("Appending to a string");

	//Create a new string to append
	String stringToAppend = "I have been appended!";

	cout << "Appending " << STRING(stringToAppend) << " to string 2 (" << STRING(string2) << ")\n";

	//Append
	string2.Append(stringToAppend);

	cout << "String 2 is now " << STRING(string2);

	//Verify that the appending worked properly
	String correctString = "Okay bye...I have been appended!";

	if (string2 != correctString)
	{
		reason = format("Incorrect result, expected \"{}\", but got \"{}\"", correctString.GetCharacters(), string2.GetCharacters());

		return false;
	}

	return true;
}

//Demonstrates the to uppercase function
DEFINE_TEST_FUNCTION(Uppercase)
{
	cout << TEST_TITLE("Converting to uppercase");

	cout << "converting " << STRING(string1) << " to uppercase";

	//Convert it to uppercase
	string1.ToUpper();

	cout << "String 1 is now " << STRING(string1);

	//Make sure it worked
	String correctString = "HELLO WORLD!";

	if (string1 != correctString)
	{
		reason = format("Expected \"{}\", but got \"{}\"", correctString, string1);
	}

	return true;
}


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
	cout << "\n String 2: " << STRING(stringCopy);

	//Make sure it works
	if (string1 != stringCopy)
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

	//Make sure it works
	if (string1 == string2)
	{
		reason = "Expected two strings to be different, but they were deemed the same";

		return false;
	}

	return true;
}

//Demonstrates the equals operator
DEFINE_TEST_FUNCTION(Equals)
{
	cout << TEST_TITLE("Copying a string");

	cout << "Copying string 2 (" << STRING(string2) << ")\n";
	cout << "To string 5 (" << STRING(stringCopy) << ")\n";

	//Copy string2 to a new string
	stringCopy = string2;

	//Make sure it worked
	if (stringCopy != string2)
	{
		reason = format("Failed to copy, was supposed to be \"{}\", but it was \"{}\"", string2.GetCharacters(), stringCopy.GetCharacters());

		return false;
	}

	cout << "\nString 5 is now " << STRING(stringCopy);

	return true;
}