#include<vector>
#include <algorithm>
#include<iostream>
template<typename T>
class TDHeap {
	std::vector <T> data;
	size_t D;
public:
	TDHeap(size_t D = 2) : D(D) {}
	//TDHeap(const TDHeap<T>& Heap) : data(Heap.data), D(Heap.D) {}
	TDHeap(const TDHeap<T>& Heap) : data(Heap.data) {
		D = Heap.D;
	}
	void insert(const T& val) {
		data.push_back(val);
		balanse_up(data.size() - 1);
	}
	size_t find(const T& val) {
		auto it = std::find(data.begin(), data.end(), val);
		if (it != data.end()) {
			return std::distance(data.begin(), it);
		}
		return -1;
	}
	void del(const T& val){

	}
	void balanse_up(size_t index) {
		size_t cur = index;
		size_t parentIndex = parent(cur);

		while (cur > 0 && data[cur] < data[parentIndex]) {
			std::swap(data[cur], data[parentIndex]);
			cur = parentIndex;
			parentIndex = parent(cur);
		}
	}
	void balanse_down(size_t index) {
		auto parent_ = parent(index);
		auto cur = index;
		while (cur < parent_) {
			std::swap(data[cur], data[parent_]);
			cur = parent_;
			parent_ = parent(cur);
		}
	}
	size_t child(size_t index, size_t childNum) {
		return(childNum + D * index + 1);
	}
	size_t left(size_t index) {
		return(child(index, 0));
	}
	size_t right(size_t index) {
		return(child(index, D - 1));
	}
	const T& front() {
		return data[0];
	}
	void pop() {
		del(data[0]);
	}
	size_t parent(size_t index) {
		if (index % D == 0) {
			return index - 1;
		}
		return index / D;
	}
	void printData() const {
		std::cout << "Data: ";
		for (const auto& val : data) {
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}
};
