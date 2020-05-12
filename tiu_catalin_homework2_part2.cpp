// Tiu Catalin Group 3 SubGroup 4 Homework 1
// Part 2

#include <iostream>

using namespace std;

class BinaryHeap {
    const static int MAX_SIZE = 32;

    int heap[MAX_SIZE];

    int size;

public:
	BinaryHeap();

    int parent(int i);

    int leftChild(int i);

    int rightChild(int i);

    void swap(int *x, int *y);
    
    void insert(int data);

    void maxHeapify(int i);

    int getMax();

    int extractMax();

    void printHeap();

    int heapSort(int v[]);
};

BinaryHeap::BinaryHeap(){
        size = 0;
    }

int BinaryHeap::parent(int i) {
        return (i - 1) / 2;
    }

int BinaryHeap::leftChild(int i) {
        return 2*i + 1;
    }

int BinaryHeap::rightChild(int i) {
        return 2*i + 2;
    }

void BinaryHeap::swap(int *x, int *y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }

void BinaryHeap::insert(int data){
        if (size >= MAX_SIZE) {
            cout<<"The heap is full. Cannot insert"<<endl;
            return;
        }

        
        heap[size] = data;
        size = size + 1;


        int i = size - 1;
        while (i != 0 && heap[BinaryHeap::parent(i)] < heap[i]) {
            BinaryHeap::swap(&heap[BinaryHeap::parent(i)], &heap[i]);
            i = BinaryHeap::parent(i);
        }
    }

void BinaryHeap::maxHeapify(int i){

        int left = BinaryHeap::leftChild(i);

        int right = BinaryHeap::rightChild(i);

        int largest = i;

        if (left <= size && heap[left] > heap[largest]) {
            largest = left;
        }

        
        if (right <= size && heap[right] > heap[largest]) {
            largest = right;
        }

        
        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            maxHeapify(largest);
        }

    }

int BinaryHeap::getMax() {
        return heap[0];
    }

int BinaryHeap::extractMax() {
        int maxItem = heap[0];

        heap[0] = heap[size - 1];
        size = size - 1;

       
        maxHeapify(0);
        return maxItem;
    }

void BinaryHeap::printHeap(){
        for (int i = 0; i < size; i++) {
            cout<<heap[i]<<' ';
        }
        cout<<endl;
    }

int BinaryHeap::heapSort(int v[]){
    int i = 0;
    while(size){
        v[i] = BinaryHeap::extractMax();     
        i++;
    }
    return i;
}

//main
int main() {
    int v[32];
    BinaryHeap heap;
    heap.insert(7);
    heap.insert(5);
    heap.insert(2);
    heap.insert(4);
    heap.insert(11);
    heap.insert(13);
    cout << "Elements in the heap in normal order: ";
    heap.printHeap();
    int k = heap.heapSort(v);
    cout<<"\n";
    cout << "Element from the heap in sorted order: ";
    for(int i = k-1; i >= 0; i--){
        cout << v[i] << ' ';
    }
    return 0;
}