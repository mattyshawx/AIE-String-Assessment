#pragma once

#include <ios>

using std::istream;
using std::ostream;

namespace aie
{
	class String
	{

	public:

		String();
		String(const char* str);
		String(const String& other);

		~String();

	public:

		size_t Length() const;

		String& Append(const String& str);
		String& ToLower();
		String& ToUpper();

		int FindCharacter(char toFind);
		int Replace(char toFind, char toReplace);
		
	public:

		friend istream& operator>>(istream& stream, String& str);
		friend ostream& operator<<(ostream& stream, const String& str);

		String& operator=(const String& rhs);

		bool operator==(const String& rhs);
		bool operator!=(const String& rhs);

		char& operator[](size_t index);
		const char& operator[](size_t index) const;
		bool operator<(const String& rhs);

	private:

		char* m_characters;
		size_t m_length;

	};

}