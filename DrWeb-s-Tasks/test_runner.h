#pragma once

#include <string>
#include <iostream>

using std::string;
using std::cerr;
using std::endl;

#define ASSERT_EQUAL(x, y) {            \
  ostringstream os;                     \
  os << #x << " != " << #y << ", "      \
    << __FILE__ << ":" << __LINE__;     \
  AssertEqual(x, y, os.str());          \
}

#define RUN_TEST(tr, func) \
  tr.RunTest(func, #func)

template<typename T, typename U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
	if (!(t == u)) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u;
		if (!hint.empty()) {
			os << " hint: " << hint;
		}
		throw runtime_error(os.str());
	}
}

class TestRunner {
public:
	template <class TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		}
		catch (exception& e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		}
		catch (...) {
			++fail_count;
			cerr << "Unknown exception caught" << endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			cerr << fail_count << " unit tests failed. Terminate" << endl;
			exit(1);
		}
	}

private:
	int fail_count = 0;
};