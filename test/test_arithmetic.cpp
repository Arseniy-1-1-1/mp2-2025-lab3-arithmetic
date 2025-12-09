// тесты для вычисления арифметических выражений

#include <gtest.h>
#include "arithmetic.h"

TEST(ArithmeticTests, SimpleAddition) {
    EXPECT_DOUBLE_EQ(evaluateExpression("2+3"), 5);
}

TEST(ArithmeticTests, MultiplicationHigherPriority) {
    EXPECT_DOUBLE_EQ(evaluateExpression("2+3*4"), 14);
}

TEST(ArithmeticTests, Brackets) {
    EXPECT_DOUBLE_EQ(evaluateExpression("(2+3)*4"), 20);
}

TEST(ArithmeticTests, ComplexExpression) {
    EXPECT_DOUBLE_EQ(evaluateExpression("10+2*3-4/2"), 14);
}

TEST(ArithmeticTests, RPNConversionCheck) {
    auto rpn = toRPN("2+3*4");
    std::vector<std::string> expected = { "2","3","4","*","+" };
    EXPECT_EQ(rpn, expected);
}

TEST(ArithmeticTests, ZeroDivisionThrows) {
    EXPECT_THROW(evaluateExpression("5/0"), std::runtime_error);
}

TEST(ArithmeticTests, MultiDigitNumbers) {
    EXPECT_DOUBLE_EQ(evaluateExpression("100+20*3"), 160);
}

TEST(ArithmeticTests, NestedBrackets) {
    EXPECT_DOUBLE_EQ(evaluateExpression("(2+(3*4))*2"), 28);
}