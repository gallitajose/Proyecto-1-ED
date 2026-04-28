#pragma once

#include <stdexcept>
#include <iostream>
#include "PriorityQueue.h"
#include "Pair.h"
#include "MinHeap.h"

using std::runtime_error;

template<typename E>
class HeapPriorityQueue : public PriorityQueue<E>
{

private:

	MinHeap<Pair<int, E>>* pairs;

public:

	HeapPriorityQueue(int max = DEFAULT_MAX)
	{
		pairs = new MinHeap<Pair<int, E>>(max);
	}

	~HeapPriorityQueue()
	{
		delete pairs;
	}

	void insert(E element, int priority)
	{
		Pair<int, E> pairs(priority, element);
		pairs->insert();
	}

	E min()
	{
		Pair<int, E> pairs = pairs->first();
		return pairs.value;
	}

	E removeMin()
	{
		Pair<int, E> p = pairs->removeFirst();
		return p.value;
	}



	void clear()
	{
		pairs->clear();
	}


	int getSize()
	{

		return pairs->getSize();

	}


	bool isEmpty()
	{

		return pairs->isEmpty();

	}


	void print()
	{

		pairs->print();

	}
};
