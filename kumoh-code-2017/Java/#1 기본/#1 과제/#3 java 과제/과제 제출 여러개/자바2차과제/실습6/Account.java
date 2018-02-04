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
 		System.out.println("예금주: "+name);
 		System.out.println("잔고: "+balance);
 	}
 	protected Object clone() { // 재정의.
 		
 		try {
 	   		Account s = (Account)super.clone();

 			// reference 타입 변수 개별 복제
 	   		

 			//복제한 객체의 reference 반환
 	   		return s;				
 		} 
 		catch (CloneNotSupportedException e) {
 			
 			  e.printStackTrace();
 	          return null;	}
 		
 		}	
	
}
