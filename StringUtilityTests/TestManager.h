// DO NOT MODIFY THIS FILE
#pragma once

#include <list>
#include <string>

#include "aie/String.h"

using std::list;
using std::string;

using aie::String;

namespace aie
{
	typedef bool(*TestFnc)(string& reason);
	typedef void(*TestInitFnc)();
	typedef void(*TestShutdownFnc)(int passCount, size_t maxTestCount);

	class TestManager
	{
	private:
		struct TestCase
		{
		public:
			const char* name;
			TestFnc test;

		};

	public:
		static void RegisterTest(TestCase fnc);
		static void SetTestInit(TestInitFnc fnc);
		static void SetTestShutdown(TestShutdownFnc fnc);
		static void Run();

	private:
		static list<TestCase> m_tests;
		static TestInitFnc m_init;
		static TestShutdownFnc m_shutdown;

	};
}

#define DEFINE_TEST_FUNCTION(FUNC_NAME) \
	bool Test##FUNC_NAME(string& reason); \
	struct TestStruct##FUNC_NAME { \
		TestStruct##FUNC_NAME() { aie::TestManager::RegisterTest({#FUNC_NAME, Test##FUNC_NAME}); } \
	}; \
	TestStruct##FUNC_NAME testStruct##FUNC_NAME; \
	bool Test##FUNC_NAME(string& reason)

#define DEFINE_TEST_INIT_FUNCTION(FUNC_NAME) \
	void Test##FUNC_NAME(); \
	struct TestStruct##FUNC_NAME { \
		TestStruct##FUNC_NAME() { aie::TestManager::SetTestInit(Test##FUNC_NAME); } \
	}; \
	TestStruct##FUNC_NAME testStruct##FUNC_NAME; \
	void Test##FUNC_NAME()

#define DEFINE_TEST_SHUTDOWN_FUNCTION(FUNC_NAME) \
	void Test##FUNC_NAME(int passCount, size_t maxTestCount); \
	struct TestStruct##FUNC_NAME { \
		TestStruct##FUNC_NAME() { aie::TestManager::SetTestShutdown(Test##FUNC_NAME); } \
	}; \
	TestStruct##FUNC_NAME testStruct##FUNC_NAME; \
	void Test##FUNC_NAME(int passCount, size_t maxTestCount)