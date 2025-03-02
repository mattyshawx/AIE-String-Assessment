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


bool VerifyOutput(const char* question)
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
	String stringToAppend = "1234 HELLO!";

	cout << "Appending " << STRING(stringToAppend) << " to string 2 (" << STRING(string2) << ")\n";

	//Append
	string2.Append(stringToAppend);

	cout << "String 2 is now " << STRING(string2);

	//Verify that the appending worked properly
	String correctString = "Okay bye...1234 HELLO!";

	if (string2 != correctString)
	{
		reason = format("Incorrect result, expected \"{}\", but got \"{}\"", correctString.GetCharacters(), string2.GetCharacters());

		return false;
	}

	return true;
}

//Demonstrates the to lowercase function
DEFINE_TEST_FUNCTION(Lowercase)
{
	cout << TEST_TITLE("Converting to lowercase");

	cout << "Converting " << STRING(string2) << " to lowercase\n";

	//Convert it to lowercase
	string2.ToLower();

	cout << "String 2 is now " << STRING(string2);

	//Make sure it worked
	String correctString = "okay bye...1234 hello!";

	if (string2 != correctString)
	{
		reason = format("Expected \"{}\", but got \"{}\"", correctString.GetCharacters(), string2.GetCharacters());

		return false;
	}

	return true;
}

//Demonstrates the to uppercase function
DEFINE_TEST_FUNCTION(Uppercase)
{
	cout << TEST_TITLE("Converting to uppercase");

	cout << "Converting " << STRING(string2) << " to uppercase\n";

	//Convert it touppercase
	string2.ToUpper();

	cout << "String 2 is now " << STRING(string2);

	//Make sure it worked
	String correctString = "OKAY BYE...1234 HELLO!";

	if (string2 != correctString)
	{
		reason = format("Expected \"{}\", but got \"{}\"", correctString.GetCharacters(), string2.GetCharacters());

		return false;
	}

	return true;
}

//Demonstrates the find character function, when the character is in the string
DEFINE_TEST_FUNCTION(FindPresentCharacter)
{
	cout << TEST_TITLE("Finding character present");

	//Find the character
	int foundIndex = string1.FindCharacter('e');

	cout << "Finding the letter 'e' in " << STRING(string1) << "\n";

	//Make sure it found the right character
	if (foundIndex != 1)
	{
		//See if nothing was found, or if the wrong character was
		if (foundIndex == -1) //Nothing found
		{
			reason = "The character 'e' was not found";
		}
		else //Wrong character found
		{
			reason = format("Supposed to find 'e', but found '{}' instead", string1[foundIndex]);
		}

		return false;
	}

	//Success message
	cout << "It was found at index " << foundIndex;

	return true;
}

//Demonstrates the find character function, when the character is NOT the string
DEFINE_TEST_FUNCTION(FindNotPresentCharacter)
{
	cout << TEST_TITLE("Finding a character not present");

	//Find the character
	int foundIndex = string1.FindCharacter('T');

	cout << "Finding the letter 'T' in " << STRING(string1) << "\n";

	//Make sure it found the right character
	if (foundIndex != -1)
	{
		reason = "Supposedly found 'T', when it is not present";

		return false;
	}

	//Success message
	cout << "It was not found";

	return true;
}

//Demonstrates the replace function
DEFINE_TEST_FUNCTION(ReplaceCharacters)
{
	cout << TEST_TITLE("Replacing characters");

	cout << "Replacing all occurances of 'O' with '5'\n";

	//Replace the letter
	int replaceCount = string2.Replace('O', '5');
	
	cout << "String 2 is now " << STRING(string2) << "\n";
	cout << "Replaced " << replaceCount << " occurances\n";

	//Make sure the right replacement was done
	if (replaceCount != 2)
	{
		reason = "Failed to replace all occurances of 'O'";

		return false;
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