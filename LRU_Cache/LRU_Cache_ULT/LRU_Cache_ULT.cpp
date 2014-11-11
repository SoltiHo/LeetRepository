#include "gtest/gtest.h"  // access test macro
#include "LRU_Cache.h"


TEST(LeetCode, Fail01){
    LRUCache cache(1);

    cache.set(2, 1);
    ASSERT_EQ(cache.get(2), 1);
    cache.set(3, 2);
    ASSERT_EQ(cache.get(2), -1);
    ASSERT_EQ(cache.get(3), 2);
}
