using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 씨샾계산기
{
    struct Token
    {
        public int number;
        public char op;
    };

    class Expression
    {
        private Token[] x = new Token[50];			//숫자와 연산자를 저장하는 객체 배열
        private bool[] state = new bool[50];		//객체 배열에 index값이 숫자인지 연산자인지 구별할 수 있도록 해주는 배열;
        private int xCount = 0;			//객체 배열의 크기
        //private int capacity = 50;

        public int getTokenNum(int i) { return x[i].number; }
        public char getTokenOp(int i) { return x[i].op; }
        public bool getTokenState(int i) { return state[i]; }
        public int getxCount() { return xCount; }

        public string expInput(String token)
        {
            int open = 0;
            int close = 0;
            int tokenSize = token.Length;
            token += " ";
            if (token.Equals(" "))
                return "***[오류]값이 없습니다.***";
            for (int i = 0; i < tokenSize; )
            {
                if (token[i] == '(') open++;
                if (token[i] == ')') close++;
                if (searchNumStrErr(token[i]) == 0)							//token[i]가 연산자일때 유니온 xCount번째의 op에 대입
                {
                    if(token[i] == ')' &&searchNumStrErr(token[i+1]) == 1)
                        return "***[오류]계산할 수 없는 계산식입니다.***";
                    if (i == 0 && (token[i] != '-' && token[i] != '('))
                    {//첫번째값이 연산자일 경우
                        return "***[오류]계산할 수 없는 계산식입니다.***";
                    }
                    if (searchNumStrErr(token[i + 1]) == 0 && (token[i + 1] != '-' && token[i + 1] != '(' && token[i] != ')'))
                    {//이후값도 연산자면 다시입력
                        return "***[오류]계산할 수 없는 계산식입니다.***";
                    }
                    if (i == tokenSize - 1)					//마지막에 입력받은 것이 연산자이면
                    {
                        if (token[i] != ')')
                        {
                            return "***[오류]계산할 수 없는 계산식입니다.***";
                        }
                        else if (open != close)
                        {
                            return "***[오류]여는괄호와 닫는괄호의 개수가 다릅니다.***";
                        }
                    }
                    x[xCount].op = token[i];
                    i++; state[xCount++] = true;
                }
                else if (searchNumStrErr(token[i]) == 1)						//token[i]가 숫자일때 유니온 xCount번째의 number에 대입
                {
                    if (searchNumStrErr(token[i + 1]) == 1 || token[i + 1] == ' ')
                    {
                        x[xCount].number = 0;
                        if (i == tokenSize - 1 && open != close)
                        {
                            return "***[오류]여는괄호와 닫는괄호의 개수가 다릅니다.***";
                        }
                        while (true)											//숫자 다음 토큰이 숫자일 경우 합쳐줌
                        {
                            if (token[i] == ' ')
                            {
                                i++;
                                continue;
                            }				//공백 제거
                            if (searchNumStrErr(token[i]) == 0)
                            {
                                xCount++;
                                break;
                            }
                            if (searchNumStrErr(token[i]) == 1)
                                x[xCount].number = x[xCount].number * 10 + token[i] - '0';
                            if (searchNumStrErr(token[i + 1]) == 0 || i == tokenSize - 1)
                            {
                                state[xCount++] = false;
                                i++;
                                break;
                            } i++;
                        }
                    }
                    else
                    {
                        x[xCount].number = token[i++] - '0';
                        state[xCount++] = false;
                    }
                }
                else
                {
                    if (token[i] == ' ')				 //공백 제거
                    {
                        i++;
                        continue;
                    }
                    else
                        return "[오류]숫자도 연산자도 아닌 문자가 입력되었습니다.";
                }
            }
            return null;
        }

        public int searchNumStrErr(char t)			//연산자인지 숫자인지 구분해주는 함수
        {
            if (t == '+' || t == '-' || t == '*' || t == '/' || t == '(' || t == ')' || t == '%' || t == '^' || t == '%' || t == '~')
                return 0;
            else if (t == '0' || t == '1' || t == '2' || t == '3' || t == '4' || t == '5' || t == '6' || t == '7' || t == '8' || t == '9')
                return 1;
            else
                return 2;
        }
    }
}
