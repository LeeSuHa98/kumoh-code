
import java.util.*;
public class Account_main {

	public static void main(String[] args) {
		Owner o = new Owner();
		Account a = new Account(100,o);
		
		Scanner input = new Scanner(System.in);
		int accountnum;
		System.out.print("���¹�ȣ�Է�: ");
		accountnum= input.nextInt();
		a.setAccountnum(accountnum);
		
		
		System.out.println("��: "+a.getAccountnum());
		System.out.println("��: "+a.getBalance());
		System.out.println("������: "+o.getName());
		System.out.println("������ �ּ�: "+o.getAddress());
		System.out.println("������ ��ȭ��ȣ: "+o.getPhonenum());
		
		input.close();
	}

}
