#pragma once
class HeapNode
{
private:
	int firstVertex;	// tail
	int secondVertex;	// head
	int weight;

public:
	HeapNode() {}
	HeapNode(int firstVertex, int secondVertex, int weight)
	{
		this->firstVertex = firstVertex;
		this->secondVertex = secondVertex;
		this->weight = weight;
	}
	~HeapNode() {}

	int getFirstVertex() { return firstVertex; }
	int getSecondVertex() { return secondVertex; }
	int getWeight() { return weight; }

};