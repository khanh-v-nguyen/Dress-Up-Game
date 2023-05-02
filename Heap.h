//
// Created by Khanh Nguyen on 3/23/23.
//

#ifndef MULTITEXT_HEAP_H
#define MULTITEXT_HEAP_H
#include <vector>
#include <iostream>

template <typename T>

class Heap
{
public:
    Heap();

    void push(T data);
    void pop();
    T top();
    int size();
    int empty();

    void printReheapUp();
    void printOrdered();
private:
    void privatePush(T data);
    std::vector<T> values;
    std::vector<T> poppedValues;
    int heapSize = 0;
    void reheapifyUp(int childIndex);
    void reheapifyDown(int parentIndex);
    void swap(int childIndex, int parentIndex);

    int getParent(int childIndex);
    int getLeftChild(int parentIndex);
    int getRightChild(int parentIndex);
    int getMaxChild(int parentIndex);

    void popLastItem(int parentIndex);

    void reheapifyDownALl(int parentIndex);
};

#include "Heap.cpp"
#endif//MULTITEXT_HEAP_H
