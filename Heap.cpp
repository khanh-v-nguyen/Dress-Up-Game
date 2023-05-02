//
// Created by Khanh Nguyen on 3/23/23.
//
#ifndef MULTITEXT_HEAP_CPP
#define MULTITEXT_HEAP_CPP

#include "Heap.h"

template<typename T>
Heap<T>::Heap()
{

}

template<typename T>
void Heap<T>::push(T data)
{
    privatePush(data);
}

template<typename T>
void Heap<T>::pop()
{
    swap(values.size()-1, 0);
    //std::cout << values[values.size()-1] << " "; // push back the last index (the greatest) to a new vector
    poppedValues.push_back(values[values.size()-1]);
    values.pop_back();
    reheapifyDown(0);
}

template<typename T>
T Heap<T>::top()
{
    return values[0];
}

template<typename T>
int Heap<T>::size()
{
    return values.size();
}

template<typename T>
int Heap<T>::empty()
{
    return values.size() == 0;
}

template<typename T>
void Heap<T>::privatePush(T data)
{
    if(values.empty())
    {
        values.push_back(data);
    }
    else
    {
        values.push_back(data);
        size();
        reheapifyUp(size()-1);
    }
}

template<typename T>
void Heap<T>::reheapifyDownALl(int parentIndex)
{
    while(!values.empty())
    {
        popLastItem(parentIndex);
        reheapifyDown(parentIndex);
    }
}

template<typename T>
void Heap<T>::reheapifyUp(int childIndex)
{
    if(values[childIndex] > values[(childIndex-1)/2])
    {
        swap(childIndex, (childIndex-1)/2);
        reheapifyUp((childIndex-1)/2);
    }
}

template<typename T>
void Heap<T>::reheapifyDown(int parentIndex)
{
    int childIndex = getMaxChild(parentIndex);
    if(childIndex == -1){return;}
    if (values[childIndex] > values[parentIndex])
    {
        swap(childIndex, parentIndex);
        reheapifyDown(childIndex);
    }
}


template<typename T>
void Heap<T>::popLastItem(int parentIndex)
{

}


template<typename T>
void Heap<T>::swap(int childIndex, int parentIndex)
{
    T temp = values[childIndex];
    values[childIndex] = values[parentIndex];
    values[parentIndex] = temp;
}

template<typename T>
int Heap<T>::getParent(int childIndex)
{
    return (childIndex - 1)/2;
}

template<typename T>
int Heap<T>::getLeftChild(int parentIndex)
{
    if(2*parentIndex +1< values.size())
    {
        return parentIndex * 2 + 1;
    }
    return -1;
}

template<typename T>
int Heap<T>::getRightChild(int parentIndex)
{
    if(2*parentIndex+2 < values.size())
    {
        return parentIndex * 2 + 2;
    }
    return -1;
}

template<typename T>
int Heap<T>::getMaxChild(int parentIndex)
{
    //int left = 2 * parentIndex + 1;
    //int right = 2 * parentIndex + 2;
    if(getLeftChild(parentIndex)==-1)
    {
        return-1;
    }
    else if (getRightChild(parentIndex)==-1)
    {
        return getLeftChild(parentIndex);
    }
    else if(values[getLeftChild(parentIndex)] > values[getRightChild(parentIndex)])
    {
        return getLeftChild(parentIndex);
    }
    else if(values[getRightChild(parentIndex)]> values[getLeftChild(parentIndex)])
    {
        return getRightChild(parentIndex);
    }
    return parentIndex;
}

template<typename T>
void Heap<T>::printOrdered()
{
    // reheaped up and down
    while(!empty())
    {
        pop();
    }

    for(int i = 0; i < poppedValues.size(); ++i)
    {
        std::cout << poppedValues[i] << " ";
    }
    std::cout << std::endl;
}


template<typename T>
void Heap<T>::printReheapUp()
{
    for(int i = 0; i < values.size(); ++i)
    {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
}

#endif
