#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parent]) {
            std::swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    
    MaxHeap() {}

    // Insert a value into the heap
    void insert(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;
        heapifyUp(index);
    }
    int extractMax() {
        if (heap.empty()) {
            std::cerr << "Heap is empty!" << std::endl;
            return -1;
        }

        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return max;
    }

    int size() {
        return heap.size();
    }
};

int main() {
    MaxHeap maxHeap;

    maxHeap.insert(5);
    maxHeap.insert(10);
    maxHeap.insert(3);
    maxHeap.insert(8);
    maxHeap.insert(1);

    std::cout << "Max Heap: ";
    while (maxHeap.size() > 0) {
        std::cout << maxHeap.extractMax() << " ";
    }
    std::cout << std::endl;

    return 0;
}
