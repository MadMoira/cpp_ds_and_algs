#include <iostream>
#include <cassert>

class IndexOutOfBoundsException : public std::exception {};

class IntArray {
    private:
        int * m_ptr{nullptr};
        int m_size{0};

    public:
        IntArray() = default;

        explicit IntArray(int size) {
            if (size != 0) {
                m_ptr = new int [size]{};
                m_size = size;
            }
        }

        ~IntArray() {
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
};

int main() {
    IntArray a{};
    assert(a.IsEmpty());

    IntArray b{10};
    assert(!b.IsEmpty());

    IntArray c{3};
    c[0] = 10;

    std::cout << c[0] << std::endl;

    try {
        c[4];
    } catch (const IndexOutOfBoundsException& e) {
        std::cout << "Index out of bounds exception";
    }

    return 0;
}
