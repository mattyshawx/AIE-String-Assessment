// DO NOT MODIFY THIS FILE

#include "TestManager.h"
#include "aie/String.h"

#ifdef _DEBUG
// ReSharper disable once IdentifierTypo
// ReSharper disable once CppInconsistentNaming

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include <cstdlib>
#endif

#include <iostream>


using aie::TestManager;


int main()
{
#if _DEBUG //Catch those pesky bugguses
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(183); //Don't forget to comment this out when not using it mate
#endif

	TestManager::Run();

	return 0;
}
