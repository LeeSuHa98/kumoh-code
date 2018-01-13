#include "MatrixGraph.h"
#include "FileHandler.h"

void MatrixGraph::setGraph(int numberOfElements)
{
	size = numberOfElements;
	adjMatrix = new bool*[size];
	for (int i = 0; i < size; i++)
	{
		adjMatrix[i] = new bool[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			adjMatrix[i][j] = false;
		}
	}
	return;
}

void MatrixGraph::updateGraph(int firstVertex, int secondVertex)
{
	adjMatrix[firstVertex][secondVertex] = true;
	adjMatrix[secondVertex][firstVertex] = true;
	return;
}

void MatrixGraph::dfs()
{
	bool* visit = new bool[size];
	memset(visit, false, size);
	Stack<int> tstack;
	Stack<int> stack;

	int visited = 0;	//	0�� vertex���� ���
	visit[visited] = true;
	stack.Push(visited);
	tstack.Push(visited);

	int connecctComponent = 1;	//	������ ����

	IoHandler ioh;
	ioh.putString("������� + DFS");
	ioh.putNewLine();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (adjMatrix[i][j] == true)	//	������ ������
			{
				if (visit[j] == false)	//	�湮���� ���� ���̸�
				{
					visit[j] = true;
					stack.Push(j);	//	�湮�� �� Push
					tstack.Push(j);
					int temp = i;
					i = j;
					j = temp;
					j = j - 1;
				}
			}
		}

		if (stack.IsEmpty() == false)
		{
			i = stack.Top();
			i = i - 1;
			stack.Pop();
			continue;
		}

		while (1)
		{	//	����ϱ� ���� �ӽ� ���ؿ� �����Ҹ� �Űܴ���
			stack.Push(tstack.Top());
			tstack.Pop();

			if (tstack.IsEmpty() == true)
			{
				break;
			}
		}

		ioh.putString("������");
		ioh.putInteger(connecctComponent++);
		ioh.putString(" - ");

		while (1)
		{	//	���
			ioh.printConnectedComponent(stack.Top());
			stack.Pop();

			if (stack.IsEmpty() == true)
			{
				break;
			}
		}
		ioh.putNewLine();

		//	���� ����
		int flag = 0;
		for (int j = 0; j < size; j++)
		{
			if (visit[j] == true)
			{
				flag++;
			}
		}
		if (flag == size)
		{
			break;
		}

		//	�湮���� ���� vertex�� �̵�
		for (int j = 0; j < size; j++)
		{
			if (visit[j] == false)
			{
				visit[j] = true;
				tstack.Push(j);
				i = j;
				i = i - 1;
				break;
			}
		}
	}	//	for end

	delete[] visit;
	return;
}

void MatrixGraph::bfs()
{
	bool* visit = new bool[size];
	memset(visit, false, size);
	Queue<int> queue;

	int visited = 0;	//	0�� vertex���� ���
	visit[visited] = true;

	queue.Push(visited);

	int connecctComponent = 1;	//	������ ����

	IoHandler ioh;
	ioh.putString("������� + BFS");
	ioh.putNewLine();

	for (int i = 0; i < size; i++)
	{

		//	���� vertex�� �Ѿ�Դµ� false�� �����Ұ� ������ ��
		if (visit[i] == false)
		{
			ioh.putString("������");
			ioh.putInteger(connecctComponent++);
			ioh.putString(" - ");

			while (1)
			{	//	���
				ioh.printConnectedComponent(queue.Front());
				queue.Pop();

				if (queue.isEmpty() == true)
				{
					break;
				}
			}
			ioh.putNewLine();
		}

		if (visit[i] == false)
		{
			visit[i] = true;
			queue.Push(i);
		}


		for (int j = 0; j < size; j++)
		{
			if (adjMatrix[i][j] == true)
			{
				if (visit[j] == false)
				{
					visit[j] = true;
					queue.Push(j);
				}
			}
		}
	}	//	for end

	if (queue.isEmpty() == false)
	{
		ioh.putString("������");
		ioh.putInteger(connecctComponent++);
		ioh.putString(" - ");

		while (1)
		{	//	���
			ioh.printConnectedComponent(queue.Front());
			queue.Pop();

			if (queue.isEmpty() == true)
			{
				break;
			}
		}
		ioh.putNewLine();
	}

	return;
}

void MatrixGraph::printMatrix()
{
	IoHandler ioh;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (adjMatrix[i][j] == true)
			{
				ioh.putInteger(1);
				ioh.putString(" ");
			}
			else
			{
				ioh.putInteger(0);
				ioh.putString(" ");
			}
		}
		ioh.putNewLine();
	}
}

void MatrixGraph::displayMatrix(MatrixGraph& mg)
{
	IoHandler ioh;

	string fileName = ioh.getString("������ �׷����� ����� ���ϸ��� �Է��Ͻÿ�.(����� quit) : ");
	if (fileName == "quit")
	{
		exit(1);
	}
	FileHandler fh;

	fh.loadMatrixGraph(fileName, mg);

	ioh.putString("�Էµ� �׷����� ���� ��� ǥ��");
	ioh.putNewLine();

	mg.printMatrix();
	ioh.putNewLine();

	mg.dfs();
	ioh.putNewLine();

	mg.bfs();
	ioh.putNewLine();
}