package �ڸ�����;

public class MyException extends Exception
{
	private int isFlag;
	
	public MyException(int check)
	{
		if(check == 0) 
		{
			isFlag = 0;
		}
		else if(check == 1) 
		{
			isFlag = 1;
		}
		else if(check == 2)
		{
			isFlag = 2;
		}
	}
	public void message()
	{
		if(isFlag == 0) 
		{
			System.out.println("����� �¼��� �������� �ʽ��ϴ�. (���� ��� ����)");
		}
		else if(isFlag == 1)
		{
			System.out.println("����� �¼��� �����մϴ�. (���� ����)");
		}
		else if(isFlag == 2)
		{
			System.out.println("����� �¼��� �����Դϴ�. (���� ����)");
		}
	}
}
