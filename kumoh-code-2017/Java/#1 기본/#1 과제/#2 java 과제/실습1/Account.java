public class Account
{
	private static long ���������¹�ȣ = 0L;
	
	private long ���¹�ȣ;
	private long �ܰ�;
	private String ������;
	
	Account(String ������, long ���ݾ�)
	{
		���¹�ȣ = nextAccountNumber();
		this.������ = ������;
		�ܰ� = ���ݾ�;
	}
	
	private static long nextAccountNumber(){return ++���������¹�ȣ;}
	
	public long getBalance(){return �ܰ�;}
	public void deposit(long ���ݾ�){�ܰ� += ���ݾ�;} // �Ա�
	public long withdraw(long ��ݾ�){return �ܰ� >= ��ݾ� ? �ܰ� -= ��ݾ� : 0L;} // ���
	
	public void showAccount()
	{
		System.out.printf("%s, %04d-%04d %10d%n", ������, ���¹�ȣ/1000, ���¹�ȣ%10000, �ܰ�);
	}
}