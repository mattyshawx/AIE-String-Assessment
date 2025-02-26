#include <format>
#include <iostream>

#include "TestManager.h"

#include <aie/String.h>

using aie::String;
using aie::TestManager;

#pragma region Example Functions
/*DEFINE_TEST_INIT_FUNCTION(ExampleInit)
{
	std::cout << "I am called before all functions are run\n\n";
}

DEFINE_TEST_SHUTDOWN_FUNCTION(ExampleShutdown)
{
	std::cout << "\nI am called after all tests are run\n";
}

DEFINE_TEST_FUNCTION(Example)
{
	reason = "I am an example error message";

	return false;
}

DEFINE_TEST_FUNCTION(Example2)
{
	reason = std::format("I am another example message with formatting: {}", 2);

	return true;
}*/  
#pragma endregion