public class Bank
{
	public static void main(String[] args)
	{
		Account ȫ, ��;
		
		ȫ = new Account("ȫ�浿", 1000); 
		ȫ.showAccount(); 
		
		ȫ.deposit(10000); 
		System.out.print("�Ա� 10000: "); 
		ȫ.showAccount();
		
		ȫ.withdraw(5000);
		System.out.print("���  5000: ");
		ȫ.showAccount();
		
		ȫ.deposit(20000);
		System.out.print("�Ա� 20000: ");
		ȫ.showAccount();
		System.out.println();
		
		�� = new Account("�����", 2000);
		��.showAccount();
		
		��.deposit(20000);
		System.out.println("�Ա� 20000: ");
		��.showAccount();
		
		��.withdraw(7000);
		System.out.println("���  7000: ");
		��.showAccount();
		
		��.deposit(40000);
		System.out.println("�Ա� 40000: ");
		��.showAccount();
	}
}
