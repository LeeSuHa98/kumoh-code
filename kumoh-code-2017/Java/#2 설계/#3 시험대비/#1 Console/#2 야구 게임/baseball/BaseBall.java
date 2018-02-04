/*
 * Created on 2005. 6. 8.
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */

/**
 * @author Kyoung-in,ryu
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
import java.io.*;
import java.lang.String;

public class BaseBall {
	
	private int []set_num=new int[3];//난수 생성하여 저장할 공간
	private int []user_num=new int[3];//유저가 입력한 값을 배열에 저장하기 위한 변수
	private int ball=0, strike=0;
	
	void compare()
	{
		ball=0;
		strike=0;
		
		for(int i=0;i<3;i++)//스트라이크 찾기
		{
			if(set_num[i]==user_num[i])
				strike++;
		}
		
		for(int i=0;i<3;i++)//볼 찾기 
		{
			for(int j=0;j<3;j++)
			{
				if(i==j)
					continue;
				if(set_num[j]==user_num[i])
					ball++;
				
			}//for
		}//for
	}//compare()
	
	void check_same()
	{
		if(user_num[0]==user_num[1]||user_num[0]==user_num[2]||user_num[1]==user_num[2])
		{
			System.out.println("숫자가 같은게 들어 있습니다.");
			user_input();
		}
	
	}
	
	void user_input()//유저input 값 배열에 저장하는 메소드
	{

		InputStreamReader ir=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(ir);
		
		String str=null;
//		int num=0;				
		try{
			while(true)//3자리수가 아니면 다시 엽력하기 위한 루프
			{
				System.out.println("\n 3개의 숫자를 각각 다르게 입력하시오  ex)325 or 952");
				System.out.print(" 이미 정해진 랜덤 번호를 보려면 r :");
				str=in.readLine();//스트링으로 값을 입력 받는다.
						
			
				int num=0;
				if(str.length()==3)//3개의 숫자가 아닐때 처리
					break;
				if(str.equals("r"))//r 을 입력하면 랜덤 숫자 보기
				{
					System.out.print("랜덤 숫자는 ");
					for(int i=0;i<3;i++)
						System.out.print(set_num[i]);
					System.out.println("입니다.\n");
					continue;
				}
				
				try{//숫자가 아닌 문자가 들어왔을때 처리
					
				num=Integer.parseInt(str);
					
				}catch(NumberFormatException e)
				{
					System.out.println("숫자만 입력하세요.. 문자가 포함되면 안됩니다.\n");
					continue;
				}
				
				
				System.out.println("3자리수만 입력 가능합니다.\n");
			}//while
		}catch(IOException e){}
				
		 int num=Integer.parseInt(str);
		
		//3자리수의 정수를 한개씩 쪼개어 int 형 배열에 집어 넣는다.
		user_num[0]=num/100;
		num=num%100;
		user_num[1]=num/10;
		user_num[2]=num%10;
		//각각 유저가 입력한  숫자가같은게 있는지 없는지 판단.  
		
		check_same();
					
}

	
	void gener_Ran()//랜덤 생성
	{
		int tmp;
		
		for(int i=0;i<3;i++)//3개의 난수 생성
		{
			tmp=(int)(Math.random()*10);
			for(int j=0;j<i;j++)//중복 비교 부분.
			{
				if(tmp==set_num[j])
				{
					tmp=(int)(Math.random()*10);
					j=-1;//다시 첨부터 비교해야 하기 때문
				}
			
			}//for
			
			set_num[i]=tmp; //전부 비교되어 중복 되지 않은 숫자 배열에 저장.
			
		}//for
		//for(int i=0;i<3;i++)
	//	System.out.println(set_num[i]);
	}
	
		
	public void getResult()
	{
		System.out.println("\n스트라이크  : "+strike+"개 , 볼 은 :"+ball+"개");
	}
	
	public static void main(String[] args)
	{
		BaseBall st=new BaseBall();
		st.gener_Ran();
		for(int i=0;i<5;i++)
		{
			System.out.println((5-i)+"회 기회가 있습니다..");
			st.user_input();
			st.compare();
			st.getResult();
		}
	}
}
