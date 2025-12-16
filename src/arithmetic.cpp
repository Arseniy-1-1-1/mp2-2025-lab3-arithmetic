// реализация функций и классов для вычисления арифметических выражений
#include "arithmetic.h"
#include "stack.h"
#include <cctype>
#include <stdexcept>
#include <iostream>
#include <map>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

vector<string> toRPN(const string& expr) {
    int balance = 0;
    Stack<char> ops;
    vector<string> output;

    for (size_t i = 0; i < expr.size(); i++) {
        char c = expr[i];

        if (c == ' ') continue;

        if (isdigit(c)) {
            string num;
            while (i < expr.size() && isdigit(expr[i])) {
                num += expr[i++];
            }
            i--;
            output.push_back(num);
        }

        else if (isalpha(c)) {
            output.push_back(string(1, c));
        }

        else if (c == '(') {
            balance++;
            ops.push(c);
        }

        else if (c == ')') {
            if (balance == 0)
                throw runtime_error("Extra ')'");
            balance--;
            while (!ops.empty() && ops.top() != '(') {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.pop();
        }

        else if (isOperator(c)) {
            while (!ops.empty() && isOperator(ops.top()) &&
                precedence(ops.top()) >= precedence(c))
            {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(c);
        }

        else {
            throw std::runtime_error("invalid character");
        }
    }

    while (!ops.empty()) {
        output.push_back(string(1, ops.top()));
        ops.pop();
    }

    if (balance != 0)
        throw std::runtime_error("Missing ')'");

    return output;
}

double evalRPN(const vector<std::string>& rpn, const std::map<char, double>& variables) {
    Stack<double> st;

    for (const auto& token : rpn) {
        if (token.size() == 1 && isOperator(token[0])) {
            if (st.size() < 2)
                throw runtime_error("invalid expression");

            double b = st.top(); st.pop();
            double a = st.top(); st.pop();

            switch (token[0]) {
            case '+': st.push(a + b); break;
            case '-': st.push(a - b); break;
            case '*': st.push(a * b); break;
            case '/':
                if (b == 0) throw runtime_error("division by zero");
                st.push(a / b);
                break;
            }
        }
        else if (token.size() == 1 && isalpha(token[0])) {
            char var = token[0];
            if (!variables.count(var))
                throw std::runtime_error("unknown variable");
            st.push(variables.at(var));
        }
        else {
            st.push(stod(token));
        }
    }

    return st.top();
}

double evaluateExpression(const std::string& expr) {
    auto rpn = toRPN(expr);
    map<char, double> variables;

    for (const auto& token : rpn) {
        if (token.size() == 1 && isalpha(token[0])) {
            char v = token[0];
            if (!variables.count(v)) {
                cout << "Введите значение " << v << ": ";
                cin >> variables[v];
            }
        }
    }
    return evalRPN(rpn, variables);
}