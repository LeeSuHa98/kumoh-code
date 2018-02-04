import java.util.Scanner;

public class AAM
{
	Scanner sc = new Scanner(System.in);
	
	private static final int MAX_COUNT = 10;
	private String message;
	private String[] msg;
	private int count;
	
	public AAM()
	{
		msg = new String[MAX_COUNT];
		count = 0;
	}
	
	public void connect()	// 초기 메시지("연결 되었습니다")를 화면에 출력하고 연결 상태 유지(연결되었다고 내부적으로 표시)
	{
		System.out.println("연결 되었습니다");
	}
	public void record()	// 입력 안내문("전달 메시지 : ")을 출력하고 메시지를 키보드를 통해 입력받음
	{
		System.out.print("전달 메시지: ");

//		if (msg == null)
//		{
//			System.out.println("DisConnected");
//		}
		if (count > MAX_COUNT)
		{
			System.out.println("메시지는 최대 10개 까지 저장 가능");
			System.out.println("DisConnected");
		}
		
		message = sc.next();
		msg[count] = message;
		count++;
	}
	public void play()
	{
		if (msg == null)
		{
			System.out.println("연결되지 않는 상태입니다.");
		}
		else
		{
			System.out.println("받은 메시지 : " + message);
		}
	}
	public void play(int n)
	{
		System.out.println(n+1 + "번째 메시지 : " + msg[n]);
	}
	public int getMsgNum()	// 저장되어 있는 메시지 개수를 돌려 줌
	{
		return count;
	}
	public void movePos(int n)	// n 번째 메시지로 이동
	{
		for (int i = 0; i < n; i++)
		{
			System.out.println(n + "번째 메시지로 이동 : " + msg[n-1]);
		}
	}
	public void deleteMsg()	// 현 위치의 메시지 삭제
	{
		msg = null;
	}
	public void disconnect()	// 연결 해제
	{
		System.out.println("Disconnect");
		msg = null;
		count = 0;
	}
}
