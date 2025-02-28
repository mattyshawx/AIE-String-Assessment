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
		this->SetCharacters(characters);
	}

	//Creates a string from another string
	String::String(const String& copyString)
	{
		this->SetCharacters(copyString.m_characters);
	}

	//Deallocates memory
	String::~String()
	{
		//Deallocate the character array
		delete m_characters;
	}


	//------------------------------------------------------------------------
	//					Utility functions
	//------------------------------------------------------------------------

	//This reads the cin, and overrides the characters
	void String::ReadLine()
	{
		//Read in cin to a standard string
		std::string inputString;
		std::getline(std::cin, inputString);

		//Convert the input to a character array, and override the characters
		this->SetCharacters(inputString.c_str());
	}

	//Returns the length of the string (doesn't include the null terminator)
	size_t String::Length() const
	{
		return m_length;
	}

	//Adds another string to the end of this one
	String& String::Append(const String& stringToAdd)
	{
		//Figure out what the new length will be
		int appendLength = stringToAdd.Length();
		int newLength = m_length + appendLength;

		//Create a new array which will contain both the current and appended characters
		char* newCharacters = new char[newLength + 1];

		//Copy in the existing characters
		strcpy_s(newCharacters, m_length + 1, m_characters);

		//Copy in the characters to append
		for (int i = 0; i < appendLength; i++)
		{
			newCharacters[m_length + i] = stringToAdd[i];
		}

		//Add the null terminator
		newCharacters[newLength] = '\0';

		//Apply the new characters to the string
		this->SetCharacters(newCharacters);

		//Deallocate the newCharacters array
		delete[] newCharacters;

		return *this;
	}

	//This converts all letters in the string to lower case
	String& String::ToLower()
	{
		//Go through the characters
		for (int i = 0; i < m_length; i++)
		{
			//Check and see if this character is an uppercase letter
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

	//This just returns m_characters
	char* String::GetCharacters()
	{
		return m_characters;
	}


	//------------------------------------------------------------------------
	//					Operators
	//------------------------------------------------------------------------

	//Stream in
	istream& operator>>(istream& stream, String& stringToUse)
	{
		//Convert the stream to a standard string
		std::string streamString;
		std::getline(stream, streamString);

		//Convert the standard string to a character array mate and apply it to the characters
		stringToUse.SetCharacters(streamString.c_str());

		return stream;
	}

	//Stream out
	ostream& operator<<(ostream& stream, const String& stringToUse)
	{
		//Add the characters array to the stream
		stream << stringToUse.m_characters;

		return stream; 
	}

	//Sets the string's characters to those of the stringToCopyFrom
	String& String::operator=(const String& stringToCopyFrom)
	{
		//Set the characters to the ones of the string to copy from
		this->SetCharacters(stringToCopyFrom.m_characters);

		return *this;
	}

	//Checks if a string IS equal to this one
	bool String::operator==(const String& compareString)
	{
		return !strcmp(m_characters, compareString.m_characters);
	}

	//Checks if another string is NOT equal to this one
	bool String::operator!=(const String& compareString)
	{
		return !(*this == compareString);
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


	//------------------------------------------------------------------------
	//					Private functions
	//------------------------------------------------------------------------

	//This deallocates the old characters, and sets up new ones from a given character array
	void String::SetCharacters(const char* newCharacters)
	{
		//Deallocate the old characters
		delete[] m_characters;

		//Get the length of the given character array
		m_length = strlen(newCharacters);

		//Initialise the new character array
		m_characters = new char[m_length + 1];

		//Copy the new characters into my characters
		strcpy_s(m_characters, m_length + 1, newCharacters);
	}
}
