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
	
	private int []set_num=new int[3];//���� �����Ͽ� ������ ����
	private int []user_num=new int[3];//������ �Է��� ���� �迭�� �����ϱ� ���� ����
	private int ball=0, strike=0;
	private String ranNum=null;
		
	public  BaseBallwithGUI() 
	{
		gener_Ran();
	}
	
	void gener_Ran()//���� ����
	{
		int tmp;
		
		for(int i=0;i<3;i++)//3���� ���� ����
		{
			tmp=(int)(Math.random()*10);
			for(int j=0;j<i;j++)//�ߺ� �� �κ�.
			{
				if(tmp==set_num[j])
				{
					tmp=(int)(Math.random()*10);
					j=-1;//�ٽ� ÷���� ���ؾ� �ϱ� ����
				}
			
			}//for
			
			set_num[i]=tmp; //���� �񱳵Ǿ� �ߺ� ���� ���� ���� �迭�� ����.
			
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
		for(int i=0;i<3;i++)//��Ʈ����ũ ã��
		{
			if(set_num[i]==user_num[i])
				strike++;
		}
		
		for(int i=0;i<3;i++)//�� ã�� 
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
	
	boolean user_input(String str)//����input �� �迭�� �����ϴ� �޼ҵ�
	{
		if(str.length()!=3)
			return  false;
		int num=0;
				
		try{
			
			num=Integer.parseInt(str);
		}catch(NumberFormatException e)
		{
			System.out.println("���ڸ� ����ϱ�");
		
		}
		System.out.println(num);
		//3�ڸ����� ������ �Ѱ��� �ɰ��� int �� �迭�� ���� �ִ´�.
		user_num[0]=num/100;
		num=num%100;
		user_num[1]=num/10;
		user_num[2]=num%10;
		//���� ������ �Է���  ���ڰ������� �ִ��� ������ �Ǵ�.  
		
		if(user_num[0]==user_num[1]||user_num[0]==user_num[2]||user_num[1]==user_num[2])
		{
			System.out.println("���ڰ� ������ ��� �ֽ��ϴ�.");
			return false;
		}
		return true;
		
				
}
	
	
	public String getResult()
	{
		System.out.println("��Ʈ����ũ  : "+strike+"�� , �� �� :"+ball+"��");
		return "��Ʈ����ũ  : "+strike+"�� , �� �� :"+ball+"��";
	}
	

}
