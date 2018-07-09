using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Omok
{
    public class intelligentMatch : match
    {
        private int playType;
        private int order;
        private const int N = 19;

        // 첫 주자이고 첫 번째 순서일 경우, 중앙 주변에 임의의 위치에 넣기 위한 코드임 
        public int getRandomPosition(ref int x, ref int y)
        {
            Random rnd = new Random();

            int k = (N + 1) / 2;
            x = rnd.Next(k - 1, k + 2);
            y = rnd.Next(k - 1, k + 2);
            return 1;
        }

        // 그 외의 경우, 각 위치의 유불리를 판단하여 가장 좋은 위치에 넣기 위한 코드임
        public int getStonePositionAuto(ref int x, ref int y)
        {
            int[,] value = new int[N, N];
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    value[i, j] = evaluatePosition(i, j);
                }
            }
            int max = 0;
            int maxi = 0, maxj = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (max < value[i, j])
                    {
                        max = value[i, j];
                        maxi = i;
                        maxj = j;
                    }
                }
            }
            x = maxi;
            y = maxj;
            if (max == 0) return 0;
            else return 1;
        }

        private int evaluatePosition(int x, int y)
        {
            int[] blacks = new int[8], whites = new int[8];
            int blackMax = 0, whiteMax = 0;
            int blockTypeBlack = 0, blockTypeWhite = 0, computerBlockType = 0, humanBlockType = 0;
            bool[] blackblocked = new bool[8], whiteblocked = new bool[8];

            if (omokboard.getStone(x, y) != 0) return 0; // 이미 다른 돌이 놓여 있으면

            //네 방향의 검은돌의 최대 갯수
            for (int i = 0; i < 8; i++) blacks[i] = 0;
            getCounts(x, y, 1, blacks, blackblocked, 8);
            getMax(blacks, blackblocked, 8, ref blackMax, ref blockTypeBlack);

            //네 방향의 흰돌의 최대 갯수
            for (int i = 0; i < 8; i++) whites[i] = 0;
            getCounts(x, y, 2, whites, whiteblocked, 8);
            getMax(whites, whiteblocked, 8, ref whiteMax, ref blockTypeWhite);

            int computerMax, humanMax;
            if (order == 1)
            { // 사람이 흑돌, 즉 첫번째 주자이면
                humanMax = blackMax;
                computerMax = whiteMax;
                humanBlockType = blockTypeBlack;
                computerBlockType = blockTypeWhite;
            }

            else
            {
                humanMax = whiteMax;
                computerMax = blackMax;
                humanBlockType = blockTypeWhite;
                computerBlockType = blockTypeBlack;
            }

            if (computerMax == 5) return 100;
            else if (humanMax == 5) return 90;
            else if (computerMax == 4 && computerBlockType == 0) return 80;
            else if (humanMax == 4 && humanBlockType == 0) return 75;
            else if (computerMax == 4 && computerBlockType == 1) return 70;
            else if (humanMax == 4 && humanBlockType == 1) return 65;
            else if (computerMax == 3 && computerBlockType == 0) return 60;
            else if (humanMax == 3 && humanBlockType == 0) return 55;
            else if (computerMax == 3 && computerBlockType == 1) return 50;
            else if (humanMax == 3 && humanBlockType == 1) return 45;
            else if (computerMax == 2 && computerBlockType == 0) return 40;
            else if (humanMax == 2 && humanBlockType == 0) return 35;
            else if (computerMax == 2 && computerBlockType == 1) return 30;
            else if (humanMax == 2 && humanBlockType == 1) return 25;
            else if (computerMax == 1 && computerBlockType == 0) return 20;
            else if (humanMax == 1 && humanBlockType == 0) return 15;
            else if (computerMax == 1 && computerBlockType == 1) return 10;
            else if (humanMax == 1 && humanBlockType == 1) return 5;

            return 0;
        }

        private void getMax(int[] a, bool[] b, int size, ref int max, ref int blocktype)
        { // a는 갯수 배열, b는 블락킹 여부 배열
            int[] d = new int[4];

            for (int i = 0; i < 4; i++) d[i] = 0;
            d[0] = a[0] + a[4] + 1;
            d[1] = a[2] + a[6] + 1;
            d[2] = a[3] + a[7] + 1;
            d[3] = a[1] + a[5] + 1;

            max = 0;
            int dir = 0;
            for (int i = 0; i < 4; i++)
            {
                if (d[i] > max)
                {
                    max = d[i];
                    dir = i;
                }
            }

            switch (dir)
            {
                case 0:
                    if (b[0] == true || b[4] == true) blocktype = 2;
                    else if (b[0] == false && b[4] == false) blocktype = 0;
                    else blocktype = 1;
                    break;
                case 1:
                    if (b[1] == true || b[5] == true) blocktype = 2;
                    else if (b[1] == false && b[5] == false) blocktype = 0;
                    else blocktype = 1;
                    break;
                case 2:
                    if (b[2] == true || b[6] == true) blocktype = 2;
                    else if (b[2] == false && b[6] == false) blocktype = 0;
                    else blocktype = 1;
                    break;
                case 3:
                    if (b[3] == true || b[7] == true) blocktype = 2;
                    else if (b[3] == false && b[7] == false) blocktype = 0;
                    else blocktype = 1;
                    break;
            }
        }

        private void getCounts(int x, int y, int type, int[] counts, bool[] blocked, int size)
        {
            int nx, ny, val;

            //0방향
            ny = y - 1;
            while (ny >= 0)
            {
                val = omokboard.getStone(x, ny);
                if (val == type)
                {
                    counts[0]++;
                    ny--;
                }
                else if (val == 2)
                {
                    blocked[0] = true;
                    break;
                }
                else
                {//반대인 경우
                    blocked[0] = false;
                    break;
                }
            }

            //1방향
            nx = x + 1;
            ny = y - 1;
            while (nx < N && ny >= 0)
            {
                val = omokboard.getStone(nx, ny);
                if (val == type)
                {
                    counts[1]++;
                    nx++;
                    ny--;
                }
                else if (val == 2)
                {
                    blocked[1] = true; // 수정(2015.7.3)
                    break;
                }
                else
                {//반대인 경우
                    blocked[1] = false; // 수정(2015.7.3)
                    break;
                }
            }

            //2방향
            nx = x + 1;
            while (nx < N)
            {
                val = omokboard.getStone(nx, y);
                if (val == type)
                {
                    counts[2]++;
                    nx++;
                }
                else if (val == 2)
                {
                    blocked[2] = true; // 수정(2015.7.3)
                    break;
                }
                else
                {//반대인 경우
                    blocked[2] = false; // 수정(2015.7.3)
                    break;
                }
            }

            //3방향
            nx = x + 1;
            ny = y + 1;
            while (nx < N && ny < N)
            {
                val = omokboard.getStone(nx, ny);
                if (val == type)
                {
                    counts[3]++;
                    nx++;
                    ny++;
                }
                else if (val == 2)
                {
                    blocked[3] = true; // 수정(2015.7.3)
                    break;
                }
                else
                {//반대인 경우
                    blocked[3] = false; // 수정(2015.7.3)
                    break;
                };
            }

            //4방향
            ny = y + 1;
            while (ny < N)
            {
                val = omokboard.getStone(x, ny);
                if (val == type)
                {
                    counts[4]++;
                    ny++;
                }
                else if (val == 2)
                {
                    blocked[4] = true; // 수정(2015.7.3)
                    break;
                }
                else
                {//반대인 경우
                    blocked[4] = false; // 수정(2015.7.3)
                    break;
                }
            }

            //5방향
            nx = x - 1;
            ny = y + 1;
            while (nx >= 0 && ny < N)
            {
                val = omokboard.getStone(nx, ny);
                if (val == type)
                {
                    counts[5]++;
                    nx--;
                    ny++;
                }
                else if (val == 2)
                {
                    blocked[5] = true; // 수정(2015.7.3)
                    break;
                }
                else
                {//반대인 경우
                    blocked[5] = false; // 수정(2015.7.3)
                    break;
                }
            }

            //6방향
            nx = x - 1;
            while (nx >= 0)
            {
                val = omokboard.getStone(nx, y);
                if (val == type)
                {
                    counts[6]++;
                    nx--;
                }
                else if (val == 2)
                {
                    blocked[6] = true; // 수정(2015.7.3)
                    break;
                }
                else
                {//반대인 경우
                    blocked[6] = false; // 수정(2015.7.3)
                    break;
                }
            }

            //7방향
            nx = x - 1;
            ny = y - 1;
            while (nx >= 0 && ny >= 0)
            {
                val = omokboard.getStone(nx, ny);
                if (val == type)
                {
                    counts[7]++;
                    nx--;
                    ny--;
                }
                else if (val == 2)
                {
                    blocked[7] = true; // 수정(2015.7.3)
                    break;
                }
                else
                {//반대인 경우
                    blocked[7] = false; // 수정(2015.7.3)
                    break;
                }
            }

        }

        public void setPlayType(int type)
        {
            playType = type;
        }

        public int getPlayType()
        {
            return playType;
        }

        //public void play()
        //{
        //    int m = selectPlayType();
        //    if (m == 1)
        //    {
        //        //base.registerPlayers();
        //        base.play();
        //    }
        //    else
        //    {
        //        //registerPlayers();
        //        playwithcomputer();
        //    }
        //}
        public void putStone(int x, int y, int stone)
        {
            omokboard.putStone(x, y, stone);
        }

        public int getStone(int x, int y)
        {
            return omokboard.getStone(x, y);
        }

        public bool isValid(int r, int c) 
        {
            if (omokboard.getStone(r, c) == 0) return true;
            else return false;
        }

        //public void playwithcomputer()
        //{
        //    bool flag, firstTime = true;
        //    int check;
        //    int i = 0, j = 0;
        //    string winner;

        //    omokboard.clear();
        //    omokboard.display();
        //    while (true)
        //    {
        //        if (order == getturn())
        //        {  // order는 사용자의 순서를 저장하는 변수
        //            check = getstoneposition(ref i, ref j);
        //        }
        //        else
        //        {
        //            if (firstTime == true)
        //            {
        //                check = getRandomPosition(ref i, ref j);
        //                firstTime = false;
        //            }
        //            else check = getStonePositionAuto(ref i, ref j);
        //        }

        //        if (check == -1) break; // 음수 위치 입력 시
        //        else if (check == 1)
        //        { // 자리가 비어 있을 경우

        //            omokboard.putStone(i, j, getturn());
        //            omokboard.display();
        //            flag = checkwinningcondition();

        //            if (flag == true)
        //            {
        //                if (getturn() == 1) winner = getfirstplayer();
        //                else winner = getsecondplayer();
        //                Console.Write("축하합니다. " + winner + "이(가) 이겼습니다.");
        //                return;
        //            }
        //            else
        //            {
        //                if (getturn() == 1)
        //                { // 첫번째 주자이면
        //                    Console.WriteLine();
        //                    Console.WriteLine(getfirstplayer() + "가 " + i + ", " + j + "위치에 돌을 놓았습니다.");
        //                    Console.WriteLine();
        //                    setturn(2);
        //                }
        //                else
        //                {
        //                    Console.WriteLine();
        //                    Console.WriteLine(getsecondplayer() + "가 " + i + ", " + j + "위치에 돌을 놓았습니다.");
        //                    Console.WriteLine();
        //                    setturn(1);
        //                }
        //            }
        //        }
        //        else
        //        { // 자리가 차 있을 경우
        //            Console.WriteLine("이미 있는 자리입니다. 다시 놓으세요.");
        //        }
        //    }
        //}
    }
}
