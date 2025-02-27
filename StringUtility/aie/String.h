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

		void ReadLine();

		size_t Length() const;

		String& Append(const String& stringToAdd);
		String& ToLower();
		String& ToUpper();

		int FindCharacter(char targetCharacter);
		int Replace(char targetCharacter, char replacementCharacter);

		char* GetCharacters();
		
		//Public operators
	public:

		friend istream& operator>>(istream& stream, String& stringToUse);
		friend ostream& operator<<(ostream& stream, const String& stringToUse);

		String& operator=(const String& stringToCopyFrom);

		bool operator==(const String& compareString);
		bool operator!=(const String& compareString);

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