#include "RandomSort.h"
#include "IncreaseSort.h"
#include "DecreaseSort.h"
#include <iostream>
using namespace std;

void main()
{
	RandomSort rs;
	IncreaseSort is;
	DecreaceSort ds;
	

	cout << "[ 정렬 타입 ]" << endl;
	cout << " 1. Random Array" << endl << " 2. Increase Array" << endl << " 3. Decrease Array" << endl << " 4. Exit " << endl;
	cout << " Select Type -> ";

	int select;
	cin >> select;

	cout << endl;

	switch (select)
	{
	case 1:
		rs.randomSort();
		break;

	case 2:
		is.increaseSort();
		break;

	case 3:
		ds.decreaceSort();
		break;
	}
}
