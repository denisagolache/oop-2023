#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;
template <class T>
class CircularQueue {
	vector<T> buffer;
	int capacity;
	int frontIndex;
	int rearIndex;
	int count;
public:
	CircularQueue(int size);
	void push(const T& element);
	void pop();
	T& front();
	T& back();
	int size()const;
	int empty()const;
};

template<class T>
inline CircularQueue<T>::CircularQueue(int maxSize) : capacity(maxSize), frontIndex(0), rearIndex(0), count(0)
{
	buffer.resize(maxSize);
}

template<class T>
inline void CircularQueue<T>::push(const T& element)
{
	if (count == capacity) {
		buffer[rearIndex] = element;
		rearIndex = (rearIndex + 1) % capacity;
		frontIndex = (frontIndex + 1) % capacity;
	}
	else {
		buffer[rearIndex] = element;
		rearIndex = (rearIndex + 1) % capacity;
		count++;
	}

}

template<class T>
inline void CircularQueue<T>::pop()
{
	if (count == 0)
		throw std::out_of_range("The queue is empty");
	else
	{
		frontIndex = (frontIndex + 1) % capacity;
		count--;
	}
}

template<class T>
inline T& CircularQueue<T>::front()
{
	if (count == 0)
		throw std::out_of_range("The queue is empty");
	else
		return buffer[frontIndex];
}

template<class T>
inline T& CircularQueue<T>::back()
{
	if (count == 0)
		throw std::out_of_range("The queue is empty");
	else {
		int lastIndex = (rearIndex - 1 + capacity) % capacity;
		return buffer[lastIndex];
	}
}

template<class T>
inline int CircularQueue<T>::size() const
{
	return count;
}

template<class T>
inline int CircularQueue<T>::empty() const
{
	return count == 0;
}

