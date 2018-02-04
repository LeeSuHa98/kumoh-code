import java.awt.Container;
import java.awt.Dialog;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;


public class WarningDialog extends JDialog implements ActionListener{
	
	/*
	 * 경고 다이얼로그
	 */
	JDialog d;
	JPanel p1,p2;
	JLabel la;
	JButton confirm;

	WarningDialog(String s,Frame f){
		super(f);
		Container co=getContentPane();
		co.setLayout(new GridLayout(2,1));
		p1=new JPanel();
		p2=new JPanel();
		la=new JLabel(s);
		confirm=new JButton("확인");
		p1.add(la);
		p2.add(confirm);
		co.add(p1);
		co.add(p2);
		confirm.addActionListener(this);
		setLocation(180,120);
		pack();
		setVisible(true);
	}
	WarningDialog(String s,Dialog f){
		super(f);
		Container co=getContentPane();
		co.setLayout(new GridLayout(2,1));
		p1=new JPanel();
		p2=new JPanel();
		la=new JLabel(s);
		confirm=new JButton("확인");
		p1.add(la);
		p2.add(confirm);
		co.add(p1);
		co.add(p2);
		confirm.addActionListener(this);
		setLocation(260,260);
		pack();
		setVisible(true);
		
	}
	public void actionPerformed(ActionEvent e){
		setVisible(false);
		
	}
	
}