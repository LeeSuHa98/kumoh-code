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
	
	private int []set_num=new int[3];//���� �����Ͽ� ������ ����
	private int []user_num=new int[3];//������ �Է��� ���� �迭�� �����ϱ� ���� ����
	private int ball=0, strike=0;
	
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
	
	void check_same()
	{
		if(user_num[0]==user_num[1]||user_num[0]==user_num[2]||user_num[1]==user_num[2])
		{
			System.out.println("���ڰ� ������ ��� �ֽ��ϴ�.");
			user_input();
		}
	
	}
	
	void user_input()//����input �� �迭�� �����ϴ� �޼ҵ�
	{

		InputStreamReader ir=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(ir);
		
		String str=null;
//		int num=0;				
		try{
			while(true)//3�ڸ����� �ƴϸ� �ٽ� �����ϱ� ���� ����
			{
				System.out.println("\n 3���� ���ڸ� ���� �ٸ��� �Է��Ͻÿ�  ex)325 or 952");
				System.out.print(" �̹� ������ ���� ��ȣ�� ������ r :");
				str=in.readLine();//��Ʈ������ ���� �Է� �޴´�.
						
			
				int num=0;
				if(str.length()==3)//3���� ���ڰ� �ƴҶ� ó��
					break;
				if(str.equals("r"))//r �� �Է��ϸ� ���� ���� ����
				{
					System.out.print("���� ���ڴ� ");
					for(int i=0;i<3;i++)
						System.out.print(set_num[i]);
					System.out.println("�Դϴ�.\n");
					continue;
				}
				
				try{//���ڰ� �ƴ� ���ڰ� �������� ó��
					
				num=Integer.parseInt(str);
					
				}catch(NumberFormatException e)
				{
					System.out.println("���ڸ� �Է��ϼ���.. ���ڰ� ���ԵǸ� �ȵ˴ϴ�.\n");
					continue;
				}
				
				
				System.out.println("3�ڸ����� �Է� �����մϴ�.\n");
			}//while
		}catch(IOException e){}
				
		 int num=Integer.parseInt(str);
		
		//3�ڸ����� ������ �Ѱ��� �ɰ��� int �� �迭�� ���� �ִ´�.
		user_num[0]=num/100;
		num=num%100;
		user_num[1]=num/10;
		user_num[2]=num%10;
		//���� ������ �Է���  ���ڰ������� �ִ��� ������ �Ǵ�.  
		
		check_same();
					
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
		//for(int i=0;i<3;i++)
	//	System.out.println(set_num[i]);
	}
	
		
	public void getResult()
	{
		System.out.println("\n��Ʈ����ũ  : "+strike+"�� , �� �� :"+ball+"��");
	}
	
	public static void main(String[] args)
	{
		BaseBall st=new BaseBall();
		st.gener_Ran();
		for(int i=0;i<5;i++)
		{
			System.out.println((5-i)+"ȸ ��ȸ�� �ֽ��ϴ�..");
			st.user_input();
			st.compare();
			st.getResult();
		}
	}
}
