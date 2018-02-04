public class Bank
{
	public static void main(String[] args)
	{
		Account È«, ±è;
		
		È« = new Account("È«±æµ¿", 1000); 
		È«.showAccount(); 
		
		È«.deposit(10000); 
		System.out.print("ÀÔ±Ý 10000: "); 
		È«.showAccount();
		
		È«.withdraw(5000);
		System.out.print("Ãâ±Ý  5000: ");
		È«.showAccount();
		
		È«.deposit(20000);
		System.out.print("ÀÔ±Ý 20000: ");
		È«.showAccount();
		System.out.println();
		
		±è = new Account("±èºÎÀÚ", 2000);
		±è.showAccount();
		
		±è.deposit(20000);
		System.out.println("ÀÔ±Ý 20000: ");
		±è.showAccount();
		
		±è.withdraw(7000);
		System.out.println("Ãâ±Ý  7000: ");
		±è.showAccount();
		
		±è.deposit(40000);
		System.out.println("ÀÔ±Ý 40000: ");
		±è.showAccount();
	}
}
