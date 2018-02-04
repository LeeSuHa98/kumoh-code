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
	ioh.putString("��������Ʈ + DFS");
	ioh.putNewLine();

	int connecctComponent = 1;	//	������ ����
	int flag = 0;
	while (1)
	{
		firstStep = new ChainNode(nullptr, visited);

		visit[visited] = true;
		stack.Push(firstStep);
		tstack.Push(firstStep);

		while (1)
		{
			if (flag == 0)	//	���� ���� �Ѿ�� ���ؼ� flag�� �ξ ��ġ���� ���ϰ�
			{
				thisNode = ChainList[visited].getNextNode();
				flag = 0;
			}

			if (thisNode == nullptr)
			{	//	Pop�ϸ鼭 �Դ� ��ġ �ǵ��ư��鼭 �Ȱ� vertex üũ
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
				//	���� ���� �̵�
				flag++;
				thisNode = thisNode->getNextNode();
				continue;
			}
			visited = thisNode->getVertex();
			flag = 0;
		}



		ioh.putString("������");
		ioh.putInteger(connecctComponent++);
		ioh.putString(" - ");

		while (1)
		{	//	����ϱ� ���� �ӽ� ���ؿ� �����Ҹ� �Űܴ���
			stack.Push(tstack.Top());
			tstack.Pop();

			if (tstack.IsEmpty() == true)
			{
				break;
			}
		}

		while (1)
		{	//	���
			ioh.printConnectedComponent(stack.Top()->getVertex());
			stack.Pop();

			if (stack.IsEmpty() == true)
			{
				break;
			}
		}
		ioh.putNewLine();

		delete firstStep;
		flag = 0;	//	���� ���� �̵����� �ʱ� ������ flag�� �ʱ�ȭ�Ͽ� thisNode��ġ ������

					//	���� ����
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

		//	�湮���� ���� vertex�� �̵�
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
	ioh.putString("��������Ʈ + BFS");
	ioh.putNewLine();

	int connecctComponent = 1;	//������ ����


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
			if (thisNode == nullptr)	//������ vertex�� ���� ��
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
		{	//�ϳ��� ������ �ϼ�
			ioh.putString("������");
			ioh.putInteger(connecctComponent++);
			ioh.putString(" - ");

			while (1)
			{	//���
				ioh.printConnectedComponent(tqueue.Front()->getVertex());
				tqueue.Pop();

				if (tqueue.isEmpty() == true)
				{
					break;
				}
			}
			ioh.putNewLine();

			delete firstStep;

			//�湮���� ���� vertex�� �̵�
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

		//���� ����
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
			start++;	// ��带 ��� �پ� �Ѿ�����
		}
		ioh.putNewLine();
	}
	return;
}

void ListGraph::displayList(ListGraph& lg)
{
	IoHandler ioh;

	string fileName = ioh.getString("������ �׷����� ����� ���ϸ��� �Է��Ͻÿ�.(����� quit) : ");
	if (fileName == "quit")
	{
		exit(1);
	}
	FileHandler fh;

	fh.loadListGraph(fileName, lg);

	ioh.putString("�Էµ� �׷����� ���� ����Ʈ ǥ��");
	ioh.putNewLine();

	lg.printList();
	ioh.putNewLine();

	lg.dfs();
	ioh.putNewLine();

	lg.bfs();
	ioh.putNewLine();
}