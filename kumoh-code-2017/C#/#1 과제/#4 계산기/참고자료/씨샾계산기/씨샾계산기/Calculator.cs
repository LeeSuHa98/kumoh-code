using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace 씨샾계산기
{
    class Calculator
    {
        private Stack<char> opeStack = new Stack<char>();			//후위연산식으로 바꿀 때 연산자를 저장해 놓는 스택
        private Stack<double> numStack = new Stack<double>();			//후위연산식을 계산할 때 숫자를 저장해 놓는 스택
        private string[] backExpres = new string[50];				//후위연산식을 저장하는 배열
        private int backCnt;					//후위연산식을 저장하는 배열의 크기

        public Stack<double> getNumStack() { return numStack; }

        public int priority(char op)
        {
            if (op == '+' || op == '-')
                return 2;
            else if (op == '*' || op == '/' || op == '%')
                return 3;
            else if (op == '^')
                return 4;
            else if (op == '~')
                return 5;
            else if (op == '(')
            {
                if (opeStack.Peek() == '(') //괄호 안의 괄호우선순위와 괄호밖의 우선순의를 구분해줌
                    return 0;
                return 6;
            }
            else
                return 0;
        }
        public void postfix(Expression e)   //후위연산식으로 바꿈
        {
            for (int i = 0; i <= e.getxCount(); i++)
            {
                if (e.getTokenState(i) == true)
                {
                    if ((i == 0 && e.getTokenOp(i) == '-') || (e.getTokenOp(i) == '-' && e.getTokenState(i - 1) == true))
                    {
                        opeStack.Push('~');
                        continue;
                    }
                    if (opeStack.Count == 0)    /////////
                        opeStack.Push(e.getTokenOp(i));
                    else if (priority(opeStack.Peek()) > priority(e.getTokenOp(i)) || e.getTokenOp(i) == ')')  //스택의 우선순위가 토큰의 우선순위보다 높으면 Pop 해줌
                    {
                        if (e.getTokenOp(i) == ')')
                        {
                            while (true)
                            {
                                if (opeStack.Peek() == '(')    // 닫는 괄호가 나왔을 때 여는괄호까지만 Pop해줌
                                {
                                    opeStack.Pop();
                                    if (i == e.getxCount() - 1)				//스택에 남은 연산자들을 pop 해줌
                                    {
                                        while (true)
                                        {
                                            if (opeStack.Count == 0)/////////
                                                break;
                                            backExpres[backCnt++] = opeStack.Peek().ToString();
                                            opeStack.Pop();
                                        }
                                    }
                                    break;
                                }

                                backExpres[backCnt++] = opeStack.Peek().ToString();
                                opeStack.Pop();
                            }
                        }
                        else
                        {
                            while (true)
                            {
                                if (opeStack.Count == 0 || opeStack.Peek() == '(' || priority(opeStack.Peek()) < priority(e.getTokenOp(i)))
                                    break;
                                backExpres[backCnt++] = opeStack.Peek().ToString();
                                opeStack.Pop();
                            }
                            opeStack.Push(e.getTokenOp(i));
                        }
                    }
                    else if (priority(opeStack.Peek()) == priority(e.getTokenOp(i)))    //스택의 우선순위가 토큰의 우선순위와 같으면 바꿈
                    {
                        if (opeStack.Peek() == '^' && e.getTokenOp(i) == '^')			// "^"연산자가 연속으로 나올경우 뒤를 먼저 계산하기 위해 push
                            opeStack.Push(e.getTokenOp(i));
                        else if (e.getTokenOp(i) == '(')								//여는 괄호가 연속으로 들어오면	
                            opeStack.Push(e.getTokenOp(i));
                        else
                        {
                            backExpres[backCnt++] = opeStack.Peek().ToString();
                            opeStack.Pop();
                            opeStack.Push(e.getTokenOp(i));
                        }
                    }
                    else if (priority(opeStack.Peek()) < priority(e.getTokenOp(i)))		//스택의 우선순위가 토큰의 우선순위보다 낮으면 Push 해줌
                        opeStack.Push(e.getTokenOp(i));
                }
                else if (i == e.getxCount())				//스택에 남은 연산자들을 pop 해줌
                {
                    while (true)
                    {
                        if (opeStack.Count == 0)
                            break;
                        backExpres[backCnt++] = opeStack.Peek().ToString();
                        opeStack.Pop();
                    }
                }
                else							//숫자면 후위연산식을 저장하는 배열 backExpres에 바로 저장
                {
                    //stringstream strNum;
                    //strNum << e.getTokenNum(i);
                    backExpres[backCnt++] = e.getTokenNum(i).ToString();
                }
            }
        }
        public string calculation()			//각 연산자에 대해 계산함
        {
	        Expression e = new Expression();
	        double f = 0;
		    char c;
	        for(int i = 0 ; i < backCnt ; i++)
            {
                c = backExpres[i][0];
		        if(e.searchNumStrErr(c) == 0)
		        {
		        	if(arithmetic(backExpres[i]))
		        	{
			        	return "나누기 혹은 나머지 연산의 두번째 수가 0입니다.";
	        		}
	        	}
	    	    else
		        {
                    f = Convert.ToDouble(backExpres[i]);
		    	    numStack.Push(f);
	    	    }
            }
            return null;
        }

        bool arithmetic(string ex)
        {
            double top = 0;
            double preTop = 0;
            if (ex == "+")
            {
                top = numStack.Peek();
                numStack.Pop();
                preTop = numStack.Peek();
                numStack.Pop();
                numStack.Push(preTop + top);
            }
            else if (ex == "-")
            {
                top = numStack.Peek();
                numStack.Pop();
                preTop = numStack.Peek();
                numStack.Pop();
                numStack.Push(preTop - top);
            }
            else if (ex == "*")
            {
                top = numStack.Peek();
                numStack.Pop();
                preTop = numStack.Peek();
                numStack.Pop();
                numStack.Push(preTop * top);
            }
            else if (ex == "/")
            {
                top = numStack.Peek();
                numStack.Pop();
                preTop = numStack.Peek();
                numStack.Pop();
                numStack.Push(preTop / top);
                if (top == 0)						//나누기연산시 두번째 숫자가 0인경우 오류처리
                    return true;
            }
            else if (ex == "%")
            {
                int top1 = Convert.ToInt16(numStack.Peek());
                numStack.Pop();
                int preTop1 = Convert.ToInt16(numStack.Peek());
                numStack.Pop();
                numStack.Push(preTop1 % top1);
                if (top == 0)						//나머지연산시 두번째 숫자가 0인경우 오류처리
                    return true;
            }
            else if (ex == "~")
            {
                top = numStack.Peek();
                numStack.Pop();
                numStack.Push(top * -1);
            }
            else
            {
                double num = 1;
                top = numStack.Peek();
                numStack.Pop();
                preTop = numStack.Peek();
                numStack.Pop();
                for (int i = 0; i < top; i++)
                    num = num * preTop;
                numStack.Push(num);
            }
            return false;
        }
    }
}
