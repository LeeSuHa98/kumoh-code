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

public class BaseBallwithGUI {
	
	private int []set_num=new int[3];//난수 생성하여 저장할 공간
	private int []user_num=new int[3];//유저가 입력한 값을 배열에 저장하기 위한 변수
	private int ball=0, strike=0;
	private String ranNum=null;
		
	public  BaseBallwithGUI() 
	{
		gener_Ran();
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
		for(int i=0;i<3;i++)
		System.out.println(set_num[i]);
	}
	public String getRanNum()
	{
		String ranNum=new String();
		for(int i=0;i<3;i++)
			ranNum=ranNum+set_num[i];
			
		return ranNum;
	}
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
	
	boolean user_input(String str)//유저input 값 배열에 저장하는 메소드
	{
		if(str.length()!=3)
			return  false;
		int num=0;
				
		try{
			
			num=Integer.parseInt(str);
		}catch(NumberFormatException e)
		{
			System.out.println("숫자만 쓰라니깐");
		
		}
		System.out.println(num);
		//3자리수의 정수를 한개씩 쪼개어 int 형 배열에 집어 넣는다.
		user_num[0]=num/100;
		num=num%100;
		user_num[1]=num/10;
		user_num[2]=num%10;
		//각각 유저가 입력한  숫자가같은게 있는지 없는지 판단.  
		
		if(user_num[0]==user_num[1]||user_num[0]==user_num[2]||user_num[1]==user_num[2])
		{
			System.out.println("숫자가 같은게 들어 있습니다.");
			return false;
		}
		return true;
		
				
}
	
	
	public String getResult()
	{
		System.out.println("스트라이크  : "+strike+"개 , 볼 은 :"+ball+"개");
		return "스트라이크  : "+strike+"개 , 볼 은 :"+ball+"개";
	}
	

}
