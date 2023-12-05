#include <iostream>
#include <algorithm>
#include <forward_list>
template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
    //정렬 됐는지 확인 변수
    bool sorted = false;
    //last값 변수
    ForwardIterator la = last;
    //정렬이 되어있지 않은 동안 반복
    while (!sorted) {
        //정렬이 되었다고 가정
        sorted = true;
        //it first로 초기화
        ForwardIterator it = first;
        //it의 다음값이 마지막 값이 아닐동안 반복
        for (it; std::next(it) != la; ++it) {
            //comp 기준에 맞춰 오름차순, 내림차순 정렬 it의 다음값과 it 값 비교
            if (comp(*std::next(it), *it)) {
                //it값과 it 다음 값 자리 변경
                std::iter_swap(it, std::next(it));
                //if문을 통과한다면 정렬되지 않은 것으로 상정
                sorted = false;
            }
        }
        //it의 마지막 값을 last로 바꿔줌(last-1)
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
