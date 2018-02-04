import java.io.*;

public class Bank implements Serializable
{
	public static void main(String[] args) throws IOException
	{
		try
		{
			ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream("accounts.txt"));
			
			Account acc1 = new FreeAccount(1000);
			acc1.showAccount();
			
			acc1.deposit(10000);
			acc1.showAccount();
			
			acc1.withdraw(9000);
			acc1.showAccount();
			
			Account acc2 = new MinusAccount(2000);
			acc2.showAccount();
			
			acc2.deposit(20000);
			acc2.showAccount();
			
			acc2.withdraw(7000);
			acc2.showAccount();
			
			os.writeObject(acc1);
			os.writeObject(acc2);
			
			os.flush();
			os.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}