public class Employee
{
	private String name; // �̸�
	private String phoneNumber; // ��ȭ��ȣ
	
	Employee(String name, String phoneNumber)
	{
		this.name = name;
		this.phoneNumber = phoneNumber;
	}
	
	void setName(String name) {this.name = name;}
	void setPhoneNumber(String phoneNo) {this.phoneNumber = phoneNo;}
	
	String getName() {return name;}
	String getPhoneNumber() {return phoneNumber;}
	
	void print()
	{
		if(name.length() > 10)
		{
			System.out.println("������ ���̰� 11�� �̻��Դϴ�.");
			System.out.println("�̸� : " + name.substring(0, 10));
		}
		else if(name.length() < 11)
		{
			System.out.println("�̸� : " + name);
			System.out.println("��ȭ��ȣ : " + phoneNumber);
		}
	}
}
