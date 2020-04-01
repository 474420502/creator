

#include "creator.hpp"
#include <gtest/gtest.h>


TEST(creator_test, number_creator) {
    ulong n;

    auto create = creator<ulong>::make_number_creator(0, 1000);
    n = create->create();

    ASSERT_TRUE(n == 1) << n;
}

TEST(creator_test, real_creator) {
    double n;
    auto create = creator<double>::make_real_creator(0.0, 1.0);
    n = create->create();
    ASSERT_TRUE(n == 1.0) << n;
}



