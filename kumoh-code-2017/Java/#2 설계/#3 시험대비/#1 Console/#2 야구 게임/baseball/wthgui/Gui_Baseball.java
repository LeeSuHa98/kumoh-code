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
		
		f=new Frame("신나는 야구게임");
		p1=new Panel();
		p2=new Panel();		p3=new Panel();
		l1=new Label("3자리 숫자를 입력하세요.");
		bGenerator=new Button("입력하기");
		bExit=new Button("끝내기");		
		t1=new TextField("",5);
		bRan=new Button("랜덤값  보기");
		dl=new Dial_log(f);
		
		gui();
		f.pack(); //보여질수있는 사이즈만큼 알아서 보여준다.
		f.setVisible(true);
		
	
	}
	
	void gui()//gui 배치 메소드
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

		actionEvent();//엑션 이벤트 등록
	}
	
	public class keylisten extends KeyAdapter//엔터키 사용을 위한 리스너.
	{
		public void keyPressed(KeyEvent e)
		{
			if(e.getKeyCode()==KeyEvent.VK_ENTER)//버튼에서 엔터키를 입력했을때
				execute();
		}
	}
	
	
	
	void actionEvent()//액션 이벤트 등록
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
				System.out.println("무명 inner class 실행.. exit");
				System.exit(0);
			}});
		
	}
	
	void execute() 
	{
		System.out.println("유저 값입력\n");
		String str=t1.getText();
		
		
		if(bb.user_input(str)==false) //숫자가 같은게 있거나, 3개가 아니면
		{
			System.out.println("다시 입력");
			dl.go("세개의연속된 숫자를 입력하세요. 숫자는 각각다르게");
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
			execute();//버튼 눌렸을시 실행.
		}
		if(e.getSource()==bExit)
		{
			System.out.println("프로그램종료,\n");
			System.exit(0);
		}
		if(e.getSource()==bRan)
		{
			System.out.println("랜덤 값 보여주기,\n");
			dl.go(bb.getRanNum());//팝업 창으로 
		}
	}
	
	public static void main(String[] args) {
		
		Gui_Baseball Gui_bb=new Gui_Baseball();
		
	}
}
