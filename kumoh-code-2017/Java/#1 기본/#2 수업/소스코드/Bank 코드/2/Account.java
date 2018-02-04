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
        System.out.print("�̸� �Է� : ");
        name = scan.nextLine();
        System.out.print("�ּ� �Է� : ");
        address = scan.nextLine();
        System.out.print("���� �Է� : ");
        birthday = scan.nextLine();
        System.out.print("��ȭ��ȣ �Է� ex)051)501-5043 : ");
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
            System.out.println("�̸� : " + storeUser[wantIndex].name);
            System.out.println("�ּ� : " + storeUser[wantIndex].address);
            System.out.println("���� : " + storeUser[wantIndex].birthday);
            System.out.println("��ȭ��ȣ : " + storeUser[wantIndex].phonNumber);
            System.out.println("�����Ͻ� : " + storeUser[wantIndex].year + "�� " + storeUser[wantIndex].month + "�� " + 
storeUser[wantIndex].day + "�� " + storeUser[wantIndex].hour + "�� " + storeUser[wantIndex].min + "�� " + storeUser
[wantIndex].sec + "��");
        }
        else    System.out.println("�����͸� ã�� �� �����ϴ�.");
    }
    
    void getMoney(long findAccountNumber)
    {
        int wantIndex;
        wantIndex = FindAccoutNumber(findAccountNumber);
        if(wantIndex != -1)      System.out.println("�ܾ� ��ȸ : " + storeUser[wantIndex].money);
        else System.out.println("�����͸� ã�� �� �����ϴ�.");
    }
    
    void Deposit(long findAccountNumber,long wantMoney)
    {
        int wantIndex;
        
        wantIndex = FindAccoutNumber(findAccountNumber);
        if(wantIndex != -1)
        {
            storeUser[wantIndex].money += wantMoney;
            System.out.println("�Ա� �Ϸ�");
            tranInfo.get(wantIndex).AddDepositInformation(wantMoney);
            //tranInfo[wantIndex].AddDepositInformation(wantMoney);
        }
        else     System.out.println("�����͸� ã�� �� �����ϴ�.");     
    }
    
    void Withdraw(long findAccountNumber,long wantMoney)
    {
        int wantIndex;
        
        wantIndex = FindAccoutNumber(findAccountNumber);
        
        
        if(wantIndex != -1)
        {
            if(storeUser[wantIndex].money < wantMoney)     System.out.println("��� ���� �Է��� �ٽ��ϼ���.");
            else 
            {
                storeUser[wantIndex].money -= wantMoney;
                System.out.println("��� ����");
                tranInfo.get(wantIndex).AddWithdrawInformation(wantMoney);
                //tranInfo[wantIndex].AddDepositInformation(wantMoney);               
            }
        }
        else System.out.println("�����͸� ã�� �� �����ϴ�.");
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