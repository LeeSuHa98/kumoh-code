#pragma once

class ChainNode
{
private:
	ChainNode* nextNode;
	int vertex;

public:
	ChainNode(ChainNode* newNode, int vertex)
	{
		this->nextNode = newNode;
		this->vertex = vertex;
	}
	~ChainNode() {}

	void setNextNode(ChainNode* newNode) { nextNode = newNode; }

	ChainNode* getNextNode() { return nextNode; }
	int getVertex() { return vertex; }
};