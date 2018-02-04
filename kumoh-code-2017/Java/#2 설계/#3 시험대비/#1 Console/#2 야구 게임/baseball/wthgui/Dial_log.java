import java.awt.event.*;
import java.awt.*;

/*
 * Created on 2005. 6. 9.
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */

/**
 * @author justine
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class Dial_log implements ActionListener{

	private Dialog dl;
	private Button b2,close;
	private Label lb;
	
	
	public class keylisten extends KeyAdapter//엔터키 사용을 위한 리스너.
	{
		public void keyPressed(KeyEvent e)
		{
			if(e.getKeyCode()==KeyEvent.VK_ENTER)//버튼에서 엔터키를 입력했을때
				dl.setVisible(false);
		}
	}
	public Dial_log(Frame f)
	{

		
		dl=new Dialog(f,"dialog",true);
		close= new Button("닫기");
		close.addActionListener(this);
		dl.add(close,BorderLayout.CENTER);
		lb=new Label();
		dl.add(lb,BorderLayout.NORTH);//
		//엔터키가 입력됐을때 실행하기위한 리스너
		close.addKeyListener(new keylisten());
		
		b2=new Button("Dialog");
		b2.addActionListener(this);
			
	}
	public void go(String str)
	{
		lb.setText(str);
		dl.pack();
		dl.setVisible(true);
		
	}
	public void actionPerformed( ActionEvent ae) 
	{
		String buttonPressed=ae.getActionCommand();
		if(buttonPressed.equals("닫기"))
		{
			dl.setVisible(false);
		}
		
	
	}
	
		
	}

