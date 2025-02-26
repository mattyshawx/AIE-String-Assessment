#include "String.h"

#include <cstdlib>
#include <cstring>
#include <iostream>


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

	//
	String& String::ToLower()
	{
		//Go through the characters
		for (int i = 0; i < m_length; i++)
		{

		}

		return *this;
	}

	String& String::ToUpper()
	{


		return *this;
	}

	int String::FindCharacter(char targetCharacter)
	{
		

		return 0;
	}

	int String::Replace(char targetCharacter, char replacementCharacter)
	{
		

		return 0;
	}


	//------------------------------------------------------------------------
	//					Operators
	//------------------------------------------------------------------------

	istream& operator>>(istream& stream, String& stringToUse)
	{
		

		return stream;
	}

	ostream& operator<<(ostream& stream, const String& stringToUse)
	{
		//Add the characters array to the stream
		stream << stringToUse.m_characters;

		return stream; 
	}

	String& String::operator=(const String& rhs)
	{


		return *this;
	}

	bool String::operator==(const String& rhs)
	{


		return false;
	}

	bool String::operator!=(const String& rhs)
	{


		return false;
	}

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

	const char& String::operator[](size_t index) const
	{
		return m_characters[index];
	}

	bool String::operator<(const String& compareString)
	{


		return false;
	}
}
