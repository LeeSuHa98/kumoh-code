public interface IAccount
{
	public abstract int getAccNum();
	public abstract long getBalance();
	public abstract void deposit(long balance);
	public abstract void withdraw(long balance);
	
	public abstract void showAccount();
}
