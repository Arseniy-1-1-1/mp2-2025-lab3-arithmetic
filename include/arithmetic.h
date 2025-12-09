// объявление функций и классов для вычисления арифметических выражений
#pragma once
#include <string>
#include <vector>

bool isOperator(char c);
int precedence(char op);

// Преобразование инфиксной записи в польскую (ОПЗ)
std::vector<std::string> toRPN(const std::string& expr);

// Вычисление польской записи
double evalRPN(const std::vector<std::string>& rpn);

// Главная функция
double evaluateExpression(const std::string& expr);