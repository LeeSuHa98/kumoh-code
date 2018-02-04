
import java.util.*;

class DepositInformation
{
    private int year,month,day,hour,min,sec;
    private long moneyinfo;
    
    DepositInformation(long money)
    {
        Calendar cal = Calendar.getInstance();
        moneyinfo = money;
        year = cal.get(Calendar.YEAR);
        month = cal.get(Calendar.MONDAY)+1;
        day = cal.get(Calendar.DATE);
	hour = cal.get(Calendar.HOUR_OF_DAY);
	min = cal.get(Calendar.MINUTE);
	sec = cal.get(Calendar.SECOND);	
    }
    void ShowData()
    {
        System.out.println("�Ա� ����");
        System.out.println(year + "�� " + month + "�� " + day + "�� " + hour + "�� " + min + "�� " + sec + "�ʿ� " + moneyinfo + "�� �Ա��ϼ̽��ϴ�.");
    }
}
class WithdrawInformation
{
    private int year,month,day,hour,min,sec;
    private long moneyinfo;
    
    WithdrawInformation(long money)
    {
        Calendar cal = Calendar.getInstance();
        moneyinfo = money;
        year = cal.get(Calendar.YEAR);
        month = cal.get(Calendar.MONDAY)+1;
        day = cal.get(Calendar.DATE);
	hour = cal.get(Calendar.HOUR_OF_DAY);
	min = cal.get(Calendar.MINUTE);
	sec = cal.get(Calendar.SECOND);	
    }
    void ShowData()
    {
        System.out.println("��� ����");
        System.out.println(year + "�� " + month + "�� " + day + "�� " + hour + "�� " + min + "�� " + sec + "�ʿ� " + moneyinfo + "�� ����ϼ̽��ϴ�.");
    }
}

class Transaction
{
    private long accountNumber;
    private DepositInformation[] depoInfo = new DepositInformation[100];
    private WithdrawInformation[] withInfo = new WithdrawInformation[100];
    private int depoIndex=0,withIndex=0;
    
    Transaction(long accountNumber) {       this.accountNumber = accountNumber;    }
    void AddDepositInformation(long moneyInfo){        depoInfo[depoIndex++] = new DepositInformation(moneyInfo);    }
    void AddWithdrawInformation(long moneyInfo){       withInfo[withIndex++] = new WithdrawInformation(moneyInfo);    }
    void ShowDepositInformation()
    {
        for(int i=0;i<depoIndex;i++)
        {
            System.out.println("2");
            depoInfo[i].ShowData();
        }
    }
    void ShowWithdrawInformation()
    {
        for(int i=0;i<withIndex;i++)
        {
            withInfo[i].ShowData();
        }
    }
    int TotalDepositInformation() {     return depoIndex;    }
    int TotalWithdrawInformation() {    return withIndex;    }
}