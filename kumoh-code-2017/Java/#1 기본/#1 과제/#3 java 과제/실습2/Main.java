import java.util.Scanner;

public class Main
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		Owner o = new Owner();
		Account a = new Account(100,o);
		
		int account_num;

		System.out.print("Input AccountNumber : ");
		account_num= sc.nextInt();
		
		a.setAccountNum(account_num);
		
		
		System.out.println("AccountNumber : "+ a.getAccountNum());
		System.out.println("Balance : "+ a.getBalance());
		System.out.println("Owner : "+ o.getName());
		System.out.println("Owner address : "+ o.getAddress());
		System.out.println("Owner PhoneNumber : "+ o.getPhoneNum());
		
		sc.close();
	}

}