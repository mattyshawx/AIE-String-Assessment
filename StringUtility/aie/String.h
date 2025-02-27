#pragma once

#include <ios>

using std::istream;
using std::ostream;

namespace aie
{
	class String
	{

		//Constructors and destructor
	public:

		String();
		String(const char* str);
		String(const String& other);

		~String();

		//Public functions
	public:

		size_t Length() const;

		String& Append(const String& stringToAdd);
		String& ToLower();
		String& ToUpper();

		int FindCharacter(char targetCharacter);
		int Replace(char targetCharacter, char replacementCharacter);
		
		//Public operators
	public:

		friend istream& operator>>(istream& stream, String& stringToUse);
		friend ostream& operator<<(ostream& stream, const String& stringToUse);

		String& operator=(const String& targetString);

		bool operator==(const String& checkString);
		bool operator!=(const String& checkString);

		char& operator[](size_t index);
		const char& operator[](size_t index) const;
		bool operator<(const String& compareString);

		//Private functions
	private:

		void SetCharacters(const char* newCharacters);

		//Private variables
	private:

		char* m_characters;
		size_t m_length;

	};

}