#include "FileHandler.h"

void FileHandler::loadMatrixGraph(string fileName, MatrixGraph& mg)
{
	ifstream fin;
	fin.open(fileName, ios_base::in);
	if (!fin)
	{
		cerr << "\n" << "can't open " << fileName << "!!";
		return;
	}

	int vertexNum = 0;
	int firstVertex = 0;
	int secondVertex = 0;

	int line = 0;
	// read data from file
	while (!fin.eof())
	{
		if (line == 0)
		{
			fin >> vertexNum;
			mg.setGraph(vertexNum);
			line++;

			continue;
		}

		fin >> firstVertex >> secondVertex;
		if (firstVertex == -1)
		{
			break;
		}

		mg.updateGraph(firstVertex, secondVertex);
	}
	// close file
	fin.close();
	return;
}

void FileHandler::loadListGraph(string fileName, ListGraph& lg)
{
	ifstream fin;
	fin.open(fileName, ios_base::in);
	if (!fin)
	{
		cerr << "\n" << "can't open " << fileName << "!!";
		return;
	}

	int vertexNum = 0;
	int secondVertex = 0;
	int firstVertex = 0;

	int line = 0;
	// read data from file
	while (!fin.eof())
	{
		if (line == 0)
		{
			fin >> vertexNum;
			lg.setGraph(vertexNum);
			line++;

			continue;
		}
		fin >> firstVertex >> secondVertex;

		if (firstVertex == -1)
		{
			break;
		}

		lg.updateGraph(firstVertex, secondVertex);

	}
	// close file
	fin.close();
	return;
}

void FileHandler::loadKruskal(string fileName, SetsGraph& sg, MinimumSpanningTree& mt)
{
	ifstream fin;
	fin.open(fileName, ios_base::in);
	if (!fin)
	{
		cerr << "\n" << "can't open " << fileName << "!!";
		return;
	}

	int vertexNum;
	int firstVertex;
	int secondVertex;
	int weight;

	int line = 0;
	// read data from file
	while (!fin.eof())
	{
		if (line == 0)
		{
			fin >> vertexNum;
			sg.setGraph(vertexNum);
			mt.setTree(vertexNum);
			line++;

			continue;
		}

		fin >> firstVertex >> secondVertex >> weight;

		if (firstVertex == -1)
		{
			break;
		}

		HeapNode t(firstVertex, secondVertex, weight);
		mt.pushNode(t);

	}
	// close file
	fin.close();
	return;
}