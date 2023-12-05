#include <iostream>
#include <algorithm>
#include <forward_list>
template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
    //���� �ƴ��� Ȯ�� ����
    bool sorted = false;
    //last�� ����
    ForwardIterator la = last;
    //������ �Ǿ����� ���� ���� �ݺ�
    while (!sorted) {
        //������ �Ǿ��ٰ� ����
        sorted = true;
        //it first�� �ʱ�ȭ
        ForwardIterator it = first;
        //it�� �������� ������ ���� �ƴҵ��� �ݺ�
        for (it; std::next(it) != la; ++it) {
            //comp ���ؿ� ���� ��������, �������� ���� it�� �������� it �� ��
            if (comp(*std::next(it), *it)) {
                //it���� it ���� �� �ڸ� ����
                std::iter_swap(it, std::next(it));
                //if���� ����Ѵٸ� ���ĵ��� ���� ������ ����
                sorted = false;
            }
        }
        //it�� ������ ���� last�� �ٲ���(last-1)
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
    std::cout << "�������� ����" << std::endl;
    bubble_sort(values.begin(), values.end(), compLess());
    for (const int& value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "�������� ����" << std::endl;
    bubble_sort(values.begin(), values.end(), compGreater());
    for (const int& value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
