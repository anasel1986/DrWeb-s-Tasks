#include "trim.h"
#include "join.h"
#include "test_runner.h"

void RunTests();

int main()
{
	RunTests();
	return 0;
}

void RunTests()
{
	TestRunner tr;
	RUN_TEST(tr, TestTrimRight);
	RUN_TEST(tr, TestJoin);
}