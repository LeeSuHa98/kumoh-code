#pragma once
template <class T> class Chain;

template <class T>
class Node
{
	friend class Chain<T>;
private:
	T data;
	Node<T>* link;

public:
	Node() { link = NULL; }
	Node(T d) { data = d; link = NULL; }
	~Node() {}
};
