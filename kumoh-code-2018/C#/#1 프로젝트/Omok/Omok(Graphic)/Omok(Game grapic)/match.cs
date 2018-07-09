using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Omok
{
    public class match
    {
        private const int n = 19;
        private string firstplayer;
        private string secondplayer;
        private int turn;
        private int seq1 = 0, seq2 = 0;

        private bool check1(int x, int y)
        {
            if (omokboard.getStone(x, y) != 0 && (y + 4) < n)
            {
                return omokboard.getStone(x, y) == omokboard.getStone(x, y + 1) && omokboard.getStone(x, y + 1) == omokboard.getStone(x, y + 2) && omokboard.getStone(x, y + 2) == omokboard.getStone(x, y + 3) && omokboard.getStone(x, y + 3) == omokboard.getStone(x, y + 4);
            }
            else return false;
        }
        private bool check2(int x, int y)
        {
            if (omokboard.getStone(x, y) != 0 && (x + 4) < n)
            {
                return omokboard.getStone(x, y) == omokboard.getStone(x + 1, y) && omokboard.getStone(x + 1, y) == omokboard.getStone(x + 2, y) && omokboard.getStone(x + 2, y) == omokboard.getStone(x + 3, y) && omokboard.getStone(x + 3, y) == omokboard.getStone(x + 4, y);
            }
            else return false;
        }
        private bool check3(int x, int y)
        {
            if (omokboard.getStone(x, y) != 0 && (x + 4) < n && (y + 4) < n)
            {
                return omokboard.getStone(x, y) == omokboard.getStone(x + 1, y + 1) && omokboard.getStone(x + 1, y + 1) == omokboard.getStone(x + 2, y + 2) && omokboard.getStone(x + 2, y + 2) == omokboard.getStone(x + 3, y + 3) && omokboard.getStone(x + 3, y + 3) == omokboard.getStone(x + 4, y + 4);
            }
            else return false;
        }
        private bool check4(int x, int y)
        {
            if (omokboard.getStone(x, y) != 0 && (x + 4) < n && (y - 4) >= 0)
            {
                return omokboard.getStone(x, y) == omokboard.getStone(x + 1, y - 1) && omokboard.getStone(x + 1, y - 1) == omokboard.getStone(x + 2, y - 2) && omokboard.getStone(x + 2, y - 2) == omokboard.getStone(x + 3, y - 3) && omokboard.getStone(x + 3, y - 3) == omokboard.getStone(x + 4, y - 4);
            }
            else return false;
        }

        protected board omokboard = new board();
        public match() {
            turn = 1; 
}
        public int getturn()
        {
            return turn;
        }
        public void setturn(int t)
        {
            turn = t;
        }

        public string getfirstplayer()
        {
            return firstplayer;
        }
        public void setfirstplayer(string name)
        {
            firstplayer = name;
        }

        public string getsecondplayer()
        {
            return secondplayer;
        }
        public void setsecondplayer(string name)
        {
            secondplayer = name;
        }

        public int getstoneposition(ref int x, ref int y)
        {
            string player = "";

            if (turn == 1) player = firstplayer;
            else if (turn == 2) player = secondplayer;
            string stone = "";

            if (turn == 1) stone = "검은돌";
            else if (turn == 2) stone = "흰돌";
            Console.WriteLine("이번에는 " + player + " 차례이며 " + stone + "입니다. 놓을 위치를 입력하세요.");
            Console.WriteLine(" 단, 게임을 종료하고 싶으면 음수의 값을 입력하세요.");
            Console.Write("행 >>");
            string line = Console.ReadLine();
            x = Convert.ToInt32(line);
            Console.Write("열 >>");
            line = Console.ReadLine();
            y = Convert.ToInt32(line);

            if (x < 0 || y < 0)
                return -1;
            if (omokboard.getStone(x, y) == 0) // 비어 있는 위치이면
                return 1;
            else
                return 0;
        }

        public bool checkwinningcondition()
        {
            int x, y;
            for (x = 0; x < n; x++)
            {
                for (y = 0; y < n; y++)
                {
                    if (check1(x, y) == true || check2(x, y) == true || check3(x, y) == true || check4(x, y) == true)
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        public void setSequenceNumber(int turn, int n) {
            if (turn == 1) seq1 = n;
            else seq2 = n;
        }
        public int getSequenceNumber(int turn)
        {
            if (turn == 1) return seq1;
            else return seq2;
        }
        public void incrementSequenceNumber(int turn)
        {
            if (turn == 1) seq1++;
            else seq2++;
        }
        public void decrementSequenceNumber(int turn)
        {
            if (turn == 1) seq1--;
            else seq2--;
        }
        //public void play()
        //{
        //    bool flag;
        //    int check;
        //    int i = 0, j = 0;
        //    string winner;

        //    omokboard.clear();
        //    omokboard.display();
        //    while (true)
        //    {
        //        check = getstoneposition(ref i, ref j);
        //        if (check == -1) break; // 음수값 입력 시
        //        else if (check == 1)
        //        { // 자리가 비어 있을 경우
        //            omokboard.putStone(i, j, turn);
        //            omokboard.display();
        //            flag = checkwinningcondition();

        //            if (flag == true)
        //            {
        //                if (turn == 1) winner = firstplayer;
        //                else winner = secondplayer;
        //                Console.Write("축하합니다. " + winner + "이(가) 이겼습니다.");
        //                return;
        //            }
        //            else
        //            {
        //                if (turn == 1)
        //                { // 첫번째 주자이면
        //                    Console.WriteLine();
        //                    Console.WriteLine(getfirstplayer() + "가 " + i + ", " + j + "위치에 돌을 놓았습니다.");
        //                    turn = 2;
        //                }
        //                else
        //                {
        //                    Console.WriteLine();
        //                    Console.WriteLine(getsecondplayer() + "가 " + i + ", " + j + "위치에 돌을 놓았습니다.");
        //                    turn = 1;
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