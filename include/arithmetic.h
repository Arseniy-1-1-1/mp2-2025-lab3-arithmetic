// объ€вление функций и классов дл€ вычислени€ арифметических выражений
#pragma once
#include <string>
#include <vector>
#include <map>
#include <stdexcept>


bool isOperator(char c);
int precedence(char op);

std::vector<std::string> toRPN(const std::string& expr);

double evalRPN(const std::vector<std::string>& rpn, const std::map<char, double>& variables);

double evaluateExpression(const std::string& expr);