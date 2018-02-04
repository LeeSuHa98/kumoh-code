import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

class Hello extends JFrame implements ActionListener {
	public static void main(String[] args){
		Hello f = new Hello("title");	
	}
	public Hello(String title) {
		super(title);
		initializeComponents();
	}
	private void initializeComponents() {
		Container c = this.getContentPane();
		JButton b = new JButton("press me");
		//MyActionHandler handler = new MyActionHandler();
		b.addActionListener(this);
		c.add(b);	
		this.setSize(200,200);
		this.setLocation(300, 300);
		this.setVisible(true);
	}
	@Override
	public void actionPerformed(ActionEvent e)
	{
		// TODO Auto-generated method stub
		System.out.println("press me 버튼이 눌렸습니다");
	}
}

/*class MyActionHandler implements ActionListener
{

	@Override
	public void actionPerformed(ActionEvent e)
	{
		// TODO Auto-generated method stub
		System.out.println("press me 버튼이 눌렸습니다");
	}
}*/


