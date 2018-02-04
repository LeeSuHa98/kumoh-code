public class Account implements Cloneable{
	
	String name;
	double balance;
	Account a;
	Account(String name, double balance)
	{
		this.name=name;
		this.balance=balance;
	}
	
	Account() {
		name = "000";
		balance = 0;
	}

	String getName()
	{
		return name;
	}
	double getBalance()
	{
		return balance;
	}
 	
 	void setName(String name)
 	{
 		this.name=name;
 	}
 	void setBalance(double balance)
 	{
 		this.balance=balance;
 	}
 	void printAccount()
 	{
 		System.out.println("������: "+name);
 		System.out.println("�ܰ�: "+balance);
 	}
 	protected Object clone() { // ������.
 		
 		try {
 	   		Account s = (Account)super.clone();

 			// reference Ÿ�� ���� ���� ����
 	   		

 			//������ ��ü�� reference ��ȯ
 	   		return s;				
 		} 
 		catch (CloneNotSupportedException e) {
 			
 			  e.printStackTrace();
 	          return null;	}
 		
 		}	
	
}
