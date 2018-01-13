#include "SetsGraph.h"

void SetsGraph::setGraph(int numberOfElements)
{
	if (numberOfElements < 2)
	{
		IoHandler ioh;
		ioh.putString("Must have at least 2 elements.");
		ioh.putNewLine();
	}

	size = numberOfElements;
	parent = new int[size];
	for (int i = 0; i < numberOfElements; ++i)
	{
		parent[i] = -1;	// 모든 원소가 집합
	}
}

// 더 적은 개수의 노드를 가진 집합을 더 큰 개수의 노드를 가진 집합에 합병
void SetsGraph::weightedUnion(int i, int j)
{	//  가중규칙을 이용하여 루트가 i와 j(i != j)인 합을 구한다.
	//	parent[i] = -count[i]이며 parent = -count[j]이다.
	int temp = parent[i] + parent[j];
	if (parent[i] > parent[j])	// i의 노드 수가 적으면
	{
		parent[i] = j;	// j를 새 루트로 만든다
		parent[j] = temp;
	}
	else // j의 노드 수가 적거나 같으면
	{
		parent[j] = i;	// i를 새 루트로 만든다
		parent[i] = temp;
	}
	return;
}
// 원소를 포함하는 루트를 찾으면서, 포함된 집합의 높이를 감소
int SetsGraph::collapsingFind(int i)
{	// 원소 i를 포함하는 루트를 찾는다.
	// 붕괴 규칙을 이용하여 i로부터 루트로 가는 모든 노드를 붕괴시킨다.
	int r = 0;
	for (r = i; parent[r] >= 0; r = parent[r]);	// 루트를 찾음
	while (i != r)	// 붕괴
	{
		int s = parent[i];
		parent[i] = r;
		i = s;
	}
	return r;
}