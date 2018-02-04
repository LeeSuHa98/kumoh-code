public class Account
{
	private static long 마지막계좌번호 = 0L;
	
	private long 계좌번호;
	private long 잔고;
	private String 예금주;
	
	Account(String 예금주, long 예금액)
	{
		계좌번호 = nextAccountNumber();
		this.예금주 = 예금주;
		잔고 = 예금액;
	}
	
	private static long nextAccountNumber(){return ++마지막계좌번호;}
	
	public long getBalance(){return 잔고;}
	public void deposit(long 예금액){잔고 += 예금액;} // 입금
	public long withdraw(long 출금액){return 잔고 >= 출금액 ? 잔고 -= 출금액 : 0L;} // 출금
	
	public void showAccount()
	{
		System.out.printf("%s, %04d-%04d %10d%n", 예금주, 계좌번호/1000, 계좌번호%10000, 잔고);
	}
}