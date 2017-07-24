#include <iostream>

#include <iterator> // std::iterator,std::input_iterator_tag
#include <algorithm>
#include <iostream> // std::cout

template <typename T, size_t N>
class SampleVector
{
	T vector[N];
public:
	class iterator : public std::iterator<std::input_iterator_tag, T>
	{
		T* vector_ptr;
	public:
		iterator(T* vector) : vector_ptr(vector) {}
		T* operator->() { return vector_ptr; }
		iterator& operator++() { ++vector_ptr; return *this; }
		iterator operator++(int) { iterator tmp(*this); operator++(); return tmp; }
		bool operator==(const iterator& rhs) { return vector_ptr == rhs.vector_ptr; }
		bool operator!=(const iterator& rhs) { return vector_ptr != rhs.vector_ptr; }
		T& operator*() { return *vector_ptr; }
	};

	SampleVector() {}

	template <typename... Tp>
	SampleVector(Tp... vec) : vector{ vec... } {}

	iterator begin()
	{
		return iterator(vector);
	}

	iterator end()
	{
		return iterator(vector + N);
	}
};
class node {
public:
	node(double value) : _value(value) {};
	void showValue() { std::cout << _value << std::endl; }
private:
	double _value;
};

SampleVector<int, 5> vector(80, 40, 30, 45, 50);
SampleVector<node, 3> vector2(node(80), node(40), node(30));

int main()
{
	SampleVector<node, 3>::iterator iter = vector2.begin();
	iter->showValue();
	getchar();
	for (node value : vector2) {
		value.showValue();
		std::cout << ' ' << std::endl;
	}

}