// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память
#pragma once
#include <stdexcept>

template <typename T>
class Stack {
private:
    T* data;
    size_t capacity;
    size_t count;

    void resize(size_t newCap) {
        T* newData = new T[newCap];
        for (size_t i = 0; i < count; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCap;
    }

public:
    Stack(size_t initial = 8)
        : capacity(initial), count(0)
    {
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(const T& value) {
        if (count == capacity)
            resize(capacity * 2);
        data[count++] = value;
    }

    void pop() {
        if (empty())
            throw std::runtime_error("stack is empty");
        count--;
    }

    T& top() {
        if (empty())
            throw std::runtime_error("stack is empty");
        return data[count - 1];
    }

    const T& top() const {
        if (empty())
            throw std::runtime_error("stack is empty");
        return data[count - 1];
    }

    bool empty() const {
        return count == 0;
    }

    size_t size() const {
        return count;
    }

    void clear() {
        count = 0;
    }
};