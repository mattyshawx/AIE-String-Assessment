#include "String.h"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string> //Used for std::getline and nothing else

using std::cout;


namespace aie
{
	//------------------------------------------------------------------------
	//					Constructors and destructor
	//------------------------------------------------------------------------

	//This creates a blank string (just the null terminator) from no input
	String::String()
	{
		m_characters = new char[1]{'\0'};
		m_length = 0;
	}

	//Creates a string from a given character array
	String::String(const char* characters)
	{
		//Get the length of the given character array
		m_length = strlen(characters);

		//Initialise the new character array
		m_characters = new char[m_length + 1];
		
		//Fill out the array
		for (int i = 0; i < m_length; i++)
		{
			m_characters[i] = characters[i];
		}

		//Add the null terminator
		m_characters[m_length] = '\0';
	}

	//Creates a string from another string
	String::String(const String& copyString)
	{

	}

	//Deallocates memory
	String::~String()
	{
		//Debugging
		cout << "Deleting | " << *this << "\n";

		//Deallocate the character array
		delete m_characters;
	}


	//------------------------------------------------------------------------
	//					Utility functions
	//------------------------------------------------------------------------

	//Returns the length of the string (doesn't include the null terminator)
	size_t String::Length() const
	{
		return m_length;
	}

	//Adds another string to the end of this one
	String& String::Append(const String& stringToAdd)
	{
		

		return *this;
	}

	//This converts all letters in the string to lower case
	String& String::ToLower()
	{
		//Go through the characters
		for (int i = 0; i < m_length; i++)
		{

		}

		return *this;
	}

	//Converts all letters in the string to upper case
	String& String::ToUpper()
	{


		return *this;
	}

	//Finds a given character in the string and returns its index, or -1 if none
	int String::FindCharacter(char targetCharacter)
	{
		

		return -1;
	}

	//Replaces all occurences of a given character in the string, and returns the number of replacements done
	int String::Replace(char targetCharacter, char replacementCharacter)
	{
		

		return 0;
	}


	//------------------------------------------------------------------------
	//					Operators
	//------------------------------------------------------------------------

	//Stream in
	istream& operator>>(istream& stream, String& stringToUse)
	{
		

		return stream;
	}

	//Stream out
	ostream& operator<<(ostream& stream, const String& stringToUse)
	{
		//Add the characters array to the stream
		stream << stringToUse.m_characters;

		return stream; 
	}

	//Sets the string's characters to those of the targetString
	String& String::operator=(const String& targetString)
	{


		return *this;
	}

	//Checks if a string IS equal to this one
	bool String::operator==(const String& checkString)
	{


		return false;
	}

	//Checks if another string is NOT equal to this one
	bool String::operator!=(const String& checkString)
	{
		return !(*this == checkString);
	}

	//Returns the character at the requested index, or a null terminator if out of bounds
	char& String::operator[](size_t index)
	{
		char returnCharacter = '\0';

		//Make sure the index is within the bounds
		if (index >= 0 && index < m_length) {
			//Grab the character at the given index
			returnCharacter = m_characters[index];
		}
		return returnCharacter;
	}

	//Same as above, except for constant type strings
	const char& String::operator[](size_t index) const
	{
		return m_characters[index];
	}

	//Checks to see if this string comes before the other one, alphabetically
	bool String::operator<(const String& compareString)
	{


		return false;
	}
}
