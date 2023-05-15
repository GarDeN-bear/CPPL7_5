#include <iostream>
#include <vector>

template <class T>
T squaring(T num) {
	return num * num;
}

template <class T>

std::vector<T> squaring(std::vector<T> &v) {
	for (int i = 0; i < v.size(); i ++) {
		v[i] = v[i] * v[i];
	}
	return v;
}
int main() {	
	int num = 4;
	std::cout << "[IN]: " << num << "\n";
	std::cout << "[OUT]: " << squaring(num) << "\n";
	std::vector<int> v{ -1, 4, 8 };
	std::cout << "[IN]: ";
	for (const auto vi : v) {
		std::cout << vi << " ";
	}
	std::cout << "\n";
	squaring(v);
	std::cout << "[OUT]: ";
	for (const auto vi : v) {
		std::cout << vi << " ";
	}
	std::cout << "\n";

}