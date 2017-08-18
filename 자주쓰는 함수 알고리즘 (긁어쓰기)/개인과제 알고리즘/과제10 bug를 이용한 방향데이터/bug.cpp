#include <iostream>
#include <time.h>

using namespace std;


int main()
{
	srand(time(NULL));
	clock_t t;
	t = clock(); // 시작시간 설정

	const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	const int N = 20, M = 20;
	const int MAX_MOVE = 100000;		// 최대 이동 한도

	int tile[N][M] = { 0, };
	int playerPosX = M / 2;
	int playerPosY = N / 2;
	int full = N * M;	// 체크되어야할 tile 갯수
	int count;			// 체크된 tile 갯수
	int moveN = 0;		// 움직인 횟수
	int k;

	tile[playerPosY][playerPosX] = 1;
	count = 1;		// playerPosY, playerPosX는 이미 벌레가 있으므로

	while (count < full && moveN < MAX_MOVE)	// count >= full 일 경우 종료, moveN >= MAX_MOVE일 경우 종료
	{
		do
		{
			k = rand() % 8;		// 이동할 위치 지정
		} while (playerPosX + dx[k] < 0 || playerPosX + dx[k] >= N || playerPosY + dy[k] < 0 || playerPosY + dy[k] >= M);		// 만약 바깥으로 이동할 경우 다시 이동할 위치 선정.

		playerPosX += dx[k];
		playerPosY += dy[k];
		
		moveN++;
		if (tile[playerPosY][playerPosX] == 0)			// 이미 지나간 타일이 아니면
		{
			count++;
			tile[playerPosY][playerPosX] = 1;
		}
	}

	t = clock() - t; // 끝나는 시간 = 현재시간 - 시작시간

	cout << "총 이동수 : " << moveN << endl;
	cout << "수행시간 : " << (((float)t) / CLOCKS_PER_SEC) << endl;

	return 0;
}