// реализация функций и классов для вычисления арифметических выражений
#include "arithmetic.h"
#include "stack.h"
#include <cctype>
#include <stdexcept>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// -------------------- INFIX → RPN --------------------
std::vector<std::string> toRPN(const std::string& expr) {
    Stack<char> ops;
    std::vector<std::string> output;

    for (size_t i = 0; i < expr.size(); i++) {
        char c = expr[i];
        if (c == ' ') continue;

        // Число
        if (isdigit(c)) {
            std::string num;
            while (i < expr.size() && isdigit(expr[i])) {
                num += expr[i];
                i++;
            }
            i--;
            output.push_back(num);
        }
        else if (c == '(') {
            ops.push(c);
        }
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                output.push_back(std::string(1, ops.top()));
                ops.pop();
            }
            ops.pop(); // удалить '('
        }
        else if (isOperator(c)) {
            while (!ops.empty() && isOperator(ops.top()) &&
                precedence(ops.top()) >= precedence(c))
            {
                output.push_back(std::string(1, ops.top()));
                ops.pop();
            }
            ops.push(c);
        }
        else {
            throw std::runtime_error("invalid character");
        }
    }

    while (!ops.empty()) {
        output.push_back(std::string(1, ops.top()));
        ops.pop();
    }

    return output;
}

// -------------------- EVAL RPN --------------------
double evalRPN(const std::vector<std::string>& rpn) {
    Stack<double> st;

    for (const auto& token : rpn) {
        if (token.size() == 1 && isOperator(token[0])) {
            if (st.size() < 2)
                throw std::runtime_error("invalid expression");

            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            char op = token[0];

            switch (op) {
            case '+': st.push(a + b); break;
            case '-': st.push(a - b); break;
            case '*': st.push(a * b); break;
            case '/':
                if (b == 0) throw std::runtime_error("division by zero");
                st.push(a / b);
                break;
            }
        }
        else {
            st.push(std::stod(token));
        }
    }

    return st.top();
}

// -------------------- FULL EVALUATION --------------------
double evaluateExpression(const std::string& expr) {
    auto rpn = toRPN(expr);
    return evalRPN(rpn);
}