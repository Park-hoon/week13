#include <iostream>
#include <algorithm>
#include <forward_list>

template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
    bool sorted = false;
    ForwardIterator la = last;
    while (!sorted) {
        sorted = true;
        ForwardIterator it = first;
        for (it = first; std::next(it) != la; ++it) {
            if (comp(*std::next(it), *it)) {
                std::iter_swap(it, std::next(it));
                sorted = false;
            }
        }
        la = it;
    }
}

class compGreater {
public:
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

class compLess {
public:
    bool operator()(const int& a, const int& b) const {
        return a < b;
    }
};

int main() {
    std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };
    std::cout << "오름차순 정렬" << std::endl;
    bubble_sort(values.begin(), values.end(), compLess());
    for (const int& value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "내림차순 정렬" << std::endl;
    bubble_sort(values.begin(), values.end(), compGreater());
    for (const int& value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
