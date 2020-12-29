#include <iostream>
#include <vector>

constexpr int kNotFound = -1;

int LinearSearch(int element, const int* v, int size) {
    for(int i=0; i < size; i++) {
        if(v[i] == element) {
            return i;
        }
    }
    return kNotFound;
}

int BinarySearch(int element, const int* v, int size) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int middle = (right + left) / 2;
        if (v[middle] == element) {
            return middle;
        } else if (v[middle] < element) {
            left = middle + 1;
        } else if (v[middle] > element) {
            right = middle - 1;
        }
    }

    return kNotFound;
}

void Print(const std::vector<int>& v) {
    std::cout << "[ ";

    for (int x : v) {
        std::cout << x << ' ';
    }

    std::cout << "]\n";
}

int main() {
    std::vector<int> v{33, 44, 55, 11, 22};
    Print(v);

    int x;
    std::cin >> x;

    int pos = LinearSearch(x, v.data(), v.size());
    if (pos == kNotFound) {
        std::cout << "Element not found.\n";
    } else {
        std::cout << "Element found at index " << pos << ".\n";
    }

    return 0;
}
