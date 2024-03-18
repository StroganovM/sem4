#include "heap.h"

int main() {
	TDHeap<int> heap(7); // Create a 3-ary heap of integers

	heap.insert(5);
	heap.insert(6);
	heap.insert(7);
	heap.insert(9);
	heap.insert(8);
	heap.insert(11);
	heap.insert(10);
	heap.printData();

	return 0;
}
