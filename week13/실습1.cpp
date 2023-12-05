#include<iostream>
//sum 營敝 蟾晦高
template <typename T>
T sum(T num) { return num; }
//sum 營敝 л熱
template <typename T, typename...Ts>
T sum(T num, Ts... ts) { return num + sum(ts...); }
// ゎ敕
template <typename...Ts>
double average(Ts... ts) {
	int a = sum(ts...);
	return a / sizeof...(ts);
}

int main() {
	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl;
	return 0;
}