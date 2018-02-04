
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
        System.out.println("입금 정보");
        System.out.println(year + "년 " + month + "월 " + day + "일 " + hour + "시 " + min + "분 " + sec + "초에 " + moneyinfo + "를 입금하셨습니다.");
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
        System.out.println("출금 정보");
        System.out.println(year + "년 " + month + "월 " + day + "일 " + hour + "시 " + min + "분 " + sec + "초에 " + moneyinfo + "를 출금하셨습니다.");
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