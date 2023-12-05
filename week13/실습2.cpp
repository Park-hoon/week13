#include<iostream>
#include<string>
#include<algorithm>

//min_value ��� �ʱⰪ
template<typename T>
double min_value(T x) {
	return x;
}

//min_vlaue ��� �Լ�
template<typename T, typename... Args>
double min_value(T x, Args... args) {
	T min = min_value(args...);
	return std::min(x, min);

}

int main() {
	auto x = min_value(42, 3.14, 11.1f, -2);
	std::cout << x;

	getchar();
	return 0; 
}