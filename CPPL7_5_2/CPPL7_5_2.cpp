#include <iostream>
#include <cassert>
#include <vector>

template<class T>
class smart_array {
public:
	smart_array() {
		size = 0;
		smartArray = new T[size];
	}
	smart_array(int size_) {
		size = size_;
		smartArray = new T[size];
	}
	smart_array& operator=(const smart_array&) = delete;
	T& operator[](int j) {
		columns = size;
		assert(j >= 0 && j < columns);
		return smartArray[j];
	}
	void resize(const int n) {
		delete[] smartArray;
		smartArray = nullptr;
		size = n;
		smartArray = new T[size];
	}
	~smart_array() {
		delete[] smartArray;
		smartArray = nullptr;
	}
private:
	int size; // количесвто элементов 
	int columns;
	T* smartArray;
};


template<class T>
class table {
public:
	table(int rows_, int columns_) {
		rows = rows_;
		columns = columns_;
		elements.resize(rows);
		for (int i = 0; i < rows; i++) {
			elements[i].resize(columns);
		}
	}
	smart_array<T>& operator[](int i) {
		assert(i >= 0 && i < rows);
		return elements[i];
	}
	void Size() const {
		std::cout << "rows = " << rows << ", columns = " << columns << "\n";
	}
private:
	int rows;
	int columns;
	smart_array<smart_array<T>> elements;
};


int main() {
	table<int> tab = table<int>(2, 3);
	tab[0][0] = 4;
	std::cout << tab[0][0] << "\n";
	tab.Size();
}