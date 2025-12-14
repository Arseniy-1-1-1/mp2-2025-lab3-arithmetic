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

TEST(StackTests, ClearEmpty) {
    Stack<int> st;
    st.push(1);
    st.clear();
    EXPECT_TRUE(st.empty());
}

TEST(StackTests, ClearSize) {
    Stack<int> st;
    st.push(1);
    st.clear();
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

TEST(StackTests, AutoResizeNoThrow) {
    Stack<int> st(2);
    st.push(1);
    st.push(2);
    EXPECT_NO_THROW(st.push(3));
}

TEST(StackTests, AutoResizeSize) {
    Stack<int> st(2);
    st.push(1);
    st.push(2);
    st.push(3);
    EXPECT_EQ(st.size(), 3);
}

TEST(StackTests, AutoResizeTop) {
    Stack<int> st(2);
    st.push(1);
    st.push(2);
    st.push(3);
    EXPECT_EQ(st.top(), 3);
}