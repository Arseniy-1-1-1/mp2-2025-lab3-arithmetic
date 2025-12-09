// тесты для стека

#include "stack.h"
#include <gtest.h>
TEST(StackTests, PushPop) {
    Stack<int> st;
    st.push(10);
    st.push(20);

    EXPECT_EQ(st.top(), 20);

    st.pop();
    EXPECT_EQ(st.top(), 10);
}

TEST(StackTests, Empty) {
    Stack<int> st;
    EXPECT_TRUE(st.empty());
    st.push(1);
    EXPECT_FALSE(st.empty());
}

TEST(StackTests, Size) {
    Stack<int> st;
    st.push(3);
    st.push(7);
    st.push(1);
    EXPECT_EQ(st.size(), 3);
}

TEST(StackTests, Clear) {
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.clear();
    EXPECT_TRUE(st.empty());
    EXPECT_EQ(st.size(), 0);
}

TEST(StackTests, TopOnEmptyThrows) {
    Stack<int> st;
    EXPECT_THROW(st.top(), std::runtime_error);
}

TEST(StackTests, PopOnEmptyThrows) {
    Stack<int> st;
    EXPECT_THROW(st.pop(), std::runtime_error);
}

TEST(StackTests, AutoResize) {
    Stack<int> st(2);
    st.push(1);
    st.push(2);

    // переполнение → должно увеличить capacity
    EXPECT_NO_THROW(st.push(3));

    EXPECT_EQ(st.size(), 3);
    EXPECT_EQ(st.top(), 3);
}