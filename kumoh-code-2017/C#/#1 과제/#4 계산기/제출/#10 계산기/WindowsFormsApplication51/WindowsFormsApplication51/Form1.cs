using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication51
{
    public partial class Form1 : Form
    {
        private bool IsEval = true;

        public class Token
        {
            private string t;

            public Token()
            {
                t = "";
            }

            public Token(string op)
            {
                t = op;
            }

            public string getT() { return t; }

            public void setToken(string op)
            {
                t = op;
            }
        }

        public class TokenList
        {
            private Token[] token;
            private int capacity;
            private int tokenNum;

            public TokenList()
            {
                capacity = 1;
                tokenNum = 0;
                token = new Token[capacity];
            }

            public void IncreaseCapacity()
            {
                Token[] newToken = new Token[capacity * 2];

                for (int i = 0; i < tokenNum; i++)
                    newToken[i] = token[i];

                token = newToken;

                capacity *= 2;
            }

            public void setArraySize()
            {
                Token[] newToken = new Token[tokenNum];

                for (int i = 0; i < tokenNum; i++)
                    newToken[i] = token[i];

                token = newToken;
            }

            public void Insert(string op)
            {
                token[tokenNum++] = new Token(op);
            }

            public Token getToken(int index)
            {
                return token[index];
            }
            public int getCapacity() { return capacity; }
            public int getTokenNum() { return tokenNum; }
        }

        public bool IsOperator(string op)
        {
            if (op == "/" || op == "+" || op == "-" || op == "*" || op == "(" || op == ")" || op == "~")
                return true;

            else
                return false;

        }

        public int isp(string s)
        {
            char ch = s.ElementAt(0);

            switch (ch)
            {
                case '~':
                    return 4;
                case '*':
                case '/':
                    return 3;
                case '+':
                case '-':
                    return 2;
                case '(':
                    return 1;
                default:
                    return -1;

            }
        }

        public int icp(string s)
        {
            char ch = s.ElementAt(0);

            switch (ch)
            {
                case '(':
                    return 6;
                case '~':
                    return 5;
                case '*':
                case '/':
                    return 3;
                case '+':
                case '-':
                    return 2;
                default:
                    return -1;
            }
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Clear_Click(object sender, EventArgs e)
        {
            view.Text = "";
            IsEval = true;
            view.Enabled = true;
        }

        private void Zero_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
                view.Text += 0.ToString();
        }

        private void One_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
                view.Text += 1.ToString();
        }

        private void Two_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
                view.Text += 2.ToString();
        }

        private void Three_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
                view.Text += 3.ToString();
        }

        private void Four_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
                view.Text += 4.ToString();
        }

        private void Five_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
                view.Text += 5.ToString();
        }

        private void Six_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
                view.Text += 6.ToString();
        }

        private void Seven_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
                view.Text += 7.ToString();
        }

        private void Eight_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
                view.Text += 8.ToString();
        }

        private void Nine_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
                view.Text += 9.ToString();
        }

        private void Open_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
                view.Text += '('.ToString();
        }

        private void Close_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
                view.Text += ')'.ToString();
        }

        private void Divide_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
                view.Text += '/'.ToString();
        }

        private void Multiply_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
                view.Text += '*'.ToString();
        }

        private void Subtract_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
                view.Text += '-'.ToString();
        }

        private void Plus_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
                view.Text += '+'.ToString();
        }

        private void Calculate_Click(object sender, EventArgs e)
        {
            if (IsEval == true)
            {
                string evalExpress = view.Text;
                view.Text = "";

                if (evalExpress.Length <= 0)
                {
                    view.Text = "입력 수식이 없습니다.";
                    IsEval = false;
                    view.Enabled = false;
                    return;
                }

                else if (evalExpress.Equals("-"))
                {
                    view.Text = "계산 불가";
                    IsEval = false;
                    view.Enabled = false;
                    return;
                }

                TokenList tl = new TokenList();

                for (int i = 0; i < evalExpress.Length; i++)
                {
                    string patchStr = evalExpress[i].ToString();
                    if (IsOperator(patchStr) == true)            // patch 한 것이 문자(연산자) 라면
                    {
                        if (tl.getTokenNum() == tl.getCapacity())
                            tl.IncreaseCapacity();

                        tl.Insert(patchStr);
                    }

                    else                                        // patch 한 것이 숫자(피연산자) 라면
                    {
                        int num = Convert.ToChar(patchStr) - '0';

                        while (true)
                        {
                            if (i + 1 >= evalExpress.Length)
                                break;

                            string nextStr = evalExpress[++i].ToString();

                            if (IsOperator(nextStr) == true)
                            {
                                i--;
                                break;
                            }

                            else
                                num = num * 10 + Convert.ToChar(nextStr) - '0';

                        }

                        if (tl.getTokenNum() == tl.getCapacity())
                            tl.IncreaseCapacity();

                        tl.Insert(num.ToString());
                    }
                }

                tl.setArraySize();
                //Tokenization

                Token[] newToken = new Token[tl.getTokenNum()];
                // 후위 계산에 사용될 Token 배열 생성
                int newTokenNum = 0;
                // 후위 계산에 사용될 토큰 개수

                int openBracketCnt = 0;     // 여는 괄호 개수
                int closeBracketCnt = 0;    // 닫는 괄호 개수

                for (int i = 0; i < tl.getTokenNum(); i++)
                {

                    Token patchToken = tl.getToken(i);

                    string patchStr = patchToken.getT();

                    if (IsOperator(patchStr) == true)    // Token이 연산자
                    {
                        if (patchStr == "+")
                        {
                            if (i == 0)
                            {
                                view.Text = "계산 불가";
                                IsEval = false;
                                view.Enabled = false;
                                return;
                            }

                            else if (i == tl.getTokenNum() - 1)
                            {
                                view.Text = "계산 불가";
                                IsEval = false;
                                view.Enabled = false;
                                return;
                            }

                            else
                            {
                                Token prevToken = tl.getToken(i - 1);
                                Token nextToken = tl.getToken(i + 1);

                                string prevStr = prevToken.getT();
                                string nextStr = nextToken.getT();

                                if (IsOperator(prevStr) == true)         // 이전 토큰 연산자(문자)
                                {
                                    if (IsOperator(nextStr) == true)     // 이후 토큰 연산자(문자)
                                    {
                                        if (prevStr.Equals(")") && (nextStr.Equals("(") || nextStr.Equals("-")))
                                            newToken[newTokenNum++] = tl.getToken(i);

                                        else
                                        {
                                            view.Text = "계산 불가";
                                            IsEval = false;
                                            view.Enabled = false;
                                            return;
                                        }
                                    }

                                    else                                // 이후 토큰 피연산자(숫자)
                                    {
                                        if (prevStr.Equals(")"))
                                            newToken[newTokenNum++] = tl.getToken(i);

                                        else
                                        {
                                            view.Text = "계산 불가";
                                            IsEval = false;
                                            view.Enabled = false;
                                            return;
                                        }
                                    }
                                }

                                else                                    // 이전 토큰 피연산자(숫자)
                                {
                                    if (IsOperator(nextStr) == true)    // 이후 토큰 연산자(문자)
                                    {
                                        if (nextStr.Equals("-") || nextStr.Equals("("))
                                            newToken[newTokenNum++] = tl.getToken(i);

                                        else
                                        {
                                            view.Text = "계산 불가";
                                            IsEval = false;
                                            view.Enabled = false;
                                            return;
                                        }

                                    }

                                    else                                // 이후 토큰 피연산자(숫자)
                                    {
                                        newToken[newTokenNum++] = tl.getToken(i);
                                    }
                                }
                            }
                        }

                        else if (patchStr == "-")
                        {
                            if (i == 0)
                            {
                                Token tilda = new Token("~");
                                newToken[newTokenNum++] = tilda;
                            }

                            else if (i == tl.getTokenNum() - 1)
                            {
                                view.Text = "계산 불가";
                                IsEval = false;
                                view.Enabled = false;
                                return;
                            }

                            else
                            {
                                Token prevToken = tl.getToken(i - 1);
                                Token nextToken = tl.getToken(i + 1);

                                string prevStr = prevToken.getT();
                                string nextStr = nextToken.getT();

                                if (nextStr.Equals("+") || nextStr.Equals("*") || nextStr.Equals("/") || nextStr.Equals(")"))
                                {
                                    view.Text = "계산 불가";
                                    IsEval = false;
                                    view.Enabled = false;
                                    return;
                                }

                                else
                                {
                                    if (prevStr.Equals("(") || prevStr.Equals("+") || prevStr.Equals("-") || prevStr.Equals("*") || prevStr.Equals("/"))
                                    {
                                        Token tilda = new Token("~");
                                        newToken[newTokenNum++] = tilda;
                                    }

                                    else
                                        newToken[newTokenNum++] = tl.getToken(i);
                                }
                            }
                        }

                        else if (patchStr == "*")
                        {
                            if (i == 0)
                            {
                                view.Text = "계산 불가";
                                IsEval = false;
                                view.Enabled = false;
                                return;
                            }

                            else if (i == tl.getTokenNum() - 1)
                            {
                                view.Text = "계산 불가";
                                IsEval = false;
                                view.Enabled = false;
                                return;
                            }

                            else
                            {
                                Token prevToken = tl.getToken(i - 1);
                                Token nextToken = tl.getToken(i + 1);

                                string prevStr = prevToken.getT();
                                string nextStr = nextToken.getT();

                                if (IsOperator(prevStr) == true)         // 이전 토큰 연산자(문자)
                                {
                                    if (IsOperator(nextStr) == true)     // 이후 토큰 연산자(문자)
                                    {
                                        if (prevStr.Equals(")") && (nextStr.Equals("(") || nextStr.Equals("-")))
                                            newToken[newTokenNum++] = tl.getToken(i);

                                        else
                                        {
                                            view.Text = "계산 불가";
                                            IsEval = false;
                                            view.Enabled = false;
                                            return;
                                        }
                                    }

                                    else                                // 이후 토큰 피연산자(숫자)
                                    {
                                        if (prevStr.Equals(")"))
                                            newToken[newTokenNum++] = tl.getToken(i);

                                        else
                                        {
                                            view.Text = "계산 불가";
                                            IsEval = false;
                                            view.Enabled = false;
                                            return;
                                        }
                                    }
                                }

                                else                                    // 이전 토큰 피연산자(숫자)
                                {
                                    if (IsOperator(nextStr) == true)    // 이후 토큰 연산자(문자)
                                    {
                                        if (nextStr.Equals("-") || nextStr.Equals("("))
                                            newToken[newTokenNum++] = tl.getToken(i);

                                        else
                                        {
                                            view.Text = "계산 불가";
                                            IsEval = false;
                                            view.Enabled = false;
                                            return;
                                        }

                                    }

                                    else                                // 이후 토큰 피연산자(숫자)
                                    {
                                        newToken[newTokenNum++] = tl.getToken(i);
                                    }
                                }
                            }
                        }

                        else if (patchStr == "/")
                        {
                            if (i == 0)
                            {
                                view.Text = "계산 불가";
                                IsEval = false;
                                view.Enabled = false;
                                return;
                            }

                            else if (i == tl.getTokenNum() - 1)
                            {
                                view.Text = "계산 불가";
                                IsEval = false;
                                view.Enabled = false;
                                return;
                            }

                            else
                            {
                                Token prevToken = tl.getToken(i - 1);
                                Token nextToken = tl.getToken(i + 1);

                                string prevStr = prevToken.getT();
                                string nextStr = nextToken.getT();

                                if (IsOperator(prevStr) == true)         // 이전 토큰 연산자(문자)
                                {
                                    if (IsOperator(nextStr) == true)     // 이후 토큰 연산자(문자)
                                    {
                                        if (prevStr.Equals(")") && (nextStr.Equals("(") || nextStr.Equals("-")))
                                            newToken[newTokenNum++] = tl.getToken(i);

                                        else
                                        {
                                            view.Text = "계산 불가";
                                            IsEval = false;
                                            view.Enabled = false;
                                            return;
                                        }
                                    }

                                    else                                // 이후 토큰 피연산자(숫자)
                                    {
                                        if (prevStr.Equals(")"))
                                            newToken[newTokenNum++] = tl.getToken(i);

                                        else
                                        {
                                            view.Text = "계산 불가";
                                            IsEval = false;
                                            view.Enabled = false;
                                            return;
                                        }
                                    }
                                }

                                else                                    // 이전 토큰 피연산자(숫자)
                                {
                                    if (IsOperator(nextStr) == true)    // 이후 토큰 연산자(문자)
                                    {
                                        if (nextStr.Equals("-") || nextStr.Equals("("))
                                            newToken[newTokenNum++] = tl.getToken(i);

                                        else
                                        {
                                            view.Text = "계산 불가";
                                            IsEval = false;
                                            view.Enabled = false;
                                            return;
                                        }

                                    }

                                    else                                // 이후 토큰 피연산자(숫자)
                                    {
                                        newToken[newTokenNum++] = tl.getToken(i);
                                    }
                                }
                            }
                        }

                        else if (patchStr == "(")
                        {
                            openBracketCnt++;

                            if (i == 0)
                            {
                                Token nextToken = tl.getToken(i + 1);
                                string nextStr = nextToken.getT();

                                if (nextStr.Equals(")"))
                                {
                                    view.Text = "계산 불가";
                                    IsEval = false;
                                    view.Enabled = false;
                                    return;
                                }


                                newToken[newTokenNum++] = tl.getToken(i);
                            }

                            else if (i == tl.getTokenNum() - 1)
                            {
                                view.Text = "계산 불가";
                                IsEval = false;
                                view.Enabled = false;
                                return;
                            }

                            else
                            {
                                Token prevToken = tl.getToken(i - 1);
                                Token nextToken = tl.getToken(i + 1);

                                string prevStr = prevToken.getT();
                                string nextStr = nextToken.getT();

                                if (IsOperator(prevStr) == true)         // 이전 토큰 연산자(문자)
                                {
                                    if (IsOperator(nextStr) == true)     // 이후 토큰 연산자(문자)
                                    {
                                        if (prevStr.Equals(")") || nextStr.Equals("+") || nextStr.Equals("*") || nextStr.Equals("/") || nextStr.Equals(")") || nextStr.Equals(")"))
                                        {
                                            view.Text = "계산 불가";
                                            IsEval = false;
                                            view.Enabled = false;
                                            return;
                                        }

                                        else
                                            newToken[newTokenNum++] = tl.getToken(i);
                                    }

                                    else                                // 이후 토큰 피연산자(숫자)
                                    {
                                        if (prevStr.Equals(")"))
                                        {
                                            view.Text = "계산 불가";
                                            IsEval = false;
                                            view.Enabled = false;
                                            return;
                                        }

                                        else
                                            newToken[newTokenNum++] = tl.getToken(i);
                                    }
                                }

                                else                                    // 이전 토큰 피연산자(숫자)
                                {
                                    view.Text = "계산 불가";
                                    IsEval = false;
                                    view.Enabled = false;
                                    return;
                                }
                            }
                        }

                        else if (patchStr == ")")
                        {
                            closeBracketCnt++;

                            if (closeBracketCnt > openBracketCnt)
                            {
                                view.Text = "계산 불가";
                                IsEval = false;
                                view.Enabled = false;
                                return;
                            }
                            if (i == 0)
                            {
                                view.Text = "계산 불가";
                                IsEval = false;
                                view.Enabled = false;
                                return;
                            }

                            else if (i == tl.getTokenNum() - 1)
                            {
                                newToken[newTokenNum++] = tl.getToken(i);
                            }

                            else
                            {
                                Token prevToken = tl.getToken(i - 1);
                                Token nextToken = tl.getToken(i + 1);

                                string prevStr = prevToken.getT();
                                string nextStr = nextToken.getT();

                                if (IsOperator(prevStr) == true)         // 이전 토큰 연산자(문자)
                                {
                                    if (IsOperator(nextStr) == true)     // 이후 토큰 연산자(문자)
                                    {
                                        if (prevStr.Equals(")") && (nextStr.Equals("+") || nextStr.Equals("-") || nextStr.Equals("*") || nextStr.Equals("/") || nextStr.Equals(")")))
                                            newToken[newTokenNum++] = tl.getToken(i);

                                        else
                                        {
                                            view.Text = "계산 불가";
                                            IsEval = false;
                                            view.Enabled = false;
                                            return;
                                        }
                                    }

                                    else                                // 이후 토큰 피연산자(숫자)
                                    {
                                        view.Text = "계산 불가";
                                        IsEval = false;
                                        view.Enabled = false;
                                        return;
                                    }
                                }

                                else                                     // 이전 토큰 피연산자(숫자)
                                {
                                    if (IsOperator(nextStr) == true)     // 이후 토큰 연산자(문자)
                                    {
                                        if (nextStr.Equals("("))
                                        {
                                            view.Text = "계산 불가";
                                            IsEval = false;
                                            view.Enabled = false;
                                            return;
                                        }

                                        else
                                            newToken[newTokenNum++] = tl.getToken(i);
                                    }

                                    else                                // 이후 토큰 피연산자(숫자)
                                    {
                                        view.Text = "계산 불가";
                                        IsEval = false;
                                        view.Enabled = false;
                                        return;
                                    }
                                }
                            }
                        }

                    }

                    else                                // Token이 피연산자
                    {
                        newToken[newTokenNum++] = tl.getToken(i);
                    }

                }

                if (openBracketCnt != closeBracketCnt)
                {
                    view.Text = "계산 불가";
                    IsEval = false;
                    view.Enabled = false;
                    return;
                }
                // Inspection

                Token[] evalToken = new Token[newTokenNum];
                // 후위 연산을 하기 위한 토큰 배열
                int evalTokenNum = 0;

                Stack<String> s = new Stack<String>();
                s.Push("#");

                for (int i = 0; i < newTokenNum; i++)
                {
                    Token patchToken = newToken[i];
                    string patchStr = patchToken.getT();

                    if (IsOperator(patchStr) == false)
                    {
                        Token inputToken = new Token(patchStr);
                        evalToken[evalTokenNum++] = inputToken;
                    }

                    else
                    {
                        if (patchStr.Equals(")"))
                        {
                            while (s.Peek() != "(")
                            {
                                Token inputToken = new Token(s.Peek());
                                evalToken[evalTokenNum++] = inputToken;
                                s.Pop();
                            }

                            s.Pop();
                        }

                        else
                        {
                            while (isp(s.Peek()) >= icp(patchStr))
                            {
                                Token inputToken = new Token(s.Peek());
                                evalToken[evalTokenNum++] = inputToken;
                                s.Pop();
                            }

                            s.Push(patchStr);
                        }
                    }
                }

                while (s.Peek() != "#")
                {
                    Token inputToken = new Token(s.Peek());
                    evalToken[evalTokenNum++] = inputToken;
                    s.Pop();
                }
                // token화 연산식


                Stack<string> finalStack = new Stack<String>();

                for (int i = 0; i < evalTokenNum; i++)
                {
                    Token patchT = evalToken[i];
                    string patchS = patchT.getT();

                    if (IsOperator(patchS) == true)
                    {
                        if (patchS.Equals("+"))
                        {
                            string op2 = finalStack.Peek();
                            finalStack.Pop();
                            string op1 = finalStack.Peek();
                            finalStack.Pop();
                            double num2 = Convert.ToDouble(op2);
                            double num1 = Convert.ToDouble(op1);
                            double sum = num1 + num2;
                            string result = sum.ToString();
                            finalStack.Push(result);
                        }

                        else if (patchS.Equals("-"))
                        {
                            string op2 = finalStack.Peek();
                            finalStack.Pop();
                            string op1 = finalStack.Peek();
                            finalStack.Pop();
                            double num2 = Convert.ToDouble(op2);
                            double num1 = Convert.ToDouble(op1);
                            double subtract = num1 - num2;
                            string result = subtract.ToString();
                            finalStack.Push(result);
                        }

                        else if (patchS.Equals("*"))
                        {
                            string op2 = finalStack.Peek();
                            finalStack.Pop();
                            string op1 = finalStack.Peek();
                            finalStack.Pop();
                            double num2 = Convert.ToDouble(op2);
                            double num1 = Convert.ToDouble(op1);
                            double multiply = num1 * num2;
                            string result = multiply.ToString();
                            finalStack.Push(result);
                        }

                        else if (patchS.Equals("/"))
                        {
                            string op2 = finalStack.Peek();
                            finalStack.Pop();
                            string op1 = finalStack.Peek();
                            finalStack.Pop();
                            double num2 = Convert.ToDouble(op2);
                            double num1 = Convert.ToDouble(op1);
                            if (num2 == 0)
                            {
                                view.Text = "연산 오류";
                                IsEval = false;
                                view.Enabled = false;
                                return;
                            }
                            double divide = num1 / num2;
                            string result = divide.ToString();
                            finalStack.Push(result);
                        }

                        else if (patchS.Equals("~"))
                        {
                            string op = finalStack.Peek();
                            finalStack.Pop();
                            double num = Convert.ToDouble(op);
                            double tilda = (-1) * num;
                            string result = tilda.ToString();
                            finalStack.Push(result);
                        }
                    }

                    else
                        finalStack.Push(patchS);
                }

                string resultStr = finalStack.Peek();
                view.Text = resultStr;
            }

            IsEval = false;
            view.Enabled = false;
        }
    }
}
