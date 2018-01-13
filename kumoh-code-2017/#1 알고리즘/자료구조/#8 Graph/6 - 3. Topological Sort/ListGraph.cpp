#include "ListGraph.h"
#include "FileHandler.h"

void ListGraph::setGraph(int numberOfElements)
{
	size = numberOfElements;
	ChainList = new Chain[size];
	return;
}

void ListGraph::updateGraph(int firstVertex, int secondVertex)
{
	ChainList[firstVertex].insertNode(new ChainNode(nullptr, secondVertex));
	ChainList[secondVertex].insertNode(new ChainNode(nullptr, firstVertex));
	return;
}

void ListGraph::dfs()
{
	Stack<ChainNode*> tstack;
	Stack<ChainNode*> stack;

	bool* visit = new bool[size];
	memset(visit, false, size);
	int visited = 0;
	ChainNode* thisNode = nullptr;
	ChainNode* firstStep = nullptr;

	IoHandler ioh;
	ioh.putString("인접리스트 + DFS");
	ioh.putNewLine();

	int connecctComponent = 1;	//	연결요소 개수
	int flag = 0;
	while (1)
	{
		firstStep = new ChainNode(nullptr, visited);

		visit[visited] = true;
		stack.Push(firstStep);
		tstack.Push(firstStep);

		while (1)
		{
			if (flag == 0)	//	다음 노드로 넘어가기 위해서 flag를 두어서 위치변동 못하게
			{
				thisNode = ChainList[visited].getNextNode();
				flag = 0;
			}

			if (thisNode == nullptr)
			{	//	Pop하면서 왔던 위치 되돌아가면서 안간 vertex 체크
				if (stack.IsEmpty() == true)
				{
					break;
				}
				thisNode = stack.Top();
				stack.Pop();
				continue;
			}

			if (visit[thisNode->getVertex()] == false)
			{
				visit[thisNode->getVertex()] = true;
				stack.Push(thisNode);
				tstack.Push(thisNode);
			}
			else
			{
				//	다음 노드로 이동
				flag++;
				thisNode = thisNode->getNextNode();
				continue;
			}
			visited = thisNode->getVertex();
			flag = 0;
		}



		ioh.putString("연결요소");
		ioh.putInteger(connecctComponent++);
		ioh.putString(" - ");

		while (1)
		{	//	출력하기 위해 임시 스텍에 연결요소를 옮겨담음
			stack.Push(tstack.Top());
			tstack.Pop();

			if (tstack.IsEmpty() == true)
			{
				break;
			}
		}

		while (1)
		{	//	출력
			ioh.printConnectedComponent(stack.Top()->getVertex());
			stack.Pop();

			if (stack.IsEmpty() == true)
			{
				break;
			}
		}
		ioh.putNewLine();

		delete firstStep;
		flag = 0;	//	다음 노드로 이동하지 않기 때문에 flag를 초기화하여 thisNode위치 재정의

					//	종료 조건
		int step = 0;
		for (int j = 0; j < size; j++)
		{
			if (visit[j] == true)
			{
				step++;
			}
		}
		if (step == size)
		{
			break;
		}

		//	방문하지 않은 vertex로 이동
		for (int j = 0; j < size; j++)
		{
			if (visit[j] == false)
			{
				visit[j] = true;
				visited = j;
				break;
			}
		}


	}
	delete[] visit;

	return;
}

void ListGraph::bfs()
{
	Queue<ChainNode*> tqueue;
	Queue<ChainNode*> queue;

	bool* visit = new bool[size];
	memset(visit, false, size);
	int visited = 0;
	ChainNode* thisNode = nullptr;
	ChainNode* firstStep = nullptr;

	IoHandler ioh;
	ioh.putString("인접리스트 + BFS");
	ioh.putNewLine();

	int connecctComponent = 1;	//연결요소 개수


	firstStep = new ChainNode(nullptr, visited);
	visit[visited] = true;

	//	queue.Push(firstStep);
	tqueue.Push(firstStep);

	int flag = 1;
	while (1)
	{
		thisNode = ChainList[visited].getNextNode();

		while (1)
		{
			if (thisNode == nullptr)	//인접된 vertex가 없을 때
			{
				break;
			}
			if (visit[thisNode->getVertex()] == false)
			{
				visit[thisNode->getVertex()] = true;
				queue.Push(thisNode);
				tqueue.Push(thisNode);
			}

			thisNode = thisNode->getNextNode();

			if (thisNode == nullptr)
			{
				break;
			}
		}

		if (queue.isEmpty() == false)
		{
			visited = queue.Front()->getVertex();
			queue.Pop();
			continue;
		}
		else
		{	//하나의 연결요소 완성
			ioh.putString("연결요소");
			ioh.putInteger(connecctComponent++);
			ioh.putString(" - ");

			while (1)
			{	//출력
				ioh.printConnectedComponent(tqueue.Front()->getVertex());
				tqueue.Pop();

				if (tqueue.isEmpty() == true)
				{
					break;
				}
			}
			ioh.putNewLine();

			delete firstStep;

			//방문하지 않은 vertex로 이동
			int unVisited = 0;
			for (int j = 0; j < size; j++)
			{
				if (visit[j] == false)
				{
					unVisited++;
					visit[j] = true;
					visited = j;

					firstStep = new ChainNode(nullptr, visited);
					tqueue.Push(firstStep);

					break;
				}
			}
			if (unVisited != 0)
			{
				continue;
			}
		}

		//종료 조건
		int step = 0;
		for (int i = 0; i < size; i++)
		{
			if (visit[i] == true)
			{
				step++;
			}
		}
		if (step == size)
		{
			break;
		}
	}

	return;
}

void ListGraph::printList()
{
	IoHandler ioh;

	for (int i = 0; i < size; i++)
	{
		ChainNode* thisNode = ChainList[i].getNextNode();
		ioh.putInteger(i);
		ioh.putString(" -> ");
		int start = 0;
		while (1)
		{

			if (start == 0 && thisNode == nullptr)
			{
				ioh.putString("null");
				break;
			}

			ioh.printConnectedComponent(thisNode->getVertex());

			if (thisNode->getNextNode() != nullptr)
			{
				ioh.putString("- ");
			}

			thisNode = thisNode->getNextNode();

			if (thisNode == nullptr)
			{
				break;
			}
			start++;	// 노드를 몇번 뛰어 넘었는지
		}
		ioh.putNewLine();
	}
	return;
}

void ListGraph::displayList(ListGraph& lg)
{
	IoHandler ioh;

	string fileName = ioh.getString("무방향 그래프가 저장된 파일명을 입력하시오.(종료는 quit) : ");
	if (fileName == "quit")
	{
		exit(1);
	}
	FileHandler fh;

	fh.loadListGraph(fileName, lg);

	ioh.putString("입력된 그래프의 인접 리스트 표현");
	ioh.putNewLine();

	lg.printList();
	ioh.putNewLine();

	lg.dfs();
	ioh.putNewLine();

	lg.bfs();
	ioh.putNewLine();
}