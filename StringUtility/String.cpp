#include "aie/String.h"

#include <cstdlib>
#include <cstring>
#include <iostream>

namespace aie
{
	String::String()
	{
	}

	String::String(const char* str)
	{
	}

	String::String(const String& other)
	{
	}

	String::~String()
	{
	}

	size_t String::Length() const
	{
		return 0;
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

	istream& operator>>(istream& stream, String& str)
	{
		return stream;
	}

	ostream& operator<<(ostream& stream, const String& str)
	{
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
		char c = ' ';
		return c;
	}

	const char& String::operator[](size_t index) const
	{
		char c = ' ';
		return c;
	}

	bool String::operator<(const String& rhs)
	{
		return false;
	}
}
