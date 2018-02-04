public class Customer 
{
    
    String name;
    long accountNumber;
    long money;
    String address,birthday,phonNumber;
    int year,month,day,hour,min,sec;
    
    Customer(String name,String address,String birthday,String phonNumber,int year,int month,int day,long accountNumber,int 
hour,int min,int sec)
    {
        this.name = name;
        this.address = address;
        this.birthday = birthday;
        this.phonNumber = phonNumber;
        this.year = year;
        this.month = month;
        this.day = day;
	this.hour = hour;
	this.min = min;
	this.sec = sec;
        this.money = 0;
        this.accountNumber = accountNumber;
	System.out.println(name + "님의 계좌번호는 " + accountNumber + " 입니다.");
    }
}