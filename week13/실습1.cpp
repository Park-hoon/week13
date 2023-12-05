#include<iostream>
//sum ��� �ʱⰪ
template <typename T>
T sum(T num) { return num; }
//sum ��� �Լ�
template <typename T, typename...Ts>
T sum(T num, Ts... ts) { return num + sum(ts...); }
// ���
template <typename...Ts>
double average(Ts... ts) {
	int a = sum(ts...);
	return a / sizeof...(ts);
}

int main() {
	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl;
	return 0;
}