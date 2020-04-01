

#include "creator.hpp"
#include <gtest/gtest.h>

TEST(creator_test, number_creator)
{
    ulong n;

    auto create = creator<ulong>::make_number_creator(0, 1000);

    for (int i = 0; i < 1000; i++)
    {
        n = create->create();
        ASSERT_LE(n, 1000) << n;
    }
}

TEST(creator_test, real_creator)
{
    double n;
    auto create = creator<double>::make_real_creator(0.0, 1.0);
    n = create->create();
    for (int i = 0; i < 1000; i++)
    {
        n = create->create();
        ASSERT_LT(n, 1.0) << n;
    }

    create = creator<double>::make_real_creator(0.0, 2.0);
    n = create->create();
    for (int i = 0; i < 1000; i++)
    {
        n = create->create();
        ASSERT_LT(n, 2.0) << n;
    }

    auto create2 = creator<float>::make_real_creator(2.0, 4.0);
    for (int i = 0; i < 1000; i++)
    {
        n = create2->create();
        ASSERT_LT(n, 4.0) << n;
        ASSERT_GE(n, 2.0) << n;
    }

}

TEST(creator_test, name_creator) {
    wstring n;
    auto create = creator<wstring>::make_name_creator();
    n = create->create();
    for (int i = 0; i < 1000; i++)
    {
        n = create->create();
        ASSERT_EQ(n, L"1") << n;
    }
}
