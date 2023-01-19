#pragma once
#include <iostream>
#include "Sequence.h"


using namespace std;

template <typename TKey, typename TElement>
class Pair
{
private:
	TKey key;
	TElement element;
public:
	Pair() {
		key = TKey();
		element = TElement();
	}

	Pair(TKey k, TElement el) {
		key = k;
		element = el;
	}
	~Pair();

	TKey GetKey() {
		return key;
	}
	TElement GetElement() {
		return element;
	}

	void SetKey(TKey x) {
		 key = x;
	}
	void SetElement(TElement x) {
		 element = x;
	}

	bool operator> (Pair<TKey, TElement> y);
	bool operator< (Pair<TKey, TElement> y);
	bool operator== (Pair<TKey, TElement> y);
	bool operator!= (Pair<TKey, TElement> y);
	Pair<TKey, TElement>& operator= (Pair<TKey, TElement> y);
};


template <typename TKey, typename TElement>
Pair<TKey, TElement>::~Pair()
{
}
template <typename TKey, typename TElement>
ostream& operator<<(ostream& os, Pair< TKey, TElement >& x) {
	os << "(" << x.GetKey() << " ~ " << x.GetElement() << ")";
	return os;
}
template <typename TKey, typename TElement>
bool Pair<TKey, TElement>::operator> (Pair<TKey, TElement> y) {
	if (this->key > y.key)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <typename TKey, typename TElement>
bool Pair<TKey, TElement>::operator< (Pair<TKey, TElement> y) {
	if (this->key < y.key)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <typename TKey, typename TElement>
bool  Pair<TKey, TElement>::operator== (Pair<TKey, TElement> y) {
	if (this->key == y.key && this->element == y.element)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <typename TKey, typename TElement>
bool  Pair<TKey, TElement>::operator!= (Pair<TKey, TElement> y) {
	if (this->key != y.key || this->element != y.element)
	{
		return false;
	}
	else
	{
		return true;
	}
}
template <typename TKey, typename TElement>
Pair<TKey, TElement>& Pair<TKey, TElement>::operator= (Pair<TKey, TElement> y) {
	Pair<TKey, TElement>::key = y.key;
	Pair<TKey, TElement>::element = y.element;
	return *this;
}