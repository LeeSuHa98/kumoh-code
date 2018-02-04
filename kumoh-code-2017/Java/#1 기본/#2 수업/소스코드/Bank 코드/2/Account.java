import java.util.*;


public class Account
{
    protected Customer[] storeUser = new Customer[10];
    Scanner scan = new Scanner(System.in);
    Calendar cal = Calendar.getInstance();
    protected int userIndex = 0,tranIndex = 0;
    protected static long lastAccountNumber = 1000;
    protected List<Transaction> tranInfo = new ArrayList<Transaction>();
    
    void CreateAccountNumber()
    {
        String name,address,birthday,phoneNumber;
        int year,month,day,hour,min,sec;
        System.out.print("이름 입력 : ");
        name = scan.nextLine();
        System.out.print("주소 입력 : ");
        address = scan.nextLine();
        System.out.print("생일 입력 : ");
        birthday = scan.nextLine();
        System.out.print("전화번호 입력 ex)051)501-5043 : ");
        phoneNumber = scan.nextLine();
        year = cal.get(Calendar.YEAR);
        month = cal.get(Calendar.MONDAY)+1;
        day = cal.get(Calendar.DATE);
	hour = cal.get(Calendar.HOUR_OF_DAY);
	min = cal.get(Calendar.MINUTE);
	sec = cal.get(Calendar.SECOND);	
        storeUser[userIndex++] = new Customer(name, address, birthday, phoneNumber, year, month, 
day,lastAccountNumber,hour,min,sec);
        tranInfo.add(new Transaction(lastAccountNumber++));
        tranIndex++;
    }
    
    void FindData(long findAccoutNumber)
    {
        int wantIndex;
        wantIndex = FindAccoutNumber(findAccoutNumber);
        if(wantIndex != -1)
        {
            System.out.println("이름 : " + storeUser[wantIndex].name);
            System.out.println("주소 : " + storeUser[wantIndex].address);
            System.out.println("생일 : " + storeUser[wantIndex].birthday);
            System.out.println("전화번호 : " + storeUser[wantIndex].phonNumber);
            System.out.println("개설일시 : " + storeUser[wantIndex].year + "년 " + storeUser[wantIndex].month + "월 " + 
storeUser[wantIndex].day + "일 " + storeUser[wantIndex].hour + "시 " + storeUser[wantIndex].min + "분 " + storeUser
[wantIndex].sec + "초");
        }
        else    System.out.println("데이터를 찾을 수 없습니다.");
    }
    
    void getMoney(long findAccountNumber)
    {
        int wantIndex;
        wantIndex = FindAccoutNumber(findAccountNumber);
        if(wantIndex != -1)      System.out.println("잔액 조회 : " + storeUser[wantIndex].money);
        else System.out.println("데이터를 찾을 수 없습니다.");
    }
    
    void Deposit(long findAccountNumber,long wantMoney)
    {
        int wantIndex;
        
        wantIndex = FindAccoutNumber(findAccountNumber);
        if(wantIndex != -1)
        {
            storeUser[wantIndex].money += wantMoney;
            System.out.println("입금 완료");
            tranInfo.get(wantIndex).AddDepositInformation(wantMoney);
            //tranInfo[wantIndex].AddDepositInformation(wantMoney);
        }
        else     System.out.println("데이터를 찾을 수 없습니다.");     
    }
    
    void Withdraw(long findAccountNumber,long wantMoney)
    {
        int wantIndex;
        
        wantIndex = FindAccoutNumber(findAccountNumber);
        
        
        if(wantIndex != -1)
        {
            if(storeUser[wantIndex].money < wantMoney)     System.out.println("출금 실패 입력을 다시하세요.");
            else 
            {
                storeUser[wantIndex].money -= wantMoney;
                System.out.println("출금 성공");
                tranInfo.get(wantIndex).AddWithdrawInformation(wantMoney);
                //tranInfo[wantIndex].AddDepositInformation(wantMoney);               
            }
        }
        else System.out.println("데이터를 찾을 수 없습니다.");
    }
    
    void DepositInformation(long findAccountNumber)
    {
        int wantIndex;
        wantIndex = FindAccoutNumber(findAccountNumber);
        tranInfo.get(wantIndex).ShowDepositInformation();
        //tranInfo[wantIndex].ShowDepositInformation();
        System.out.println("1");
    }
    
    void WithdrawInformation(long findAccountNumber)
    {
        int wantIndex;
        wantIndex = FindAccoutNumber(findAccountNumber);
        tranInfo.get(wantIndex).ShowWithdrawInformation();
        //tranInfo[wantIndex].ShowWithdrawInformation();
    }
    
    int FindAccoutNumber(long findAccountNumber)
    {
        for(int i=0;i<userIndex;i++)
        {
            if(storeUser[i].accountNumber == findAccountNumber)
                return i;
        }
        return -1;
    }
}