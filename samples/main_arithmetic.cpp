// реализация пользовательского приложения
#include <iostream>
#include <string>
#include "arithmetic.h"

int main() {
    std::cout << "Vvedite arithm virazhenie: ";
    std::string expr;
    std::getline(std::cin, expr);

    try {
        // Преобразование в ОПЗ
        auto rpn = toRPN(expr);

        std::cout << "\nOPZ: ";
        for (const auto& token : rpn)
            std::cout << token << " ";

        // Вычисление
        double result = evalRPN(rpn);

        std::cout << "\nRes: " << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "\nError: " << e.what() << std::endl;
    }

    return 0;
}