#include <iostream>

template<class T>
class functor {
public:
	functor(T* arr_, const int size_) {
		size = size_;
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = arr_[i];
		}
	}
	~functor() {
		delete[] arr;
	}
	void operator()(){
		get_sum(sum, arr, size);
		get_count(count, arr, size);
		std::cout << "[OUT]: get_sum() = " << sum << "\n";
		std::cout << "[OUT]: get_count() = " << count << "\n";
	}
private:
	T* arr;
	int size = 0;
	int sum = 0;
	int count = 0;
	void get_sum(int&, T*, const int);
	void get_count(int&, T*, const int);
};

template<class T>
void functor<T>::get_sum(int& sum, T* arr, const int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] % 3 == 0) {
			sum += arr[i];
		}
	}
}
template<class T>
void functor<T>::get_count(int& count, T* arr, const int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] % 3 == 0) {
			count += 1;
		}
	}
}
int main() {
	int size = 6;
	int* arr = new int[size] {4, 1, 3, 6, 25, 54};
	std::cout << "[IN]: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	functor<int> funct(arr, size);
	funct();
}