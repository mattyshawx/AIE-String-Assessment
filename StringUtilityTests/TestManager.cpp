// DO NOT MODIFY THIS FILE
#include "TestManager.h"

#include <format>
#include <iostream>

namespace aie
{
	list<TestManager::TestCase> TestManager::m_tests;
	TestInitFnc TestManager::m_init;
	TestShutdownFnc TestManager::m_shutdown;

	void TestManager::RegisterTest(TestCase fnc)
	{
		m_tests.emplace_back(fnc);
	}

	void TestManager::SetTestInit(TestInitFnc fnc)
	{
		m_init = fnc;
	}

	void TestManager::SetTestShutdown(TestShutdownFnc fnc)
	{
		m_shutdown = fnc;
	}

	void TestManager::Run()
	{
		if (m_init != nullptr)
		{
			m_init();
		}

		int passed = 0;
		string reason;

		for (auto& [name, test] : m_tests)
		{
			if (!test(reason))
			{
				std::cout << std::format("\n\n\x1B[31m[ FAIL ] {}: \x1B[37m{}\n\n", name, reason);
			}
			else
			{
				std::cout << std::format("\n\n\x1B[32m[ PASS ] {}\x1B[37m\n\n", name);
				passed++;
			}
		}

		std::cout << std::format("\n\n\n\x1B[33m{} out of {} tests passed!\x1B[37m\n", passed, m_tests.size());

		if (m_shutdown != nullptr)
		{
			m_shutdown(passed, m_tests.size());
		}
	}
}
