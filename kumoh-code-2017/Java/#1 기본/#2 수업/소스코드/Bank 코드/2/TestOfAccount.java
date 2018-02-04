import java.util.*;

public class TestOfAccount
{
    static void MenuViewer()
    {
        System.out.println("1. ���� ����");
        System.out.println("2. ������ ���� ��ȸ");
        System.out.println("3. �ܰ� ��ȸ");
        System.out.println("4. �Ա�");
        System.out.println("5. ���");
        System.out.println("6. ��ȸ");
        System.out.println("7. ���� ��ü");
        System.out.println("8. ����");
        System.out.print("�Է��ϼ��� : ");
    }
    public static void main(String[] args)
    {
        MinusAccount storeMemory = new MinusAccount();
        Scanner scan = new Scanner(System.in);
        int choice,choiceinfo;
        long findAccountNumber,wantMoney,sendAccountNumber;
        boolean Stop = true;
        
        while(Stop)
        {
            MenuViewer();
            choice = scan.nextInt();
            switch(choice)
            {
                case 1 :
                    storeMemory.CreateAccountNumber();
                    break;
                    
                case 2:
                    System.out.print("���¹�ȣ �Է� : ");
                    findAccountNumber = scan.nextLong();
                    storeMemory.FindData(findAccountNumber);
                    break;
                    
                case 3:
                    System.out.print("���¹�ȣ �Է� : ");
                    findAccountNumber = scan.nextLong();
                    storeMemory.getMoney(findAccountNumber);
                    break;
                    
                case 4 :
                    System.out.print("���¹�ȣ �Է� : ");
                    findAccountNumber = scan.nextLong();
                    System.out.print("�Ա��Ͻ� �ݾ� : ");
                    wantMoney = scan.nextLong();
                    storeMemory.Deposit(findAccountNumber, wantMoney);
                    break;
                    
                case 5:
                    System.out.print("���¹�ȣ �Է� : ");
                    findAccountNumber = scan.nextLong();
                    System.out.print("�Ա��Ͻ� �ݾ� : ");
                    wantMoney = scan.nextLong();
                    storeMemory.Withdraw(findAccountNumber, wantMoney);
                    break;
                            
                case 6:
                    System.out.print("���¹�ȣ �Է� : ");
                    findAccountNumber = scan.nextLong();
                    System.out.print("�Ա��̸� 1�� ����̸� 2�� �Է��ϼ���.");
                    choiceinfo = scan.nextInt();
                    
                    if(choiceinfo == 1)
                        storeMemory.DepositInformation(findAccountNumber);
                    else if(choiceinfo == 2)
                        storeMemory.WithdrawInformation(findAccountNumber);
                    else
                        System.out.println("�߸� �Է��ϼ̽��ϴ�.");
                    
                    break;
                case 7:
                    System.out.print("���¹�ȣ �Է� : ");
                    findAccountNumber = scan.nextLong();
                    System.out.print("������ ���¹�ȣ �Է� : ");
                    sendAccountNumber = scan.nextLong();
                    System.out.print("������ �ݾ��� �Է��ϼ��� : ");
                    wantMoney = scan.nextLong();
                    storeMemory.SendMoney(findAccountNumber, sendAccountNumber, wantMoney);
                    break;
                case 8:
                    System.out.println("����Ǿ����ϴ�.");
                    Stop = false;
             }
        }
    }
}