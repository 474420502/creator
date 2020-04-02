

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
    }
}

TEST(creator_test, name_creator) {
    words ws;
    auto create = creator<wstring>::make_name_creator();
    for (int i = 0; i < 1000; i++)
    {
        wstring n = create->create();
        ASSERT_LE(n.size(), 2) << n;
        ws.push_back(n);
    }
 
    ASSERT_TRUE(ws.size() == 1000) << ws.size();
}
