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

	String::String()
	{
		
	}

	String::String(const char* str)
	{
		//Get the length of the given character array
		m_length = strlen(str);

		//Initialise the new character array
		m_characters = new char[m_length + 1];
		
		//Fill out the array
		for (int i = 0; i < m_length; i++)
		{
			m_characters[i] = str[i];
		}

		//Add the null terminator
		m_characters[m_length] = '\0';
	}

	String::String(const String& other)
	{

	}

	String::~String()
	{
		//Deallocate the character array
		cout << "Deleting\n";
		delete m_characters;
	}


	//------------------------------------------------------------------------
	//					Utility functions
	//------------------------------------------------------------------------

	size_t String::Length() const
	{
		return m_length;
	}

	String& String::Append(const String& str)
	{
		

		return *this;
	}

	String& String::ToLower()
	{


		return *this;
	}

	String& String::ToUpper()
	{


		return *this;
	}

	int String::FindCharacter(char toFind)
	{


		return 0;
	}

	int String::Replace(char toFind, char toReplace)
	{
		

		return 0;
	}


	//------------------------------------------------------------------------
	//					Operators
	//------------------------------------------------------------------------

	istream& operator>>(istream& stream, String& str)
	{
		

		return stream;
	}

	ostream& operator<<(ostream& stream, const String& str)
	{
		//Add the characters array to the stream
		stream << str.m_characters;

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

	bool String::operator<(const String& rhs)
	{


		return false;
	}
}
