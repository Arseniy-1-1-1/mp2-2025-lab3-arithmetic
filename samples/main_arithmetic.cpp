// реализация пользовательского приложения
#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include "arithmetic.h"

int main() {
    std::cout << "Vvedite arithm virazhenie: ";
    std::string expr;
    std::getline(std::cin, expr);

    try {
        auto rpn = toRPN(expr);

        std::cout << "\nOPZ: ";
        for (const auto& token : rpn)
            std::cout << token << " ";
        std::cout << std::endl;
        std::map<char, double> variables;

        for (const auto& token : rpn) {
            if (token.size() == 1 && std::isalpha(token[0])) {
                char v = token[0];
                if (!variables.count(v)) {
                    std::cout << "Vvedite znachenie " << v << ": ";
                    std::cin >> variables[v];
                }
            }
        }
        double result = evalRPN(rpn, variables);

        std::cout << "\nRes: " << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "\nError: " << e.what() << std::endl;
    }

    return 0;
}