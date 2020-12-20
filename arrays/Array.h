//
// Created by mirag on 12/20/2020.
//

#ifndef ARRAYS_ARRAY_H
#define ARRAYS_ARRAY_H

#include <cassert>
#include <ostream>
#include <utility>

class IndexOutOfBoundsException : std::exception{};

template <typename T>
class Array {
private:
    T* m_ptr{nullptr};
    int m_size{0};

public:
    Array() = default;

    Array(const Array& source) {
        // Copy method
        if (!source.IsEmpty()) {
            m_size = source.m_size;
            m_ptr = new T[m_size]{};

            for (int i = 0; i < m_size; i++) {
                m_ptr[i] = source.m_ptr[i];
            }
        }
    }

    Array(Array&& source) noexcept {
        // Transfer ownership to another class
        m_ptr = source.m_ptr;
        m_size = source.m_size;

        // Clean up source
        source.m_ptr = nullptr;
        source.m_size = 0;
    }

    explicit Array(int size) {
        // Array constructor
        if (size != 0) {
            m_ptr = new T[size]{};
            m_size = size;
        }
    }

    ~Array() {
        delete[] m_ptr;
    }

    [[nodiscard]] int Size() const {
        return m_size;
    };

    [[nodiscard]] bool IsEmpty() const {
        return (m_size == 0);
    }

    [[nodiscard]] bool IsValidIndex(int index) const {
        return (index >= 0) && (index < m_size);
    }

    Array& operator=(Array& source) {
        if (this != &source) {
            swap(*this, source);
        }
        return *this;
    }

    int& operator[] (int index) {
        if (!IsValidIndex(index)) {
            throw IndexOutOfBoundsException{};
        }
        return m_ptr[index];
    }

    int operator[] (int index) const {
        if (!IsValidIndex(index)) {
            throw IndexOutOfBoundsException{};
        }
        return m_ptr[index];
    }

    friend void swap(Array& a, Array& b) noexcept {
        using std::swap;

        swap(a.m_ptr, b.m_ptr);
        swap(a.m_size, b.m_size);
    }

    friend std::ostream& operator<< (std::ostream& os, const Array& a) {
        // Override cout representation IntArray properly
        os << "[ ";
        for (int i = 0; i < a.Size(); i++) {
            os << a[i] << ' ';
        }
        os << "]";
        return os;
    }
};

#endif
