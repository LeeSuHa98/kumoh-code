/*
 * Created on 2005. 6. 8.
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */

/**
 * @author Kyoung-in,Ryu
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
import java.awt.*;
import java.awt.event.*;
import java.awt.event.KeyEvent;

public class Gui_Baseball implements ActionListener{
	
	Frame f;
	Panel p1,p2,p3;
	Label l1;
	TextField t1;
	Button bGenerator,bExit,bRan;
	BaseBallwithGUI bb=new BaseBallwithGUI();
	Dial_log dl;
	
	public Gui_Baseball()
	{
		
		f=new Frame("�ų��� �߱�����");
		p1=new Panel();
		p2=new Panel();		p3=new Panel();
		l1=new Label("3�ڸ� ���ڸ� �Է��ϼ���.");
		bGenerator=new Button("�Է��ϱ�");
		bExit=new Button("������");		
		t1=new TextField("",5);
		bRan=new Button("������  ����");
		dl=new Dial_log(f);
		
		gui();
		f.pack(); //���������ִ� �����ŭ �˾Ƽ� �����ش�.
		f.setVisible(true);
		
	
	}
	
	void gui()//gui ��ġ �޼ҵ�
	{
		p1.setBackground(Color.LIGHT_GRAY);
		p2.setBackground(Color.LIGHT_GRAY);
		p3.setBackground(Color.LIGHT_GRAY);
		f.add(p1,BorderLayout.NORTH);
		f.add(p2,BorderLayout.CENTER);
		f.add(p3,BorderLayout.SOUTH);
		p1.add(l1);
		p2.add(t1);
		p3.add(bGenerator); p3.add(bExit);p3.add(bRan);

		actionEvent();//���� �̺�Ʈ ���
	}
	
	public class keylisten extends KeyAdapter//����Ű ����� ���� ������.
	{
		public void keyPressed(KeyEvent e)
		{
			if(e.getKeyCode()==KeyEvent.VK_ENTER)//��ư���� ����Ű�� �Է�������
				execute();
		}
	}
	
	
	
	void actionEvent()//�׼� �̺�Ʈ ���
	{
		keylisten Lkey=new keylisten();
		bGenerator.addActionListener(this);
		bExit.addActionListener(this);
		bGenerator.addKeyListener(Lkey);
		t1.addKeyListener(Lkey);
		bRan.addActionListener(this);
				
		f.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e)
			{
				System.out.println("���� inner class ����.. exit");
				System.exit(0);
			}});
		
	}
	
	void execute() 
	{
		System.out.println("���� ���Է�\n");
		String str=t1.getText();
		
		
		if(bb.user_input(str)==false) //���ڰ� ������ �ְų�, 3���� �ƴϸ�
		{
			System.out.println("�ٽ� �Է�");
			dl.go("�����ǿ��ӵ� ���ڸ� �Է��ϼ���. ���ڴ� �����ٸ���");
			t1.setText("");

		}else
		{
			bb.compare();
			dl.go(bb.getResult());
			t1.setText("");
		}
		
	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==bGenerator)
		{
			execute();//��ư �������� ����.
		}
		if(e.getSource()==bExit)
		{
			System.out.println("���α׷�����,\n");
			System.exit(0);
		}
		if(e.getSource()==bRan)
		{
			System.out.println("���� �� �����ֱ�,\n");
			dl.go(bb.getRanNum());//�˾� â���� 
		}
	}
	
	public static void main(String[] args) {
		
		Gui_Baseball Gui_bb=new Gui_Baseball();
		
	}
}
