#include <fakeit/gtest.h>
#include <gtest/gtest.h>

#define protected public
#define private public

#include "componentA.h"

using namespace componentA;
using namespace fakeit;

namespace componentA {
namespace tests
{
	TEST(ComponentA_Tests, Test1)
	{
		// Setup

		// Tests

		// Validate
		ASSERT_FALSE(false);
	}
} 
}
