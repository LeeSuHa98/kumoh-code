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

	int visited = 0;	//	0번 vertex부터 출발
	visit[visited] = true;
	stack.Push(visited);
	tstack.Push(visited);

	int connecctComponent = 1;	//	연결요소 개수

	IoHandler ioh;
	ioh.putString("인접행렬 + DFS");
	ioh.putNewLine();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (adjMatrix[i][j] == true)	//	간선이 있으면
			{
				if (visit[j] == false)	//	방문하지 않은 곳이면
				{
					visit[j] = true;
					stack.Push(j);	//	방문한 곳 Push
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
		{	//	출력하기 위해 임시 스텍에 연결요소를 옮겨담음
			stack.Push(tstack.Top());
			tstack.Pop();

			if (tstack.IsEmpty() == true)
			{
				break;
			}
		}

		ioh.putString("연결요소");
		ioh.putInteger(connecctComponent++);
		ioh.putString(" - ");

		while (1)
		{	//	출력
			ioh.printConnectedComponent(stack.Top());
			stack.Pop();

			if (stack.IsEmpty() == true)
			{
				break;
			}
		}
		ioh.putNewLine();

		//	종료 조건
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

		//	방문하지 않은 vertex로 이동
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

	int visited = 0;	//	0번 vertex부터 출발
	visit[visited] = true;

	queue.Push(visited);

	int connecctComponent = 1;	//	연결요소 개수

	IoHandler ioh;
	ioh.putString("인접행렬 + BFS");
	ioh.putNewLine();

	for (int i = 0; i < size; i++)
	{

		//	다음 vertex로 넘어왔는데 false면 연결요소가 끊어진 것
		if (visit[i] == false)
		{
			ioh.putString("연결요소");
			ioh.putInteger(connecctComponent++);
			ioh.putString(" - ");

			while (1)
			{	//	출력
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
		ioh.putString("연결요소");
		ioh.putInteger(connecctComponent++);
		ioh.putString(" - ");

		while (1)
		{	//	출력
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

	string fileName = ioh.getString("무방향 그래프가 저장된 파일명을 입력하시오.(종료는 quit) : ");
	if (fileName == "quit")
	{
		exit(1);
	}
	FileHandler fh;

	fh.loadMatrixGraph(fileName, mg);

	ioh.putString("입력된 그래프의 인접 행렬 표현");
	ioh.putNewLine();

	mg.printMatrix();
	ioh.putNewLine();

	mg.dfs();
	ioh.putNewLine();

	mg.bfs();
	ioh.putNewLine();
}