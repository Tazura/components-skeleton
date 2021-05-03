#include <fakeit/gtest.h>
#include <gtest/gtest.h>

#define protected public
#define private public

#include "componentB.h"

using namespace componentB;
using namespace fakeit;

namespace componentB {
namespace tests
{
	TEST(componentB_Tests, Test1)
	{
		// Setup

		// Tests

		// Validate
		ASSERT_FALSE(false);
	}
} 
}
