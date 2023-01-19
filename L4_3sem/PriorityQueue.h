#pragma once
#include <iostream>
#include "Sequence.h"
#include "Pair.h"
using namespace std;

template <typename T>
class PriorityQueue: private ArraySequence<T>
{
private:
	DynamicArray<T> items;
public:
	PriorityQueue() {}
	~PriorityQueue() {}

	T Get(int index);
	T GetFirst();
	T GetLast();
//	ArraySequence<T>* GetSubsequence(int startIndex, int endIndex);
//	void Append(T item);
//	void Prepend(T item);
//	void InserAt(int index, T item);
//	void Remove(T item);
	void DelEnd();

	T& operator[](int index) override;
	void operator= (PriorityQueue<T> array);


	T Peek(int i) {
		return Get(i);
	}
	T PeekFirst() {
		return GetFirst();
	}
	T PeekLast() {
		return GetLast();
	}
	void Enqueue(T item/*, int priority*/);
	T Dequeue();

	bool empty();
};

template<typename T>
T PriorityQueue<T>::Dequeue() {
	T tmp = PeekLast();
	DelEnd();
	return tmp;
}

template<typename T>
void PriorityQueue<T>::Enqueue(T item/*, int priority*/) {
	items.Resize(items.GetSize() + 1);
	int i = 0;
	while (items[i] > item && i < items.GetSize())
	{
		i++;
	}
	for (int j = items.GetSize() - 1; j > i; j--)
	{
		items[j] = items[j - 1];
	}
	items[i] = item;
}

template<typename T>
bool PriorityQueue<T>::empty() {
	if (items.GetSize() > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<typename T>
T PriorityQueue<T>::GetFirst() {
	return (this->items).GetFirst();
}

template<typename T>
T PriorityQueue<T>::GetLast() {
	return this->items.GetLast();
}

template<typename T>
T PriorityQueue<T>::Get(int index) {
	return this->items.Get(index);
}

template<typename T>
void PriorityQueue<T>::DelEnd() {
	this->items.DelEnd();
}

template<typename T>
T& PriorityQueue<T>::operator[](int index) {
	return this->items[index];
}

template<typename T>
void PriorityQueue<T>::operator=(PriorityQueue<T> array) {
	this->items = array.items;

}