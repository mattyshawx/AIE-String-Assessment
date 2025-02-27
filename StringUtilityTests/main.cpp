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

	TestManager::Run();

	return 0;
}
