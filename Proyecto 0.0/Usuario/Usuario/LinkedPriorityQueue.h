#pragma once
#include <iostream>
#include "PriorityQueue.h"
#include "LinkedQueue.h"

using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class LinkedPriorityQueue : public PriorityQueue <E>
{

private:

	LinkedQueue<E>* queues;
	int priorities;
	int size;

public:

	LinkedPriorityQueue(int priorities)
	{

		this->priorities = priorities;
		queues = new LinkedQueue<E>[priorities];
		size = 0;

	}

	~LinkedPriorityQueue()
	{
		delete[] queues;
	}

	void insert(E element, int priority)
	{

		if (priority < 0)
		{
			throw runtime_error("El numero de prioridad no es valido");
		}

		if (priority >= priorities)
		{
			throw runtime_error("El numero de prioridad no es valido");
		}

		queues[priority].enqueue(element);

		size++;
	}


	E min()
	{

		if (isEmpty())
		{
			throw runtime_error("La cola esta vacia");
		}

		for (int k = 0; k <= priorities; k++)
		{
			if (!queues[k].isEmpty())
			{
				return queues[k].frontValue();
			}

		}

		throw runtime_error("Error de sistema");
	}


	E removeMin()
	{

		if (isEmpty())
		{
			throw runtime_error("La cola esta vacia");
		}

		for (int k = 0; k < priorities; k++)
		{
			if (!queues[k].isEmpty())
			{

				size--;
				return queues[k].dequeue();
			}



		}

		throw runtime_error("Error");
	}



	void clear()
	{
		for (int k = 0; k < priorities; k++)
		{

			queues[k].clear();

		}

		size = 0;
	}


	int getSize()
	{

		return size;

	}


	bool isEmpty()
	{

		return size == 0;

	}


	void print()
	{


		for (int k = 0; k < priorities; k++)
		{

			cout << k << ":";

			queues[k].print();
		}


	}




};

