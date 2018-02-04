public class Employee
{
	private String name; // 이름
	private String phoneNumber; // 전화번호
	
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
			System.out.println("문자의 길이가 11자 이상입니다.");
			System.out.println("이름 : " + name.substring(0, 10));
		}
		else if(name.length() < 11)
		{
			System.out.println("이름 : " + name);
			System.out.println("전화번호 : " + phoneNumber);
		}
	}
}
