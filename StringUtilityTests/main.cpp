// DO NOT MODIFY THIS FILE

#include "TestManager.h"
#include "aie/String.h"

#ifdef _DEBUG
// ReSharper disable once IdentifierTypo
// ReSharper disable once CppInconsistentNaming
#define _CRTDBG_MAP_ALLOC  // NOLINT(bugprone-reserved-identifier, clang-diagnostic-reserved-macro-identifier, clang-diagnostic-unused-macros)
#include <crtdbg.h>
#include <cstdlib>
#endif

#include <iostream>

using aie::TestManager;

using std::cout;

int main()
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	//TestManager::Run();

	String test = "Hello world!";

	//Couting
	cout << "Printing:\n";

	cout << test << "\n";

	//Indexing
	cout << "\nIndexing:\n";

	for (size_t i = 0; i < test.Length(); i++)
	{
		cout << "[" << i << "]\t" << test[i] << "\n";
	}
	
	//Changing index
	cout << "\nChanging index:\n";

	test[2] = 'A';

	cout << test << "\n";
	
	
	//Constants
	cout << "Constant indexing:\n";

	const String test2 = "Hello";

	cout << test2[1];

	//Finish
	cout << "\n\n\n\n\n";

	return 0;
}
