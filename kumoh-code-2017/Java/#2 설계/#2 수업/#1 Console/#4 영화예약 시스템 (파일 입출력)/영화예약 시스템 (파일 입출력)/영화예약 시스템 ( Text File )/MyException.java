package 자리예약;

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
			System.out.println("예약된 좌석이 존재하지 않습니다. (예약 취소 실패)");
		}
		else if(isFlag == 1)
		{
			System.out.println("예약된 좌석이 존재합니다. (예약 실패)");
		}
		else if(isFlag == 2)
		{
			System.out.println("예약된 좌석이 만석입니다. (예약 실패)");
		}
	}
}
